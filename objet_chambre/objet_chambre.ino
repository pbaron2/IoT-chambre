#include "main.h"


RTC_DS1307 rtc;
TM1637Display afficheur = TM1637Display(PIN_CLK_7SEG, PIN_DIO_7SEG);
Adafruit_SSD1306 ecran(D3);

DHT_Unified dht(PIN_DHT, DHT22);

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org");

//Central European Time (Frankfurt, Paris)
TimeChangeRule CEST = {"CEST", Last, Sun, Mar, 2, 120};     //Central European Summer Time
TimeChangeRule CET = {"CET ", Last, Sun, Oct, 3, 60};       //Central European Standard Time
Timezone tz(CEST, CET);

//ESP8266WebServer server(80); //Server on port 80
WiFiClient espClient;
PubSubClient client(espClient);

bool wifiConnected = false;
bool mqttConnected = false;

volatile bool etatSwitch[3] = {false, false, false};

String jourL[7] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"};
String moisL[12] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};

int temperature = 0;
int humidite = 0;
int luminosite = 0;
int lumiRaw = 0;

alarmTime alarme = {0, 0};
bool activateAlarme = false;
unsigned long previousMillis = 0;
bool etatBuzzer = false;

bool dataValid = false;

meteoStruct meteo = {0, 0, 0, 0};

Affichage etatAffich = NORMAL;
bool changeAffichStat = true;

unsigned long tempsEcoule = 0;


Timer t;


const uint8_t SEG_BOOT[] = {
  SEG_C | SEG_D | SEG_E | SEG_F | SEG_G,           // b
  SEG_C | SEG_D | SEG_E | SEG_G,                   // o
  SEG_C | SEG_D | SEG_E | SEG_G,                   // o
  SEG_D | SEG_E | SEG_F | SEG_G                    // t
  };


void setup()
{
  
  Serial.begin(115200);

  // RTC
  Wire.begin(PIN_SDA, PIN_SCL);
  rtc.begin();
  if (!rtc.isrunning())
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));


  // Afficheur
  afficheur.setBrightness(0);
  afficheur.setSegments(SEG_BOOT);


  // Ecran
  ecran.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  affichageInitTitre();


  // EEPROM
  EEPROM.begin(8);
  

  // Definition des PINs
  pinMode(PIN_BUZZ, OUTPUT);
  noTone(PIN_BUZZ);
  
  pinMode(PIN_SW1, INPUT);
  pinMode(PIN_SW2, INPUT);
  pinMode(PIN_SW3, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_SW1), switchPressed1, RISING);
  attachInterrupt(digitalPinToInterrupt(PIN_SW2), switchPressed2, RISING);
  attachInterrupt(digitalPinToInterrupt(PIN_SW3), switchPressed3, RISING);


  // DHT
  dht.begin();
  t.every(DELAI_MESURE, updateDHT);
  

  // WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  int nbTent = 0;
  while (WiFi.status() != WL_CONNECTED && nbTent < DELAI_CONNEXION * 2)
  {
    affichageInitConnexion(nbTent/3);
    delay(500);
    Serial.print(".");
    nbTent++;
  }
  Serial.println();

  if(nbTent == DELAI_CONNEXION * 2) // Connexion echouee
  {
    Serial.print("Not connected");
    EEPROM.write(ADDRESS_MODEREGL, MANUEL);
    EEPROM.commit();
    wifiConnected = false;
  }
  else
  {
    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
    wifiConnected = true;
  }
  affichageInitConnected(wifiConnected);

  
  // NTP
  timeClient.begin();
  timeClient.setUpdateInterval(3600000);
  timeClient.setTimeOffset(0);
  if(wifiConnected)
    timeClient.update();


  // Web
  /*server.on("/", webpage); // Which routine to handle at root location
  server.begin(); */

  // MQTT
  client.setServer(MQTT_SERVER, 1883);
  reconnectMqtt();
  t.every(DELAI_MQTT, mqttPost);
  t.every(5 * DELAI_MQTT, reconnectMqtt);

  // Meteo
  updateMeteo();
  t.every(3600000, updateMeteo);


  // Alarme
  alarme.hour = EEPROM.read(ADDRESS_H_ALARME);
  alarme.minute = EEPROM.read(ADDRESS_M_ALARME);


  // Mesures
  for(int nbMes = 0; nbMes < NB_MESURES; nbMes++)
  {
    affichageInitMesures(nbMes);

    updateLuminosite();
    updateDHT();

    delay(500);
  }
  

}











void loop()
{
  // Connexion WiFi
  wifiConnected = (WiFi.status() == WL_CONNECTED);


  // Timer
  t.update();

  /*// Gestion Web
  if(wifiConnected)
    server.handleClient();*/

  // Gestion MQTT
  mqttConnected = client.connected();
  if(wifiConnected && mqttConnected)
    client.loop();
  Serial.println(mqttConnected);

  
  // Luminosite afficheur
  updateLuminosite();
  afficheur.setBrightness(luminosite);
  Serial.print("\nLUMINOSITE: ");
  Serial.println(luminosite);


  // Synchronisation auto de l'heure
  if(EEPROM.read(ADDRESS_MODEREGL) == AUTO && wifiConnected)
  {
    rtc.adjust(DateTime(tz.toLocal(timeClient.getEpochTime())));
    Serial.println("\nHeure synchronisee via NTP");
  }


  // Maj variable timeout retour affichage normal
  if(etatSwitch[MENU] || etatSwitch[PLUS] || etatSwitch[MOINS])
  {
    tempsEcoule = millis();
  }


  // Navigation menu
  if(etatSwitch[MENU])
  {
    if(EEPROM.read(ADDRESS_MODEREGL) == MANUEL)
      etatAffich = (Affichage) ((etatAffich + 1) % 11);
    else if(EEPROM.read(ADDRESS_MODEREGL) == AUTO)
      etatAffich = (Affichage) ((etatAffich + 1) % 5);
    else
    {
      EEPROM.write(ADDRESS_MODEREGL, AUTO);
      EEPROM.commit();
      etatAffich = (Affichage) ((etatAffich + 1) % 5);
    }

    if(!EEPROM.read(ADDRESS_ETATALAR) && etatAffich == ALARME_HOUR)
    {
      etatAffich = TIME_MODE;
    }
      
    if(etatAffich == NORMAL || etatAffich == ALARME_ETAT || etatAffich == TIME_MODE)
      changeAffichStat = true;

    etatSwitch[MENU] = false;
  }
  Serial.print("\netatAffich / changeAffichStat : ");
  Serial.print(etatAffich);
  Serial.print(" / ");
  Serial.println(changeAffichStat);



  // Retour affichage normal timeout
  if(etatAffich != NORMAL && abs(millis() - tempsEcoule) > DELAI_RETOUR)
  {
    etatAffich = NORMAL;
    changeAffichStat = true;
    Serial.println("\nTimeout -> retour a l'affichage normal");
  }


  // Afficheur
  DateTime now = rtc.now(); 
  bool pair = now.second() % 2;

  afficheur.showNumberDecEx(now.hour(), 0xFF * pair, false, 2, HOURS);
  afficheur.showNumberDecEx(now.minute(), 0xFF * pair, true, 2, MINUTES);

  Serial.print("\nTime actuel : ");
  Serial.print(now.day());
  Serial.print("/");
  Serial.print(now.month());
  Serial.print("/");
  Serial.print(now.year());
  Serial.print("  ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.println(now.second());


/*
  ecran.fillRect(10, 8, 6*4, 8, BLACK);
  ecran.setCursor(10,8);
  ecran.print(analogRead(PIN_PHOTORES));

  ecran.fillRect(10, 32, 6*5, 8, BLACK);
  ecran.setCursor(10,32);
  for(byte i = 0 ; i < 3 ; i++)
  {
    if(etatSwitch[i])
      ecran.print("X ");
    else
      ecran.print("_ ");
    etatSwitch[i] = false;
  }
   
  ecran.display();
  */


  // Gestion de l'affichage et des interactions
  if(etatAffich == NORMAL)
  {
    if(changeAffichStat)
    {
      affichageNormalStat();

      if(EEPROM.read(ADDRESS_H_ALARME) != alarme.hour)
      {
        EEPROM.write(ADDRESS_H_ALARME, alarme.hour);
        EEPROM.commit();
      }
      if(EEPROM.read(ADDRESS_M_ALARME) != alarme.minute)
      {
        EEPROM.write(ADDRESS_M_ALARME, alarme.minute);
        EEPROM.commit();
      }
      
    }
    affichageNormalDyna(now);
  }
  else if(etatAffich == ALARME_ETAT || etatAffich == ALARME_HOUR || etatAffich == ALARME_MINUTE)
  {
    if(changeAffichStat)
    {
      affichageAlarmeStat();
    }

    if(etatSwitch[PLUS])
    {
      if(etatAffich == ALARME_ETAT)
      {
        if(EEPROM.read(ADDRESS_ETATALAR) != 1)
        {
          EEPROM.write(ADDRESS_ETATALAR, 1);
          EEPROM.commit();
        }
      }
      else if(etatAffich == ALARME_HOUR)
        alarme.hour = (alarme.hour + 1) % 24;
      else if(etatAffich == ALARME_MINUTE)
        alarme.minute = (alarme.minute + 1) % 60;
      etatSwitch[PLUS] = false;
    }
    if(etatSwitch[MOINS])
    {
      if(etatAffich == ALARME_ETAT)
      {
        if(EEPROM.read(ADDRESS_ETATALAR) != 0)
        {
          EEPROM.write(ADDRESS_ETATALAR, 0);
          EEPROM.commit();
        }
      }
      else if(etatAffich == ALARME_HOUR)
        alarme.hour = (alarme.hour +23) % 24;
      else if(etatAffich == ALARME_MINUTE)
        alarme.minute = (alarme.minute +59) % 60;
      etatSwitch[MOINS] = false;
    }
    
    affichageAlarmeDyna();
  }
  else if(etatAffich == TIME_JOUR || etatAffich == TIME_MOIS || etatAffich == TIME_ANNEE || etatAffich == TIME_HEURE || etatAffich == TIME_MINUTE || etatAffich == TIME_SECONDE || etatAffich == TIME_MODE)
  {
    if(changeAffichStat)
    {
      affichageTimeStat();
    }
    if(etatSwitch[PLUS])
    {
      if(etatAffich == TIME_JOUR)
        rtc.adjust(DateTime(now.year(), now.month(), now.day() % nbJourDansMois(now.month(), now.year()) + 1, now.hour(), now.minute(), now.second()));
      else if(etatAffich == TIME_MOIS)
      {
        int nbJour = nbJourDansMois((now.month() % 12) + 1, now.year());
        int jour = (now.day() > nbJour) ? nbJour : now.day();
        rtc.adjust(DateTime(now.year(), (now.month() % 12) + 1, jour, now.hour(), now.minute(), now.second()));
      }
      else if(etatAffich == TIME_ANNEE)
        rtc.adjust(DateTime(((now.year() - 1999) % 100) + 2000, now.month(), now.day(), now.hour(), now.minute(), now.second()));
      else if(etatAffich == TIME_HEURE)
        rtc.adjust(DateTime(now.year(), now.month(), now.day(), (now.hour() + 1) % 24, now.minute(), now.second()));
      else if(etatAffich == TIME_MINUTE)
        rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), (now.minute() + 1) % 60, now.second()));
      else if(etatAffich == TIME_SECONDE)
        rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), now.minute(), 30));
      else if(etatAffich == TIME_MODE)
      {
        if(EEPROM.read(ADDRESS_MODEREGL) != AUTO)
        {
          EEPROM.write(ADDRESS_MODEREGL, AUTO);
          EEPROM.commit();
        }
        
        if(wifiConnected)
          timeClient.update();
      }
      
      etatSwitch[PLUS] = false;
    }
    if(etatSwitch[MOINS])
    {
      if(etatAffich == TIME_JOUR)
        rtc.adjust(DateTime(now.year(), now.month(), ((now.day() + nbJourDansMois(now.month(), now.year()) - 2) % nbJourDansMois(now.month(), now.year())) + 1, now.hour(), now.minute(), now.second()));
      else if(etatAffich == TIME_MOIS)
      {
        int nbJour = nbJourDansMois(((now.month() + 10) % 12) + 1, now.year());
        int jour = (now.day() > nbJour) ? nbJour : now.day();
        rtc.adjust(DateTime(now.year(), ((now.month() + 10) % 12) + 1, jour, now.hour(), now.minute(), now.second()));
      }
      else if(etatAffich == TIME_ANNEE)
        rtc.adjust(DateTime(((now.year() - 1901) % 100) + 2000, now.month(), now.day(), now.hour(), now.minute(), now.second()));
      else if(etatAffich == TIME_HEURE)
        rtc.adjust(DateTime(now.year(), now.month(), now.day(), (now.hour() + 23) % 24, now.minute(), now.second()));
      else if(etatAffich == TIME_MINUTE)
        rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), (now.minute() + 59) % 60, now.second()));
      else if(etatAffich == TIME_SECONDE)
        rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), now.minute(), 0));
      else if(etatAffich == TIME_MODE)
      {
        if(EEPROM.read(ADDRESS_MODEREGL) != MANUEL)
        {
          EEPROM.write(ADDRESS_MODEREGL, MANUEL);
          EEPROM.commit();
        }
      }
        
      etatSwitch[MOINS] = false;
    }
    
    affichageTimeDyna(now);
  }
  
  changeAffichStat = false;


  // Alarme
  activateAlarme = false;
  if(EEPROM.read(ADDRESS_ETATALAR))
  {
    int refAct = 60 * now.hour() + now.minute();
    int refAlarme = 60 * alarme.hour + alarme.minute;
    if(refAlarme < 1440 - ALARME_DUREE)
    {
      if(refAct >= refAlarme && refAct <= refAlarme + ALARME_DUREE)
      {
        activateAlarme = true;
      }
    }
    else
    {
      if(refAct >= refAlarme || refAct <= refAlarme + ALARME_DUREE - 1440)
      {
        activateAlarme = true;
      }
    }
  }

  unsigned long currentMillis = millis();

  if (activateAlarme && currentMillis - previousMillis >= 500)
  {
    previousMillis = currentMillis;
    etatBuzzer = !etatBuzzer;
  }

  if(etatBuzzer && activateAlarme)
  {
    tone(PIN_BUZZ, 330);
  }
  else
  {
    noTone(PIN_BUZZ);
  }

  delay(10);
  
  
  /*
  digitalWrite(PIN_DHT, HIGH);
  delay(200);
  digitalWrite(PIN_DHT, LOW);
  delay(100);*/
}
