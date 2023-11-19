#ifndef DIGITALOUTPUTS_H
#define DIGITALOUTPUTS_H

#include <Arduino.h>

namespace DO
{
    const uint8_t PIN_BR53_ANWAHL       = 30;
    const uint8_t PIN_V200_ANWAHL       = 28;
    const uint8_t PIN_BR41_ANWAHL       = 26;
    const uint8_t PIN_STOP              = 24;
    const uint8_t PIN_RICHTUNG_RUECK    = 22;
    // 20 -> SDA mit i2c belegt
    const uint8_t PIN_BR53_RANGIERGESCHW = 18;
    const uint8_t PIN_ENTK1_HOCH        = 16;
    const uint8_t PIN_WEICHE1           = 14;
    const uint8_t PIN_WEICHE2           = 12;
    const uint8_t PIN_WEICHE3           = 10;
    const uint8_t PIN_ENTK41_HOCH       = 8;
    const uint8_t PIN_V200_RANGIERGESCHW = 6;
    const uint8_t PIN_LICHTSCHRANKE_AN  = 4;
    const uint8_t PIN_START             = 2;

    void setup();
    void loop();

    // Relais funktionen
    // Relais Modul: 
    //   5V -> Relais AUS
    //   0V -> Relais AN
    inline void setOutBr53Anwahl(uint8_t val){digitalWrite(PIN_BR53_ANWAHL, !val);};
    inline void setOutV200Anwahl(uint8_t val){digitalWrite(PIN_V200_ANWAHL, !val);};
    inline void setOutBr41Anwahl(uint8_t val){digitalWrite(PIN_BR41_ANWAHL, !val);};
    inline void setOutStop      (uint8_t val){digitalWrite(PIN_STOP, !val);};
    inline void setOutRichtungRueck(uint8_t val){digitalWrite(PIN_RICHTUNG_RUECK, !val);};
    inline void setOutBR53Rangiergeschw(uint8_t val){digitalWrite(PIN_BR53_RANGIERGESCHW, !val);};
    inline void setOutEntk1Hoch (uint8_t val){digitalWrite(PIN_ENTK1_HOCH, !val);};
    inline void setOutWeiche1   (uint8_t val){digitalWrite(PIN_WEICHE1, !val);};
    inline void setOutWeiche2   (uint8_t val){digitalWrite(PIN_WEICHE2, !val);};
    inline void setOutWeiche3   (uint8_t val){digitalWrite(PIN_WEICHE3, !val);};
    inline void setOutEntk41Hoch(uint8_t val){digitalWrite(PIN_ENTK41_HOCH, !val);};
    inline void setOutV200Rangiergeschw(uint8_t val){digitalWrite(PIN_V200_RANGIERGESCHW, !val);};
    inline void setOutLichtschrankeAn(uint8_t val){digitalWrite(PIN_LICHTSCHRANKE_AN, !val);};
    inline void setOutStart     (uint8_t val){digitalWrite(PIN_START, !val);};
}
#endif