
#include <Arduino.h>

#include "display.h"


void setup(void)
{
  Serial.begin(9600);
  while (!Serial);
  Serial.println(F("Start"));

  MYDISPLAY::setup();
}
void loop(void)
{
  MYDISPLAY::loop();
  delay(1000);
}
