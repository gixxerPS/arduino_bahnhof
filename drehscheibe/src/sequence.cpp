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
    RICHTUNG richtung; // wie rum soll gedreht werden
    HOLBRING holbringAuftrag; 

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
                    holbringAuftrag = HOLBRING::KEIN;
                }

                // pruefe anwahl
                for (uint8_t i = 1; i <= ANZ_GLEISE; i++) { // 1..12 gleis num, 13=A, 14=B, 15=C
                    if (DI::getInGLEIS_ANWAHL(i)) { // anwahltaste gedrueckt ?
                        if (zielGleis == 0) { 
                            zielGleis = i;
                            DO::setOutStandrelais(i, HIGH); // und anzeigen
                            if (zielGleis >= ERSTES_STANDGLEIS && zielGleis <= LETZTES_STANDGLEIS) {
                                step = 100;
                            } else if (zielGleis >= ERSTES_EINFAHRTSGLEIS && zielGleis <= LETZTES_EINFAHRTSGLEIS) {
                                step = 100; // 200; doch gleiche sequenz moeglich
                            } else if (zielGleis >= ERSTES_AUSFAHRTSGLEIS && zielGleis <= LETZTES_AUSFAHRTSGLEIS) {
                                step = 100; // 300; doch gleiche sequenz moeglich
                            }
                        } 
                    }
                }
            break;

//=============================================================================
// Drehen auf Standgleis zum abholen ODER wegbringen
//=============================================================================
            case 100: // besetzt pruefen
                if (DI::getInBUEHNE_BESETZT() && !DI::getInGLEIS_BESETZT(zielGleis)) { // wegbringen
                    holbringAuftrag = HOLBRING::BRINGEN;
                    step = 110;
                } else if (!DI::getInBUEHNE_BESETZT() && DI::getInGLEIS_BESETZT(zielGleis)) { // abholen
                    holbringAuftrag = HOLBRING::HOLEN;
                    step = 110; 
                } else { // buehne und stand besetzt, stoerung
                    step = 999;
                }
            break;
            case 110: // standrelais an, drehrichtung ermitteln
                if (aktGleisPos != zielGleis) {
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
                } else { // aktGleisPos == zielGleis
                    if (zielGleis >= ERSTES_STANDGLEIS && zielGleis <= LETZTES_STANDGLEIS) {
                        DO::setOutZielTorRelais(zielGleis, HIGH);
                    }
                    step = 140;
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
                if (richtung == RICHTUNG::LINKS) {
                    DO::setOutLinks(HIGH);
                } else if (richtung == RICHTUNG::RECHTS) {
                    DO::setOutRechts(HIGH);
                }
                DO::setOutStart(HIGH);

                // tor oeffnen, wenn nah genug am ziel
                if (abs(zielGleis - aktGleisPos) < 3) { // bsp. ziel=5, aktGleisPos=7 => tor 5 auf
                    // aber nur bei standgleis
                    if (zielGleis >= ERSTES_STANDGLEIS && zielGleis <= LETZTES_STANDGLEIS) {
                        DO::setOutZielTorRelais(zielGleis, HIGH);
                    }
                }
                if (DI::getInGLEIS_POSITION(zielGleis)) {
                    DO::setOutLinks(LOW);
                    DO::setOutRechts(LOW);
                    DO::setOutStart(LOW);
                    step = 140;
                }
            break;
            case 140: // fahrstrom an
                if (millis() - stepStartMillis > T_VERZ_NACH_TOR_AUF) {
                    DO::setOutFahrstrom(HIGH);
                    if (holbringAuftrag == HOLBRING::HOLEN) {
                        step = 150;
                    } else { // wegbringen
                        // warte auf reset durch bediener
                    }
                }
            break;
            case 150: // warte auf auffahrt auf buehne
                if (DI::getInBUEHNE_BESETZT()) {
                    step = 0; // fertig, alles aus
                }
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
            case 300: // besetzt pruefen
                if (!DI::getInBUEHNE_BESETZT() ) {
                    step = 999;
                } else if (DI::getInGLEIS_BESETZT(zielGleis)) {
                    step = 999;
                } else { // frei, ok weiter
                    step = 310;
                }
            break;
            case 310: // tor oeffnen
                DO::setOutZielTorRelais(aktGleisPos, HIGH);
                if (millis() - stepStartMillis > T_VERZ_NACH_TOR_AUF) {
                    step = 320;
                }
            break;
            case 320: // auf buehne fahren
                DO::setOutFahrstrom(HIGH);
                if (DI::getInBUEHNE_BESETZT()) {
                    DO::setOutFahrstrom(LOW);
                    DO::setOutZielTorRelais(aktGleisPos, LOW);
                    DO::setOutStandrelais(aktGleisPos, LOW);
                }
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
            Serial.print(F("Schrittwechsel! aktuell: "));
            Serial.print(step);
            Serial.print(F(" | letzer: "));
            Serial.print(lastStep);
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