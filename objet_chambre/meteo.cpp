#include "main.h"

HTTPClient http;

int iMesures = 0;
int temperatureL[NB_MESURES] = {0};
int humiditeL[NB_MESURES] = {0};
bool dataValidL[NB_MESURES] = {0};

int iLuminosite = 0;
int luminositeL[NB_MESURES] = {0};


void updateMeteo()
{
  if(wifiConnected)
  {
    Serial.println("\nActualisation de la meteo...");
    String payload;
    
    http.begin(URL_METEO);  // Specify request destination

    int httpCode = http.GET();
    if (httpCode > 0) // Send the request and check the returning code
    { 
      Serial.println("Reponse recue");

      payload = http.getString();   // Get the request response payload
      Serial.println(payload);
      
      const size_t capacity = 2*JSON_ARRAY_SIZE(1) + 4*JSON_OBJECT_SIZE(2) + 2*JSON_OBJECT_SIZE(3) + JSON_OBJECT_SIZE(8) + JSON_OBJECT_SIZE(9) + 1110;
      DynamicJsonBuffer jsonBuffer(capacity);
    
      JsonObject& root = jsonBuffer.parseObject(payload);
      
      if (root.success())
      {
        Serial.println("JSON parse");
        
        meteo.tempMin = float(root["DailyForecasts"][0]["Temperature"]["Minimum"]["Value"]) * 10;
        meteo.tempMax = float(root["DailyForecasts"][0]["Temperature"]["Maximum"]["Value"]) * 10;
        meteo.vent = int(root["DailyForecasts"][0]["Day"]["Wind"]["Speed"]["Value"]);
        meteo.pluie = int(root["DailyForecasts"][0]["Day"]["TotalLiquid"]["Value"]);
      }
    }
    else
    {
      Serial.printf("error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();   // Close connection
  }
  else
  {
    meteo.tempMin = 0;
    meteo.tempMax = 0;
    meteo.vent = 0;
    meteo.pluie = 0;
  }
  Serial.println("Fin d'actualisation");
}



void updateDHT()
{
  dataValidL[iMesures] = true;
  
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  if (!isnan(event.temperature))
  {
    Serial.print("\nTemperature: ");
    Serial.print(event.temperature);
    Serial.println(" *C");
    
    temperatureL[iMesures] = int(event.temperature * 10);
  }
  else
  {
    temperatureL[iMesures] = temperatureL[(iMesures + NB_MESURES + 1) % NB_MESURES];
    dataValidL[iMesures] = false;
    Serial.print("\nFail mesure temperature\n");
  }

  dht.humidity().getEvent(&event);
  if (!isnan(event.relative_humidity))
  {
    Serial.print("\nHumidite: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
    humiditeL[iMesures] = int(event.relative_humidity);
  }
  else
  {
    humiditeL[iMesures] = humiditeL[(iMesures + NB_MESURES + 1) % NB_MESURES];
    dataValidL[iMesures] = false;
    Serial.print("\nFail mesure humidity\n");
  }

  temperature = moyenneMesures(temperatureL, NB_MESURES);
  humidite = moyenneMesures(humiditeL, NB_MESURES);
  iMesures = (iMesures + 1) % NB_MESURES;
  dataValid = true;
  for(int i = 0; i < NB_MESURES; i++)
  {
    dataValid = dataValid && dataValidL[i];
  }
}

void updateLuminosite()
{
  luminositeL[iLuminosite] = map(analogRead(PIN_PHOTORES), 0, 1023, 7, 0);
  Serial.print("\nLuminosite (raw) : ");
  Serial.print(analogRead(PIN_PHOTORES));
  iLuminosite = (iLuminosite + 1) % NB_MESURES;
  luminosite = moyenneMesures(luminositeL, NB_MESURES);
}

int moyenneMesures(int mesures[], int nb)
{
  int S = 0;
  for(int i = 0; i < nb; i++)
  {
    S += mesures[i];
  }
  return S / nb;
}


