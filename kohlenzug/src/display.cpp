#include "display.h"

using namespace MYDISPLAY;

U8X8_SH1106_128X64_NONAME_HW_I2C MYDISPLAY::oled(U8X8_PIN_NONE);

void MYDISPLAY::setup(void)
{
  oled.begin();

  // oled.setFont( u8x8_font_8x13_1x2_f ); // enthaelt "°"; 2376 byte
  /* enthaelt "°"; 2427 byte
  * 4 Zeilen moeglich => print idx [y] = [0,2,4,6]
   * 
   */
  oled.setFont( u8x8_font_7x14_1x2_f ); // enthaelt "°"; 2427 byte 4

  oled.setCursor(0, 0);
  oled.print(F("Jetzt mit"));

  oled.setCursor(0, 2);
  oled.print(F("einer schoenen"));

  oled.setCursor(0, 4);
  oled.print(F("nachhaltigen"));

  oled.setCursor(0, 6);
  oled.print(F("Struktur"));
}

void MYDISPLAY::loop(void)
{

}
