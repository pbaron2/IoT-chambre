#include "main.h"




void affichageInitTitre()
{
  ecran.fillRect(0, 0, 128, 64, BLACK);

  
  ecran.setTextColor(WHITE);

  ecran.setTextSize(1);
  
  ecran.setCursor(22, 0);  
  ecran.print("Initialisation");

  ecran.setCursor(0, 12);
  ecran.print("Connexion au WiFi :");

  ecran.setCursor(12, 22);
  if(String(WIFI_SSID).length() <= 19)
    ecran.print(WIFI_SSID);
  else
    ecran.print(String(WIFI_SSID).substring(0, 16) + "...");

  ecran.display();
}

void affichageInitConnexion(int nbPts)
{
  ecran.fillRect(0, 32, 128, 8, BLACK);
    
  for(int i = 0; i < nbPts; i++)
  {
    ecran.setCursor(12 + i*6, 32);
    ecran.print('-');
  }

  ecran.display();
}

void affichageInitConnected(bool success)
{
  ecran.setCursor(12, 42);
  if(success)
    ecran.print("Connexion reussie");
  else
    ecran.print("Echec de connexion");

  ecran.display();
}

void affichageInitMesures(int compte)
{
  ecran.fillRect(0, 56, 128, 8, BLACK);

  ecran.setCursor(0, 56);
  ecran.print("Demarrage dans " + String(NB_MESURES - compte));

  ecran.display();
}

