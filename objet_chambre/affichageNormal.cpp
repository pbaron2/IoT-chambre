#include "main.h"




void affichageNormalDyna(DateTime time)
{
  ecran.setTextColor(WHITE);

  ecran.setTextSize(1);
  
  ecran.fillRect(0, 0, 128, 8, BLACK); // Date
  String date = dateForm(time.day(), time.month(), time.year());
  ecran.setCursor(64 - date.length() * 3, 0);  
  ecran.print(date);

  if(wifiConnected)
  {
    ecran.fillRect(0, 45, 12, 8, BLACK); // Temp min
    ecran.setCursor(0, 45);  
    ecran.print(editForm(meteo.tempMin/10, 100, ' '));
    
    ecran.fillRect(18, 45, 6, 8, BLACK); // Temp min (dixieme)
    ecran.setCursor(18, 45);  
    ecran.print(abs(meteo.tempMin - (meteo.tempMin/10) * 10));
  
    
    ecran.fillRect(36, 45, 12, 8, BLACK); // Temp max
    ecran.setCursor(36, 45);  
    ecran.print(editForm(meteo.tempMax/10, 100, ' '));
    
    ecran.fillRect(54, 45, 6, 8, BLACK); // Temp max (dixieme)
    ecran.setCursor(54, 45);  
    ecran.print(abs(meteo.tempMax - (meteo.tempMax/10) * 10));
  
    
    ecran.fillRect(0, 56, 12, 8, BLACK); // Pluie
    ecran.setCursor(0, 56);  
    ecran.print(editForm(meteo.pluie, 100, ' '));
    
    ecran.fillRect(36, 56, 12, 8, BLACK); // Vent
    ecran.setCursor(36, 56);  
    ecran.print(editForm(meteo.vent, 100, ' '));
  }

  
  ecran.setTextSize(2);

  ecran.fillRect(82, 16, 24, 16, BLACK); // Humidite
  ecran.setCursor(82, 16);  
  ecran.print(editForm(humidite, 100, ' '));

  if(EEPROM.read(ADDRESS_ETATALAR))
  {
    ecran.fillRect(73, 48, 24, 16, BLACK); // Heures alarme
    ecran.setCursor(73, 48);  
    ecran.print(editForm(alarme.hour, 24, ' '));
    
    ecran.fillRect(104, 48, 24, 16, BLACK); // Minutes alarme
    ecran.setCursor(104, 48);  
    ecran.print(editForm(alarme.minute, 60, '0'));
  }


  ecran.setTextSize(3);
  
  ecran.fillRect(0, 16, 36, 24, BLACK); // Temperature
  ecran.setCursor(0, 16);  
  ecran.print(editForm(temperature/10, 100, ' '));
  
  ecran.fillRect(45, 16, 18, 24, BLACK); // Temperature (dixieme)
  ecran.setCursor(45, 16);  
  ecran.print(abs(temperature - (temperature/10) * 10));

  ecran.display();
}



void affichageNormalStat()
{
  ecran.clearDisplay();
  ecran.setTextColor(WHITE);

  
  ecran.setTextSize(3);
  
  // Temperature
  ecran.setCursor(30, 16);  
  ecran.print(".");
  ecran.drawCircle(67, 21, 4, WHITE);
  ecran.drawCircle(67, 21, 3, WHITE);


  ecran.setTextSize(2);

  // Humidite
  ecran.setCursor(106, 16);
  ecran.print("%");

  // Alarme
  if(EEPROM.read(ADDRESS_ETATALAR))
  {
    ecran.setCursor(95, 48);
    ecran.print(":");
  }

  ecran.setTextSize(1);

  if(wifiConnected)
  {
    // Temperature min et max
    ecran.setCursor(12, 45);
    ecran.print(".     .");
    ecran.drawCircle(25, 46, 1, WHITE);
    ecran.drawCircle(61, 46, 1, WHITE);
  
    // Vent et pluie
    ecran.setCursor(2, 56);
    ecran.print("  mm    kmh");
  }

  // "Alarme"
  if(EEPROM.read(ADDRESS_ETATALAR))
  {
    ecran.setCursor(82, 39);
    ecran.print("ALARME");
  }
  
  ecran.display();
}


