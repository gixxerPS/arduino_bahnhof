#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <Arduino.h>

namespace SEQ
{
    const unsigned long T_SERIAL_AUSGABE = 10000; // [ms] schrittinfo ausgabe alle x ms
    const unsigned long T_VERZ_START_F_DREHR = 10000; // [ms] verzoegerung startbefehl fuer drehrichtungswahl
    const unsigned long T_STOER_ANZ = 10000; // [ms] anzeigedauer stoerung
    const unsigned long T_STOER_IMPULS = 500; // [ms] anzeigedauer stoerung
    const unsigned long T_VERZ_NACH_TOR_AUF = 4000; // [ms] verzoegerung fuer fahrstrom nachdem tor geoeffnet wurde
    
    enum RICHTUNG {
        KEINE = 0,
        LINKS = 1,
        RECHTS = 2
    };
    enum HOLBRING {
        KEIN = 0,
        HOLEN = 1,
        BRINGEN = 2
    };
    
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