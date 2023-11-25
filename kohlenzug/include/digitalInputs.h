#ifndef DIGITALINPUTS_H
#define DIGITALINPUTS_H

#include <ezButton.h>

namespace DI
{
    extern ezButton buttonArray[];
    extern uint8_t ezBtnArrLen;

    // alias zugriff auf eingaenge in buttonArray
    enum IN {
        BR53_ENTK1      = 0,
        V200_ENTK1      = 1,
        BR41_ENTK1      = 2,
        LOKERK_START    = 3,
        LOKERK_BR53     = 4,
        LOKERK_V200     = 5,
        LOKERK_BR41     = 6,
        PRELLBOCK_W1    = 7,
        PRELLBOCK_W2    = 8,
        PRELLBOCK_W3    = 9,
        PRELLBOCK_W41   = 10,
        ENTK1_OBEN      = 11,
        ENTK41_OBEN     = 12,
        TASTER_AUTO     = 13,
        AUSFAHRT_FREI   = 14,
        LICHTSCHR_ENTK_41 = 15,
        TASTER_RESET    = 16
    };

    void setup();
    void loop();
    // void printInputs();

    // Zugriffsfunktionen fuer eingaenge
    inline int getInBr53Entk1(){return buttonArray[IN::BR53_ENTK1].getState() == LOW;};
    inline int getInV200Entk1(){return buttonArray[IN::V200_ENTK1].getState() == LOW;};
    inline int getInBr41Entk1(){return buttonArray[IN::BR41_ENTK1].getState() == LOW;};
    inline int getInLokErkStart(){return buttonArray[IN::LOKERK_START].getState() == LOW;};
    inline int getInLokErkBr53(){return buttonArray[IN::LOKERK_BR53].getState() == LOW;};
    inline int getInLokErkV200(){return buttonArray[IN::LOKERK_V200].getState() == LOW;};
    inline int getInLokErkBr41(){return buttonArray[IN::LOKERK_BR41].getState() == LOW;};
    inline int getInPrellbockW1(){return buttonArray[IN::PRELLBOCK_W1].getState() == LOW;};
    inline int getInPrellbockW2(){return buttonArray[IN::PRELLBOCK_W2].getState() == LOW;};
    inline int getInPrellbockW3(){return buttonArray[IN::PRELLBOCK_W3].getState() == LOW;};
    inline int getInPrellbockW41(){return buttonArray[IN::PRELLBOCK_W41].getState() == LOW;};
    inline int getInEntk1Oben(){return buttonArray[IN::ENTK1_OBEN].getState() == LOW;};
    inline int getInEntk41Oben(){return buttonArray[IN::ENTK41_OBEN].getState() == LOW;};

    // inline bool isAutoPressed(){return buttonArray[IN::TASTER_AUTO].isPressed();};
    // inline bool isAutoReleased(){return buttonArray[IN::TASTER_AUTO].isReleased();};
    inline bool isAutoEnabled(){return buttonArray[IN::TASTER_AUTO].getState() == LOW;};
    inline bool getInReset(){return buttonArray[IN::TASTER_RESET].getState() == LOW;};

    inline int getInAusfahrtFrei(){return buttonArray[IN::AUSFAHRT_FREI].getState() == LOW;};
    inline int getInLichtschrEntk41(){return buttonArray[IN::LICHTSCHR_ENTK_41].getState() == LOW;};
}
#endif