#ifndef DIGITALOUTPUTS_H
#define DIGITALOUTPUTS_H

#include <Arduino.h>
#include "PCF8575.h" // https://github.com/xreef/PCF8575_library

namespace DO
{
    // Ziel- / Tor- Relais
    extern PCF8575 pcf8575; // A0=0 | A1=0 | A2=0

    // LED f Anwahl
    extern PCF8575 pcf8575_2; // A0=1 | A1=0 | A2=0

    // Relaismodul 1 (oben)
    const uint8_t PIN_RECHTS                    = 46;
    const uint8_t PIN_LINKS                     = 47; 
    const uint8_t PIN_RESERVE_2                 = 44;
    const uint8_t PIN_RESERVE_3                 = 45;
    const uint8_t PIN_RESERVE_4                 = 42;
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

    inline void setOutZielTorRelais(uint8_t num, uint8_t val) { pcf8575.digitalWrite(num, !val); }
    inline void setOutLedAnwahl(uint8_t num, uint8_t val) { pcf8575_2.digitalWrite(num, val); }
}
#endif