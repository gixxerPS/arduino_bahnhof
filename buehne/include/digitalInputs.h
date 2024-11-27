#ifndef DIGITALINPUTS_H
#define DIGITALINPUTS_H

#include <ezButton.h>

namespace DI
{
    extern ezButton buttonArray[];
    extern uint8_t ezBtnArrLen;

    // alias zugriff auf eingaenge in buttonArray
    enum IN {
        EIN                          = 0,
        AUS                          = 1,
        AUS_BUEHNE                   = 2,
        FUEHLER_EINGERASTET          = 3,
        FUEHLER_EINGEFAHREN          = 4,
        GLEISZENTRIERUNG_EINGEF      = 5, // Einfahrtsgleis
        GLEISZENTRIERUNG_AUSGEF      = 6, // Einfahrtsgleis
        KEIN_LANGZUG_START           = 7,
        EINF_GLEIS_BESETZT           = 8,
        EINF_BUEHNE_BESETZT          = 9,
        AUSF_GLEIS_BESETZT           = 10,
        ZENTR_GLEIS_EINGEF           = 11, // Ausfahrtsgleis
        ZENTR_GLEIS_AUSGEF           = 12, // Ausfahrtsgleis
        WIPPE_OBEN                   = 13,
        WIPPE_UNTEN                  = 14,
        AUFZUGGLEIS_BESETZT          = 15,
        AUFZUGGLEIS_OBEN             = 16,
        AUFZUGGLEIS_UNTEN            = 17,
        ANSCHLUSSGLEIS_BESETZT       = 18,
        ANSCHLUSSGLEIS_VERRIEGEL_AN  = 19,
        ANSCHLUSSGLEIS_VERRIEGEL_AUS = 20,
        ANSCHLUSSGLEIS_ENDSCH_EINGEF = 21,
        ANSCHLUSSGLEIS_ENDSCH_AUSGEF = 22
        
    };

    void setup();
    void loop();
    // void printInputs();

    // Zugriffsfunktionen fuer eingaenge
    inline bool getInStartEINFAHRT(){return buttonArray[IN::EIN].getState() == LOW;};
    inline bool getInStartAUSFAHRT(){return buttonArray[IN::AUS].getState() == LOW;};
    inline bool getInStartAUSFAHRTBUEHNE() { return buttonArray[IN::AUS_BUEHNE].getState() == LOW; }
    inline bool getInFUEHLEREINGERASTET() { return buttonArray[IN::FUEHLER_EINGERASTET].getState() == LOW; }
    inline bool getInFUEHLEREINGEFAHREN() { return buttonArray[IN::FUEHLER_EINGEFAHREN].getState() == LOW; }
    inline bool getInGLEISZENTRIERUNGEINGEF() { return buttonArray[IN::GLEISZENTRIERUNG_EINGEF].getState() == LOW; }
    inline bool getInGLEISZENTRIERUNGAUSGEF() { return buttonArray[IN::GLEISZENTRIERUNG_AUSGEF].getState() == LOW; }
    inline bool getInKEINLANGZUGSTART() { return buttonArray[IN::KEIN_LANGZUG_START].getState() == LOW; }
    inline bool getInEINFGLEISBESETZT() { return buttonArray[IN::EINF_GLEIS_BESETZT].getState() == LOW; }
    inline bool getInEINFBUEHNEBESETZT() { return buttonArray[IN::EINF_BUEHNE_BESETZT].getState() == LOW; }
    inline bool getInAUSFGLEISBESETZT() { return buttonArray[IN::AUSF_GLEIS_BESETZT].getState() == LOW; }
    inline bool getInZENTRGLEISEINGEF() { return buttonArray[IN::ZENTR_GLEIS_EINGEF].getState() == LOW; }
    inline bool getInZENTRGLEISAUSGEF() { return buttonArray[IN::ZENTR_GLEIS_AUSGEF].getState() == LOW; }
    inline bool getInWIPPEOBEN() { return buttonArray[IN::WIPPE_OBEN].getState() == LOW; }
    inline bool getInWIPPEUNTEN() { return buttonArray[IN::WIPPE_UNTEN].getState() == LOW; }
    inline bool getInAUFZUGGLEISBESETZT() { return buttonArray[IN::AUFZUGGLEIS_BESETZT].getState() == LOW; }
    inline bool getInAUFZUGGLEISOBEN() { return buttonArray[IN::AUFZUGGLEIS_OBEN].getState() == LOW; }
    inline bool getInAUFZUGGLEISUNTEN() { return buttonArray[IN::AUFZUGGLEIS_UNTEN].getState() == LOW; }
    // inline bool getInANSCHLUSSGLEISBESETZT() { return buttonArray[IN::ANSCHLUSSGLEIS_BESETZT].getState() == LOW; }
    inline bool getInAUFZUGGLEISVERRIEGELAN() { return buttonArray[IN::ANSCHLUSSGLEIS_VERRIEGEL_AN].getState() == LOW; }
    inline bool getInAUFZUGGLEISVERRIEGELAUS() { return buttonArray[IN::ANSCHLUSSGLEIS_VERRIEGEL_AUS].getState() == LOW; }
    inline bool getInAUFZUGGLEISENDSCHEINGEF() { return buttonArray[IN::ANSCHLUSSGLEIS_ENDSCH_EINGEF].getState() == LOW; }
    inline bool getInAUFZUGGLEISENDSCHAUSGEF() { return buttonArray[IN::ANSCHLUSSGLEIS_ENDSCH_AUSGEF].getState() == LOW; }

}
#endif