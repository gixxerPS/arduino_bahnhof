#ifndef DIGITALOUTPUTS_H
#define DIGITALOUTPUTS_H

#include <Arduino.h>

namespace DO
{
    // Relaismodul 1 (oben)
    const uint8_t PIN_1_EINF_GLEISZENTR_AUS     = 46;
    const uint8_t PIN_2_ZUG_AUF_BUEHNE_START    = 47; // zug von einfahrtsgleis auf buehne koppeln
    const uint8_t PIN_3_EINF_GLEISZENTR_EIN     = 44;
    const uint8_t PIN_4_FUEHLER_AUS             = 45;
    const uint8_t PIN_5_MOTOR_SLOW              = 42;
    const uint8_t PIN_6_MOTOR_FAST              = 43;
    const uint8_t PIN_7_RICHTUNG_AENDERN        = 40;
    const uint8_t PIN_8_AUSF_GLEISZENTR_AUS     = 41;

    // Relaismodule 2 (mitte)
    const uint8_t PIN_9_ZUG_AUF_AUS_START       = 38; // zug auf ausfahrtsgleis koppeln
    const uint8_t PIN_10_ENDSCH_AUFZUGGL_EINF   = 39;
    const uint8_t PIN_11_AUFZUG_START_SLOW      = 36;
    const uint8_t PIN_12_AUFZUG_START_FAST      = 37;
    const uint8_t PIN_13_AUFZUGGL_ANSCHALTEN    = 34;
    const uint8_t PIN_14_AUFZUG_NACH_UNTEN      = 35;
    const uint8_t PIN_15_AUFZUGGL_VERRIEGEL_AN  = 32;
    const uint8_t PIN_16_RESERVE                = 31;

    // Relaismodul 3 (unten)
    const uint8_t PIN_GESCHW_BIT0               = 69;
    const uint8_t PIN_GESCHW_BIT1               = 68;
    const uint8_t PIN_GESCHW_BIT2               = 67;
    const uint8_t PIN_GESCHW_BIT3               = 66;
    const uint8_t PIN_RESERVE_REL5              = 65;
    const uint8_t PIN_RESERVE_REL6              = 64;
    const uint8_t PIN_RESERVE_REL7              = 63;
    const uint8_t PIN_RESERVE_REL8              = 62;

    void setup();
    void loop();
    void allOutsOff();

    // Zugriffsfunktionen fuer Relaisausgaenge
    // Relais Modul: 
    //   5V -> Relais AUS
    //   0V -> Relais AN
    inline void setOutEinfGleiszentrAus(uint8_t val) { digitalWrite(PIN_1_EINF_GLEISZENTR_AUS, !val); }
    inline void setOutZugAufBuehneStart(uint8_t val) { digitalWrite(PIN_2_ZUG_AUF_BUEHNE_START, !val); }
    inline void setOutEinfGleiszentrEin(uint8_t val) { digitalWrite(PIN_3_EINF_GLEISZENTR_EIN, !val); }
    inline void setOutFuehlerAus(uint8_t val) { digitalWrite(PIN_4_FUEHLER_AUS, !val); }
    inline void setOutMotorSlow(uint8_t val) { digitalWrite(PIN_5_MOTOR_SLOW, !val); }
    inline void setOutMotorFast(uint8_t val) { digitalWrite(PIN_6_MOTOR_FAST, !val); }
    inline void setOutRichtungAendern(uint8_t val) { digitalWrite(PIN_7_RICHTUNG_AENDERN, !val); }
    inline void setOutAusfGleiszentrAus(uint8_t val) { digitalWrite(PIN_8_AUSF_GLEISZENTR_AUS, !val); }

    inline void setOutZugAufAusStart(uint8_t val) { digitalWrite(PIN_9_ZUG_AUF_AUS_START, !val); }
    inline void setOutEndschAufzugglEinf(uint8_t val) { digitalWrite(PIN_10_ENDSCH_AUFZUGGL_EINF, !val); }
    inline void setOutAufzugStartSlow(uint8_t val) { digitalWrite(PIN_11_AUFZUG_START_SLOW, !val); }
    inline void setOutAufzugStartFast(uint8_t val) { digitalWrite(PIN_12_AUFZUG_START_FAST, !val); }
    inline void setOutAufzugglAnschalten(uint8_t val) { digitalWrite(PIN_13_AUFZUGGL_ANSCHALTEN, !val); }
    inline void setOutAufzugNachUnten(uint8_t val) { digitalWrite(PIN_14_AUFZUG_NACH_UNTEN, !val); }
    inline void setOutAufzugglVerriegelAn(uint8_t val) { digitalWrite(PIN_15_AUFZUGGL_VERRIEGEL_AN, !val); }
    inline void setOutReserve(uint8_t val) { digitalWrite(PIN_16_RESERVE, !val); }

    inline void setOutGeschwBit0(uint8_t val) { digitalWrite(PIN_GESCHW_BIT0, !val); }
    inline void setOutGeschwBit1(uint8_t val) { digitalWrite(PIN_GESCHW_BIT1, !val); }
    inline void setOutGeschwBit2(uint8_t val) { digitalWrite(PIN_GESCHW_BIT2, !val); }
    inline void setOutGeschwBit3(uint8_t val) { digitalWrite(PIN_GESCHW_BIT3, !val); }
    inline void setOutReserveRel5(uint8_t val) { digitalWrite(PIN_RESERVE_REL5, !val); }
    inline void setOutReserveRel6(uint8_t val) { digitalWrite(PIN_RESERVE_REL6, !val); }
    inline void setOutReserveRel7(uint8_t val) { digitalWrite(PIN_RESERVE_REL7, !val); }
    inline void setOutReserveRel8(uint8_t val) { digitalWrite(PIN_RESERVE_REL8, !val); }

}
#endif