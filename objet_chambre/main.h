#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED


#include <Wire.h>
#include <RTClib.h>
#include <Adafruit_SSD1306_64.h>
#include <TM1637Display.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include <Event.h>
#include <Timer.h>
#include <EEPROM.h>

//#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <Timezone.h>
#include <PubSubClient.h>

#include "boutons.h"
#include "affichageDivers.h"
#include "affichageNormal.h"
#include "affichageAlarme.h"
#include "affichageTime.h"
#include "affichageInit.h"
#include "web.h"
#include "meteo.h"


#define PIN_PHOTORES    A0

#define PIN_SW1         D6
#define PIN_SW2         D7
#define PIN_SW3         D8

#define PIN_CLK_7SEG    D5
#define PIN_DIO_7SEG    D0

#define PIN_SCL         D1
#define PIN_SDA         D2

#define PIN_BUZZ        D3
#define PIN_DHT         D4

#define MINUTES   2
#define HOURS     0

#define NB_MESURES   10

#define ADDRESS_MODEREGL    0
#define ADDRESS_ETATALAR    1
#define ADDRESS_H_ALARME    2
#define ADDRESS_M_ALARME    3

#define ALARME_DUREE      5


#define MENU    0
#define PLUS    1
#define MOINS   2

#define MANUEL  0
#define AUTO    1

#define DELAI_RETOUR    15000
#define DELAI_MQTT      120000
#define DELAI_MESURE    2000

#define WIFI_SSID   "UPC614C757"
#define WIFI_PASS   "tHbdk5cykK8m"

#define DELAI_CONNEXION   30
#define LOCALIZATION_KEY  String("995")   // St-Blaise
//#define LOCALIZATION_KEY  String("1109787")   // Cesson
#define API_KEY           String("aU7vFJJFtJrHBOAKXeqvjICKPwrFkMCi")
#define URL_METEO         String("http://dataservice.accuweather.com/forecasts/v1/daily/1day/" + LOCALIZATION_KEY + "?apikey=" + API_KEY + "&language=fr-fr&details=true&metric=true")

#define MQTT_SERVER   "ec2-18-222-208-169.us-east-2.compute.amazonaws.com"
#define MQTT_USER     "Fx1KhsgQ7mLwkMHdHuqW"
#define MQTT_PASS     ""
#define MQTT_TOPIC "v1/devices/me/telemetry"


extern RTC_DS1307 rtc;
extern TM1637Display afficheur;
extern Adafruit_SSD1306 ecran;

extern DHT_Unified dht;

extern WiFiUDP ntpUDP;
extern NTPClient timeClient;

//Central European Time (Frankfurt, Paris)
extern TimeChangeRule CEST;     //Central European Summer Time
extern TimeChangeRule CET;       //Central European Standard Time
extern Timezone tz;

//extern ESP8266WebServer server;

extern WiFiClient espClient;
extern PubSubClient client;

extern bool wifiConnected;

extern volatile bool etatSwitch[3];

extern String jourL[7];
extern String moisL[12];

enum Affichage
{
    NORMAL, ALARME_ETAT, ALARME_HOUR, ALARME_MINUTE, TIME_MODE, TIME_JOUR, TIME_MOIS, TIME_ANNEE, TIME_HEURE, TIME_MINUTE, TIME_SECONDE 
};
typedef enum Affichage Affichage;

struct alarmTime
{
    byte hour;
    byte minute;
};
typedef struct alarmTime alarmTime;

extern bool activateAlarme;

struct meteoStruct
{
    int vent;
    int tempMin;
    int tempMax;
    int pluie;
};
typedef struct meteoStruct meteoStruct;

extern int temperature;
extern int humidite;
extern int luminosite;
extern bool dataValid;

extern alarmTime alarme;
extern meteoStruct meteo;

extern Affichage etatAffich;
extern bool changeAffichStat;

extern unsigned long tempsEcoule;

extern Timer t;



#endif

