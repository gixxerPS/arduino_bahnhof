#include "digitalInputs.h"
#include "appConstants.h"

namespace DI
{
    ezButton buttonArray[] = {
        ezButton(30), // RESET                         
        ezButton(31), // DREHRICHTUNG                         
        ezButton(29)  // DREHFREIGABE                  
        
        

    };
    uint8_t ezBtnArrLen = sizeof(buttonArray) / sizeof(ezButton);


    ezButton buttonArrayEndsch[ANZ_GLEISE+1] = {
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30), // A
        ezButton(30), // B
        ezButton(30)  // C
    };
    ezButton buttonArrayAnwahl[ANZ_GLEISE+1] = {
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30), // A
        ezButton(30), // B
        ezButton(30)  // C
    };
    ezButton buttonArrayPosition[ANZ_GLEISE+1] = {
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30), // A
        ezButton(30), // B
        ezButton(30)  // C
    };
    ezButton buttonArrayBesetzt[ANZ_GLEISE+1] = {
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30),                         
        ezButton(30),
        ezButton(30), // A
        ezButton(30), // B
        ezButton(30)  // C
    };
    void setup()
    {
        for (uint8_t i = 0; i < ezBtnArrLen; i++)
        {
            buttonArray[i].setDebounceTime(40); // [ms]
        }
        for (uint8_t i = 0; i <= ANZ_GLEISE; i++)
        {
            buttonArrayEndsch[i].setDebounceTime(40); // [ms]
            buttonArrayAnwahl[i].setDebounceTime(40); // [ms]
            buttonArrayPosition[i].setDebounceTime(40); // [ms]
            buttonArrayBesetzt[i].setDebounceTime(40); // [ms]
        }
    }

    void loop()
    {
        // eigene eingaenge entprellen und einlesen
        for (uint8_t i = 0; i < ezBtnArrLen; i++)
        {
            buttonArray[i].loop();
        }
        for (uint8_t i = 0; i <= ANZ_GLEISE; i++)
        {
            buttonArrayEndsch[i].loop();
            buttonArrayAnwahl[i].loop(); 
            buttonArrayPosition[i].loop(); 
            buttonArrayBesetzt[i].loop(); 
        }
    }
}