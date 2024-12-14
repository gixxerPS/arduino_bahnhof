#ifndef DIGITALINPUTS_H
#define DIGITALINPUTS_H

#include <ezButton.h>

namespace DI
{
    extern ezButton buttonArray[];
    extern uint8_t ezBtnArrLen;

    extern ezButton buttonArrayEndsch[];
    extern ezButton buttonArrayAnwahl[];
    extern ezButton buttonArrayPosition[];
    extern ezButton buttonArrayBesetzt[];

    // alias zugriff auf eingaenge in buttonArray
    enum IN {
        RESET                        = 0, // taster f neustart / ruecksetzen
        DREHRICHTUNG                 = 1, // taster f drehrichtungsaenderung
        DREHFREIGABE                 = 2, // drehfreigabe v extern
        BUEHNE_BESETZT               = 3  // endschalter buehne besetzt
    };

    void setup();
    void loop();
    // void printInputs();

    // Zugriffsfunktionen fuer eingaenge
    inline bool getInRESET(){return buttonArray[IN::RESET].getState() == LOW;};
    inline bool getInDREHRICHTUNG(){return buttonArray[IN::DREHRICHTUNG].getState() == LOW;};
    inline bool getInDREHRICHTUNGpressed(){return buttonArray[IN::DREHRICHTUNG].isPressed();};
    inline bool getInDREHFREIGABE() { return buttonArray[IN::DREHFREIGABE].getState() == LOW; }
    inline bool getInBUEHNE_BESETZT() { return buttonArray[IN::BUEHNE_BESETZT].getState() == LOW; }
   
    /**
     * @param num - 1..12 gleis num, 13=A, 14=B, 15=C */ 
    inline bool getInGLEIS_ENDSCHALTER(uint8_t num) { return buttonArrayEndsch[num].getState() == LOW; }
   
    /**
     * @param num - 1..12 gleis num, 13=A, 14=B, 15=C */ 
    inline bool getInGLEIS_ANWAHL(uint8_t num) { return buttonArrayAnwahl[num].getState() == LOW; }

    /**
     * @param num - 1..12 gleis num, 13=A, 14=B, 15=C */ 
    inline bool getInGLEIS_POSITION(uint8_t num) { return buttonArrayPosition[num].getState() == LOW; }

    /**
     * @param num - 1..12 gleis num, 13=A, 14=B, 15=C */ 
    inline bool getInGLEIS_BESETZT(uint8_t num) { return buttonArrayBesetzt[num].getState() == LOW; }

}
#endif