#include <Arduino.h>
#include "digitalOutputs.h"

namespace DO
{
    void setup()
    {
        pinMode(PIN_1_EINF_GLEISZENTR_AUS, OUTPUT);
        digitalWrite(PIN_1_EINF_GLEISZENTR_AUS, HIGH); // Relais sofort ausschalten

        pinMode(PIN_2_ZUG_AUF_BUEHNE_START, OUTPUT);
        digitalWrite(PIN_2_ZUG_AUF_BUEHNE_START, HIGH); // Relais sofort ausschalten

        pinMode(PIN_3_EINF_GLEISZENTR_EIN, OUTPUT);
        digitalWrite(PIN_3_EINF_GLEISZENTR_EIN, HIGH); // Relais sofort ausschalten

        pinMode(PIN_4_FUEHLER_AUS, OUTPUT);
        digitalWrite(PIN_4_FUEHLER_AUS, HIGH); // Relais sofort ausschalten

        pinMode(PIN_5_MOTOR_SLOW, OUTPUT);
        digitalWrite(PIN_5_MOTOR_SLOW, HIGH); // Relais sofort ausschalten

        pinMode(PIN_6_MOTOR_FAST, OUTPUT);
        digitalWrite(PIN_6_MOTOR_FAST, HIGH); // Relais sofort ausschalten

        pinMode(PIN_7_RICHTUNG_AENDERN, OUTPUT);
        digitalWrite(PIN_7_RICHTUNG_AENDERN, HIGH); // Relais sofort ausschalten

        pinMode(PIN_8_AUSF_GLEISZENTR_AUS, OUTPUT);
        digitalWrite(PIN_8_AUSF_GLEISZENTR_AUS, HIGH); // Relais sofort ausschalten

        pinMode(PIN_9_ZUG_AUF_AUS_START, OUTPUT);
        digitalWrite(PIN_9_ZUG_AUF_AUS_START, HIGH); // Relais sofort ausschalten

        pinMode(PIN_10_ENDSCH_AUFZUGGL_EINF, OUTPUT);
        digitalWrite(PIN_10_ENDSCH_AUFZUGGL_EINF, HIGH); // Relais sofort ausschalten

        pinMode(PIN_11_AUFZUG_START_SLOW, OUTPUT);
        digitalWrite(PIN_11_AUFZUG_START_SLOW, HIGH); // Relais sofort ausschalten

        pinMode(PIN_12_AUFZUG_START_FAST, OUTPUT);
        digitalWrite(PIN_12_AUFZUG_START_FAST, HIGH); // Relais sofort ausschalten

        pinMode(PIN_13_AUFZUGGL_ANSCHALTEN, OUTPUT);
        digitalWrite(PIN_13_AUFZUGGL_ANSCHALTEN, HIGH); // Relais sofort ausschalten

        pinMode(PIN_14_AUFZUG_NACH_UNTEN, OUTPUT);
        digitalWrite(PIN_14_AUFZUG_NACH_UNTEN, HIGH); // Relais sofort ausschalten

        pinMode(PIN_15_AUFZUGGL_VERRIEGEL_AN, OUTPUT);
        digitalWrite(PIN_15_AUFZUGGL_VERRIEGEL_AN, HIGH); // Relais sofort ausschalten

        pinMode(PIN_16_RESERVE, OUTPUT);
        digitalWrite(PIN_16_RESERVE, HIGH); // Relais sofort ausschalten

        pinMode(PIN_GESCHW_BIT0, OUTPUT);
        digitalWrite(PIN_GESCHW_BIT0, HIGH); // Relais sofort ausschalten

        pinMode(PIN_GESCHW_BIT1, OUTPUT);
        digitalWrite(PIN_GESCHW_BIT1, HIGH); // Relais sofort ausschalten

        pinMode(PIN_GESCHW_BIT2, OUTPUT);
        digitalWrite(PIN_GESCHW_BIT2, HIGH); // Relais sofort ausschalten

        pinMode(PIN_GESCHW_BIT3, OUTPUT);
        digitalWrite(PIN_GESCHW_BIT3, HIGH); // Relais sofort ausschalten

        pinMode(PIN_RESERVE_REL5, OUTPUT);
        digitalWrite(PIN_RESERVE_REL5, HIGH); // Relais sofort ausschalten

        pinMode(PIN_RESERVE_REL6, OUTPUT);
        digitalWrite(PIN_RESERVE_REL6, HIGH); // Relais sofort ausschalten

        pinMode(PIN_RESERVE_REL7, OUTPUT);
        digitalWrite(PIN_RESERVE_REL7, HIGH); // Relais sofort ausschalten

        pinMode(PIN_RESERVE_REL8, OUTPUT);
        digitalWrite(PIN_RESERVE_REL8, HIGH); // Relais sofort ausschalten

    }

    void loop()
    {
    }

    void allOutsOff()
    {
        setOutEinfGleiszentrAus(LOW);      // PIN_1_EINF_GLEISZENTR_AUS
        setOutZugAufBuehneStart(LOW);      // PIN_2_ZUG_AUF_BUEHNE_START
        setOutEinfGleiszentrEin(LOW);      // PIN_3_EINF_GLEISZENTR_EIN
        setOutFuehlerAus(LOW);             // PIN_4_FUEHLER_AUS
        setOutMotorSlow(LOW);              // PIN_5_MOTOR_SLOW
        setOutMotorFast(LOW);              // PIN_6_MOTOR_FAST
        setOutRichtungAendern(LOW);        // PIN_7_RICHTUNG_AENDERN
        setOutAusfGleiszentrAus(LOW);      // PIN_8_AUSF_GLEISZENTR_AUS

        setOutZugAufAusStart(LOW);         // PIN_9_ZUG_AUF_AUS_START
        setOutEndschAufzugglEinf(LOW);     // PIN_10_ENDSCH_AUFZUGGL_EINF
        setOutAufzugStartSlow(LOW);        // PIN_11_AUFZUG_START_SLOW
        setOutAufzugStartFast(LOW);        // PIN_12_AUFZUG_START_FAST
        setOutAufzugglAnschalten(LOW);     // PIN_13_AUFZUGGL_ANSCHALTEN
        setOutAufzugNachUnten(LOW);        // PIN_14_AUFZUG_NACH_UNTEN
        setOutAufzugglVerriegelAn(LOW);    // PIN_15_AUFZUGGL_VERRIEGEL_AN
        setOutReserve(LOW);                // PIN_16_RESERVE

        setOutGeschwBit0(LOW);             // PIN_GESCHW_BIT0
        setOutGeschwBit1(LOW);             // PIN_GESCHW_BIT1
        setOutGeschwBit2(LOW);             // PIN_GESCHW_BIT2
        setOutGeschwBit3(LOW);             // PIN_GESCHW_BIT3
        setOutReserveRel5(LOW);            // PIN_RESERVE_REL5
        setOutReserveRel6(LOW);            // PIN_RESERVE_REL6
        setOutReserveRel7(LOW);            // PIN_RESERVE_REL7
        setOutReserveRel8(LOW);            // PIN_RESERVE_REL8
    }
}