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
      
      const size_t capacity = 2*JSON_ARRAY_SIZE(1) + JSON_ARRAY_SIZE(6) + 9*JSON_OBJECT_SIZE(2) + 24*JSON_OBJECT_SIZE(3) + 6*JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(6) + JSON_OBJECT_SIZE(9) + JSON_OBJECT_SIZE(15) + 2*JSON_OBJECT_SIZE(21) + 2910;
      DynamicJsonDocument root(capacity);
    
      DeserializationError error = deserializeJson(root, payload);
      
      if (!error)
      {
        Serial.println("JSON parse");
        JsonObject DailyForecasts_0 = root["DailyForecasts"][0];
        meteo.tempMin = float(DailyForecasts_0["Temperature"]["Minimum"]["Value"]) * 10;
        meteo.tempMax = float(DailyForecasts_0["Temperature"]["Maximum"]["Value"]) * 10;
        meteo.vent = int(DailyForecasts_0["Day"]["Wind"]["Speed"]["Value"]);
        meteo.pluie = int(DailyForecasts_0["Day"]["TotalLiquid"]["Value"]);
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
  lumiRaw = analogRead(PIN_PHOTORES);
  luminositeL[iLuminosite] = map(lumiRaw, 0, 1023, 7, 0);
  Serial.print("\nLuminosite (raw) : ");
  Serial.print(lumiRaw);
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
