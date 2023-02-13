#include "pcf8575Handling.h"
#include "PCF8575.h" // https://github.com/xreef/PCF8575_library

PCF8575 pcf8575  (0x20); // A0=0 | A1=0 | A2=0
PCF8575 pcf8575_2(0x21); // A0=1 | A1=0 | A2=0
PCF8575 pcf8575_3(0x22); // A0=0 | A1=1 | A2=0
PCF8575 pcf8575_4(0x23); // A0=1 | A1=1 | A2=0
PCF8575 pcf8575_5(0x24); // A0=0 | A1=0 | A2=1
PCF8575 pcf8575_6(0x25); // A0=1 | A1=0 | A2=1
PCF8575 pcf8575_7(0x26); // A0=0 | A1=1 | A2=1
//PCF8575 pcf8575_8(0x27); // A0=1 | A1=1 | A2=1
// 0x27 wird vom LCD belegt

// pcf8575 => 0x20
void MY_PCF8575::set1inA(uint8_t val)  {pcf8575.digitalWrite(15,!val);}
void MY_PCF8575::set1inB(uint8_t val)  {pcf8575.digitalWrite(14,!val);}
void MY_PCF8575::set1inG(uint8_t val)  {pcf8575.digitalWrite(13,!val);}
void MY_PCF8575::set1inN(uint8_t val)  {pcf8575.digitalWrite(12,!val);}
void MY_PCF8575::set2inA(uint8_t val)  {pcf8575.digitalWrite(11,!val);}
void MY_PCF8575::set2inB(uint8_t val)  {pcf8575.digitalWrite(10,!val);}
void MY_PCF8575::set2inG(uint8_t val)  {pcf8575.digitalWrite( 9,!val);}
void MY_PCF8575::set3inA(uint8_t val)  {pcf8575.digitalWrite( 8,!val);}
void MY_PCF8575::set15inA(uint8_t val) {pcf8575.digitalWrite( 0,!val);}
void MY_PCF8575::set15inB(uint8_t val) {pcf8575.digitalWrite( 1,!val);}
void MY_PCF8575::set15inF(uint8_t val) {pcf8575.digitalWrite( 2,!val);}
void MY_PCF8575::set16inA(uint8_t val) {pcf8575.digitalWrite( 3,!val);}
void MY_PCF8575::set16inB(uint8_t val) {pcf8575.digitalWrite( 4,!val);}
void MY_PCF8575::set16inF(uint8_t val) {pcf8575.digitalWrite( 5,!val);}
void MY_PCF8575::set17inA(uint8_t val) {pcf8575.digitalWrite( 6,!val);}
void MY_PCF8575::set17inB(uint8_t val) {pcf8575.digitalWrite( 7,!val);}

// pcf8575_2 => 0x21
void MY_PCF8575::setCin7(uint8_t val)  {pcf8575_2.digitalWrite(15,!val);}
void MY_PCF8575::setCin8(uint8_t val)  {pcf8575_2.digitalWrite(14,!val);}
void MY_PCF8575::setCin9(uint8_t val)  {pcf8575_2.digitalWrite(13,!val);}
void MY_PCF8575::setCin10(uint8_t val) {pcf8575_2.digitalWrite(12,!val);}
void MY_PCF8575::setCin11(uint8_t val) {pcf8575_2.digitalWrite(11,!val);}
void MY_PCF8575::setCin12(uint8_t val) {pcf8575_2.digitalWrite(10,!val);}
void MY_PCF8575::setCin13(uint8_t val) {pcf8575_2.digitalWrite( 9,!val);}
void MY_PCF8575::setCin14(uint8_t val) {pcf8575_2.digitalWrite( 8,!val);}
void MY_PCF8575::set19inG(uint8_t val) {pcf8575_2.digitalWrite( 0,!val);}
void MY_PCF8575::set12inK(uint8_t val) {pcf8575_2.digitalWrite( 1,!val);}
void MY_PCF8575::setRes1 (uint8_t val) {pcf8575_2.digitalWrite( 2,!val);}
void MY_PCF8575::setRes2 (uint8_t val) {pcf8575_2.digitalWrite( 3,!val);}
void MY_PCF8575::setRes3 (uint8_t val) {pcf8575_2.digitalWrite( 4,!val);}
void MY_PCF8575::setRes4 (uint8_t val) {pcf8575_2.digitalWrite( 5,!val);}
void MY_PCF8575::setRes5 (uint8_t val) {pcf8575_2.digitalWrite( 6,!val);}
void MY_PCF8575::setRes6 (uint8_t val) {pcf8575_2.digitalWrite( 7,!val);}

// pcf8575_3 => 0x22
void MY_PCF8575::set3inB(uint8_t val)  {pcf8575_3.digitalWrite(15,!val);}
void MY_PCF8575::set3inG(uint8_t val)  {pcf8575_3.digitalWrite(14,!val);}
void MY_PCF8575::set4inA(uint8_t val)  {pcf8575_3.digitalWrite(13,!val);}
void MY_PCF8575::set4inB(uint8_t val)  {pcf8575_3.digitalWrite(12,!val);}
void MY_PCF8575::set4inG(uint8_t val)  {pcf8575_3.digitalWrite(11,!val);}
void MY_PCF8575::set5inA(uint8_t val)  {pcf8575_3.digitalWrite(10,!val);}
void MY_PCF8575::set5inB(uint8_t val)  {pcf8575_3.digitalWrite( 9,!val);}
void MY_PCF8575::set5inF(uint8_t val)  {pcf8575_3.digitalWrite( 8,!val);}
void MY_PCF8575::set17inF(uint8_t val) {pcf8575_3.digitalWrite( 0,!val);}
void MY_PCF8575::set18inA(uint8_t val) {pcf8575_3.digitalWrite( 1,!val);}
void MY_PCF8575::set18inB(uint8_t val) {pcf8575_3.digitalWrite( 2,!val);}
void MY_PCF8575::set18inF(uint8_t val) {pcf8575_3.digitalWrite( 3,!val);}
void MY_PCF8575::set19inA(uint8_t val) {pcf8575_3.digitalWrite( 4,!val);}
void MY_PCF8575::set19inB(uint8_t val) {pcf8575_3.digitalWrite( 5,!val);}
void MY_PCF8575::set19inF(uint8_t val) {pcf8575_3.digitalWrite( 6,!val);}
void MY_PCF8575::setDin1 (uint8_t val) {pcf8575_3.digitalWrite( 7,!val);}

// pcf8575_4 => 0x23
void MY_PCF8575::setCin15(uint8_t val) {pcf8575_4.digitalWrite(15,!val);}
void MY_PCF8575::setCin16(uint8_t val) {pcf8575_4.digitalWrite(14,!val);}
void MY_PCF8575::setCin17(uint8_t val) {pcf8575_4.digitalWrite(13,!val);}
void MY_PCF8575::setCin18(uint8_t val) {pcf8575_4.digitalWrite(12,!val);}
void MY_PCF8575::setCin19(uint8_t val) {pcf8575_4.digitalWrite(11,!val);}
void MY_PCF8575::setNin1 (uint8_t val) {pcf8575_4.digitalWrite(10,!val);}
void MY_PCF8575::set19inM(uint8_t val) {pcf8575_4.digitalWrite( 9,!val);}
void MY_PCF8575::setMin19(uint8_t val) {pcf8575_4.digitalWrite( 8,!val);}
void MY_PCF8575::setRes7 (uint8_t val) {pcf8575_4.digitalWrite( 0,!val);}
void MY_PCF8575::setRes8 (uint8_t val) {pcf8575_4.digitalWrite( 1,!val);}
void MY_PCF8575::setRes9 (uint8_t val) {pcf8575_4.digitalWrite( 2,!val);}
void MY_PCF8575::setRes10(uint8_t val) {pcf8575_4.digitalWrite( 3,!val);}
void MY_PCF8575::setRes11(uint8_t val) {pcf8575_4.digitalWrite( 4,!val);}
void MY_PCF8575::setRes12(uint8_t val) {pcf8575_4.digitalWrite( 5,!val);}
void MY_PCF8575::setRes13(uint8_t val) {pcf8575_4.digitalWrite( 6,!val);}
void MY_PCF8575::setRes14(uint8_t val) {pcf8575_4.digitalWrite( 7,!val);}

// pcf8575_5 => 0x24
void MY_PCF8575::set6inA(uint8_t val) {pcf8575_5.digitalWrite(15,!val);}
void MY_PCF8575::set6inB(uint8_t val) {pcf8575_5.digitalWrite(14,!val);}
void MY_PCF8575::set6inF(uint8_t val) {pcf8575_5.digitalWrite(13,!val);}
void MY_PCF8575::set7inA(uint8_t val) {pcf8575_5.digitalWrite(12,!val);}
void MY_PCF8575::set7inB(uint8_t val) {pcf8575_5.digitalWrite(11,!val);}
void MY_PCF8575::set7inF(uint8_t val) {pcf8575_5.digitalWrite(10,!val);}
void MY_PCF8575::set8inA(uint8_t val) {pcf8575_5.digitalWrite( 9,!val);}
void MY_PCF8575::set8inB(uint8_t val) {pcf8575_5.digitalWrite( 8,!val);}
void MY_PCF8575::setDin2(uint8_t val) {pcf8575_5.digitalWrite( 0,!val);}
void MY_PCF8575::setDin3(uint8_t val) {pcf8575_5.digitalWrite( 1,!val);}
void MY_PCF8575::setDin4(uint8_t val) {pcf8575_5.digitalWrite( 2,!val);}
void MY_PCF8575::setDin5(uint8_t val) {pcf8575_5.digitalWrite( 3,!val);}
void MY_PCF8575::setDin6(uint8_t val) {pcf8575_5.digitalWrite( 4,!val);}
void MY_PCF8575::setDin7(uint8_t val) {pcf8575_5.digitalWrite( 5,!val);}
void MY_PCF8575::setDin8(uint8_t val) {pcf8575_5.digitalWrite( 6,!val);}
void MY_PCF8575::setDin9(uint8_t val) {pcf8575_5.digitalWrite( 7,!val);}

// pcf8575_6 => 0x25
void MY_PCF8575::setHin1(uint8_t val)  {pcf8575_6.digitalWrite(15,!val);}
void MY_PCF8575::setHin2(uint8_t val)  {pcf8575_6.digitalWrite(14,!val);}
void MY_PCF8575::setHin3(uint8_t val)  {pcf8575_6.digitalWrite(13,!val);}
void MY_PCF8575::setRes15(uint8_t val) {pcf8575_6.digitalWrite(12,!val);}
void MY_PCF8575::setJin5(uint8_t val)  {pcf8575_6.digitalWrite(11,!val);}
void MY_PCF8575::setJin6(uint8_t val)  {pcf8575_6.digitalWrite(10,!val);}
void MY_PCF8575::setJin7(uint8_t val)  {pcf8575_6.digitalWrite( 9,!val);}
void MY_PCF8575::setJinB(uint8_t val)  {pcf8575_6.digitalWrite( 8,!val);}
void MY_PCF8575::setRes16(uint8_t val) {pcf8575_6.digitalWrite( 0,!val);}
void MY_PCF8575::setRes17(uint8_t val) {pcf8575_6.digitalWrite( 1,!val);}
void MY_PCF8575::setRes18(uint8_t val) {pcf8575_6.digitalWrite( 2,!val);}
void MY_PCF8575::setRes19(uint8_t val) {pcf8575_6.digitalWrite( 3,!val);}
void MY_PCF8575::setRes20(uint8_t val) {pcf8575_6.digitalWrite( 4,!val);}
void MY_PCF8575::setRes21(uint8_t val) {pcf8575_6.digitalWrite( 5,!val);}
void MY_PCF8575::setRes22(uint8_t val) {pcf8575_6.digitalWrite( 6,!val);}
void MY_PCF8575::setRes23(uint8_t val) {pcf8575_6.digitalWrite( 7,!val);}

// pcf8575_7 => 0x26
void MY_PCF8575::set8inF(uint8_t val)  {pcf8575_7.digitalWrite(15,!val);}
void MY_PCF8575::set9inA(uint8_t val)  {pcf8575_7.digitalWrite(14,!val);}
void MY_PCF8575::set9inB(uint8_t val)  {pcf8575_7.digitalWrite(13,!val);}
void MY_PCF8575::set9inF(uint8_t val)  {pcf8575_7.digitalWrite(12,!val);}
void MY_PCF8575::set10inA(uint8_t val) {pcf8575_7.digitalWrite(11,!val);}
void MY_PCF8575::set10inB(uint8_t val) {pcf8575_7.digitalWrite(10,!val);}
void MY_PCF8575::set10inF(uint8_t val) {pcf8575_7.digitalWrite( 9,!val);}
void MY_PCF8575::set11inA(uint8_t val) {pcf8575_7.digitalWrite( 8,!val);}
void MY_PCF8575::setDin10(uint8_t val) {pcf8575_7.digitalWrite( 0,!val);}
void MY_PCF8575::setDin11(uint8_t val) {pcf8575_7.digitalWrite( 1,!val);}
void MY_PCF8575::setDin12(uint8_t val) {pcf8575_7.digitalWrite( 2,!val);}
void MY_PCF8575::setDin13(uint8_t val) {pcf8575_7.digitalWrite( 3,!val);}
void MY_PCF8575::setDin14(uint8_t val) {pcf8575_7.digitalWrite( 4,!val);}
void MY_PCF8575::setDin15(uint8_t val) {pcf8575_7.digitalWrite( 5,!val);}
void MY_PCF8575::setDin16(uint8_t val) {pcf8575_7.digitalWrite( 6,!val);}
void MY_PCF8575::setDin17(uint8_t val) {pcf8575_7.digitalWrite( 7,!val);}

// pcf8575_8 => 0x27
// void MY_PCF8575::setJin9(uint8_t val)  {pcf8575_8.digitalWrite(15,!val);}
// void MY_PCF8575::setJin10(uint8_t val) {pcf8575_8.digitalWrite(14,!val);}
// void MY_PCF8575::setJin11(uint8_t val) {pcf8575_8.digitalWrite(13,!val);}
// void MY_PCF8575::setJin13(uint8_t val) {pcf8575_8.digitalWrite(12,!val);}
// void MY_PCF8575::setJin14(uint8_t val) {pcf8575_8.digitalWrite(11,!val);}
// void MY_PCF8575::setJin15(uint8_t val) {pcf8575_8.digitalWrite(10,!val);}
// void MY_PCF8575::setJin16(uint8_t val) {pcf8575_8.digitalWrite( 9,!val);}
// void MY_PCF8575::setJin17(uint8_t val) {pcf8575_8.digitalWrite( 8,!val);}
// void MY_PCF8575::setRes24(uint8_t val) {pcf8575_8.digitalWrite( 0,!val);}
// void MY_PCF8575::setRes25(uint8_t val) {pcf8575_8.digitalWrite( 1,!val);}
// void MY_PCF8575::setRes26(uint8_t val) {pcf8575_8.digitalWrite( 2,!val);}
// void MY_PCF8575::setRes27(uint8_t val) {pcf8575_8.digitalWrite( 3,!val);}
// void MY_PCF8575::setRes28(uint8_t val) {pcf8575_8.digitalWrite( 4,!val);}
// void MY_PCF8575::setRes29(uint8_t val) {pcf8575_8.digitalWrite( 5,!val);}
// void MY_PCF8575::setRes30(uint8_t val) {pcf8575_8.digitalWrite( 6,!val);}
// void MY_PCF8575::setRes31(uint8_t val) {pcf8575_8.digitalWrite( 7,!val);}

void MY_PCF8575::setup()
{
    for (int i = 0; i < 16; i++)
    {
        pcf8575.pinMode(i, OUTPUT);
        pcf8575_2.pinMode(i, OUTPUT);
        pcf8575_3.pinMode(i, OUTPUT);
        pcf8575_4.pinMode(i, OUTPUT);
        pcf8575_5.pinMode(i, OUTPUT);
        pcf8575_6.pinMode(i, OUTPUT);
        pcf8575_7.pinMode(i, OUTPUT);
        // pcf8575_8.pinMode(i, OUTPUT);
    }
    pcf8575.begin(); // begin nur einmal aufrufen sonst friert arduino ein
    for (int i = 0; i < 16; i++)
    {
        pcf8575.digitalWrite  (i, HIGH); // default is low aber low heisst relais an!
        pcf8575_2.digitalWrite(i, HIGH);
        pcf8575_3.digitalWrite(i, HIGH);
        pcf8575_4.digitalWrite(i, HIGH);
        pcf8575_5.digitalWrite(i, HIGH);
        pcf8575_6.digitalWrite(i, HIGH);
        pcf8575_7.digitalWrite(i, HIGH);
    }
}

// void setRemoteIo(bool status)
// {
//     if (!status) {
//         pcf8575.digitalWrite(0, LOW);
//         pcf8575.digitalWrite(1, LOW);
//         pcf8575_2.digitalWrite(0, LOW);
//         pcf8575_2.digitalWrite(1, LOW);
//     } else {
//         pcf8575.digitalWrite(0, HIGH);
//         pcf8575.digitalWrite(1, HIGH);
//         pcf8575_2.digitalWrite(0, HIGH);
//         pcf8575_2.digitalWrite(1, HIGH);
//     }
//     // static int pin = 0;
//     // pcf8575.digitalWrite(pin, HIGH);
//     // delay(100);
//     // pcf8575.digitalWrite(pin, LOW);
//     // delay(100);
//     // pin++;
//     // if (pin > 15)
//     //     pin = 0;
// }

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
    for (int i = 0; i < 16; i++)
    {
        pcf8575_3.digitalWrite(i, LOW);
        delay(msDelayOut);
        pcf8575_3.digitalWrite(i, HIGH);
        delay(msDelayOut);
    }
    for (int i = 0; i < 16; i++)
    {
        pcf8575_4.digitalWrite(i, LOW);
        delay(msDelayOut);
        pcf8575_4.digitalWrite(i, HIGH);
        delay(msDelayOut);
    }
    for (int i = 0; i < 16; i++)
    {
        pcf8575_5.digitalWrite(i, LOW);
        delay(msDelayOut);
        pcf8575_5.digitalWrite(i, HIGH);
        delay(msDelayOut);
    }
    for (int i = 0; i < 16; i++)
    {
        pcf8575_6.digitalWrite(i, LOW);
        delay(msDelayOut);
        pcf8575_6.digitalWrite(i, HIGH);
        delay(msDelayOut);
    }
    for (int i = 0; i < 16; i++)
    {
        pcf8575_7.digitalWrite(i, LOW);
        delay(msDelayOut);
        pcf8575_7.digitalWrite(i, HIGH);
        delay(msDelayOut);
    }
    // for (int i = 0; i < 16; i++)
    // {
    //     pcf8575_8.digitalWrite(i, LOW);
    //     delay(200);
    //     pcf8575_8.digitalWrite(i, HIGH);
    //     delay(200);
    // }
}

