/**
 * @mainpage
 * Logik controller der buehnen steuerung fuer diethelm.
 * 
 * https://github.com/gixxerPS/arduino_bahnhof/tree/main/buehne
 *
 * - 3x 8er Relaismodule -> 24 DO
 * - 4x 8er Eingaenge direkt / Pulldown -> 32 DI
 *
 * 8-fach Relais-Module
 * ====================
 * INx = false => relais AN
 * INx = true  => relais AUS
 * JD-VCC, GND = Last 5V versorgung fuer relais => 2. netzteil
 * VCC, GND = Steuerspannung
 * 
 * Unklahrheiten:
 * - 
 */
#include <Arduino.h>

#include "sequence.h"
#include "digitalInputs.h"
#include "digitalOutputs.h"

const uint8_t PIN_GESCHW = 21; // INT0


volatile bool flagGeschw = false;
volatile bool flagImpulsVerpasst = false;
volatile unsigned long msPulsGeschwJetzt = 0;
volatile unsigned long msPulsGeschwVorher = 0;

void speedMessungInterrupt() {
  unsigned long msNow = millis();
  if (msNow - msPulsGeschwJetzt > 100) { // alles kleiner 100ms ignorieren (debounce)
    if (!flagGeschw) { // wird nach auswertung wieder zurueckgesetzt
        msPulsGeschwVorher = msPulsGeschwJetzt;
        msPulsGeschwJetzt = msNow;
        flagGeschw = true; 
    } else { // auswertung dauerte laenger als der naechste impuls reinkam
      flagImpulsVerpasst = true; 
    }
  }
}

void setup(void)
{
  Serial.begin(9600);
  while (!Serial);

  Serial.println(F(">>>>>>>>>>>>>>>>>>>>>>> Buehnensteuerung V0.1.0 <<<<<<<<<<<<<<<<<<<"));

  Serial.print(F("  Kompilierzeitstempel: "));
  Serial.print(F(__DATE__));
  Serial.print(F(" "));
  Serial.println(F(__TIME__));

  DI::setup();

  pinMode(PIN_GESCHW, INPUT_PULLUP); 
  attachInterrupt(digitalPinToInterrupt(PIN_GESCHW), speedMessungInterrupt, RISING); // 21=INT0
  //DO::setup();
}

void testDO(void) 
{
  const unsigned long del = 500;

  Serial.println(F("setOutEinfGleiszentrAus"));
  DO::setOutEinfGleiszentrAus(HIGH);
  delay(del);
  DO::setOutEinfGleiszentrAus(LOW);


}

void loop(void)
{
  static unsigned long msLastOutput = 0;
  unsigned long msNow = millis();

  DI::loop();
  SEQ::loop();

  if (flagGeschw) {
    flagGeschw = false;
    if (msPulsGeschwVorher > 0 && msPulsGeschwJetzt > 0) {
      Serial.print(F("deltaT = "));
      unsigned long deltaT = (msPulsGeschwJetzt-msPulsGeschwVorher);
      Serial.print(deltaT);
      Serial.println(F(" ms"));
    }
  }

  if (flagImpulsVerpasst) {
    flagImpulsVerpasst = false;
    Serial.println(F("Geschwindigkeitsimpuls verpasst :("));
  }

  if (msNow - msLastOutput > 100000) {
    msLastOutput = msNow;
    Serial.print( F("getInEIN: ") );
    Serial.print( DI::getInEIN() );
    Serial.print( F(" | getInAUS: ") );
    Serial.print( DI::getInAUS() );
    Serial.print( F(" | getInAUS_BUEHNE: ") );
    Serial.print( DI::getInAUSBUEHNE() );
    Serial.print( F(" | geschw: ") );
    Serial.print( digitalRead(PIN_GESCHW) );
    Serial.println();
  }
}
