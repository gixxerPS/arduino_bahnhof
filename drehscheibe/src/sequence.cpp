#include "sequence.h"
#include "digitalInputs.h"
#include "digitalOutputs.h"
#include "appConstants.h"

namespace SEQ
{
    uint16_t step;
    uint16_t stepOld;
    uint16_t lastStep;
    long unsigned int stepStartMillis;
    bool stepChange;

    int8_t zielGleis;
    int8_t aktGleisPos; // aktuelle position
    RICHTUNG richtung; // 0=aus, 1=links, 2=rechts

    void loop()
    {
        // aktuelle position ermitteln
        for (uint8_t i = 1; i <= ANZ_GLEISE; i++) { // 1..12 gleis num, 13=A, 14=B, 15=C
            if (DI::getInGLEIS_POSITION(i)) {
                aktGleisPos = i;
            }
        }
        static unsigned long msLastOutput = 0;
        unsigned long msNow = millis();

        if (DI::getInRESET()) {
            step = 0;
        }

        switch (step) {
            case 0: // init, warten auf start
                if (stepOld > 0) {
                    DO::allOutsOff();
                    zielGleis = 0;
                    richtung = RICHTUNG::KEINE;
                }

                // pruefe anwahl
                for (uint8_t i = 1; i <= ANZ_GLEISE; i++) { // 1..12 gleis num, 13=A, 14=B, 15=C
                    if (DI::getInGLEIS_ANWAHL(i)) { // anwahltaste gedrueckt ?
                        if (zielGleis == 0) { 
                            if (DI::getInGLEIS_BESETZT(i)) {
                                step = 999;
                            } else { // gleis noch nicht besetzt
                                zielGleis = i;
                                DO::setOutStandrelais(i, HIGH); // und anzeigen
                                if (zielGleis >= ERSTES_STANDGLEIS && zielGleis <= LETZTES_STANDGLEIS) {
                                    step = 100;
                                } else if (zielGleis >= ERSTES_EINFAHRTSGLEIS && zielGleis <= LETZTES_EINFAHRTSGLEIS) {
                                    step = 200;
                                } else if (zielGleis >= ERSTES_AUSFAHRTSGLEIS && zielGleis <= LETZTES_AUSFAHRTSGLEIS) {
                                    step = 300;
                                }
                            }
                        } 
                    }
                }
            break;

//=============================================================================
// Drehen auf Standgleis
//=============================================================================
            case 100: // besetzt pruefen
                if (DI::getInBUEHNE_BESETZT() ) {
                    step = 999;
                } else if (DI::getInGLEIS_BESETZT(zielGleis)) {
                    step = 999;
                } else { // frei, ok weiter
                    step = 110;
                }
            break;
            case 110: // standrelais an, drehrichtung ermitteln
                DO::setOutStandrelais(zielGleis, HIGH);
                if (aktGleisPos == 0) {
                    richtung = RICHTUNG::LINKS; // default = links
                    step = 120;
                } else if (aktGleisPos - zielGleis > 0) {
                    richtung = RICHTUNG::LINKS;
                    step = 120;
                } else if (aktGleisPos - zielGleis < 0) {
                    richtung = RICHTUNG::RECHTS;
                    step = 120;
                } else { // aktGleisPos - zielGleis = 0, also ziel = istposition: error
                    step = 999;
                }
            break;
            case 120: // manuelle drehrichtungsaenderung moeglich
                DO::setOutStandrelais(zielGleis, HIGH);
                if (DI::getInDREHRICHTUNGpressed()) {
                    if (richtung == RICHTUNG::RECHTS) {
                        richtung = RICHTUNG::LINKS;
                    } else {
                        richtung = RICHTUNG::RECHTS;
                    }
                }
                if (millis() - stepStartMillis > T_VERZ_START_F_DREHR) {
                    step = 130;
                }
            break;
            case 130: // drehen
                // TODO: continue here
            break;
//=============================================================================
// Drehen auf Einfahrtsgleis
//=============================================================================
            case 200: // standrelais an
                DO::setOutStandrelais(zielGleis, HIGH);
                if (millis() - stepStartMillis > 1000) {
                    step = 210;
                }
            break;
            case 210: // drehen bis ziel

                // A oder B -> rechts nach lr-matrix
                DO::setOutLinks(LOW);
                DO::setOutRechts(HIGH);
                DO::setOutStart(HIGH);
                if (aktGleisPos == zielGleis) {
                    DO::setOutRechts(LOW);
                    DO::setOutStart(LOW);
                    step = 220;
                }
            break;
            case 220: // fahrstrom relais an
                DO::setOutFahrstrom(HIGH);
                if (DI::getInBUEHNE_BESETZT()) {
                    DO::setOutFahrstrom(LOW);
                    DO::setOutStandrelais(zielGleis, LOW);
                    step = 0;
                }
            break;
//=============================================================================
// Drehen auf Ausfahrtsgleis
//=============================================================================
            case 300: 
            break;
//=============================================================================
// stoerung
//=============================================================================
            case 998: // stoerrelais aus
                DO::setOutStoerung(LOW);
                if (millis() - stepStartMillis > T_STOER_ANZ) {
                    step = 0;
                } else if (millis() - stepStartMillis > T_STOER_IMPULS) {
                    step = 999;
                }
            break;
            case 999: // stoerrelais an
                DO::setOutStoerung(HIGH);
                if (millis() - stepStartMillis > T_STOER_ANZ) {
                    step = 0;
                } else if (millis() - stepStartMillis > T_STOER_IMPULS) {
                    step = 998;
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

            Serial.print(F(" | Letzte Gleispos: "));
            Serial.print(aktGleisPos);
            Serial.print(F(" | Ziel Gleispos: "));
            Serial.print(zielGleis);
            
        }
    }

}