#include "digitalInputs.h"

namespace DI
{
    ezButton buttonArray[] = {
        ezButton(46), // BR53_ENTK1  
        ezButton(44), // V200_ENTK1  
        ezButton(42), // BR41_ENTK1  
        ezButton(40), // LOKERK_START
        ezButton(38), // LOKERK_BR53 
        ezButton(36), // LOKERK_V200 
        ezButton(34), // LOKERK_BR41 
        ezButton(32), // PRELLBOCK_W1

        ezButton(68), // PRELLBOCK_W2    
        ezButton(66), // PRELLBOCK_W3    
        ezButton(64), // PRELLBOCK_W41   
        ezButton(62), // ENTK1_OBEN      
        ezButton(60), // ENTK41_OBEN     
        ezButton(58), // TASTER_AUTO     
        ezButton(56), // AUSFAHRT_FREI   
        ezButton(54), // LICHTSCHR_ENTK_41

        ezButton(47), // Reserve
        ezButton(45), // Reserve
        ezButton(43), // Reserve
        ezButton(41), // Reserve
        ezButton(39), // Reserve
        ezButton(37), // Reserve
        ezButton(35), // Reserve
        ezButton(33), // Reserve

        ezButton(69), // Reserve
        ezButton(67), // Reserve
        ezButton(65), // Reserve
        ezButton(63), // Reserve
        ezButton(61), // Reserve
        ezButton(59), // Reserve
        ezButton(57), // Reserve
        ezButton(55) // Reserve

    };

    uint8_t ezBtnArrLen = sizeof(buttonArray) / sizeof(ezButton);

    void setup()
    {
        for (uint8_t i = 0; i < ezBtnArrLen; i++)
        {
            buttonArray[i].setDebounceTime(40); // [ms]
        }
    }

    void loop()
    {
        // eigene eingaenge entprellen und einlesen
        for (uint8_t i = 0; i < ezBtnArrLen; i++)
        {
            buttonArray[i].loop();
        }

        // TEST
        // for (uint8_t i = 0; i < ezBtnArrLen; i++)
        // {
        //     if (!buttonArray[i].getState()) { // debounced zustand ausgeben
        //         Serial.print(F("idx ["));
        //         Serial.print(i);
        //         Serial.print(F("] is high"));
        //         Serial.println();
        //     }

        //     if (buttonArray[i].isPressed()) { // flanke gedrueckt
        //         Serial.print(F("idx ["));
        //         Serial.print(i);
        //         Serial.print(F("] isPressed"));
        //         Serial.println();
        //     }

        //     if (buttonArray[i].isReleased()) { // flanke losgelassen
        //         Serial.print(F("idx ["));
        //         Serial.print(i);
        //         Serial.print(F("] isReleased"));
        //         Serial.println();
        //     }
        // }


    }

}