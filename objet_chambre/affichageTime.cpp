#include "main.h"


void affichageTimeStat()
{
  ecran.clearDisplay();
  ecran.setTextColor(WHITE);

  
  ecran.setTextSize(1);

  // Titre
  ecran.setCursor(9, 0);
  ecran.print("Reglage de l'heure");


  ecran.setTextSize(2);

  // Date
  ecran.setCursor(28, 28);
  ecran.print("/  /");


  // Heure
  ecran.setCursor(40, 49);
  ecran.print(":  :");
  
  
  
  ecran.display();
}





void affichageTimeDyna(DateTime now)
{
  ecran.setTextColor(WHITE);

  
  ecran.setTextSize(2);

  // Mode
  if(etatAffich == TIME_MODE)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(27, 9, 72, 16, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
    ecran.fillRect(27, 9, 72, 16, BLACK);
  }
  ecran.setCursor(28, 10);
  if(EEPROM.read(ADDRESS_MODEREGL) == AUTO)
    ecran.print(" AUTO ");
  else
    ecran.print("MANUEL");

  

  // Jour
  if(etatAffich == TIME_JOUR)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(3, 27, 24, 16, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
    ecran.fillRect(3, 27, 24, 16, BLACK);
  }
  ecran.setCursor(4, 28);
  ecran.print(editForm(now.day(), 32, ' '));

  // Mois
  if(etatAffich == TIME_MOIS)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(39, 27, 24, 16, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
    ecran.fillRect(39, 27, 24, 16, BLACK);
  }
  ecran.setCursor(40, 28);
  ecran.print(editForm(now.month(), 13, '0'));

  // Annee
  if(etatAffich == TIME_ANNEE)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(75, 27, 48, 16, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
    ecran.fillRect(75, 27, 48, 16, BLACK);
  }
  ecran.setCursor(76, 28);
  ecran.print(now.year());



  // Heure
  if(etatAffich == TIME_HEURE)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(15, 47, 24, 16, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
    ecran.fillRect(15, 47, 24, 16, BLACK);
  }
  ecran.setCursor(16, 48);
  ecran.print(editForm(now.hour(), 24, ' '));

  // Minute
  if(etatAffich == TIME_MINUTE)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(51, 47, 24, 16, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
    ecran.fillRect(51, 47, 24, 16, BLACK);
  }
  ecran.setCursor(52, 48);
  ecran.print(editForm(now.minute(), 60, '0'));

  // Seconde
  if(etatAffich == TIME_SECONDE)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(87, 47, 24, 16, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
    ecran.fillRect(87, 47, 24, 16, BLACK);
  }
  ecran.setCursor(88, 48);
  ecran.print(editForm(now.second(), 60, '0'));
  
  
  ecran.display();
}
