/**
 * @mainpage
 * slave 2 der bahnhof steuerung fuer diethelm.
 *
 * Aufgaben slave2
 * ===============
 *   - an slave2 angeschlossene eingaenge debouncen und an slave1 schicken
 *   - an slave2 angeschlossene ausgaenge gemaess vom slave1 empfangener
 *     befehle setzen
 * 
 * Kommunikation mit Slave1 ueber Serial1
 *   - Ausgaenge von Slave1 empfangen und ausgeben
 *   - Eingaenge an Slave1 schicken
 * 
 * Arduino / VS code einstellungen:
 * ================================
 * Programmer = arduino:avrispmkii
 * Board      = Arduino Mega
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
 * 8-fach Relais-Module
 * ====================
 * INx = false => relais AN
 * INx = true  => relais AUS
 * JD-VCC, GND = Last 5V versorgung fuer relais => 2. netzteil
 * VCC, GND = Steuerspannung
 */
#include <Wire.h>
#include <ezButton.h> // https://github.com/ArduinoGetStarted/button

#include "pcf8575Handling.h"
#include "rxtx.h"

#define RX_SLAVE_BYTE_CNT 10 // pauschal 10 bytes je slaves lesen
#define TX_SLAVE_BYTE_CNT 10 // pauschal 10 bytes je slaves schreiben

uint8_t rawInputsSlave2[RX_SLAVE_BYTE_CNT] = {0}; // 1=aktiv/gedrueckt, 0=inaktiv/nicht gedrueckt
uint8_t rawOutputsSlave2[TX_SLAVE_BYTE_CNT]; // werden von slave 1 empfangen

ezButton buttonArray[] = { // aktiviert automatisch pullup
  // rawInputsSlave2 byte 0
  ezButton(28), // cB
  ezButton(29), // cA
  ezButton(26), // cD
  ezButton(27), // cC
  ezButton(68), // 15li
  ezButton(69), // 16li
  ezButton(32), // 17li
  ezButton(33), // 18li

  // rawInputsSlave2 byte1
  ezButton(34), // 19li
  ezButton(35), // Kre
  ezButton(36), // cR
  ezButton(37), // Kbel
  ezButton(38), // Bbel
  ezButton(39), // Abel
  ezButton(40), // Nbel
  ezButton(41), // Lbel

  // rawInputsSlave2 byte2
  ezButton(42), // Gbel2
  ezButton(43), // Fbel
  ezButton(44), // Gbel1
  ezButton(45), // cM
  ezButton(46), // cL
  ezButton(47), // cK
  ezButton(22), // cJ???
  ezButton(23), // cH

  // rawInputsSlave2 byte3
  ezButton(24), // cG
  ezButton(25), // cF
  ezButton(54), // 1li
  ezButton(55), // 2li
  ezButton(56), // 3li
  ezButton(57), // 4li
  ezButton(58), // 5li
  ezButton(59), // 6li

  // rawInputsSlave2 byte4
  ezButton(60), // 7li
  ezButton(61), // 8li
  ezButton(62), // 9li
  ezButton(63), // 10li
  ezButton(64), // 11li
  ezButton(65), // 12li
  ezButton(66), // 13li
  ezButton(67) // 14li
};
uint8_t ezBtnArrLen = sizeof(buttonArray) / sizeof(ezButton);

void setup()
{
  Serial.begin(9600);
  Serial.print("Diethelms Bahnhofsteuerung: Slave 2. >>> kompiliert am ");
  Serial.print(__DATE__);
  Serial.print(". ");
  Serial.println(__TIME__);
  RXTX::setup();
  pinMode(LED_BUILTIN, OUTPUT);
  MY_PCF8575::setup();
  for (byte i = 0; i < ezBtnArrLen; i++) {
    buttonArray[i].setDebounceTime(50); // [ms]
  }
  delay(500);
}

/**
 * @param inputByte call by reference
 * @param bitpos (1<<3)
 * @param val wird invertiert wg LOW aktiv (eingaenge werden extern nach masse gezogen)
 */
void setInput(uint8_t &inputByte, uint8_t bitpos, int val) {
  if (val) {
    inputByte &= ~(bitpos);
  } else {
    inputByte |= (bitpos);
  }
}

void printInputs()
{
  static unsigned long lastTXTime;
  if (millis() - lastTXTime > 10000) {
    lastTXTime = millis();
    Serial.println("Eingangsstati >>>>>>>>>>>>>>>>>>>>");
    for (int i = 0; i < RX_SLAVE_BYTE_CNT; i++) {
      Serial.print("  byte ");
      Serial.print(i);
      Serial.print("=0x");
      Serial.println(rawInputsSlave2[i], HEX);
    }
  }
}
void printOutputs()
{
  static unsigned long lastTXTime;
  if (millis() - lastTXTime > 10000) {
    lastTXTime = millis();
    Serial.println("Ausgangsstati <<<<<<<<<<<<<<<<<<<<<<");
    for (int i = 0; i < TX_SLAVE_BYTE_CNT; i++) {
      Serial.print("  byte ");
      Serial.print(i);
      Serial.print("=0x");
      Serial.println(rawOutputsSlave2[i], HEX);
    }
  }
}

void loop()
{
  // MY_PCF8575::outputTest();
  // ==========================================================================
  // eigene eingaenge entprellen und einlesen
  // ==========================================================================
  for (byte i = 0; i < ezBtnArrLen; i++) {
    buttonArray[i].loop();
  }
  // eingaenge in transferbereich schreiben
  setInput(rawInputsSlave2[0],(1<<0),buttonArray[0].getState());
  setInput(rawInputsSlave2[0],(1<<1),buttonArray[1].getState());
  setInput(rawInputsSlave2[0],(1<<2),buttonArray[2].getState());
  setInput(rawInputsSlave2[0],(1<<3),buttonArray[3].getState());
  setInput(rawInputsSlave2[0],(1<<4),buttonArray[4].getState());
  setInput(rawInputsSlave2[0],(1<<5),buttonArray[5].getState());
  setInput(rawInputsSlave2[0],(1<<6),buttonArray[6].getState());
  setInput(rawInputsSlave2[0],(1<<7),buttonArray[7].getState());
  setInput(rawInputsSlave2[1],(1<<0),buttonArray[8].getState());
  setInput(rawInputsSlave2[1],(1<<1),buttonArray[9].getState());
  setInput(rawInputsSlave2[1],(1<<2),buttonArray[10].getState());
  setInput(rawInputsSlave2[1],(1<<3),buttonArray[11].getState());
  setInput(rawInputsSlave2[1],(1<<4),buttonArray[12].getState());
  setInput(rawInputsSlave2[1],(1<<5),buttonArray[13].getState());
  setInput(rawInputsSlave2[1],(1<<6),buttonArray[14].getState());
  setInput(rawInputsSlave2[1],(1<<7),buttonArray[15].getState());
  setInput(rawInputsSlave2[2],(1<<0),buttonArray[16].getState());
  setInput(rawInputsSlave2[2],(1<<1),buttonArray[17].getState());
  setInput(rawInputsSlave2[2],(1<<2),buttonArray[18].getState());
  setInput(rawInputsSlave2[2],(1<<3),buttonArray[19].getState());
  setInput(rawInputsSlave2[2],(1<<4),buttonArray[20].getState());
  setInput(rawInputsSlave2[2],(1<<5),buttonArray[21].getState());
  setInput(rawInputsSlave2[2],(1<<6),buttonArray[22].getState());
  setInput(rawInputsSlave2[2],(1<<7),buttonArray[23].getState());
  setInput(rawInputsSlave2[3],(1<<0),buttonArray[24].getState());
  setInput(rawInputsSlave2[3],(1<<1),buttonArray[25].getState());
  setInput(rawInputsSlave2[3],(1<<2),buttonArray[26].getState());
  setInput(rawInputsSlave2[3],(1<<3),buttonArray[27].getState());
  setInput(rawInputsSlave2[3],(1<<4),buttonArray[28].getState());
  setInput(rawInputsSlave2[3],(1<<5),buttonArray[29].getState());
  setInput(rawInputsSlave2[3],(1<<6),buttonArray[30].getState());
  setInput(rawInputsSlave2[3],(1<<7),buttonArray[31].getState());
  setInput(rawInputsSlave2[4],(1<<0),buttonArray[32].getState());
  setInput(rawInputsSlave2[4],(1<<1),buttonArray[33].getState());
  setInput(rawInputsSlave2[4],(1<<2),buttonArray[34].getState());
  setInput(rawInputsSlave2[4],(1<<3),buttonArray[35].getState());
  setInput(rawInputsSlave2[4],(1<<4),buttonArray[36].getState());
  setInput(rawInputsSlave2[4],(1<<5),buttonArray[37].getState());
  setInput(rawInputsSlave2[4],(1<<6),buttonArray[38].getState());
  setInput(rawInputsSlave2[4],(1<<7),buttonArray[39].getState());
  
  // ==========================================================================
  // ausgaenge von slave1 empfangen
  // ==========================================================================
  RXTX::receiveData(rawOutputsSlave2);

  // ==========================================================================
  // eingaenge an slave1 senden
  // ==========================================================================
  switch (RXTX::getReceivedCode() ) {
    case RXTX::E_CODES::NONE: // nichts zu tun, nur der vollstaendigkeit halber
      break;
    // falls eingaenge angefordert wurden
    case RXTX::E_CODES::REQ_INPUTS:
      // Serial.println("eingaenge angefordert");
      RXTX::sendData(rawInputsSlave2, RX_SLAVE_BYTE_CNT);
      break;
  }

  uint32_t totalMsgCnt =  RXTX::getTotalRxMsgCnt();
  static uint32_t totalMsgCntOld = 0;
  if (totalMsgCnt != totalMsgCntOld) {
    totalMsgCntOld = totalMsgCnt;
    if (totalMsgCnt % 2) { // led bei jeder 2. nachricht togglen => ja er lebt noch
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      digitalWrite(LED_BUILTIN, LOW);
    }
    // Serial.print("Anzahl Nachrichten empfangen gesamt = ");
    // Serial.println(totalMsgCnt);
  }

  // ==========================================================================
  // empfangene ausgaenge setzen
  // ==========================================================================
  // ausgangsbyte 0 => kanal 0-7 pcf an 0x20
  MY_PCF8575::setDin18(rawOutputsSlave2[0] & (1<<0));
  MY_PCF8575::setDin19(rawOutputsSlave2[0] & (1<<1));
  MY_PCF8575::setCin1 (rawOutputsSlave2[0] & (1<<2));
  MY_PCF8575::setCin2 (rawOutputsSlave2[0] & (1<<3));
  MY_PCF8575::setCin3 (rawOutputsSlave2[0] & (1<<4));
  MY_PCF8575::setCin4 (rawOutputsSlave2[0] & (1<<5));
  MY_PCF8575::setCin5 (rawOutputsSlave2[0] & (1<<6));
  MY_PCF8575::setCin6 (rawOutputsSlave2[0] & (1<<7));

  // ausgangsbyte 1 => kanal 8-15 pcf an 0x20
  MY_PCF8575::set14inF(rawOutputsSlave2[1] & (1<<0));
  MY_PCF8575::set14inB(rawOutputsSlave2[1] & (1<<1));
  MY_PCF8575::set14inA(rawOutputsSlave2[1] & (1<<2));
  MY_PCF8575::set13inF(rawOutputsSlave2[1] & (1<<3));
  MY_PCF8575::set13inB(rawOutputsSlave2[1] & (1<<4));
  MY_PCF8575::set13inA(rawOutputsSlave2[1] & (1<<5));
  MY_PCF8575::set11inF(rawOutputsSlave2[1] & (1<<6) );
  MY_PCF8575::set11inB(rawOutputsSlave2[1] & (1<<7) );

  // ausgangsbyte 2 => kanal 0-7 pcf an 0x21
  MY_PCF8575::setRes32(rawOutputsSlave2[2] & (1<<0));
  MY_PCF8575::setRes33(rawOutputsSlave2[2] & (1<<1));
  MY_PCF8575::setRes34(rawOutputsSlave2[2] & (1<<2));
  MY_PCF8575::setRes35(rawOutputsSlave2[2] & (1<<3));
  MY_PCF8575::setRes36(rawOutputsSlave2[2] & (1<<4));
  MY_PCF8575::setRes37(rawOutputsSlave2[2] & (1<<5));
  MY_PCF8575::setRes38(rawOutputsSlave2[2] & (1<<6));
  MY_PCF8575::setRes39(rawOutputsSlave2[2] & (1<<7));

  // ausgangsbyte 3 => kanal 8-15 pcf an 0x21
  MY_PCF8575::set18inG(rawOutputsSlave2[3] & (1<<0));
  MY_PCF8575::set17inG(rawOutputsSlave2[3] & (1<<1));
  MY_PCF8575::set16inG(rawOutputsSlave2[3] & (1<<2));
  MY_PCF8575::set15inG(rawOutputsSlave2[3] & (1<<3));
  MY_PCF8575::set14inG(rawOutputsSlave2[3] & (1<<4));
  MY_PCF8575::set13inG(rawOutputsSlave2[3] & (1<<5));
  MY_PCF8575::setJin19(rawOutputsSlave2[3] & (1<<6));
  MY_PCF8575::setJin18(rawOutputsSlave2[3] & (1<<7));
  
    // ausgangsbyte 4 => kanal 0-7 pcf an 0x21
  MY_PCF8575::setRes24(rawOutputsSlave2[4] & (1<<0));
  MY_PCF8575::setRes25(rawOutputsSlave2[4] & (1<<1));
  MY_PCF8575::setRes26(rawOutputsSlave2[4] & (1<<2));
  MY_PCF8575::setRes27(rawOutputsSlave2[4] & (1<<3));
  MY_PCF8575::setRes28(rawOutputsSlave2[4] & (1<<4));
  MY_PCF8575::setRes29(rawOutputsSlave2[4] & (1<<5));
  MY_PCF8575::setRes30(rawOutputsSlave2[4] & (1<<6));
  MY_PCF8575::setRes31(rawOutputsSlave2[4] & (1<<7));

  // ausgangsbyte 5 => kanal 8-15 pcf an 0x21
  MY_PCF8575::setJin17(rawOutputsSlave2[5] & (1<<0));
  MY_PCF8575::setJin16(rawOutputsSlave2[5] & (1<<1));
  MY_PCF8575::setJin15(rawOutputsSlave2[5] & (1<<2));
  MY_PCF8575::setJin14(rawOutputsSlave2[5] & (1<<3));
  MY_PCF8575::setJin13(rawOutputsSlave2[5] & (1<<4));
  MY_PCF8575::setJin11(rawOutputsSlave2[5] & (1<<5));
  MY_PCF8575::setJin10(rawOutputsSlave2[5] & (1<<6));
  MY_PCF8575::setJin9(rawOutputsSlave2[5] & (1<<7));
  
  // printInputs();
  // printOutputs();


}