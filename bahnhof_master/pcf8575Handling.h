#ifndef PCF8575HANDLING_H
#define PCF8575HANDLING_H

namespace MY_PCF8575 
{

void setup();
void outputTest();

void set1inA(uint8_t val) ; 
void set1inB(uint8_t val) ; 
void set1inG(uint8_t val) ; 
void set1inN(uint8_t val) ; 
void set2inA(uint8_t val) ; 
void set2inB(uint8_t val) ; 
void set2inG(uint8_t val) ; 
void set3inA(uint8_t val) ; 
void set15inA(uint8_t val); 
void set15inB(uint8_t val); 
void set15inF(uint8_t val); 
void set16inA(uint8_t val); 
void set16inB(uint8_t val); 
void set16inF(uint8_t val); 
void set17inA(uint8_t val); 
void set17inB(uint8_t val); 

// pcf8575_2 => 0x21
void setCin7(uint8_t val)  ;
void setCin8(uint8_t val)  ;
void setCin9(uint8_t val)  ;
void setCin10(uint8_t val) ;
void setCin11(uint8_t val) ;
void setCin12(uint8_t val) ;
void setCin13(uint8_t val) ;
void setCin14(uint8_t val) ;
void set19inG(uint8_t val) ;
void set12inK(uint8_t val) ;
void set20inK(uint8_t val) ;
void set13inK(uint8_t val) ;
void set14inK(uint8_t val) ;
void set4inL (uint8_t val) ;
void set6inL (uint8_t val) ;
void set8inL (uint8_t val) ;

// pcf8575_3 => 0x22
void set3inB(uint8_t val)  ;
void set3inG(uint8_t val)  ;
void set4inA(uint8_t val)  ;
void set4inB(uint8_t val)  ;
void set4inG(uint8_t val)  ;
void set5inA(uint8_t val)  ;
void set5inB(uint8_t val)  ;
void set5inF(uint8_t val)  ;
void set17inF(uint8_t val) ;
void set18inA(uint8_t val) ;
void set18inB(uint8_t val) ;
void set18inF(uint8_t val) ;
void set19inA(uint8_t val) ;
void set19inB(uint8_t val) ;
void set19inF(uint8_t val) ;
void setDin1 (uint8_t val) ;

// pcf8575_4 => 0x23
void setCin15(uint8_t val) ;
void setCin16(uint8_t val) ;
void setCin17(uint8_t val) ;
void setCin18(uint8_t val) ;
void setCin19(uint8_t val) ;
void setNin1 (uint8_t val) ;
void set19inM(uint8_t val) ;
void setMin19(uint8_t val) ;
void set9inL (uint8_t val) ;
void set12inL(uint8_t val) ;
void set20inL(uint8_t val) ;
void set13inR(uint8_t val) ;
void set14inR(uint8_t val) ;
void setKin12(uint8_t val) ;
void setKin20(uint8_t val) ;
void setKin13(uint8_t val) ;

// pcf8575_5 => 0x24
void set6inA(uint8_t val);
void set6inB(uint8_t val);
void set6inF(uint8_t val);
void set7inA(uint8_t val);
void set7inB(uint8_t val);
void set7inF(uint8_t val);
void set8inA(uint8_t val);
void set8inB(uint8_t val);
void setDin2(uint8_t val);
void setDin3(uint8_t val);
void setDin4(uint8_t val);
void setDin5(uint8_t val);
void setDin6(uint8_t val);
void setDin7(uint8_t val);
void setDin8(uint8_t val);
void setDin9(uint8_t val);

// pcf8575_6 => 0x25
void setHin1(uint8_t val)  ;
void setHin2(uint8_t val)  ;
void setHin3(uint8_t val)  ;
void setHin4(uint8_t val) ;
void setJin5(uint8_t val)  ;
void setJin6(uint8_t val)  ;
void setJin7(uint8_t val)  ;
void setJin8(uint8_t val)  ;
void setKin14(uint8_t val) ;
void setRin13(uint8_t val) ;
void setRin14(uint8_t val) ;
void setRes19(uint8_t val) ;
void setRes20(uint8_t val) ;
void setRes21(uint8_t val) ;
void setRes22(uint8_t val) ;
void setRes23(uint8_t val) ;

// pcf8575_7 => 0x26
void set8inF(uint8_t val)  ;
void set9inA(uint8_t val)  ;
void set9inB(uint8_t val)  ;
void set9inF(uint8_t val)  ;
void set10inA(uint8_t val) ;
void set10inB(uint8_t val) ;
void set10inF(uint8_t val) ;
void set11inA(uint8_t val) ;
void setDin10(uint8_t val) ;
void setDin11(uint8_t val) ;
void setDin12(uint8_t val) ;
void setDin13(uint8_t val) ;
void setDin14(uint8_t val) ;
void setDin15(uint8_t val) ;
void setDin16(uint8_t val) ;
void setDin17(uint8_t val) ;

// pcf8575_8 => 0x27
void setJin9(uint8_t val)  ;
void setJin10(uint8_t val) ;
void setJin11(uint8_t val) ;
void setJin13(uint8_t val) ;
void setJin14(uint8_t val) ;
void setJin15(uint8_t val) ;
void setJin16(uint8_t val) ;
void setJin17(uint8_t val) ;
void setRes24(uint8_t val) ;
void setRes25(uint8_t val) ;
void setRes26(uint8_t val) ;
void setRes27(uint8_t val) ;
void setRes28(uint8_t val) ;
void setRes29(uint8_t val) ;
void setRes30(uint8_t val) ;
void setRes31(uint8_t val) ;

}

#endif