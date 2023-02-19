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
  ezButton(13), // 12bel => gibts nicht
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
  ezButton(69), // 15re
  ezButton(68), // 16re
  ezButton(33), // 17re
  ezButton(32), // 18re
  ezButton(35), // 19re
  ezButton(34), // cN
  ezButton(37), // c1
  ezButton(36), // c2

  // rawInputsSlave1 byte4
  ezButton(39), // c3
  ezButton(38), // c4
  ezButton(41), // c5
  ezButton(40), // c6
  ezButton(43), // c7
  ezButton(42), // c8
  ezButton(45), // c9
  ezButton(44), // c10

  // rawInputsSlave1 byte5
  ezButton(47), // c11
  ezButton(46), // c20
  ezButton(22), // c13
  ezButton(23), // c14
  ezButton(24), // c15
  ezButton(25), // c16
  ezButton(55), // 1re
  ezButton(54), // 2re

  // rawInputsSlave1 byte6
  ezButton(57), // 3re
  ezButton(56), // 4re
  ezButton(59), // 5re
  ezButton(58), // 6re
  ezButton(61), // 7re
  ezButton(60), // 8re
  ezButton(63), // 9re
  ezButton(62), // 10re

  // rawInputsSlave1 byte7
  ezButton(65), // 11re
  ezButton(64), // c12
  ezButton(67), // 13re
  ezButton(66) // 14re
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

  setInput(rawInputsSlave1[5],(1<<0),buttonArray[40].getState());
  setInput(rawInputsSlave1[5],(1<<1),buttonArray[41].getState());
  setInput(rawInputsSlave1[5],(1<<2),buttonArray[42].getState());
  setInput(rawInputsSlave1[5],(1<<3),buttonArray[43].getState());
  setInput(rawInputsSlave1[5],(1<<4),buttonArray[44].getState());
  setInput(rawInputsSlave1[5],(1<<5),buttonArray[45].getState());
  setInput(rawInputsSlave1[5],(1<<6),buttonArray[46].getState());
  setInput(rawInputsSlave1[5],(1<<7),buttonArray[47].getState());

  setInput(rawInputsSlave1[6],(1<<0),buttonArray[48].getState());
  setInput(rawInputsSlave1[6],(1<<1),buttonArray[49].getState());
  setInput(rawInputsSlave1[6],(1<<2),buttonArray[50].getState());
  setInput(rawInputsSlave1[6],(1<<3),buttonArray[51].getState());
  setInput(rawInputsSlave1[6],(1<<4),buttonArray[52].getState());
  setInput(rawInputsSlave1[6],(1<<5),buttonArray[53].getState());
  setInput(rawInputsSlave1[6],(1<<6),buttonArray[54].getState());
  setInput(rawInputsSlave1[6],(1<<7),buttonArray[55].getState());

  setInput(rawInputsSlave1[7],(1<<0),buttonArray[56].getState());
  setInput(rawInputsSlave1[7],(1<<1),buttonArray[57].getState());
  setInput(rawInputsSlave1[7],(1<<2),buttonArray[58].getState());
  setInput(rawInputsSlave1[7],(1<<3),buttonArray[59].getState());
}

}
#endif