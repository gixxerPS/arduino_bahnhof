#ifndef DISPLAY_H
#define DISPLAY_H

#include "U8x8lib.h" // schnell, NUR text keine grafik; https://github.com/olikraus/u8g2
// #include <ezButton.h> // https://github.com/ArduinoGetStarted/button

namespace MYDISPLAY {

const uint8_t NUM_MENU_ITEMS = 3;

extern U8X8_SH1106_128X64_NONAME_HW_I2C oled; // 1,3"
// U8X8_SSD1306_128X64_NONAME_HW_I2C oled(U8X8_PIN_NONE); // 0,96"

// ezButton tasteLinks(32);
// ezButton tasteOben(31); passt vom platz her nicht mehr
// ezButton tasteSelect(31);

void setup();
void loop();

}
#endif