#include "sequence.h"
#include "digitalInputs.h"
#include "digitalOutputs.h"

namespace SEQ
{
    uint16_t step;
    uint16_t stepOld;
    uint16_t lastStep;
    long unsigned int stepStartMillis;
    bool stepChange;

    void loop()
    {
        static unsigned long msLastOutput = 0;
        unsigned long msNow = millis();

        switch (step) {
            case 0: // init, warten auf freigabe
                if (stepOld > 0) {
                    DO::allOutsOff();
                }
                if (DI::getInEINFBUEHNEBESETZT() 
                && DI::getInWIPPEOBEN()
                && DI::getInAUFZUGGLEISFREI() 
                && DI::getInEIN()
                && lastStep < 10) {
                    step = 10;     

                }
            break;

//=============================================================================
// Start Ausfahrt Buehne
//=============================================================================
            case 10: // Zentrierung Ausfahrt ausfahren
                DO::setOutAusfGleiszentrAus(HIGH);
                if (millis() - stepStartMillis > T_IMPULS_ZENTRIERUNG) {
                    DO::setOutAusfGleiszentrAus(LOW);
                    step = 20;
                }
            break;

            case 20: // Ausfahrtgleis an Buehne schalten
                DO::setOutZugAufAusStart(HIGH);
                step = 30;
            break;        

            case 30: // Auf Endschalter warten
                if ( DI::getInAUSFGLEISBESETZT()) { // TODO: richtiger eingang???
                    step = 40;
                }
            break;       

            case 40: // Impuls Endschalter Aufzuggleis einfahren
                DO::setOutEndschAufzugglEinf(HIGH);
                if (millis() - stepStartMillis > T_IMPULS_ENDSCHALTER) {
                    DO::setOutEndschAufzugglEinf(LOW);
                    step = 50;
                }
            break;

            case 50: // Start Aufzuggleismotor nach oben slow
                DO::setOutAufzugStartSlow(HIGH);
                if (millis() - stepStartMillis > 1000) { // TODO: kleine verzoegerung noetig bevor fast eingeschaltet wird?
                    step = 60;
                }
            break;

            case 60: // Start Aufzuggleismotor nach oben fast
                DO::setOutAufzugStartFast(HIGH);
                if (millis() - stepStartMillis > T_IMPULS_AUFZUGFAST) { // TODO: kleine verzoegerung noetig bevor fast eingeschaltet wird?
                    DO::setOutAufzugStartFast(LOW);
                    step = 70;
                }
            break;

            case 70: // Warte Aufzuggleis oben
                if ( DI::getInAUFZUGGLEISOBEN() ) {
                    DO::setOutAufzugStartFast(LOW);
                    step = 0; // FERTIG 
                }
            break;
//=============================================================================
// Start Ausfahrt
//=============================================================================
            case 1000: // Warte auf Start
                if ( DI::getInKEINLANGZUGSTART() ) {
                    DO::setOutAufzugglAnschalten(HIGH);
                    step = 1010;
                }
            break;
            case 1010: // Warte auf Aufzuggleis frei
                if ( DI::getInAUFZUGGLEISFREI() ) {
                    DO::setOutAufzugglAnschalten(LOW);
                    DO::setOutAufzugNachUnten(HIGH);
                    DO::setOutAufzugStartFast(HIGH);
                    step = 1020; 
                }
            break;
            case 1020: // Warte auf Aufzuggleis unten
                if (millis() - stepStartMillis > T_IMPULS_AUFZUGFAST) {
                    DO::setOutAufzugStartFast(LOW);
                }
                if ( DI::getInAUFZUGGLEISUNTEN() ) {
                    DO::setOutAufzugStartFast(LOW);
                    DO::setOutAufzugNachUnten(LOW);
                    step = 1030; 
                }
            break;
            case 1030: // Impuls Gleisverriegelung
                DO::setOutAufzugglVerriegelAn(HIGH);
                if (millis() - stepStartMillis > T_IMPULS_GLEISVERRIEGELUNG) {
                    DO::setOutAufzugglVerriegelAn(LOW);
                    step = 1040;
                }
            break;
            case 1040: // Endschalter Aufzuggleis ausfahren
                DO::setOutEndschAufzugglEinf(HIGH);
                if (DI::getInANSCHLUSSGLEISENDSCHAUSGEF()) {
                    DO::setOutEndschAufzugglEinf(LOW);
                    step = 0;
                }
            break;
//=============================================================================
// Start Einfahrt
//=============================================================================
            case 2000: // Warte auf Start
                if ( DI::getInEINFGLEISBESETZT() 
                && !DI::getInEINFBUEHNEBESETZT()
                
                && DI::getInEIN() ) {
                    DO::setOutEinfGleiszentrAus(HIGH);
                    step = 0; // FERTIG 
                }
            break;

            case 2010: // Zentrierung Einfahrtsgleis ausfahren
                DO::setOutAusfGleiszentrAus(HIGH);
                if (millis() - stepStartMillis > T_IMPULS_ZENTRIERUNG) {
                    DO::setOutAusfGleiszentrAus(LOW);
                    step = 2020;
                }
            break;

            case 2020: // warten auf wippe unten
                if ( DI::getInWIPPEUNTEN() ) {
                    
                    DO::setOutZugAufBuehneStart(HIGH);

                    // setGeschwWert(SPEED_MIN) // = 15 = 3,5 V
                    DO::setOutGeschwBit0(HIGH);
                    DO::setOutGeschwBit1(HIGH);
                    DO::setOutGeschwBit2(HIGH);
                    DO::setOutGeschwBit3(HIGH);
                    step = 2030;
                }
            break;

            case 2030: // warten auf endschalter

                // HIER GESCHWINDIGKEIT STEUERN UND UEBERWACHEN


                if ( DI::getInWIPPEUNTEN() ) {
                    DO::setOutZugAufBuehneStart(LOW);
                    step = 2040;
                }
            break;

            case 2040: // Zentrierung Einfahrtsgleis einfahren
                DO::setOutEinfGleiszentrEin(HIGH);
                if (millis() - stepStartMillis > T_IMPULS_ZENTRIERUNG) {
                    DO::setOutEinfGleiszentrEin(LOW);
                    step = 2050;
                }
            break;

            case 2050: // warten auf wippe oben
                if ( DI::getInWIPPEOBEN() ) {
                    DO::setOutAusfGleiszentrAus(HIGH); // TODO: laut text Gleiszentrierung Ausfahrt einfahren. impuls 2s notwendig?
                    step = 2060;
                }
            break;

            case 2060: // Impulsdauer Gleiszentrierung Ausfahrt
                DO::setOutAusfGleiszentrAus(HIGH);
                if (millis() - stepStartMillis > T_IMPULS_ZENTRIERUNG) {
                    DO::setOutAusfGleiszentrAus(LOW);
                    step = 2070;
                }
            break;

            case 2070: // Buehnenfuehler ausfahren
                if (!DI::getInEINFGLEISBESETZT() && !DI::getInAUSFGLEISBESETZT()) {
                    DO::setOutFuehlerAus(HIGH);
                    step = 2080;
                }
            break;

            case 2080: // Start Buehnenmotor
                if (DI::getInFUEHLEREINGEFAHREN()) {
                    DO::setOutFuehlerAus(LOW);
                    DO::setOutMotorSlow(HIGH);
                    DO::setOutMotorFast(HIGH);
                    step = 2090;
                }
            break;

            case 2090: // Impulsdauer Buehne Fast und warten auf fuehler
                // @TODO: impuls richtig? wann sonst fast wieder aus
                if (millis() - stepStartMillis > T_IMPULS_BUEHNEFAST) {
                    DO::setOutMotorFast(LOW);
                }

                if ( DI::getInFUEHLEREINGERASTET() ) {
                    DO::setOutMotorSlow(LOW);
                    step = 2100;
                }
            break;

            case 2100: // Impulsdauer Umschalten rechts/links
                DO::setOutRichtungAendern(HIGH);
                if (millis() - stepStartMillis > T_IMPULS_UMSCH_RECHTSLINKS) {
                    DO::setOutRichtungAendern(LOW);
                    step = 0; // FERTIG
                }
            break;

            default: // should not happen
                break;
        }
        if (step != stepOld) { // neuer schritt aktiv geworden ?
            stepStartMillis = millis(); // zeitpunkt merken
            // if (step > 0 && step != lastStep) { // neuer schritt ungleich init ?
            //     lastStep = step;
            // }
        }
        stepChange = step != stepOld;
        stepOld = step;
        if (msNow - msLastOutput > T_SERIAL_AUSGABE) {
            msLastOutput = msNow;

            Serial.print(F("Schritt aktuell: "));
            Serial.print(step);
            Serial.print(F(" | letzer: "));
            Serial.print(lastStep);
        }
    }

}