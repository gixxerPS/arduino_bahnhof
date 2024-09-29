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
        switch (step) {
            case 0: // init, warten auf freigabe
                if (stepOld > 0) {
                    // DO::setOutV200Anwahl(LOW);
                    // DO::setOutBr41Anwahl(LOW);
                    // DO::setOutBr53Anwahl(LOW);
                    // DO::setOutStop(LOW);
                    // DO::setOutRichtungRueck(LOW);
                    // DO::setOutBR53Rangiergeschw(LOW);
                    // DO::setOutEntk1Hoch(LOW);
                    // DO::setOutWeiche1(LOW);
                    // DO::setOutWeiche2(LOW);
                    // DO::setOutWeiche3(LOW);
                    // DO::setOutEntk41Hoch(LOW);
                    // DO::setOutV200Rangiergeschw(LOW);
                    // DO::setOutLichtschrankeAn(LOW);
                    // DO::setOutStart(LOW);
                }
                // if (DI::isAutoEnabled() && lastStep < 10) {
                //     step = 10;     

                // }
            break;

//=============================================================================
// Start
//=============================================================================
            case 10: // BR53 Anwahl
                step = 20;
            break;

            case 20: // warte auf reed BR53
                if (millis() - stepStartMillis > T2) {
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
    }
}