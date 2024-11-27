#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <Arduino.h>

namespace SEQ
{
    const unsigned long T_SERIAL_AUSGABE = 10000; // [ms] schrittinfo ausgabe alle x ms
    const unsigned long T_IMPULS_ZENTRIERUNG = 2000; // [ms] impulslaenge zentrierung ausfahren
    const unsigned long T_IMPULS_ENDSCHALTER = 2000; // [ms] impulslaenge zentrierung ausfahren
    const unsigned long T_IMPULS_AUFZUGFAST = 6000; // [ms] impulslaenge
    const unsigned long T_IMPULS_BUEHNEFAST = 6000; // [ms] impulslaenge
    const unsigned long T_IMPULS_GLEISVERRIEGELUNG = 2000; // [ms] impulslaenge
    const unsigned long T_IMPULS_UMSCH_RECHTSLINKS = 2000; // [ms] impulslaenge
    
    extern uint16_t step;
    extern uint16_t stepOld; // step vom letzten zyklus
    extern uint16_t lastStep; // step der als letztes vor dem aktuellen aktiv war (ausser 0)
    extern long unsigned int stepStartMillis; // zeitpunkt an dem step aktiv wurde
    extern bool stepChange;
    
    // void setup();
    void loop();
    // void printInputs();
}
#endif