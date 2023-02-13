#ifndef COMMAND_H
#define COMMAND_H

// einkommentieren um debugausgaben zu aktivieren
#define COMMAND_DEBUG

#ifdef COMMAND_DEBUG
	#define COMMAND_DEBUG_PRINT(...) { Serial.print(__VA_ARGS__); }
	#define COMMAND_DEBUG_PRINTLN(...) { Serial.println(__VA_ARGS__); }
#else
	#define COMMAND_DEBUG_PRINT(...) {}
	#define COMMAND_DEBUG_PRINTLN(...) {}
#endif

namespace CCommand
{
  #include "command_rail_input.h" // excel generiertes zeugs
  #include "command_rail_output.h" // excel generiertes zeugs
  const uint8_t N_COMMANDS = 16;

  uint32_t cmdInputs1_32;
  uint32_t cmdInputsA_Z;
  
  /**
   * entspricht bit position in cmdInputs
   */
  enum eRail
  {
    cNone = -1,
    c1 = 0,
    c2 = 1,
    c3 = 2,
    c4 = 3,
    c5 = 4,
    c6 = 5,
    c7 = 6,
    c8 = 7,
    c9 = 8,
    c10 = 9,
    c11 = 10,
    c12 = 11,
    c13 = 12,
    c14 = 13,
    c15 = 14,
    c16 = 15,
    c17 = 16,
    c18 = 17,
    c19 = 18,
    c20 = 19,

    cA = 32, // offset 32
    cB = 33,
    cC = 34,
    cD = 35,

    cF = 36,
    cG = 37,
    cH = 38,

    cJ = 39,
    cK = 40,
    cL = 41,
    cM = 42,
    cN = 43,

    cR = 44,
    cS = 45,
    cT = 46
  };
  void setCmdInput1_32(eRail cmdIn, bool val);
  void setCmdInputA_Z(eRail cmdIn, bool val);

  // alle moeglichen kombinationen / je kombination = 1 ausgang.
  // entspricht auch array idx im funktionspointer array setOut
  enum eCMD
  {
    NONE = -1,
    i1_IN_A = 0,
    i2_IN_A = 1,
    i3_IN_A = 2,
    i4_IN_A = 3,
    i5_IN_A = 4,
    i6_IN_A = 5,
    i7_IN_A = 6,
    i8_IN_A = 7,
    i9_IN_A = 8,
    i10_IN_A = 9,
    i11_IN_A = 10,
    i12_IN_A = 11,
    i13_IN_A = 12,
    i14_IN_A = 13,
    i15_IN_A = 14,
    i16_IN_A = 15,
    i17_IN_A = 16,
    i18_IN_A = 17,
    i19_IN_A = 18,
    i1_IN_B = 19,
    i2_IN_B = 20,
    i3_IN_B = 21,
    i4_IN_B = 22,
    i5_IN_B = 23,
    i6_IN_B = 24,
    i7_IN_B = 25,
    i8_IN_B = 26,
    i9_IN_B = 27,
    i10_IN_B = 28,
    i11_IN_B = 29,
    i12_IN_B = 30,
    i13_IN_B = 31,
    i14_IN_B = 32,
    i15_IN_B = 33,
    i16_IN_B = 34,
    i17_IN_B = 35,
    i18_IN_B = 36,
    i19_IN_B = 37,
    iC_IN_1 = 38,
    iC_IN_2 = 39,
    iC_IN_3 = 40,
    iC_IN_4 = 41,
    iC_IN_5 = 42,
    iC_IN_6 = 43,
    iC_IN_7 = 44,
    iC_IN_8 = 45,
    iC_IN_9 = 46,
    iC_IN_10 = 47,
    iC_IN_11 = 48,
    iC_IN_12 = 49,
    iC_IN_13 = 50,
    iC_IN_14 = 51,
    iC_IN_15 = 52,
    iC_IN_16 = 53,
    iC_IN_17 = 54,
    iC_IN_18 = 55,
    iC_IN_19 = 56,
    iD_IN_1 = 57,
    iD_IN_2 = 58,
    iD_IN_3 = 59,
    iD_IN_4 = 60,
    iD_IN_5 = 61,
    iD_IN_6 = 62,
    iD_IN_7 = 63,
    iD_IN_8 = 64,
    iD_IN_9 = 65,
    iD_IN_10 = 66,
    iD_IN_11 = 67,
    iD_IN_12 = 68,
    iD_IN_13 = 69,
    iD_IN_14 = 70,
    iD_IN_15 = 71,
    iD_IN_16 = 72,
    iD_IN_17 = 73,
    iD_IN_18 = 74,
    iD_IN_19 = 75,
    i5_IN_F = 76,
    i6_IN_F = 77,
    i7_IN_F = 78,
    i8_IN_F = 79,
    i9_IN_F = 80,
    i10_IN_F = 81,
    i11_IN_F = 82,
    i12_IN_T = 83,
    i13_IN_T = 84,
    i14_IN_T = 85,
    i15_IN_T = 86,
    i16_IN_T = 87,
    i17_IN_T = 88,
    i18_IN_T = 89,
    i19_IN_T = 90,
    i1_IN_G = 91,
    i2_IN_G = 92,
    i3_IN_G = 93,
    i4_IN_G = 94,
    i13_IN_G = 95,
    i14_IN_G = 96,
    i15_IN_G = 97,
    i16_IN_G = 98,
    i17_IN_G = 99,
    i18_IN_G = 100,
    i19_IN_G = 101,
    iH_IN_1 = 102,
    iH_IN_2 = 103,
    iH_IN_3 = 104,
    iH_IN_4 = 105,
    iJ_IN_5 = 106,
    iJ_IN_6 = 107,
    iJ_IN_7 = 108,
    iJ_IN_8 = 109,
    iJ_IN_9 = 110,
    iJ_IN_10 = 111,
    iJ_IN_11 = 112,
    iJ_IN_12 = 113,
    iJ_IN_13 = 114,
    iJ_IN_14 = 115,
    iJ_IN_15 = 116,
    iJ_IN_16 = 117,
    iJ_IN_17 = 118,
    iJ_IN_18 = 119,
    iJ_IN_19 = 120,
    i12_IN_K = 121,
    i20_IN_K = 122,
    i13_IN_K = 123,
    i14_IN_K = 124,
    i4_IN_L = 125,
    i6_IN_L = 126,
    i8_IN_L = 127,
    i9_IN_L = 128,
    i12_IN_L = 129,
    i20_IN_L = 130,
    i13_IN_R = 131,
    i14_IN_R = 132,
    iK_IN_12 = 133,
    iK_IN_20 = 134,
    iK_IN_13 = 135,
    iK_IN_14 = 136,
    iR_IN_13 = 137,
    iR_IN_14 = 138,
    i19_IN_M = 139,
    iM_IN_19 = 140,
    iP_IN_12 = 141,
    i1_IN_N = 142,
    iN_IN_1 = 143

  };

  struct commandStruct
  {
    bool active; // aktiv oder nicht
    eRail src;
    eRail target;
    eCMD railCombi; // ausgang/relais um src mit target zu verbinden => gleichzeitig zum indizieren von ausgangsfunktion und belegtfunktion
    bool railReleaseState; // bei ausfahrtsgleisen wird bei flanke 1 -> 0 der auftrag wieder zurueckgesetzt

    // vllt so....
    //bool (*doneFctPtr)(); //* funktionspointer auf bedingung damit auftrag fertig ist. z.b. getRailInput1li()
  };
  commandStruct activeCommands[N_COMMANDS]; // befehle die gleichzeitig aktiv sein koennen

  /**
   * pruefung ob neuer auftrag bei aktiv bestehendem moeglich ist
   * @returns 
   *   1 wenn auftrag ok
   *   -1 wenn ungueltig
   *   -2 alle auftraege  belegt 
   *   0 kein neuer noetig
   */
  int8_t checkAndActivateNewCommand();

  /**
   * pruefen ob bestehender auftrag beendet werden kann.
   * Ziel erreicht ? 
   */
  void checkAndFinishRunningCommand();

  void updateSrcTarget();
  eRail curSrc; // -1 = keins
  eRail curTarget; // -1 = keins
  eRail oldSrc; // -1 = keins
  eRail oldTarget; // -1 = keins

  uint8_t activeCmdCount; // wie viele auftraege sind aktiv ?
  inline uint8_t getActiveCmdCount(){return activeCmdCount;};

  void finishCmd(commandStruct &cmd);
  void resetAllCmds();
  void finishCmdByIdx(uint8_t idx);
  
  eCMD mapSrcTarget2Cmd(eRail src, eRail target);

};
#endif