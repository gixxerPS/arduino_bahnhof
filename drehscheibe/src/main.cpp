/**
 * @mainpage
 * Logik controller der drehscheiben steuerung fuer diethelm.
 * 
 * https://github.com/gixxerPS/arduino_bahnhof/tree/main/drehscheibe
 *
 * Unklahrheiten:
 * - test
 */
#include <Arduino.h>

#include "sequence.h"
#include "digitalInputs.h"
#include "digitalOutputs.h"

void setup(void)
{
  Serial.begin(9600);
  while (!Serial);

  Serial.println(F(">>>>>>>>>>>>>>>>>>>>>>> Drehscheibe V0.1.0 <<<<<<<<<<<<<<<<<<<"));

  Serial.print(F("  Kompilierzeitstempel: "));
  Serial.print(F(__DATE__));
  Serial.print(F(" "));
  Serial.println(F(__TIME__));

  DI::setup();
  //DO::setup();
}

void loop(void)
{
  static unsigned long msLastOutput = 0;
  unsigned long msNow = millis();

  DI::loop();
  SEQ::loop();

  if (msNow - msLastOutput > 100000) {
    msLastOutput = msNow;
    // Serial.print( F("getInEIN: ") );
    // Serial.print( DI::getInEIN() );
    // Serial.print( F(" | getInAUS: ") );
    // Serial.print( DI::getInAUS() );
    // Serial.print( F(" | getInAUS_BUEHNE: ") );
    // Serial.print( DI::getInAUSBUEHNE() );
    // Serial.print( F(" | geschw: ") );
    // Serial.print( digitalRead(PIN_GESCHW) );
    // Serial.println();
  }
}
