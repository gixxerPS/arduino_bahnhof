#ifndef DIGITALOUTPUTS_H
#define DIGITALOUTPUTS_H

#include <Arduino.h>
#include "PCF8575.h" // https://github.com/xreef/PCF8575_library

namespace DO
{
    // Torrelais
    extern PCF8575 pcf8575; // A0=0 | A1=0 | A2=0

    // Standrelais
    extern PCF8575 pcf8575_2; // A0=1 | A1=0 | A2=0

    // Relaismodul 1 (oben)
    const uint8_t PIN_RECHTS                    = 46;
    const uint8_t PIN_LINKS                     = 47; 
    const uint8_t PIN_START                     = 44;
    const uint8_t PIN_STOERUNG                  = 45;
    const uint8_t PIN_FAHRSTROM                 = 42;
    const uint8_t PIN_RESERVE_5                 = 43;
    const uint8_t PIN_RESERVE_6                 = 40;
    const uint8_t PIN_RESERVE_7                 = 41;

    void setup();
    void loop();
    void allOutsOff();

    // Zugriffsfunktionen fuer Relaisausgaenge
    // Relais Modul: 
    //   5V -> Relais AUS
    //   0V -> Relais AN
    inline void setOutRechts(uint8_t val) { digitalWrite(PIN_RECHTS, !val); }
    inline void setOutLinks(uint8_t val) { digitalWrite(PIN_LINKS, !val); }
    inline void setOutStart(uint8_t val) { digitalWrite(PIN_START, !val); }
    inline void setOutStoerung(uint8_t val) { digitalWrite(PIN_STOERUNG, !val); }
    inline void setOutFahrstrom(uint8_t val) { digitalWrite(PIN_FAHRSTROM, !val); }

    // 1..12 gleis num, 13=A, 14=B, 15=C
    inline void setOutZielTorRelais(uint8_t num, uint8_t val) { pcf8575.digitalWrite(num-1, !val); }

    // 1..12 gleis num, 13=A, 14=B, 15=C
    inline void setOutStandrelais(uint8_t num, uint8_t val) { pcf8575_2.digitalWrite(num-1, val); }


}
#endif