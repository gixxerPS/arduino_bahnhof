#include <Arduino.h>
#include "digitalOutputs.h"

namespace DO
{
    PCF8575 pcf8575  (0x20); // A0=0 | A1=0 | A2=0
    PCF8575 pcf8575_2(0x21); // A0=1 | A1=0 | A2=0
    
    void setup()
    {
        for (int i = 0; i < 16; i++)
        {
            pcf8575.pinMode(i, OUTPUT);
            pcf8575_2.pinMode(i, OUTPUT);
        }
        pcf8575.begin(); // begin nur einmal aufrufen sonst friert arduino ein
        for (int i = 0; i < 16; i++)
        {
            pcf8575.digitalWrite  (i, HIGH); // default is low aber low heisst relais an!
            pcf8575_2.digitalWrite(i, HIGH);
        }
        pinMode(PIN_RECHTS, OUTPUT);
        digitalWrite(PIN_RECHTS, HIGH); // Relais sofort ausschalten

        pinMode(PIN_LINKS, OUTPUT);
        digitalWrite(PIN_LINKS, HIGH); // Relais sofort ausschalten

        pinMode(PIN_START, OUTPUT);
        digitalWrite(PIN_START, HIGH); // Relais sofort ausschalten

        pinMode(PIN_STOERUNG, OUTPUT);
        digitalWrite(PIN_STOERUNG, HIGH); // Relais sofort ausschalten

        pinMode(PIN_FAHRSTROM, OUTPUT);
        digitalWrite(PIN_FAHRSTROM, HIGH); // Relais sofort ausschalten
    }

    void loop()
    {
    }

    void allOutsOff()
    {
        setOutRechts(LOW);      
        setOutLinks(LOW);      
        setOutStart(LOW); 
        setOutStoerung(LOW); 
        setOutFahrstrom(LOW); 

        for (int i = 0; i < 16; i++)
        {
            pcf8575.digitalWrite  (i, HIGH); // default is low aber low heisst relais an!
            pcf8575_2.digitalWrite(i, HIGH);
        }
    }
}