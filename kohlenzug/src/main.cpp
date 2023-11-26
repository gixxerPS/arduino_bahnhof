/**
 * @mainpage
 * Logik controller der kohlenzug steuerung fuer diethelm.
 *
 * - 1,3" OLED Display
 * - 4x 8er Relaismodule -> 32 DO
 * - 4x 8er Eingaenge direkt / Pulldown -> 32 DI
 *
 * 8-fach Relais-Module
 * ====================
 * INx = false => relais AN
 * INx = true  => relais AUS
 * JD-VCC, GND = Last 5V versorgung fuer relais => 2. netzteil
 * VCC, GND = Steuerspannung
 */
#include <Arduino.h>

#include "display.h"
#include "sequence.h"
#include "digitalInputs.h"
#include "digitalOutputs.h"

void setup(void)
{
  Serial.begin(9600);
  while (!Serial);

  Serial.println(F(">>>>>>>>>>>>>>>>>>>>>>> Kohlenzug V0.2.0 <<<<<<<<<<<<<<<<<<<"));

  Serial.print(F("  Kompilierzeitstempel: "));
  Serial.print(F(__DATE__));
  Serial.print(F(" "));
  Serial.println(F(__TIME__));

  MYDISPLAY::setup();
  DI::setup();
  DO::setup();
}

void testDO(void) 
{
  const unsigned long del = 500;

  Serial.println(F("setOutBr53Anwahl"));
  DO::setOutBr53Anwahl(HIGH);
  delay(del);
  DO::setOutBr53Anwahl(LOW);

Serial.println(F("setOutV200Anwahl"));
  DO::setOutV200Anwahl(HIGH);
  delay(del);
  DO::setOutV200Anwahl(LOW);

Serial.println(F("setOutBr41Anwahl"));
  DO::setOutBr41Anwahl(HIGH);
  delay(del);
  DO::setOutBr41Anwahl(LOW);

Serial.println(F("setOutStop"));
  DO::setOutStop(HIGH);
  delay(del);
  DO::setOutStop(LOW);

Serial.println(F("setOutRichtungRueck"));
  DO::setOutRichtungRueck(HIGH);
  delay(del);
  DO::setOutRichtungRueck(LOW);

Serial.println(F("setOutBR53Rangiergeschw"));
  DO::setOutBR53Rangiergeschw(HIGH);
  delay(del);
  DO::setOutBR53Rangiergeschw(LOW);

Serial.println(F("setOutEntk1Hoch"));
  DO::setOutEntk1Hoch(HIGH);
  delay(del);
  DO::setOutEntk1Hoch(LOW);

Serial.println(F("setOutWeiche1"));
  DO::setOutWeiche1(HIGH);
  delay(del);
  DO::setOutWeiche1(LOW);

Serial.println(F("setOutWeiche2"));
  DO::setOutWeiche2(HIGH);
  delay(del);
  DO::setOutWeiche2(LOW);

Serial.println(F("setOutWeiche3"));
  DO::setOutWeiche3(HIGH);
  delay(del);
  DO::setOutWeiche3(LOW);

Serial.println(F("setOutEntk41Hoch"));
  DO::setOutEntk41Hoch(HIGH);
  delay(del);
  DO::setOutEntk41Hoch(LOW);

Serial.println(F("setOutV200Rangiergeschw"));
  DO::setOutV200Rangiergeschw(HIGH);
  delay(del);
  DO::setOutV200Rangiergeschw(LOW);

Serial.println(F("setOutLichtschrankeAn"));
  DO::setOutLichtschrankeAn(HIGH);
  delay(del);
  DO::setOutLichtschrankeAn(LOW);

Serial.println(F("setOutStart"));
  DO::setOutStart(HIGH);
  delay(del);
  DO::setOutStart(LOW);


}

void loop(void)
{
  
  DI::loop();
  SEQ::loop();

  MYDISPLAY::loop();
}
