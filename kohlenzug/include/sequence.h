#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <Arduino.h>

namespace SEQ
{
    extern uint16_t step;
    extern uint16_t stepOld; // step vom letzten zyklus
    extern uint16_t lastStep; // step der als letztes vor dem aktuellen aktiv war (ausser 0)
    extern long unsigned int stepStartMillis; // zeitpunkt an dem step aktiv wurde
    extern bool stepChange;
    const long unsigned int T1 = 1000; // [ms] verzoegerung anhalten vorwaerts nach reed BR53, BR41, V200
    const long unsigned int T2 = 1000; // [ms] impulslaenge start/stop
    const long unsigned int T3 = 1000; // [ms] impulslaenge richtungswechsel

    // void setup();
    void loop();
    // void printInputs();
}
#endif