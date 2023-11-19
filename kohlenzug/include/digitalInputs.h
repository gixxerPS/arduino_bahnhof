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
        LICHTSCHR_ENTK_41 = 15
    };

    void setup();
    void loop();
    // void printInputs();
}
#endif