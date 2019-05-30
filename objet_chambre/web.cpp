#include "main.h"



/*
  void webpage()
  {
  DateTime now = rtc.now();
  String s = "Mesures de la chambre\n";
  s += "\tDate: " + String(now.day()) + "/" + String(now.month()) + "/" + String(now.year()) + "\n";
  s += "\tHeure: " + String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second()) + "\n";
  s += "\tTemperature: " + String(temperature) + "'C\n";
  s += "\tHumidite: " + String(humidite) + "%\n";

  server.send(200, "text/plain", s);
  }
*/


void mqttPost()
{
  Serial.println("SEND MQTT DATA :");
  if(dataValid)
  {
    Serial.println("{\"temperature\":" + String(float(temperature) / 10) + ",\"humidity\":" + String(humidite) + "}");
    client.publish(MQTT_TOPIC, ("{\"temperature\":" + String(float(temperature) / 10) + ",\"humidity\":" + String(humidite) + "}").c_str(), true);
  }
}


void reconnectMqtt()
{
  Serial.print("Attempting MQTT connection...");
  // Attempt to connect
  // If you do not want to use a username and password, change next line to
  //if (client.connect("ESP8266Client"))
  if (client.connect("ObjetChambre", MQTT_USER, MQTT_PASS))
  {
    Serial.println("connected");
  }
  else
  {
    Serial.print("failed, rc=");
    Serial.println(client.state());
  }
}

