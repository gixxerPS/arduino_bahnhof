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

        if (!DI::isAutoEnabled()) {
            //Serial.println(F("keine freigabe"));
            step = 0;
            if (stepOld > 0) { // aus welchem schritt kommen wir ?
                lastStep = stepOld;
            }
            if (lastStep > 0) {
                Serial.print(F("Schritt gespeichert: "));
                Serial.println(lastStep);
            }
            DO::allOutsOff();
            if (DI::getInReset()) {
                Serial.println(F("reset"));
                lastStep = stepOld = 0;
            }
        } else if (DI::isAutoEnabled() && step == 0 && lastStep > 0) { // autofreigabe -> schritt wiederherstellen
            Serial.print(F("Schritt wiederhergestellt: "));
            Serial.println(lastStep);
            step = lastStep;
        }

        switch (step) {
            case 0: // init, warten auf freigabe
                if (stepOld > 0) {
                    DO::setOutV200Anwahl(LOW);
                    DO::setOutBr41Anwahl(LOW);
                    DO::setOutBr53Anwahl(LOW);
                    DO::setOutStop(LOW);
                    DO::setOutRichtungRueck(LOW);
                    DO::setOutBR53Rangiergeschw(LOW);
                    DO::setOutEntk1Hoch(LOW);
                    DO::setOutWeiche1(LOW);
                    DO::setOutWeiche2(LOW);
                    DO::setOutWeiche3(LOW);
                    DO::setOutEntk41Hoch(LOW);
                    DO::setOutV200Rangiergeschw(LOW);
                    DO::setOutLichtschrankeAn(LOW);
                    DO::setOutStart(LOW);
                }
                if (DI::isAutoEnabled() && lastStep < 10) {
                    step = 10;     

                }
            break;

//=============================================================================
// BR53
//=============================================================================
            case 10: // BR53 Anwahl
                DO::setOutBr53Anwahl(HIGH);
                DO::setOutStart(HIGH);
                step = 20;
            break;

            case 20: // warte auf reed BR53
                if (millis() - stepStartMillis > T2) {
                    DO::setOutStart(LOW);
                }
                if (DI::getInBr53Entk1()) {
                    DO::setOutStart(LOW);
                    step = 50;
                }
            break;        

            case 50: // verzoegerungszeit
                if (millis() - stepStartMillis > T1) {
                    step = 51;
                }
            break;

            case 51: // stop
                DO::setOutStop(HIGH);
                if (millis() - stepStartMillis > T2) {
                    DO::setOutStop(LOW);
                    step = 52;
                }
            break;

            case 52: // richtungswechsel
                DO::setOutRichtungRueck(HIGH);
                if (millis() - stepStartMillis > T3) {
                    DO::setOutRichtungRueck(LOW);
                    DO::setOutBR53Rangiergeschw(HIGH);
                    step = 53;
                }
                break;

            case 53: // start rueckwaerts
                DO::setOutStart(HIGH);
                if (millis() - stepStartMillis > T2) {
                    DO::setOutStart(LOW);
                    step = 100;
                }
            break;

            case 100: // stop rueckwaerts
                if (DI::getInBr53Entk1()) {
                    step = 110;
                }
            break;

            case 110: // stop impulslaenge
                DO::setOutStop(HIGH);
                if (millis() - stepStartMillis > T2) {
                    DO::setOutStop(LOW);
                    step = 111;
                }

            case 111: // Richtungswechsel
                DO::setOutRichtungRueck(HIGH);
                if (millis() - stepStartMillis > T3) {
                    DO::setOutRichtungRueck(LOW);
                    DO::setOutEntk1Hoch(HIGH);
                    DO::setOutWeiche1(HIGH);
                    step = 150;
                }
            break;

            case 150: // warte auf entkuppler 1 oben
                if (DI::getInEntk1Oben()) {
                    step = 160;
                }
            break;
            
            case 160: // start vorwaerts
                DO::setOutStart(HIGH);
                if (millis() - stepStartMillis > T2) {
                    DO::setOutStart(LOW);
                    step = 200;
                }
            break;
            
            case 200: // warte auf prellbock weiche 1
                if (DI::getInPrellbockW1()) {
                    step = 210;
                }
            break;
            
            case 210: // stop impuls
                DO::setOutStop(HIGH);
                if (millis() - stepStartMillis > T2) {
                    DO::setOutStop(LOW);
                    step = 211;
                }
            break;

//=============================================================================
// V200
//=============================================================================
            case 211: // vorbereitung v200 zurueck
                DO::setOutEntk1Hoch(LOW);
                DO::setOutWeiche1(LOW);
                DO::setOutWeiche2(HIGH);
                DO::setOutBr53Anwahl(LOW);
                DO::setOutV200Anwahl(HIGH);
                DO::setOutRichtungRueck(HIGH);
                if (millis() - stepStartMillis > T3) {
                    DO::setOutRichtungRueck(LOW);
                    DO::setOutStart(HIGH);
                    step = 212;
                }
            break;

            case 250: // warte auf reed V200
                DO::setOutStart(HIGH);
                if (millis() - stepStartMillis > T2) {
                    DO::setOutStart(LOW);
                }
                if (DI::getInV200Entk1()) {
                    DO::setOutStart(LOW);
                    step = 260;
                }
            break;

            case 260: // stop
                DO::setOutStop(HIGH);
                if (millis() - stepStartMillis > T2) {
                    DO::setOutStop(LOW);
                    step = 261;
                }
            break;     
            
            case 261: // richtungsimpuls: vor
                DO::setOutRichtungRueck(HIGH);
                if (millis() - stepStartMillis > T3) {
                    DO::setOutRichtungRueck(LOW);
                    DO::setOutWeiche2(LOW);
                    step = 300;
                }
            break;
            
            case 300: // ausfahrt frei ?
                if (DI::getInAusfahrtFrei()) {
                    step = 310;
                }
            break;
            
            case 310: // start
                DO::setOutStart(HIGH);
                if (millis() - stepStartMillis > T2) {
                    DO::setOutStart(LOW);
                    step = 350;
                }
            break;
            
            case 350: // reed v200 aktiv ?
                if (DI::getInV200Entk1()) {
                    step = 360;
                }
            break;

            case 360: // verzoegerungszeit
                if (millis() - stepStartMillis > T1) {
                    step = 361;
                }
            break;

            case 361: // stop impuls
                DO::setOutStop(HIGH);
                if (millis() - stepStartMillis > T2) {
                    DO::setOutStop(LOW);
                    step = 362;
                }
            break;  

            case 362: // richtungsimpuls: zurueck
                DO::setOutRichtungRueck(HIGH);
                if (millis() - stepStartMillis > T3) {
                    DO::setOutRichtungRueck(LOW);
                    DO::setOutLichtschrankeAn(HIGH);
                    step = 400;
                }
            break;

            case 400: // start rueckwaerts
                DO::setOutStart(HIGH);
                if (millis() - stepStartMillis > T2) {
                    DO::setOutStart(LOW);
                }
                if (DI::getInLichtschrEntk41()) {
                    DO::setOutStart(LOW);
                    step = 410;
                }
            break;

            case 410: // stop impuls
                DO::setOutStop(HIGH);
                if (millis() - stepStartMillis > T2) {
                    DO::setOutStop(LOW);
                    step = 411;
                }
            break;  

            case 411: // richtungsimpuls: vorwaerts
                DO::setOutRichtungRueck(HIGH);
                if (millis() - stepStartMillis > T3) {
                    DO::setOutRichtungRueck(LOW);
                    DO::setOutEntk41Hoch(HIGH);
                    step = 450;
                }
            break;

            // TODO: weiter mit seite 2 <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
            
            
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
    }
}