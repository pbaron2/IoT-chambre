#include "main.h"


void affichageAlarmeStat()
{
  ecran.clearDisplay();
  ecran.setTextColor(WHITE);

  
  ecran.setTextSize(1);

  // Titre
  ecran.setCursor(6, 0);
  ecran.print("Reglage de l'alarme");
  

  ecran.setTextSize(3);
  
  // Alarme
  ecran.setCursor(55, 40);
  ecran.print(":");

  
  ecran.display();
}



void affichageAlarmeDyna()
{

  ecran.setTextSize(2);

  if(etatAffich == ALARME_ETAT)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(27, 17, 72, 16, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
    ecran.fillRect(27, 17, 72, 16, BLACK);
  }
  ecran.setCursor(28, 18);
  if(EEPROM.read(ADDRESS_ETATALAR))
    ecran.print("ACTIVE");
  else
    ecran.print("ETEINT");


    
  ecran.setTextSize(3);

  // Heure
  if(etatAffich == ALARME_HOUR)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(17, 38, 37, 25, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
    ecran.fillRect(17, 38, 37, 25, BLACK);
  }
  ecran.setCursor(19, 40);
  ecran.print(editForm(alarme.hour, 24, ' '));

  // Minute
  if(etatAffich == ALARME_MINUTE)
  {
    ecran.setTextColor(BLACK);
    ecran.fillRect(71, 38, 37, 25, WHITE);
  }
  else
  {
    ecran.setTextColor(WHITE);
    ecran.fillRect(71, 38, 37, 25, BLACK);
  }
  ecran.setCursor(73, 40);
  ecran.print(editForm(alarme.minute, 60, '0'));
  
  
  
  ecran.display();
}
