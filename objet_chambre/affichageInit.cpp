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
/*
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
*/
void affichageInitManager (WiFiManager *myWiFiManager)
{
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  Serial.println(myWiFiManager->getConfigPortalSSID());

  ecran.fillRect(0, 22, 128, 8, BLACK);
  ecran.setCursor(12, 22);
  ecran.print("Echec de connexion");
  ecran.display();
  
  delay(3000);
  
  ecran.fillRect(0, 12, 128, 8, BLACK);
  ecran.setCursor(0, 12);
  ecran.print("Configuration WiFi :");
  
  ecran.fillRect(0, 22, 128, 8, BLACK);
  ecran.setCursor(12, 22);
  String ssid = myWiFiManager->getConfigPortalSSID();
  if(ssid.length() <= 19)
    ecran.print(ssid);
  else
    ecran.print(ssid.substring(0, 16) + "...");
  
  ecran.display();
  
}


void affichageInitConnected(bool success)
{
  ecran.setCursor(12, 42);
  if(success)
    ecran.print("Connexion reussie");
  else
    ecran.print("Echec de config.");

  ecran.display();
}

void affichageInitMesures(int compte)
{
  ecran.fillRect(0, 56, 128, 8, BLACK);

  ecran.setCursor(0, 56);
  ecran.print("Demarrage dans " + String(NB_MESURES - compte));

  ecran.display();
}
