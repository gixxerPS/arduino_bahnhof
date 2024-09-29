#include "digitalInputs.h"

namespace DI
{
    ezButton buttonArray[] = {
        ezButton(30), // EIN                         
        ezButton(31), // AUS                         
        ezButton(99), // AUS_BUEHNE                  
        ezButton(29), // FUEHLER_EINGERASTET         
        ezButton(28), // FUEHLER_EINGEFAHREN         
        ezButton(27), // GLEISZENTRIERUNG_EINGEF     
        ezButton(25), // GLEISZENTRIERUNG_AUSGEF     
        ezButton(20), // KEIN_LANGZUG_START          
        ezButton(26), // EINF_GLEIS_BESETZT          
        ezButton(22), // EINF_BUEHNE_BESETZT         
        ezButton(24), // AUSF_GLEIS_BESETZT          
        ezButton(19), // ZENTR_GLEIS_EINGEF          
        ezButton(18), // ZENTR_GLEIS_AUSGEF          
        ezButton(17), // WIPPE_OBEN                  
        ezButton(16), // WIPPE_UNTEN                 
        ezButton(15), // AUFZUGGLEIS_FREI            
        ezButton(14), // AUFZUGGLEIS_OBEN            
        ezButton(13), // AUFZUGGLEIS_UNTEN           
        ezButton(12), // ANSCHLUSSGLEIS_BESETZT      
        ezButton(10), // ANSCHLUSSGLEIS_VERRIEGEL_AN 
        ezButton( 9), // ANSCHLUSSGLEIS_VERRIEGEL_AUS
        ezButton( 8), // ANSCHLUSSGLEIS_ENDSCH_EINGEF
        ezButton( 7) // ANSCHLUSSGLEIS_ENDSCH_AUSGEF
        

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