#ifndef PCF8575HANDLING_H
#define PCF8575HANDLING_H

namespace MY_PCF8575 
{
void setup();
void outputTest();

void set11inB(uint8_t val);
void set11inF(uint8_t val);
void set13inA(uint8_t val);
void set13inB(uint8_t val);
void set13inF(uint8_t val);
void set14inA(uint8_t val);
void set14inB(uint8_t val);
void set14inF(uint8_t val);
void setDin18(uint8_t val);
void setDin19(uint8_t val);
void setCin1 (uint8_t val);
void setCin2 (uint8_t val);
void setCin3 (uint8_t val);
void setCin4 (uint8_t val);
void setCin5 (uint8_t val);
void setCin6 (uint8_t val);

void setJin18(uint8_t val);
void setJin19(uint8_t val);
void set13inG(uint8_t val);
void set14inG(uint8_t val);
void set15inG(uint8_t val);
void set16inG(uint8_t val);
void set17inG(uint8_t val);
void set18inG(uint8_t val);
void setRes32(uint8_t val);
void setRes33(uint8_t val);
void setRes34(uint8_t val);
void setRes35(uint8_t val);
void setRes36(uint8_t val);
void setRes37(uint8_t val);
void setRes38(uint8_t val);
void setRes39(uint8_t val);

// pcf8575_8 => 0x27
void setJin9(uint8_t val)  ;
void setJin10(uint8_t val) ;
void setJin11(uint8_t val) ;
void setJin13(uint8_t val) ;
void setJin14(uint8_t val) ;
void setJin15(uint8_t val) ;
void setJin16(uint8_t val) ;
void setJin17(uint8_t val) ;
void setLin20(uint8_t val) ;
void setRes25(uint8_t val) ;
void setRes26(uint8_t val) ;
void setRes27(uint8_t val) ;
void setRes28(uint8_t val) ;
void setRes29(uint8_t val) ;
void setRes30(uint8_t val) ;
void setRes31(uint8_t val) ;
}
#endif