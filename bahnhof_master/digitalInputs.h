#ifndef DIGITALINPUTS_H
#define DIGITALINPUTS_H

#include <ezButton.h> // https://github.com/ArduinoGetStarted/button

namespace DI {

uint8_t rawInputsSlave1[10]; // 1=aktiv/gedrueckt, 0=inaktiv/nicht gedrueckt


ezButton buttonArray[] = {
  // rawInputsSlave1 byte0
  ezButton(52), // 19bel
  ezButton(53), // Lfrei
  ezButton(50), // 17bel
  ezButton(51), // 18bel
  ezButton(16), // 15bel
  ezButton(17), // 16bel
  ezButton(14), // 13bel
  ezButton(15), // 14bel

  // rawInputsSlave1 byte1
  ezButton(12), // 11bel
  ezButton(13), // 12bel
  ezButton(10), // 9bel
  ezButton(11), // 10bel
  ezButton( 8), // 7bel
  ezButton( 9), // 8bel
  ezButton( 6), // 5bel
  ezButton( 7), // 6bel

  // rawInputsSlave1 byte2
  ezButton( 4), // 3bel
  ezButton( 5), // 4bel
  ezButton( 2), // 1bel
  ezButton( 3), // 2bel
  ezButton(28), // c19
  ezButton(29), // NC
  ezButton(26), // c17
  ezButton(27), // c18

  // rawInputsSlave1 byte3
  ezButton(68), // 15re
  ezButton(69), // 16re
  ezButton(32), // 17re
  ezButton(33), // 18re
  ezButton(34), // 19re
  ezButton(35), // Nfrei
  ezButton(36), // c1
  ezButton(37), // c2

  // rawInputsSlave1 byte4
  ezButton(38), // c3
  ezButton(39), // c4
  ezButton(40), // c5
  ezButton(41), // c6
  ezButton(42), // c7
  ezButton(43), // c8
  ezButton(44), // c9
  ezButton(45), // c10

  // rawInputsSlave1 byte5
  ezButton(46), // c11
  ezButton(47), // c12
  ezButton(22), // c13
  ezButton(23), // c14
  ezButton(24), // c15
  ezButton(25), // c16
  ezButton(54), // 1re
  ezButton(55), // 2re

  // rawInputsSlave1 byte6
  ezButton(56), // 3re
  ezButton(57), // 4re
  ezButton(58), // 5re
  ezButton(59), // 6re
  ezButton(60), // 7re
  ezButton(61), // 8re
  ezButton(62), // 9re
  ezButton(63), // 10re

  // rawInputsSlave1 byte7
  ezButton(64), // 11re
  ezButton(65), // 12re
  ezButton(66), // 13re
  ezButton(67) // 14re
};
uint8_t ezBtnArrLen = sizeof(buttonArray) / sizeof(ezButton);

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

void setup() 
{
    for (byte i = 0; i < ezBtnArrLen; i++) {
        buttonArray[i].setDebounceTime(50); // [ms]
    }
}

void loop() 
{
    // ==========================================================================
    // eigene eingaenge entprellen und einlesen
    // ==========================================================================
    for (byte i = 0; i < ezBtnArrLen; i++) {
        buttonArray[i].loop();
    }
      // eingaenge in transferbereich schreiben
  setInput(rawInputsSlave1[0],(1<<0),buttonArray[0].getState());
  setInput(rawInputsSlave1[0],(1<<1),buttonArray[1].getState());
  setInput(rawInputsSlave1[0],(1<<2),buttonArray[2].getState());
  setInput(rawInputsSlave1[0],(1<<3),buttonArray[3].getState());
  setInput(rawInputsSlave1[0],(1<<4),buttonArray[4].getState());
  setInput(rawInputsSlave1[0],(1<<5),buttonArray[5].getState());
  setInput(rawInputsSlave1[0],(1<<6),buttonArray[6].getState());
  setInput(rawInputsSlave1[0],(1<<7),buttonArray[7].getState());
  setInput(rawInputsSlave1[1],(1<<0),buttonArray[8].getState());
  setInput(rawInputsSlave1[1],(1<<1),buttonArray[9].getState());
  setInput(rawInputsSlave1[1],(1<<2),buttonArray[10].getState());
  setInput(rawInputsSlave1[1],(1<<3),buttonArray[11].getState());
  setInput(rawInputsSlave1[1],(1<<4),buttonArray[12].getState());
  setInput(rawInputsSlave1[1],(1<<5),buttonArray[13].getState());
  setInput(rawInputsSlave1[1],(1<<6),buttonArray[14].getState());
  setInput(rawInputsSlave1[1],(1<<7),buttonArray[15].getState());
  setInput(rawInputsSlave1[2],(1<<0),buttonArray[16].getState());
  setInput(rawInputsSlave1[2],(1<<1),buttonArray[17].getState());
  setInput(rawInputsSlave1[2],(1<<2),buttonArray[18].getState());
  setInput(rawInputsSlave1[2],(1<<3),buttonArray[19].getState());
  setInput(rawInputsSlave1[2],(1<<4),buttonArray[20].getState());
  setInput(rawInputsSlave1[2],(1<<5),buttonArray[21].getState());
  setInput(rawInputsSlave1[2],(1<<6),buttonArray[22].getState());
  setInput(rawInputsSlave1[2],(1<<7),buttonArray[23].getState());
  setInput(rawInputsSlave1[3],(1<<0),buttonArray[24].getState());
  setInput(rawInputsSlave1[3],(1<<1),buttonArray[25].getState());
  setInput(rawInputsSlave1[3],(1<<2),buttonArray[26].getState());
  setInput(rawInputsSlave1[3],(1<<3),buttonArray[27].getState());
  setInput(rawInputsSlave1[3],(1<<4),buttonArray[28].getState());
  setInput(rawInputsSlave1[3],(1<<5),buttonArray[29].getState());
  setInput(rawInputsSlave1[3],(1<<6),buttonArray[30].getState());
  setInput(rawInputsSlave1[3],(1<<7),buttonArray[31].getState());
  setInput(rawInputsSlave1[4],(1<<0),buttonArray[32].getState());
  setInput(rawInputsSlave1[4],(1<<1),buttonArray[33].getState());
  setInput(rawInputsSlave1[4],(1<<2),buttonArray[34].getState());
  setInput(rawInputsSlave1[4],(1<<3),buttonArray[35].getState());
  setInput(rawInputsSlave1[4],(1<<4),buttonArray[36].getState());
  setInput(rawInputsSlave1[4],(1<<5),buttonArray[37].getState());
  setInput(rawInputsSlave1[4],(1<<6),buttonArray[38].getState());
  setInput(rawInputsSlave1[4],(1<<7),buttonArray[39].getState());
}

}
#endif