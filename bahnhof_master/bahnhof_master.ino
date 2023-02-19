/**
 * @mainpage
 * Logik controller der bahnhof steuerung fuer diethelm.
 * Neu: slave1 gibts nicht mehr, da der alte master (uno)
 * nicht genug speicher fuer lcd hatte => hardware wurde umgebaut
 * so dass lcd jetzt an slave1 angeschlossen wurde und slave1 jetzt 
 * auch master ist.
 *
 * Arduino / VS code einstellungen:
 * ================================
 * Programmer = arduino:avrispmkii
 * Board      = Arduino Uno
 * Port       = /dev/ttyACM0
 *
 * serial monitor:
 * ==============
 * Ctrl + Shift + P
 * Arduino: Open Serial Monitor <= funktioniert iwie nicht
 * ABER
 * sudo picocom /dev/ttyACM0
 * geht. beenden mit Ctrl+A, Ctrl+X
 *
 * Für die LCD-Schnittstelle werden die Anschlüsse 4, 5, 6, 7, 8, 9 und 10 belegt. Die Taster werden über ein Widerstandsnetzwerk am analogen Eingang Pin 0 eingelesen.
 * https://funduino.de/zb-01-keypad-shield
 *
 * 8-fach Relais-Module
 * ====================
 * INx = false => relais AN
 * INx = true  => relais AUS
 * JD-VCC, GND = Last 5V versorgung fuer relais => 2. netzteil
 * VCC, GND = Steuerspannung
 */
#include <Wire.h>

#include "pcf8575Handling.h"
#include "lcdMenu.h"
#include "command.h"
#include "rxtx.h"
#include "digitalInputs.h"

#define N_LOOP_AVG 9 // N-1 => N_LOOP_AVG=9  bedeutet N = 10!
#define PRINT_LOOP_INTERVAL 5000 // [ms] alle n ms zykluszeit seriell ausgeben 

//#define I2C_SLAVE1_ADDR 9
#define RX_SLAVE_BYTE_CNT 10 // pauschal 10 bytes je slaves lesen
#define TX_SLAVE_BYTE_CNT 10 // pauschal 10 bytes je slaves schreiben
// uint8_t rawInputsSlave1[RX_SLAVE_BYTE_CNT]; // 1=aktiv/gedrueckt, 0=inaktiv/nicht gedrueckt
//uint8_t rawOutputsSlave1[TX_SLAVE_BYTE_CNT]; // gibts nicht da slave1 ueber denselben i2c bus angeschlossen ist wie die pcf => also werden die ausgaenge direkt vom master gesetzt
uint8_t rawInputsSlave2[RX_SLAVE_BYTE_CNT]; // 1=aktiv/gedrueckt, 0=inaktiv/nicht gedrueckt
uint8_t rawOutputsSlave2[TX_SLAVE_BYTE_CNT];

/* befehls modul direktes setzen der ausgaenge ohne umweg ermoeglichen.
 * so kann verhindert werden dass zyklisch die ausgaenge ausgelesen und extra gesetzt werden muessen
 */
void setEmpty(uint8_t val) {}; // fuer aktuell nicht benutzte ausgaenge
// remote ausgaenge an slave2
void set13inA(uint8_t val) {bitWrite(rawOutputsSlave2[1], 5, val);};
void set14inA(uint8_t val) {bitWrite(rawOutputsSlave2[1], 2, val);};
void set11inB(uint8_t val) {bitWrite(rawOutputsSlave2[1], 7, val);};
void set13inB(uint8_t val) {bitWrite(rawOutputsSlave2[1], 4, val);};
void set14inB(uint8_t val) {bitWrite(rawOutputsSlave2[1], 1, val);};
void setCin1(uint8_t val) {bitWrite(rawOutputsSlave2[0], 2, val);};
void setCin2(uint8_t val) {bitWrite(rawOutputsSlave2[0], 3, val);};
void setCin3(uint8_t val) {bitWrite(rawOutputsSlave2[0], 4, val);};
void setCin4(uint8_t val) {bitWrite(rawOutputsSlave2[0], 5, val);};
void setCin5(uint8_t val) {bitWrite(rawOutputsSlave2[0], 6, val);};
void setCin6(uint8_t val) {bitWrite(rawOutputsSlave2[0], 7, val);};
void setDin18(uint8_t val) {bitWrite(rawOutputsSlave2[0], 0, val);};
void setDin19(uint8_t val) {bitWrite(rawOutputsSlave2[0], 1, val);};
void set11inF(uint8_t val) {bitWrite(rawOutputsSlave2[1], 6, val);};
void set13inF(uint8_t val) {bitWrite(rawOutputsSlave2[1], 3, val);};
void set14inF(uint8_t val) {bitWrite(rawOutputsSlave2[1], 0, val);};
void set13inG(uint8_t val) {bitWrite(rawOutputsSlave2[3], 5, val);};
void set14inG(uint8_t val) {bitWrite(rawOutputsSlave2[3], 4, val);};
void set15inG(uint8_t val) {bitWrite(rawOutputsSlave2[3], 3, val);};
void set16inG(uint8_t val) {bitWrite(rawOutputsSlave2[3], 2, val);};
void set17inG(uint8_t val) {bitWrite(rawOutputsSlave2[3], 1, val);};
void set18inG(uint8_t val) {bitWrite(rawOutputsSlave2[3], 0, val);};
void setJin18(uint8_t val) {bitWrite(rawOutputsSlave2[3], 7, val);};
void setJin19(uint8_t val) {bitWrite(rawOutputsSlave2[3], 6, val);};
void setJin9(uint8_t val)  {bitWrite(rawOutputsSlave2[5], 7, val);};
void setJin10(uint8_t val) {bitWrite(rawOutputsSlave2[5], 6, val);};
void setJin11(uint8_t val) {bitWrite(rawOutputsSlave2[5], 5, val);};
void setJin13(uint8_t val) {bitWrite(rawOutputsSlave2[5], 4, val);};
void setJin14(uint8_t val) {bitWrite(rawOutputsSlave2[5], 3, val);};
void setJin15(uint8_t val) {bitWrite(rawOutputsSlave2[5], 2, val);};
void setJin16(uint8_t val) {bitWrite(rawOutputsSlave2[5], 1, val);};
void setJin17(uint8_t val) {bitWrite(rawOutputsSlave2[5], 0, val);};

void connectSetOutFunctions() 
{
  CCommand::setOut[CCommand::i1_IN_A] = &MY_PCF8575::set1inA;
CCommand::setOut[CCommand::i1_IN_A] = &MY_PCF8575::set1inA;
CCommand::setOut[CCommand::i2_IN_A] = &MY_PCF8575::set2inA;
CCommand::setOut[CCommand::i3_IN_A] = &MY_PCF8575::set3inA;
CCommand::setOut[CCommand::i4_IN_A] = &MY_PCF8575::set4inA;
CCommand::setOut[CCommand::i5_IN_A] = &MY_PCF8575::set5inA;
CCommand::setOut[CCommand::i6_IN_A] = &MY_PCF8575::set6inA;
CCommand::setOut[CCommand::i7_IN_A] = &MY_PCF8575::set7inA;
CCommand::setOut[CCommand::i8_IN_A] = &MY_PCF8575::set8inA;
CCommand::setOut[CCommand::i9_IN_A] = &MY_PCF8575::set9inA;
CCommand::setOut[CCommand::i10_IN_A] = &MY_PCF8575::set10inA;
CCommand::setOut[CCommand::i11_IN_A] = &MY_PCF8575::set11inA;
CCommand::setOut[CCommand::i12_IN_A] = &setEmpty;
CCommand::setOut[CCommand::i13_IN_A] = &set13inA;
CCommand::setOut[CCommand::i14_IN_A] = &set14inA;
CCommand::setOut[CCommand::i15_IN_A] = &MY_PCF8575::set15inA;
CCommand::setOut[CCommand::i16_IN_A] = &MY_PCF8575::set16inA;
CCommand::setOut[CCommand::i17_IN_A] = &MY_PCF8575::set17inA;
CCommand::setOut[CCommand::i18_IN_A] = &MY_PCF8575::set18inA;
CCommand::setOut[CCommand::i19_IN_A] = &MY_PCF8575::set19inA;
CCommand::setOut[CCommand::i1_IN_B] = &MY_PCF8575::set1inB;
CCommand::setOut[CCommand::i2_IN_B] = &MY_PCF8575::set2inB;
CCommand::setOut[CCommand::i3_IN_B] = &MY_PCF8575::set3inB;
CCommand::setOut[CCommand::i4_IN_B] = &MY_PCF8575::set4inB;
CCommand::setOut[CCommand::i5_IN_B] = &MY_PCF8575::set5inB;
CCommand::setOut[CCommand::i6_IN_B] = &MY_PCF8575::set6inB;
CCommand::setOut[CCommand::i7_IN_B] = &MY_PCF8575::set7inB;
CCommand::setOut[CCommand::i8_IN_B] = &MY_PCF8575::set8inB;
CCommand::setOut[CCommand::i9_IN_B] = &MY_PCF8575::set9inB;
CCommand::setOut[CCommand::i10_IN_B] = &MY_PCF8575::set10inB;
CCommand::setOut[CCommand::i11_IN_B] = &set11inB;
CCommand::setOut[CCommand::i12_IN_B] = &setEmpty;
CCommand::setOut[CCommand::i13_IN_B] = &set13inB;
CCommand::setOut[CCommand::i14_IN_B] = &set14inB;
CCommand::setOut[CCommand::i15_IN_B] = &MY_PCF8575::set15inB;
CCommand::setOut[CCommand::i16_IN_B] = &MY_PCF8575::set16inB;
CCommand::setOut[CCommand::i17_IN_B] = &MY_PCF8575::set17inB;
CCommand::setOut[CCommand::i18_IN_B] = &MY_PCF8575::set18inB;
CCommand::setOut[CCommand::i19_IN_B] = &MY_PCF8575::set19inB;
CCommand::setOut[CCommand::iC_IN_1] = &setCin1;
CCommand::setOut[CCommand::iC_IN_2] = &setCin2;
CCommand::setOut[CCommand::iC_IN_3] = &setCin3;
CCommand::setOut[CCommand::iC_IN_4] = &setCin4;
CCommand::setOut[CCommand::iC_IN_5] = &setCin5;
CCommand::setOut[CCommand::iC_IN_6] = &setCin6;
CCommand::setOut[CCommand::iC_IN_7] = &MY_PCF8575::setCin7;
CCommand::setOut[CCommand::iC_IN_8] = &MY_PCF8575::setCin8;
CCommand::setOut[CCommand::iC_IN_9] = &MY_PCF8575::setCin9;
CCommand::setOut[CCommand::iC_IN_10] = &MY_PCF8575::setCin10;
CCommand::setOut[CCommand::iC_IN_11] = &MY_PCF8575::setCin11;
CCommand::setOut[CCommand::iC_IN_12] = &MY_PCF8575::setCin12;
CCommand::setOut[CCommand::iC_IN_13] = &MY_PCF8575::setCin13;
CCommand::setOut[CCommand::iC_IN_14] = &MY_PCF8575::setCin14;
CCommand::setOut[CCommand::iC_IN_15] = &MY_PCF8575::setCin15;
CCommand::setOut[CCommand::iC_IN_16] = &MY_PCF8575::setCin16;
CCommand::setOut[CCommand::iC_IN_17] = &MY_PCF8575::setCin17;
CCommand::setOut[CCommand::iC_IN_18] = &MY_PCF8575::setCin18;
CCommand::setOut[CCommand::iC_IN_19] = &MY_PCF8575::setCin19;
CCommand::setOut[CCommand::iD_IN_1] = &MY_PCF8575::setDin1;
CCommand::setOut[CCommand::iD_IN_2] = &MY_PCF8575::setDin2;
CCommand::setOut[CCommand::iD_IN_3] = &MY_PCF8575::setDin3;
CCommand::setOut[CCommand::iD_IN_4] = &MY_PCF8575::setDin4;
CCommand::setOut[CCommand::iD_IN_5] = &MY_PCF8575::setDin5;
CCommand::setOut[CCommand::iD_IN_6] = &MY_PCF8575::setDin6;
CCommand::setOut[CCommand::iD_IN_7] = &MY_PCF8575::setDin7;
CCommand::setOut[CCommand::iD_IN_8] = &MY_PCF8575::setDin8;
CCommand::setOut[CCommand::iD_IN_9] = &MY_PCF8575::setDin9;
CCommand::setOut[CCommand::iD_IN_10] = &MY_PCF8575::setDin10;
CCommand::setOut[CCommand::iD_IN_11] = &MY_PCF8575::setDin11;
CCommand::setOut[CCommand::iD_IN_12] = &MY_PCF8575::setDin12;
CCommand::setOut[CCommand::iD_IN_13] = &MY_PCF8575::setDin13;
CCommand::setOut[CCommand::iD_IN_14] = &MY_PCF8575::setDin14;
CCommand::setOut[CCommand::iD_IN_15] = &MY_PCF8575::setDin15;
CCommand::setOut[CCommand::iD_IN_16] = &MY_PCF8575::setDin16;
CCommand::setOut[CCommand::iD_IN_17] = &MY_PCF8575::setDin17;
CCommand::setOut[CCommand::iD_IN_18] = &setDin18;
CCommand::setOut[CCommand::iD_IN_19] = &setDin19;
CCommand::setOut[CCommand::i5_IN_F] = &MY_PCF8575::set5inF;
CCommand::setOut[CCommand::i6_IN_F] = &MY_PCF8575::set6inF;
CCommand::setOut[CCommand::i7_IN_F] = &MY_PCF8575::set7inF;
CCommand::setOut[CCommand::i8_IN_F] = &MY_PCF8575::set8inF;
CCommand::setOut[CCommand::i9_IN_F] = &MY_PCF8575::set9inF;
CCommand::setOut[CCommand::i10_IN_F] = &MY_PCF8575::set10inF;
CCommand::setOut[CCommand::i11_IN_F] = &set11inF;
CCommand::setOut[CCommand::i12_IN_T] = &setEmpty;
CCommand::setOut[CCommand::i13_IN_T] = &set13inF;
CCommand::setOut[CCommand::i14_IN_T] = &set14inF;
CCommand::setOut[CCommand::i15_IN_T] = &MY_PCF8575::set15inF;
CCommand::setOut[CCommand::i16_IN_T] = &MY_PCF8575::set16inF;
CCommand::setOut[CCommand::i17_IN_T] = &MY_PCF8575::set17inF;
CCommand::setOut[CCommand::i18_IN_T] = &MY_PCF8575::set18inF;
CCommand::setOut[CCommand::i19_IN_T] = &MY_PCF8575::set19inF;
CCommand::setOut[CCommand::i1_IN_G] = &MY_PCF8575::set1inG;
CCommand::setOut[CCommand::i2_IN_G] = &MY_PCF8575::set2inG;
CCommand::setOut[CCommand::i3_IN_G] = &MY_PCF8575::set3inG;
CCommand::setOut[CCommand::i4_IN_G] = &MY_PCF8575::set4inG;
CCommand::setOut[CCommand::i13_IN_G] = &set13inG;
CCommand::setOut[CCommand::i14_IN_G] = &set14inG;
CCommand::setOut[CCommand::i15_IN_G] = &set15inG;
CCommand::setOut[CCommand::i16_IN_G] = &set16inG;
CCommand::setOut[CCommand::i17_IN_G] = &set17inG;
CCommand::setOut[CCommand::i18_IN_G] = &set18inG;
CCommand::setOut[CCommand::i19_IN_G] = &MY_PCF8575::set19inG;
CCommand::setOut[CCommand::iH_IN_1] = &MY_PCF8575::setHin1;
CCommand::setOut[CCommand::iH_IN_2] = &MY_PCF8575::setHin2;
CCommand::setOut[CCommand::iH_IN_3] = &MY_PCF8575::setHin3;
CCommand::setOut[CCommand::iH_IN_4] = &MY_PCF8575::setHin4;
CCommand::setOut[CCommand::iJ_IN_5] = &MY_PCF8575::setJin5;
CCommand::setOut[CCommand::iJ_IN_6] = &MY_PCF8575::setJin6;
CCommand::setOut[CCommand::iJ_IN_7] = &MY_PCF8575::setJin7;
CCommand::setOut[CCommand::iJ_IN_8] = &MY_PCF8575::setJin8;
CCommand::setOut[CCommand::iJ_IN_9] = &setJin9;
CCommand::setOut[CCommand::iJ_IN_10] = &setJin10;
CCommand::setOut[CCommand::iJ_IN_11] = &setJin11;
CCommand::setOut[CCommand::iJ_IN_12] = &setEmpty;
CCommand::setOut[CCommand::iJ_IN_13] = &setJin13;
CCommand::setOut[CCommand::iJ_IN_14] = &setJin14;
CCommand::setOut[CCommand::iJ_IN_15] = &setJin15;
CCommand::setOut[CCommand::iJ_IN_16] = &setJin16;
CCommand::setOut[CCommand::iJ_IN_17] = &setJin17;
CCommand::setOut[CCommand::iJ_IN_18] = &setJin18;
CCommand::setOut[CCommand::iJ_IN_19] = &setJin19;
CCommand::setOut[CCommand::i12_IN_K] = &MY_PCF8575::set12inK;
CCommand::setOut[CCommand::i20_IN_K] = &MY_PCF8575::set20inK;
CCommand::setOut[CCommand::i13_IN_K] = &MY_PCF8575::set13inK;
CCommand::setOut[CCommand::i14_IN_K] = &MY_PCF8575::set14inK;
CCommand::setOut[CCommand::i4_IN_L] = &MY_PCF8575::set4inL;
CCommand::setOut[CCommand::i6_IN_L] = &MY_PCF8575::set6inL;
CCommand::setOut[CCommand::i8_IN_L] = &MY_PCF8575::set8inL;
CCommand::setOut[CCommand::i9_IN_L] = &MY_PCF8575::set9inL;
CCommand::setOut[CCommand::i12_IN_L] = &MY_PCF8575::set12inL;
CCommand::setOut[CCommand::i20_IN_L] = &MY_PCF8575::set20inL;
CCommand::setOut[CCommand::i13_IN_R] = &MY_PCF8575::set13inR;
CCommand::setOut[CCommand::i14_IN_R] = &MY_PCF8575::set14inR;
CCommand::setOut[CCommand::iK_IN_12] = &MY_PCF8575::setKin12;
CCommand::setOut[CCommand::iK_IN_20] = &MY_PCF8575::setKin20;
CCommand::setOut[CCommand::iK_IN_13] = &MY_PCF8575::setKin13;
CCommand::setOut[CCommand::iK_IN_14] = &MY_PCF8575::setKin14;
CCommand::setOut[CCommand::iR_IN_13] = &MY_PCF8575::setRin13;
CCommand::setOut[CCommand::iR_IN_14] = &MY_PCF8575::setRin14;
CCommand::setOut[CCommand::i19_IN_M] = &MY_PCF8575::set19inM;
CCommand::setOut[CCommand::iM_IN_19] = &MY_PCF8575::setMin19;
CCommand::setOut[CCommand::iP_IN_12] = &setEmpty;
CCommand::setOut[CCommand::i1_IN_N] = &MY_PCF8575::set1inN;
CCommand::setOut[CCommand::iN_IN_1] = &MY_PCF8575::setNin1;

}
void printInputs()
{
  static unsigned long lastTXTime;
  if (millis() - lastTXTime > 4000) {
    lastTXTime = millis();
    Serial.print("Eingangsstati master >>>>");
    for (int i = 0; i < RX_SLAVE_BYTE_CNT; i++) {
      Serial.print(" | byte ");
      Serial.print(i);
      Serial.print("=0x");
      Serial.print(DI::rawInputsSlave1[i], HEX);
    }
    Serial.println();
    Serial.print("Eingangsstati slave2 >>>>");
    for (int i = 0; i < RX_SLAVE_BYTE_CNT; i++) {
      Serial.print(" | byte ");
      Serial.print(i);
      Serial.print("=0x");
      Serial.print(rawInputsSlave2[i], HEX);
    }
    Serial.println();
  }
}
// void printOutputs()
// {
//   static unsigned long lastTXTime;
//   if (millis() - lastTXTime > 10000) {
//     lastTXTime = millis();
//     Serial.println("Ausgangsstati <<<<<<<<<<<<<<<<<<<<<<");
//     for (int i = 0; i < TX_SLAVE_BYTE_CNT; i++) {
//       Serial.print("  byte ");
//       Serial.print(i);
//       Serial.print("=0x");
//       Serial.println(rawOutputsSlave2[i], HEX);
//     }
//   }
// }
void evalAndPrintLoopTime () {
  static unsigned long loopTimeStart = 0;
  static unsigned long loopDeltaArr[N_LOOP_AVG]; // 0...N_LOOP_AVG => N+1 werte!
  static unsigned long lastPrintMillis = 0;
  static int loopInsertIdx = 0;
  unsigned long long avgLoopTime = 0;
  loopDeltaArr[loopInsertIdx] = millis() - loopTimeStart;
  for (int i = 0; i < N_LOOP_AVG; i++) {
    avgLoopTime += loopDeltaArr[i];
  }
  avgLoopTime /= (N_LOOP_AVG+1);
  if (++loopInsertIdx >= N_LOOP_AVG) {
    loopInsertIdx = 0;
  }
  // zeit die zykluszeit auszugeben?
  if (millis() - lastPrintMillis > PRINT_LOOP_INTERVAL) {
    lastPrintMillis = millis();
    Serial.print("Zykluszeit: ");
    Serial.print(int16_t(avgLoopTime));
    Serial.println(" ms");
  }
  loopTimeStart = millis();
}

//=============================================================================

void setup()
{
  Serial.begin(9600);
  Serial.println(">>>>>>>>>>>>>>>>>>>>>>> Bahnhof Master <<<<<<<<<<<<<<<<<<<");
  MYLCD::setup();
  DI::setup();
  RXTX::setup();
  MY_PCF8575::setup();
  Wire.begin();
  //Wire.setWireTimeout(3000 /* us */, true /* reset_on_timeout */);
  Wire.setWireTimeout(0, false); // disable timeout. da vorher auf antwort von slave2 gewartet werden muss
  connectSetOutFunctions(); // ausgangssetzfunktionen mit command modul verknuepfen

  delay(3000);

}

//=============================================================================

void loop()
{
  static uint8_t wireTimeoutCnt;
  static bool wireErrRX, wireErrTX;
  static uint32_t oldRxMsgCnt = 0;
  uint32_t totalMsgCnt = 0;
  static uint32_t totalMsgCntOld = 0;
  static unsigned long msStart;
  unsigned long duration;
  int8_t ret;

  // evalAndPrintLoopTime();
  // MY_PCF8575::outputTest();
  // return;
  MYLCD::loop();
  RXTX::receiveData(rawInputsSlave2); // buffer leeren falls noetig
  DI::loop(); // timing nicht verzerren / eigene eingaenge debouncen

  /* Loop ablauf uebersicht
   * 10. ALLE AUSGAENGE AKTUALISIEREN
   * 20. ALLE REMOTE AUSGAENGE UEBERTRAGEN
   * 30. ALLE REMOTE EINGAENGE LESEN (TASTER FUER AUFTRAEGE, GLEIS BELEGT MELDUNGEN)
   * 40. ALLE EINGAENGE AKTUALISIEREN
   * 50. NEUE AUFTRAEGE AUSWERTEN (neuer auftrag vorhanden, gueltig?)
   * 60. LAUFENDE AUFTRAEGE UEBERWACHEN
   */
  static uint8_t loopState;
  static uint8_t loopStateNext;
  static unsigned long loopStateMs;
  switch (loopState) {
    case 0: // init
      loopStateNext = 10;
      break;
    //===========================================================================
    case 10: // ALLE AUSGAENGE AKTUALISIEREN
        // => von commandos nach rawOutputs mappen
        // funktionen zum setzen der ausgaenge werden als funktionspointer an das command-modul gegeben. damit koennen die ausgaenge direkt gesetzt werden
        // rawOutputsMaster
        // rawOutputsSlave2
        loopStateNext = 20;
        break;
    //===========================================================================
    case 20: // ALLE REMOTE AUSGAENGE UEBERTRAGEN
        RXTX::sendData(rawOutputsSlave2, TX_SLAVE_BYTE_CNT);
        loopStateNext = 30;
        break;
    //===========================================================================
    case 30: // ALLE (REMOTE) EINGAENGE LESEN (TASTER FUER AUFTRAEGE, GLEIS BELEGT MELDUNGEN)
        oldRxMsgCnt = RXTX::getTotalRxMsgCnt();
        RXTX::sendRequestInputs(); // zunaechst eingaenge von slave2 anfordern
        msStart = millis();
        loopStateNext = 35;
        break;
    case 35: // antwort abwarten (dauert ca. 20ms)
        // vollstaendiges empfangen ueber nachrichtenzaehler auswerten
        // alternativ in rxtx modul das abfragen auf ETX ermoeglichen ob eine nachricht komplett empfangen wurde
        totalMsgCnt = RXTX::getTotalRxMsgCnt();
        duration = millis() - msStart;
        if (RXTX::getTotalRxMsgCnt() > oldRxMsgCnt) { 
          oldRxMsgCnt = totalMsgCnt;
          // togglen geht nicht weil mit eingang belegt !!!
          // if (totalMsgCnt % 2) { // led bei jeder 2. nachricht togglen => ja er lebt noch
          //   digitalWrite(LED_BUILTIN, HIGH);
          // } else {
          //   digitalWrite(LED_BUILTIN, LOW);
          // }
          // Serial.print("Dauer [ms]: ");
          // Serial.print(duration);
          // Serial.print(". Anzahl Nachrichten empfangen gesamt = ");
          // Serial.println(totalMsgCnt);
          loopStateNext = 40;
        } else if (duration > 100) { 
          Serial.println("timeout!!! keine antwort von slave2");
          loopStateNext = 40;
        }
        break;
    //===========================================================================
    case 40: // ALLE EINGAENGE AKTUALISIEREN
        // eigene eingaenge entprellen und einlesen wird eh in DI::loop(); erledigt, also hier nichts mehr zu tun
        DI::loop();
        loopStateNext = 42;
        break;
    case 42: //Befehlseingaenge mappen von rawInputs -> command
        CCommand::setCmdInput1_32( CCommand:: c1, DI::rawInputsSlave1[3] & (1<<6) );
        CCommand::setCmdInput1_32( CCommand:: c2, DI::rawInputsSlave1[3] & (1<<7) );
        CCommand::setCmdInput1_32( CCommand:: c3, DI::rawInputsSlave1[4] & (1<<0) );
        CCommand::setCmdInput1_32( CCommand:: c4, DI::rawInputsSlave1[4] & (1<<1) );
        CCommand::setCmdInput1_32( CCommand:: c5, DI::rawInputsSlave1[4] & (1<<2) );
        CCommand::setCmdInput1_32( CCommand:: c6, DI::rawInputsSlave1[4] & (1<<3) );
        CCommand::setCmdInput1_32( CCommand:: c7, DI::rawInputsSlave1[4] & (1<<4) );
        CCommand::setCmdInput1_32( CCommand:: c8, DI::rawInputsSlave1[4] & (1<<5) );
        CCommand::setCmdInput1_32( CCommand:: c9, DI::rawInputsSlave1[4] & (1<<6) );
        CCommand::setCmdInput1_32( CCommand::c10, DI::rawInputsSlave1[4] & (1<<7) );
        CCommand::setCmdInput1_32( CCommand::c11, DI::rawInputsSlave1[5] & (1<<0) );
        CCommand::setCmdInput1_32( CCommand::c12, DI::rawInputsSlave1[7] & (1<<1) );
        CCommand::setCmdInput1_32( CCommand::c13, DI::rawInputsSlave1[5] & (1<<2) );
        CCommand::setCmdInput1_32( CCommand::c14, DI::rawInputsSlave1[5] & (1<<3) );
        CCommand::setCmdInput1_32( CCommand::c15, DI::rawInputsSlave1[5] & (1<<4) );
        CCommand::setCmdInput1_32( CCommand::c16, DI::rawInputsSlave1[5] & (1<<5) );
        CCommand::setCmdInput1_32( CCommand::c17, DI::rawInputsSlave1[2] & (1<<6) );
        CCommand::setCmdInput1_32( CCommand::c18, DI::rawInputsSlave1[2] & (1<<7) );
        CCommand::setCmdInput1_32( CCommand::c19, DI::rawInputsSlave1[2] & (1<<4) );
        CCommand::setCmdInput1_32( CCommand::c20, DI::rawInputsSlave1[5] & (1<<1) );

        CCommand::setCmdInputA_Z( CCommand::cA, rawInputsSlave2[0] & (1<<1) );
        CCommand::setCmdInputA_Z( CCommand::cB, rawInputsSlave2[0] & (1<<0) );
        CCommand::setCmdInputA_Z( CCommand::cC, rawInputsSlave2[0] & (1<<3) );
        CCommand::setCmdInputA_Z( CCommand::cD, rawInputsSlave2[0] & (1<<2) );
        CCommand::setCmdInputA_Z( CCommand::cF, rawInputsSlave2[3] & (1<<1) );
        CCommand::setCmdInputA_Z( CCommand::cG, rawInputsSlave2[3] & (1<<0) );
        CCommand::setCmdInputA_Z( CCommand::cH, rawInputsSlave2[2] & (1<<7) );
        CCommand::setCmdInputA_Z( CCommand::cJ, rawInputsSlave2[2] & (1<<6) );
        CCommand::setCmdInputA_Z( CCommand::cK, rawInputsSlave2[2] & (1<<4) );
        CCommand::setCmdInputA_Z( CCommand::cL, rawInputsSlave2[2] & (1<<5) );
        CCommand::setCmdInputA_Z( CCommand::cM, rawInputsSlave2[2] & (1<<3) );
        CCommand::setCmdInputA_Z( CCommand::cN, DI::rawInputsSlave1[3] & (1<<5) ); 
        CCommand::setCmdInputA_Z( CCommand::cR, rawInputsSlave2[1] & (1<<2) );
        CCommand::setCmdInputA_Z( CCommand::cS, 0/*rawInputsSlave2[4] & (1<<0) */); // fehlt ???
        CCommand::setCmdInputA_Z( CCommand::cT, 0/*rawInputsSlave2[4] & (1<<1) */); // fehlt ???
        
        //4.2 Gleisstati mappen von rawInputs -> railStatus
        CCommand::setRailInput1li  (rawInputsSlave2[3] & (1<<2));
        CCommand::setRailInput1re  (DI::rawInputsSlave1[5] & (1<<6));
        CCommand::setRailInput1bel (DI::rawInputsSlave1[2] & (1<<2));
        CCommand::setRailInput2li  (rawInputsSlave2[3] & (1<<3));
        CCommand::setRailInput2re  (DI::rawInputsSlave1[5] & (1<<7));
        CCommand::setRailInput2bel (DI::rawInputsSlave1[2] & (1<<3));
        CCommand::setRailInput3li  (rawInputsSlave2[3] & (1<<4));
        CCommand::setRailInput3re  (DI::rawInputsSlave1[6] & (1<<0));
        CCommand::setRailInput3bel (DI::rawInputsSlave1[2] & (1<<0));
        CCommand::setRailInput4li  (rawInputsSlave2[3] & (1<<5));
        CCommand::setRailInput4re  (DI::rawInputsSlave1[6] & (1<<1));
        CCommand::setRailInput4bel (DI::rawInputsSlave1[2] & (1<<1));
        CCommand::setRailInput5li  (rawInputsSlave2[3] & (1<<6));
        CCommand::setRailInput5re  (DI::rawInputsSlave1[6] & (1<<2));
        CCommand::setRailInput5bel (DI::rawInputsSlave1[1] & (1<<6));
        CCommand::setRailInput6li  (rawInputsSlave2[3] & (1<<7));
        CCommand::setRailInput6re  (DI::rawInputsSlave1[6] & (1<<3));
        CCommand::setRailInput6bel (DI::rawInputsSlave1[1] & (1<<7));
        CCommand::setRailInput7li  (rawInputsSlave2[4] & (1<<0));
        CCommand::setRailInput7re  (DI::rawInputsSlave1[6] & (1<<4));
        CCommand::setRailInput7bel (DI::rawInputsSlave1[1] & (1<<4));
        CCommand::setRailInput8li  (rawInputsSlave2[4] & (1<<1));
        CCommand::setRailInput8re  (DI::rawInputsSlave1[6] & (1<<6));
        CCommand::setRailInput8bel (DI::rawInputsSlave1[1] & (1<<5));
        CCommand::setRailInput9li  (rawInputsSlave2[4] & (1<<2));
        CCommand::setRailInput9re  (DI::rawInputsSlave1[6] & (1<<6));
        CCommand::setRailInput9bel (DI::rawInputsSlave1[1] & (1<<2));
        CCommand::setRailInput10li (rawInputsSlave2[4] & (1<<3));
        CCommand::setRailInput10re (DI::rawInputsSlave1[6] & (1<<7));
        CCommand::setRailInput10bel(DI::rawInputsSlave1[1] & (1<<3));
        CCommand::setRailInput11li (rawInputsSlave2[4] & (1<<4));
        CCommand::setRailInput11re (DI::rawInputsSlave1[7] & (1<<0));
        CCommand::setRailInput11bel(DI::rawInputsSlave1[1] & (1<<0));
        CCommand::setRailInput12li (rawInputsSlave2[4] & (1<<5));
        CCommand::setRailInput12re (DI::rawInputsSlave1[7] & (1<<1));
        CCommand::setRailInput12bel(0/*DI::rawInputsSlave1[1] & (1<<1)*/);
        CCommand::setRailInput13li (rawInputsSlave2[4] & (1<<6));
        CCommand::setRailInput13re (DI::rawInputsSlave1[7] & (1<<2));
        CCommand::setRailInput13bel(DI::rawInputsSlave1[0] & (1<<6));
        CCommand::setRailInput14li (rawInputsSlave2[4] & (1<<7));
        CCommand::setRailInput14re (DI::rawInputsSlave1[7] & (1<<3));
        CCommand::setRailInput14bel(DI::rawInputsSlave1[0] & (1<<7));
        CCommand::setRailInput15li (rawInputsSlave2[0] & (1<<4));
        CCommand::setRailInput15re (DI::rawInputsSlave1[3] & (1<<0));
        CCommand::setRailInput15bel(DI::rawInputsSlave1[0] & (1<<4));
        CCommand::setRailInput16li (rawInputsSlave2[0] & (1<<5));
        CCommand::setRailInput16re (DI::rawInputsSlave1[3] & (1<<1));
        CCommand::setRailInput16bel(DI::rawInputsSlave1[0] & (1<<5));
        CCommand::setRailInput17li (rawInputsSlave2[0] & (1<<6));
        CCommand::setRailInput17re (DI::rawInputsSlave1[3] & (1<<2));
        CCommand::setRailInput17bel(DI::rawInputsSlave1[0] & (1<<2));
        CCommand::setRailInput18li (rawInputsSlave2[0] & (1<<7));
        CCommand::setRailInput18re (DI::rawInputsSlave1[3] & (1<<3));
        CCommand::setRailInput18bel(DI::rawInputsSlave1[0] & (1<<3));
        CCommand::setRailInput19li (rawInputsSlave2[1] & (1<<0));
        CCommand::setRailInput19re (DI::rawInputsSlave1[3] & (1<<3));
        CCommand::setRailInput19bel(DI::rawInputsSlave1[0] & (1<<0));
        // spezial
        // CCommand::setRailInput20li (rawInputsSlave1[0] & (1<<0));
        // CCommand::setRailInput20re (rawInputsSlave1[0] & (1<<1));
        // CCommand::setRailInput20bel(rawInputsSlave1[0] & (1<<2));
        
        CCommand::setRailInputAbel(rawInputsSlave2[1] & (1<<5));
        CCommand::setRailInputKre (rawInputsSlave2[1] & (1<<1));
        CCommand::setRailInputBbel(rawInputsSlave2[1] & (1<<4));
        CCommand::setRailInputKbel(rawInputsSlave2[1] & (1<<3));
        CCommand::setRailInputLbel(rawInputsSlave2[1] & (1<<7));
        CCommand::setRailInputGbel(rawInputsSlave2[2] & (1<<2));
        CCommand::setRailInputFbel(rawInputsSlave2[4] & (1<<5));
        CCommand::setRailInputNbel(rawInputsSlave2[1] & (1<<6));
        CCommand::setRailInputTbel(rawInputsSlave2[2] & (1<<1));
        loopStateNext = 50;
        break;

    //===========================================================================
    case 50: // NEUE AUFTRAEGE AUSWERTEN (neuer auftrag vorhanden, gueltig?)

      // befehlstasten gedrueckt ?
      CCommand::updateSrcTarget(); 
      if (CCommand::curSrc != CCommand::oldSrc) {
        Serial.print("Neue Quelle: ");
        Serial.print(CCommand::curSrc);
        Serial.print(". alt: ");
        Serial.println(CCommand::oldSrc);
      }
      if (CCommand::curTarget != CCommand::oldTarget) {
        Serial.print("Neues Ziel: ");
        Serial.print(CCommand::curTarget);
        Serial.print(". alt: ");
        Serial.println(CCommand::oldTarget);
      }
      
      // befehl ueberpruefen
      ret = CCommand::checkAndActivateNewCommand();
      switch (ret) {
        case 0: // kein neuer noetig
        break;
        case 1:
          Serial.println("auftrag ok");
        break;
        case -1:
          Serial.println("ungueltig");
        break;
        case -2:
          Serial.println("auftragsspeicher voll");
        break;
        case -3:
          Serial.println("gleis belegt");
        break;
        case -4:
          Serial.println("blockiert durch bestehenden auftrag");
        break;
      }
      loopStateNext = 60;
      break;
    //===========================================================================
    case 60: // LAUFENDE AUFTRAEGE UEBERWACHEN
      CCommand::checkAndFinishRunningCommand();
      loopStateNext = 10;
      break;
    case 255: // uebergangszustand warten bis loopStateNext aktiv wird

    break;
  }
  // neuen zustand angefordert ?
  if (loopState != loopStateNext) {
    if (loopState != 255) {
      loopState = 255;
      loopStateMs = millis();
    } 
    // wenn (kuenstliche) 
    // verzoegerungszeit abgelaufen dann naechsten zustand aktivieren
    else if (millis() - loopStateMs > 50) { 
      loopState = loopStateNext;
      // Serial.print("loopstate: ");
      // Serial.println(loopState);
    }
  }
  //===========================================================================
  // 
  //===========================================================================


  // diagnoseausgaben alle 10s
  static unsigned long lastDiagTime;
  if (millis() - lastDiagTime > 10000) {
    lastDiagTime = millis();
    // Serial.println("Diag:----------------");
    // // anzahl auftraege ausgeben
    Serial.print("> Anzahl Auftraege: ");
    Serial.println(CCommand::getActiveCmdCount());

    Serial.print("> Aktive: ");
    for (int i = 0; i < CCommand::N_COMMANDS; i++) {
      if (CCommand::activeCommands[i].active) {
        Serial.print("[");
        Serial.print(i);
        Serial.print("]:");
        Serial.print(CCommand::activeCommands[i].src);
        Serial.print(" -> ");
        Serial.print(CCommand::activeCommands[i].target);
        Serial.print("(");
        Serial.print(MYLCD::railCombiEnum2Str(CCommand::activeCommands[i].railCombi)); 
        Serial.print(") | ");
      }
    }
    Serial.println();
    
    Serial.print("cmdInputs1_32: ");
    Serial.print(CCommand::cmdInputs1_32, HEX);

    Serial.print(" | cmdInputsA_Z: ");
    Serial.print(CCommand::cmdInputsA_Z, HEX);

    Serial.print(" | curSrc: ");
    Serial.print(CCommand::curSrc);
    
    Serial.print(" | curTarget: ");
    Serial.println(CCommand::curTarget);

  }
  printInputs();
}