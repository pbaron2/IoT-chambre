#include "main.h"




void switchPressed1()
{
  Serial.println("\nINT 1");
  etatSwitch[MENU] = true;
}

void switchPressed2()
{
  Serial.println("\nINT 2");
  etatSwitch[PLUS] = true;
}

void switchPressed3()
{
  Serial.println("\nINT 3");
  etatSwitch[MOINS] = true;
}


