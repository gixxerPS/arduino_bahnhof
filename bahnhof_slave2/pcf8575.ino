#include "pcf8575Handling.h"
#include "PCF8575.h" // https://github.com/xreef/PCF8575_library

PCF8575 pcf8575  (0x20); // A0=0 | A1=0 | A2=0
PCF8575 pcf8575_2(0x21); // A0=1 | A1=0 | A2=0
// PCF8575 pcf8575_3(0x22); // A0=0 | A1=1 | A2=0
// PCF8575 pcf8575_4(0x23); // A0=1 | A1=1 | A2=0
// PCF8575 pcf8575_5(0x24); // A0=0 | A1=0 | A2=1
// PCF8575 pcf8575_6(0x25); // A0=1 | A1=0 | A2=1
// PCF8575 pcf8575_7(0x26); // A0=0 | A1=1 | A2=1
PCF8575 pcf8575_8(0x27); // A0=1 | A1=1 | A2=1 => von master uebernommen

// pcf8575 => 0x20
void MY_PCF8575::set11inB(uint8_t val) {pcf8575.digitalWrite(15,!val);}
void MY_PCF8575::set11inF(uint8_t val) {pcf8575.digitalWrite(14,!val);}
void MY_PCF8575::set13inA(uint8_t val) {pcf8575.digitalWrite(13,!val);}
void MY_PCF8575::set13inB(uint8_t val) {pcf8575.digitalWrite(12,!val);}
void MY_PCF8575::set13inF(uint8_t val) {pcf8575.digitalWrite(11,!val);}
void MY_PCF8575::set14inA(uint8_t val) {pcf8575.digitalWrite(10,!val);}
void MY_PCF8575::set14inB(uint8_t val) {pcf8575.digitalWrite( 9,!val);}
void MY_PCF8575::set14inF(uint8_t val) {pcf8575.digitalWrite( 8,!val);}
void MY_PCF8575::setDin18(uint8_t val) {pcf8575.digitalWrite( 0,!val);}
void MY_PCF8575::setDin19(uint8_t val) {pcf8575.digitalWrite( 1,!val);}
void MY_PCF8575::setCin1 (uint8_t val) {pcf8575.digitalWrite( 2,!val);}
void MY_PCF8575::setCin2 (uint8_t val) {pcf8575.digitalWrite( 3,!val);}
void MY_PCF8575::setCin3 (uint8_t val) {pcf8575.digitalWrite( 4,!val);}
void MY_PCF8575::setCin4 (uint8_t val) {pcf8575.digitalWrite( 5,!val);}
void MY_PCF8575::setCin5 (uint8_t val) {pcf8575.digitalWrite( 6,!val);}
void MY_PCF8575::setCin6 (uint8_t val) {pcf8575.digitalWrite( 7,!val);}

// pcf8575_2 => 0x21
void MY_PCF8575::setJin18(uint8_t val) {pcf8575_2.digitalWrite(15,!val);}
void MY_PCF8575::setJin19(uint8_t val) {pcf8575_2.digitalWrite(14,!val);}
void MY_PCF8575::set13inG(uint8_t val) {pcf8575_2.digitalWrite(13,!val);}
void MY_PCF8575::set14inG(uint8_t val) {pcf8575_2.digitalWrite(12,!val);}
void MY_PCF8575::set15inG(uint8_t val) {pcf8575_2.digitalWrite(11,!val);}
void MY_PCF8575::set16inG(uint8_t val) {pcf8575_2.digitalWrite(10,!val);}
void MY_PCF8575::set17inG(uint8_t val) {pcf8575_2.digitalWrite( 9,!val);}
void MY_PCF8575::set18inG(uint8_t val) {pcf8575_2.digitalWrite( 8,!val);}
void MY_PCF8575::setRes32(uint8_t val) {pcf8575_2.digitalWrite( 0,!val);}
void MY_PCF8575::setRes33(uint8_t val) {pcf8575_2.digitalWrite( 1,!val);}
void MY_PCF8575::setRes34(uint8_t val) {pcf8575_2.digitalWrite( 2,!val);}
void MY_PCF8575::setRes35(uint8_t val) {pcf8575_2.digitalWrite( 3,!val);}
void MY_PCF8575::setRes36(uint8_t val) {pcf8575_2.digitalWrite( 4,!val);}
void MY_PCF8575::setRes37(uint8_t val) {pcf8575_2.digitalWrite( 5,!val);}
void MY_PCF8575::setRes38(uint8_t val) {pcf8575_2.digitalWrite( 6,!val);}
void MY_PCF8575::setRes39(uint8_t val) {pcf8575_2.digitalWrite( 7,!val);}

// // pcf8575_3 => 0x22
// void set3inB(uint8_t val)  {pcf8575_3.digitalWrite(15,!val);}
// void set3inG(uint8_t val)  {pcf8575_3.digitalWrite(14,!val);}
// void set4inA(uint8_t val)  {pcf8575_3.digitalWrite(13,!val);}
// void set4inB(uint8_t val)  {pcf8575_3.digitalWrite(12,!val);}
// void set4inG(uint8_t val)  {pcf8575_3.digitalWrite(11,!val);}
// void set5inA(uint8_t val)  {pcf8575_3.digitalWrite(10,!val);}
// void set5inB(uint8_t val)  {pcf8575_3.digitalWrite( 9,!val);}
// void set5inF(uint8_t val)  {pcf8575_3.digitalWrite( 8,!val);}
// void set17inF(uint8_t val) {pcf8575_3.digitalWrite( 0,!val);}
// void set18inA(uint8_t val) {pcf8575_3.digitalWrite( 1,!val);}
// void set18inB(uint8_t val) {pcf8575_3.digitalWrite( 2,!val);}
// void set18inF(uint8_t val) {pcf8575_3.digitalWrite( 3,!val);}
// void set19inA(uint8_t val) {pcf8575_3.digitalWrite( 4,!val);}
// void set19inB(uint8_t val) {pcf8575_3.digitalWrite( 5,!val);}
// void set19inF(uint8_t val) {pcf8575_3.digitalWrite( 6,!val);}
// void setDin1 (uint8_t val) {pcf8575_3.digitalWrite( 7,!val);}

// // pcf8575_4 => 0x23
// void setCin15(uint8_t val) {pcf8575_4.digitalWrite(15,!val);}
// void setCin16(uint8_t val) {pcf8575_4.digitalWrite(14,!val);}
// void setCin17(uint8_t val) {pcf8575_4.digitalWrite(13,!val);}
// void setCin18(uint8_t val) {pcf8575_4.digitalWrite(12,!val);}
// void setCin19(uint8_t val) {pcf8575_4.digitalWrite(11,!val);}
// void setNin1 (uint8_t val) {pcf8575_4.digitalWrite(10,!val);}
// void set19inM(uint8_t val) {pcf8575_4.digitalWrite( 9,!val);}
// void setMin19(uint8_t val) {pcf8575_4.digitalWrite( 8,!val);}
// void setRes7 (uint8_t val) {pcf8575_4.digitalWrite( 0,!val);}
// void setRes8 (uint8_t val) {pcf8575_4.digitalWrite( 1,!val);}
// void setRes9 (uint8_t val) {pcf8575_4.digitalWrite( 2,!val);}
// void setRes10(uint8_t val) {pcf8575_4.digitalWrite( 3,!val);}
// void setRes11(uint8_t val) {pcf8575_4.digitalWrite( 4,!val);}
// void setRes12(uint8_t val) {pcf8575_4.digitalWrite( 5,!val);}
// void setRes13(uint8_t val) {pcf8575_4.digitalWrite( 6,!val);}
// void setRes14(uint8_t val) {pcf8575_4.digitalWrite( 7,!val);}

// // pcf8575_5 => 0x24
// void set6inA(uint8_t val) {pcf8575_5.digitalWrite(15,!val);}
// void set6inB(uint8_t val) {pcf8575_5.digitalWrite(14,!val);}
// void set6inF(uint8_t val) {pcf8575_5.digitalWrite(13,!val);}
// void set7inA(uint8_t val) {pcf8575_5.digitalWrite(12,!val);}
// void set7inB(uint8_t val) {pcf8575_5.digitalWrite(11,!val);}
// void set7inF(uint8_t val) {pcf8575_5.digitalWrite(10,!val);}
// void set8inA(uint8_t val) {pcf8575_5.digitalWrite( 9,!val);}
// void set8inB(uint8_t val) {pcf8575_5.digitalWrite( 8,!val);}
// void setDin2(uint8_t val) {pcf8575_5.digitalWrite( 0,!val);}
// void setDin3(uint8_t val) {pcf8575_5.digitalWrite( 1,!val);}
// void setDin4(uint8_t val) {pcf8575_5.digitalWrite( 2,!val);}
// void setDin5(uint8_t val) {pcf8575_5.digitalWrite( 3,!val);}
// void setDin6(uint8_t val) {pcf8575_5.digitalWrite( 4,!val);}
// void setDin7(uint8_t val) {pcf8575_5.digitalWrite( 5,!val);}
// void setDin8(uint8_t val) {pcf8575_5.digitalWrite( 6,!val);}
// void setDin9(uint8_t val) {pcf8575_5.digitalWrite( 7,!val);}

// // pcf8575_6 => 0x25
// void setHin1(uint8_t val)  {pcf8575_6.digitalWrite(15,!val);}
// void setHin2(uint8_t val)  {pcf8575_6.digitalWrite(14,!val);}
// void setHin3(uint8_t val)  {pcf8575_6.digitalWrite(13,!val);}
// void setRes15(uint8_t val) {pcf8575_6.digitalWrite(12,!val);}
// void setJin5(uint8_t val)  {pcf8575_6.digitalWrite(11,!val);}
// void setJin6(uint8_t val)  {pcf8575_6.digitalWrite(10,!val);}
// void setJin7(uint8_t val)  {pcf8575_6.digitalWrite( 9,!val);}
// void setJinB(uint8_t val)  {pcf8575_6.digitalWrite( 8,!val);}
// void setRes16(uint8_t val) {pcf8575_6.digitalWrite( 0,!val);}
// void setRes17(uint8_t val) {pcf8575_6.digitalWrite( 1,!val);}
// void setRes18(uint8_t val) {pcf8575_6.digitalWrite( 2,!val);}
// void setRes19(uint8_t val) {pcf8575_6.digitalWrite( 3,!val);}
// void setRes20(uint8_t val) {pcf8575_6.digitalWrite( 4,!val);}
// void setRes21(uint8_t val) {pcf8575_6.digitalWrite( 5,!val);}
// void setRes22(uint8_t val) {pcf8575_6.digitalWrite( 6,!val);}
// void setRes23(uint8_t val) {pcf8575_6.digitalWrite( 7,!val);}

// // pcf8575_7 => 0x26
// void set8inF(uint8_t val)  {pcf8575_7.digitalWrite(15,!val);}
// void set9inA(uint8_t val)  {pcf8575_7.digitalWrite(14,!val);}
// void set9inB(uint8_t val)  {pcf8575_7.digitalWrite(13,!val);}
// void set9inF(uint8_t val)  {pcf8575_7.digitalWrite(12,!val);}
// void set10inA(uint8_t val) {pcf8575_7.digitalWrite(11,!val);}
// void set10inB(uint8_t val) {pcf8575_7.digitalWrite(10,!val);}
// void set10inF(uint8_t val) {pcf8575_7.digitalWrite( 9,!val);}
// void set11inA(uint8_t val) {pcf8575_7.digitalWrite( 8,!val);}
// void setDin10(uint8_t val) {pcf8575_7.digitalWrite( 0,!val);}
// void setDin11(uint8_t val) {pcf8575_7.digitalWrite( 1,!val);}
// void setDin12(uint8_t val) {pcf8575_7.digitalWrite( 2,!val);}
// void setDin13(uint8_t val) {pcf8575_7.digitalWrite( 3,!val);}
// void setDin14(uint8_t val) {pcf8575_7.digitalWrite( 4,!val);}
// void setDin15(uint8_t val) {pcf8575_7.digitalWrite( 5,!val);}
// void setDin16(uint8_t val) {pcf8575_7.digitalWrite( 6,!val);}
// void setDin17(uint8_t val) {pcf8575_7.digitalWrite( 7,!val);}

// // pcf8575_8 => 0x27
void MY_PCF8575::setJin9(uint8_t val)  {pcf8575_8.digitalWrite(15,!val);}
void MY_PCF8575::setJin10(uint8_t val) {pcf8575_8.digitalWrite(14,!val);}
void MY_PCF8575::setJin11(uint8_t val) {pcf8575_8.digitalWrite(13,!val);}
void MY_PCF8575::setJin13(uint8_t val) {pcf8575_8.digitalWrite(12,!val);}
void MY_PCF8575::setJin14(uint8_t val) {pcf8575_8.digitalWrite(11,!val);}
void MY_PCF8575::setJin15(uint8_t val) {pcf8575_8.digitalWrite(10,!val);}
void MY_PCF8575::setJin16(uint8_t val) {pcf8575_8.digitalWrite( 9,!val);}
void MY_PCF8575::setJin17(uint8_t val) {pcf8575_8.digitalWrite( 8,!val);}
void MY_PCF8575::setRes24(uint8_t val) {pcf8575_8.digitalWrite( 0,!val);}
void MY_PCF8575::setRes25(uint8_t val) {pcf8575_8.digitalWrite( 1,!val);}
void MY_PCF8575::setRes26(uint8_t val) {pcf8575_8.digitalWrite( 2,!val);}
void MY_PCF8575::setRes27(uint8_t val) {pcf8575_8.digitalWrite( 3,!val);}
void MY_PCF8575::setRes28(uint8_t val) {pcf8575_8.digitalWrite( 4,!val);}
void MY_PCF8575::setRes29(uint8_t val) {pcf8575_8.digitalWrite( 5,!val);}
void MY_PCF8575::setRes30(uint8_t val) {pcf8575_8.digitalWrite( 6,!val);}
void MY_PCF8575::setRes31(uint8_t val) {pcf8575_8.digitalWrite( 7,!val);}

void MY_PCF8575::setup()
{
    for (int i = 0; i < 16; i++)
    {
        pcf8575.pinMode(i, OUTPUT);
        pcf8575_2.pinMode(i, OUTPUT);
        // pcf8575_3.pinMode(i, OUTPUT);
        // pcf8575_4.pinMode(i, OUTPUT);
        // pcf8575_5.pinMode(i, OUTPUT);
        // pcf8575_6.pinMode(i, OUTPUT);
        // pcf8575_7.pinMode(i, OUTPUT);
        pcf8575_8.pinMode(i, OUTPUT);
    }
    pcf8575.begin(); // begin nur einmal aufrufen sonst friert arduino ein
    for (int i = 0; i < 16; i++)
    {
        pcf8575.digitalWrite  (i, HIGH); // default is low aber low heisst relais an!
        pcf8575_2.digitalWrite(i, HIGH);
        pcf8575_8.digitalWrite(i, HIGH);
    }
}

void MY_PCF8575::outputTest() {
    const uint8_t msDelayOut = 100;
    for (int i = 0; i < 16; i++)
    {
        pcf8575.digitalWrite(i, LOW);
        delay(msDelayOut);
        pcf8575.digitalWrite(i, HIGH);
        delay(msDelayOut);
    }
    for (int i = 0; i < 16; i++)
    {
        pcf8575_2.digitalWrite(i, LOW);
        delay(msDelayOut);
        pcf8575_2.digitalWrite(i, HIGH);
        delay(msDelayOut);
    }
    // for (int i = 0; i < 16; i++)
    // {
    //     pcf8575_3.digitalWrite(i, LOW);
    //     delay(200);
    //     pcf8575_3.digitalWrite(i, HIGH);
    //     delay(200);
    // }
    // for (int i = 0; i < 16; i++)
    // {
    //     pcf8575_4.digitalWrite(i, LOW);
    //     delay(200);
    //     pcf8575_4.digitalWrite(i, HIGH);
    //     delay(200);
    // }
    // for (int i = 0; i < 16; i++)
    // {
    //     pcf8575_5.digitalWrite(i, LOW);
    //     delay(200);
    //     pcf8575_5.digitalWrite(i, HIGH);
    //     delay(200);
    // }
    // for (int i = 0; i < 16; i++)
    // {
    //     pcf8575_6.digitalWrite(i, LOW);
    //     delay(200);
    //     pcf8575_6.digitalWrite(i, HIGH);
    //     delay(200);
    // }
    // for (int i = 0; i < 16; i++)
    // {
    //     pcf8575_7.digitalWrite(i, LOW);
    //     delay(200);
    //     pcf8575_7.digitalWrite(i, HIGH);
    //     delay(200);
    // }
    for (int i = 0; i < 16; i++)
    {
        pcf8575_8.digitalWrite(i, LOW);
        delay(msDelayOut);
        pcf8575_8.digitalWrite(i, HIGH);
        delay(msDelayOut);
    }
}
