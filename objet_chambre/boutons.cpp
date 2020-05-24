#include "main.h"




void ICACHE_RAM_ATTR switchPressed1()
{
  Serial.println("\nINT 1");
  etatSwitch[MOINS] = true;
}

void ICACHE_RAM_ATTR switchPressed2()
{
  Serial.println("\nINT 2");
  etatSwitch[MENU] = true;
}

void ICACHE_RAM_ATTR switchPressed3()
{
  Serial.println("\nINT 3");
  etatSwitch[PLUS] = true;
}
