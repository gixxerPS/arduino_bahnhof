#include "display.h"
#include "sequence.h"
#include "digitalInputs.h"
#include "digitalOutputs.h"

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
  oled.print(F("Kohlenzug"));

  oled.setCursor(0, 2);
  oled.print(F("V0.2.0"));

  oled.setCursor(0, 4);
  oled.print(F("----------------"));

  oled.setCursor(0, 6);
  oled.print(F("Init"));

  delay(3000);

  oled.setCursor(0, 0);
  oled.print(F("Automatik: AUS"));

  oled.setCursor(0, 2);
  oled.print(F("Schritt  :"));

  oled.setCursor(0, 6);
  oled.print(F("Warte auf Freig"));


}
void MYDISPLAY::updateAuto(bool autoStatus)
{
    if (autoStatus) {
        oled.setCursor(11, 0);
        oled.print(F("EIN"));
    } else {
        oled.setCursor(11, 0);
        oled.print(F("AUS"));
    }
}
void MYDISPLAY::updateStep(uint16_t step)
{
    char buf[4];
    oled.setCursor(11, 2);
    sprintf(buf, "%4d", step);
    oled.print(buf);

    if (step == 0) {
        oled.setCursor(0, 6);
        oled.print(F("Warte auf Freig"));
        oled.print(F("               "));
    } else if (step > 0 && step < 211) {
        oled.setCursor(0, 6);
        oled.print(F("PROG BR53      "));
    } else if (step >= 211 && step < 661) {
        oled.setCursor(0, 6);
        oled.print(F("PROG V200      "));
    } else if (step >= 661 && step < 999) {
        oled.setCursor(0, 6);
        oled.print(F("PROG BR41      "));
    }
}

void MYDISPLAY::loop(void)
{
    static bool autoOld;
    if (SEQ::stepChange) {
        updateStep(SEQ::step);
    }

    bool autoStatus = DI::isAutoEnabled();
    if (autoOld != autoStatus) {
        updateAuto(autoStatus);
    }
    autoOld = autoStatus;
}
