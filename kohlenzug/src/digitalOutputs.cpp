#include <Arduino.h>
#include "digitalOutputs.h"

namespace DO
{
    void setup()
    {
        pinMode(PIN_BR53_ANWAHL     , OUTPUT);
        digitalWrite(PIN_BR53_ANWAHL , HIGH); // Relais sofort ausschalten
        pinMode(PIN_V200_ANWAHL     , OUTPUT);
        digitalWrite(PIN_V200_ANWAHL , HIGH); // Relais sofort ausschalten
        pinMode(PIN_BR41_ANWAHL     , OUTPUT);
        digitalWrite(PIN_BR41_ANWAHL , HIGH); // Relais sofort ausschalten
        pinMode(PIN_STOP            , OUTPUT);
        digitalWrite(PIN_STOP , HIGH); // Relais sofort ausschalten
        pinMode(PIN_RICHTUNG_RUECK  , OUTPUT);
        digitalWrite(PIN_RICHTUNG_RUECK , HIGH); // Relais sofort ausschalten
        pinMode(PIN_BR53_RANGIERGESCHW, OUTPUT);
        digitalWrite(PIN_BR53_RANGIERGESCHW , HIGH); // Relais sofort ausschalten
        pinMode(PIN_ENTK1_HOCH        , OUTPUT);
        digitalWrite(PIN_ENTK1_HOCH , HIGH); // Relais sofort ausschalten
        pinMode(PIN_WEICHE1           , OUTPUT);
        digitalWrite(PIN_WEICHE1 , HIGH); // Relais sofort ausschalten
        pinMode(PIN_WEICHE2           , OUTPUT);
        digitalWrite(PIN_WEICHE2 , HIGH); // Relais sofort ausschalten
        pinMode(PIN_WEICHE3           , OUTPUT);
        digitalWrite(PIN_WEICHE3 , HIGH); // Relais sofort ausschalten
        pinMode(PIN_ENTK41_HOCH       , OUTPUT);
        digitalWrite(PIN_ENTK41_HOCH , HIGH); // Relais sofort ausschalten
        pinMode(PIN_V200_RANGIERGESCHW, OUTPUT);
        digitalWrite(PIN_V200_RANGIERGESCHW , HIGH); // Relais sofort ausschalten
        pinMode(PIN_LICHTSCHRANKE_AN  , OUTPUT);
        digitalWrite(PIN_LICHTSCHRANKE_AN , HIGH); // Relais sofort ausschalten
        pinMode(PIN_START             , OUTPUT);
        digitalWrite(PIN_START , HIGH); // Relais sofort ausschalten
    }

    void loop()
    {
    }

    void allOutsOff()
    {
        setOutV200Anwahl(LOW);
        setOutBr41Anwahl(LOW);
        setOutBr53Anwahl(LOW);
        setOutStop(LOW);
        setOutRichtungRueck(LOW);
        setOutBR53Rangiergeschw(LOW);
        setOutEntk1Hoch(LOW);
        setOutWeiche1(LOW);
        setOutWeiche2(LOW);
        setOutWeiche3(LOW);
        setOutEntk41Hoch(LOW);
        setOutV200Rangiergeschw(LOW);
        setOutLichtschrankeAn(LOW);
        setOutStart(LOW);  
    }
}