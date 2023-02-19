#ifndef LCDMENU_H
#define LCDMENU_H

//#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h> // https://github.com/johnrickman/LiquidCrystal_I2C
#include "command.h"
//LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
#include <ezButton.h> // https://github.com/ArduinoGetStarted/button

namespace MYLCD {

const uint8_t NUM_MENU_ITEMS = 3;

LiquidCrystal_I2C lcd(0x27, 16, 2);
ezButton tasteLinks(30);
//ezButton tasteOben(31); passt vom platz her nicht mehr
ezButton tasteSelect(31);

void setup();
void loop();
String railCombiEnum2Str(CCommand::eCMD railCombi);

}
#endif