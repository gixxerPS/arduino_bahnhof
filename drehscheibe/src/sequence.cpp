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
                if (DI::getInRESET()
                && lastStep < 10) {
                    step = 10;     

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