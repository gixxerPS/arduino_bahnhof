#include "command.h"
#include "command_conditions.h"

void CCommand::setCmdInput1_32(eRail cmdIn, bool val)
{
    uint8_t offs = cmdIn % 32; // z.B. 34%32 = 2 | 8%32 = 8
    if (val) {
        cmdInputs1_32 |= ((uint32_t)1<<offs);
    } else {
        cmdInputs1_32 &= ~((uint32_t)1<<offs);
    }
}

void CCommand::setCmdInputA_Z(eRail cmdIn, bool val)
{
    uint8_t offs = (cmdIn-32) % 32; // z.B. 34%32 = 2 | 8%32 = 8
    if (val) {
        cmdInputsA_Z |= ((uint32_t)1<<offs);
    } else {
        cmdInputsA_Z &= ~((uint32_t)1<<offs);
    }
}

// das waere eigtl auch die stelle an der man die bedingung / den eingang
// zum aufheben des befehls verwenden koennte
eCMD CCommand::mapSrcTarget2Cmd(eRail src, eRail target) {
    eCMD ret = NONE;
    if (src == c1) { // 1in...
        if (target == cA) {ret = i1_IN_A;}
        else if (target == cB) {ret = i1_IN_B;}
        else if (target == cG) {ret = i1_IN_G;}
        else if (target == cN) {ret = i1_IN_N;}
    } else if (src == c2) { // 2in...
        if (target == cA) {ret = i2_IN_A;}
        else if (target == cB) {ret = i2_IN_B;}
        else if (target == cG) {ret = i2_IN_G;}
    } else if (src == c3) { // 3in...
        if (target == cA) {ret = i3_IN_A;}
        else if (target == cB) {ret = i3_IN_B;}
        else if (target == cG) {ret = i3_IN_G;}
    } else if (src == c4) { // 4in...
        if (target == cA) {ret = i4_IN_A;}
        else if (target == cB) {ret = i4_IN_B;}
        else if (target == cG) {ret = i4_IN_G;}
        else if (target == cL) {ret = i4_IN_L;}
    } else if (src == c5) { // 5in...
        if (target == cA) {ret = i5_IN_A;}
        else if (target == cB) {ret = i5_IN_B;}
        else if (target == cF) {ret = i5_IN_F;}
    } else if (src == c6) { // 6in...
        if (target == cA) {ret = i6_IN_A;}
        else if (target == cB) {ret = i6_IN_B;}
        else if (target == cF) {ret = i6_IN_F;}
        else if (target == cL) {ret = i6_IN_L;}
    } else if (src == c7) { // 7in...
        if (target == cA) {ret = i7_IN_A;}
        else if (target == cB) {ret = i7_IN_B;}
        else if (target == cF) {ret = i7_IN_F;}
    } else if (src == c8) { // 8in...
        if (target == cA) {ret = i8_IN_A;}
        else if (target == cB) {ret = i8_IN_B;}
        else if (target == cF) {ret = i8_IN_F;}
        else if (target == cL) {ret = i8_IN_L;}
    } else if (src == c9) { // 9in...
        if (target == cA) {ret = i9_IN_A;}
        else if (target == cB) {ret = i9_IN_B;}
        else if (target == cF) {ret = i9_IN_F;}
        else if (target == cL) {ret = i9_IN_L;}
    } else if (src == c10) { // 10in...
        if (target == cA) {ret = i10_IN_A;}
        else if (target == cB) {ret = i10_IN_B;}
        else if (target == cF) {ret = i10_IN_F;}
    } else if (src == c11) { // 11in...
        if (target == cA) {ret = i11_IN_A;}
        else if (target == cB) {ret = i11_IN_B;}
        else if (target == cF) {ret = i11_IN_F;}
    } else if (src == c12) { // 12in...
        if (target == cK) {ret = i12_IN_K;}
        else if (target == cL) {ret = i12_IN_L;}
    } else if (src == c13) { // 13in...
        if (target == cA) {ret = i13_IN_A;}
        else if (target == cB) {ret = i13_IN_B;}
        else if (target == cG) {ret = i13_IN_G;}
        else if (target == cK) {ret = i13_IN_K;}
        else if (target == cR) {ret = i13_IN_R;}
        else if (target == cF) {ret = i13_IN_T;} // 13inF = 13inT
    } else if (src == c14) { // 14in...
        if (target == cA) {ret = i14_IN_A;}
        else if (target == cB) {ret = i14_IN_B;}
        else if (target == cG) {ret = i14_IN_G;}
        else if (target == cK) {ret = i14_IN_K;}
        else if (target == cR) {ret = i14_IN_R;}
        else if (target == cF) {ret = i14_IN_T;} // 14inF = 14inT
    } else if (src == c15) { // 15in...
        if (target == cA) {ret = i15_IN_A;}
        else if (target == cB) {ret = i15_IN_B;}
        else if (target == cG) {ret = i15_IN_G;}
        else if (target == cF) {ret = i15_IN_T;} // 15inF = 15inT
    } else if (src == c16) { // 16in...
        if (target == cA) {ret = i16_IN_A;}
        else if (target == cB) {ret = i16_IN_B;}
        else if (target == cG) {ret = i16_IN_G;}
        else if (target == cF) {ret = i16_IN_T;} // 16inF = 16inT
    } else if (src == c17) { // 17in...
        if (target == cA) {ret = i17_IN_A;}
        else if (target == cB) {ret = i17_IN_B;}
        else if (target == cG) {ret = i17_IN_G;}
        else if (target == cF) {ret = i17_IN_T;} // 17inF = 17inT
    } else if (src == c18) { // 18in...
        if (target == cA) {ret = i18_IN_A;}
        else if (target == cB) {ret = i18_IN_B;}
        else if (target == cG) {ret = i18_IN_G;}
        else if (target == cF) {ret = i18_IN_T;} // 18inF = 18inT
    } else if (src == c19) { // 19in...
        if (target == cA) {ret = i19_IN_A;}
        else if (target == cB) {ret = i19_IN_B;}
        else if (target == cG) {ret = i19_IN_G;}
        else if (target == cM) {ret = i19_IN_M;}
        else if (target == cF) {ret = i19_IN_T;} // 19inF = 19inT
    } else if (src == c20) { // 20in...
        if (target == cK) {ret = i20_IN_K;}
        else if (target == cL) {ret = i20_IN_L;}
    } else if (src == cC) { // Cin...
        if (target == c1) {ret = iC_IN_1;}
        else if (target == c2) {ret = iC_IN_2;}
        else if (target == c3) {ret = iC_IN_3;}
        else if (target == c4) {ret = iC_IN_4;}
        else if (target == c5) {ret = iC_IN_5;}
        else if (target == c6) {ret = iC_IN_6;}
        else if (target == c7) {ret = iC_IN_7;}
        else if (target == c8) {ret = iC_IN_8;}
        else if (target == c9) {ret = iC_IN_9;}
        else if (target == c10) {ret = iC_IN_10;}
        else if (target == c11) {ret = iC_IN_11;}
        else if (target == c13) {ret = iC_IN_13;}
        else if (target == c14) {ret = iC_IN_14;}
        else if (target == c15) {ret = iC_IN_15;}
        else if (target == c16) {ret = iC_IN_16;}
        else if (target == c17) {ret = iC_IN_17;}
        else if (target == c18) {ret = iC_IN_18;}
        else if (target == c19) {ret = iC_IN_19;}
    } else if (src == cD) { // Din...
        if (target == c1) {ret = iD_IN_1;}
        else if (target == c2) {ret = iD_IN_2;}
        else if (target == c3) {ret = iD_IN_3;}
        else if (target == c4) {ret = iD_IN_4;}
        else if (target == c5) {ret = iD_IN_5;}
        else if (target == c6) {ret = iD_IN_6;}
        else if (target == c7) {ret = iD_IN_7;}
        else if (target == c8) {ret = iD_IN_8;}
        else if (target == c9) {ret = iD_IN_9;}
        else if (target == c10) {ret = iD_IN_10;}
        else if (target == c11) {ret = iD_IN_11;}
        else if (target == c13) {ret = iD_IN_13;}
        else if (target == c14) {ret = iD_IN_14;}
        else if (target == c15) {ret = iD_IN_15;}
        else if (target == c16) {ret = iD_IN_16;}
        else if (target == c17) {ret = iD_IN_17;}
        else if (target == c18) {ret = iD_IN_18;}
        else if (target == c19) {ret = iD_IN_19;}
    } else if (src == cH) { // Hin...
        if (target == c1) {ret = iH_IN_1;}
        else if (target == c2) {ret = iH_IN_2;}
        else if (target == c3) {ret = iH_IN_3;}
        else if (target == c4) {ret = iH_IN_4;}
        else if (target == c5) {ret = iD_IN_5;};
    } else if (src == cJ) { // Jin...
        if (target == c5) {ret = iJ_IN_5;}
        else if (target == c6) {ret = iJ_IN_6;}
        else if (target == c7) {ret = iJ_IN_7;}
        else if (target == c8) {ret = iJ_IN_8;}
        else if (target == c9) {ret = iJ_IN_9;}
        else if (target == c10) {ret = iJ_IN_10;}
        else if (target == c11) {ret = iJ_IN_11;}
        else if (target == c13) {ret = iJ_IN_13;}
        else if (target == c14) {ret = iJ_IN_14;}
        else if (target == c15) {ret = iJ_IN_15;}
        else if (target == c16) {ret = iJ_IN_16;}
        else if (target == c17) {ret = iJ_IN_17;}
        else if (target == c18) {ret = iJ_IN_18;}
        else if (target == c19) {ret = iJ_IN_19;}
    } else if (src == cK) { // Kin...
        if (target == c12) {ret = iK_IN_12;}
        else if (target == c13) {ret = iK_IN_13;}
        else if (target == c14) {ret = iK_IN_14;}
        else if (target == c20) {ret = iK_IN_20;}
    } else if (src == cL) { // Lin...
        if (target == c4) {ret = iL_IN_4;}
        else if (target == c6) {ret = iL_IN_6;}
        else if (target == c8) {ret = iL_IN_8;}
        else if (target == c9) {ret = iL_IN_9;}
        else if (target == c12) {ret = iL_IN_12;}
        else if (target == c20) {ret = iL_IN_20;}
    } else if (src == cM) { // Min...
        if (target == c19) {ret = iM_IN_19;}
    } else if (src == cN) { // Nin...
        if (target == c1) {ret = iN_IN_1;}
    } else if (src == cR) { // Rin...
        if (target == c13) {ret = iR_IN_13;}
        else if (target == c14) {ret = iR_IN_14;}
    // } else if (src == cL) { // Reihenfolge egal bei *inL
    //     if (target == c4) {ret = i4_IN_L;}
    //     else if (target == c6) {ret = i6_IN_L;}
    //     else if (target == c8) {ret = i8_IN_L;}
    //     else if (target == c9) {ret = i9_IN_L;}
    //     else if (target == c12) {ret = i12_IN_L;}
    //     else if (target == c20) {ret = i20_IN_L;}
    } else if (src == cR) { // Reihenfolge egal bei *inR
        if (target == c13) {ret = i13_IN_R;}
        else if (target == c14) {ret = i14_IN_R;}
    }
    return ret;
}

/**
 * @returns 
 *   1 wenn auftrag ok
 *   -1 wenn ungueltig
 *   -2 alle auftraege  belegt 
 *   -3 gleis belegt
 *   -4 durch anderen auftrag blockiert 
 *   0 kein neuer noetig
 */
int8_t CCommand::checkAndActivateNewCommand()
{
    int8_t fullIdx = -1;
    

    // keine quelle ODER kein ziel ausgewaehlt ?
    if (curSrc == cNone || curTarget == cNone) {
        return 0; // nix zu tun
    }
    // gleicher zustand wie im letzten durchlauf ?
    if (curSrc == oldSrc && curTarget == oldTarget) {
        return 0; // nix zu tun
    }

    // 0. kombination ueberhaupt gueltig ?
    eCMD cmd = mapSrcTarget2Cmd(curSrc, curTarget);
    if (cmd == NONE) {
        return -1;
    }

    // 1. ist noch platz im auftragsbuch frei ?
    // 2. wird kombi durch bereits aktivem auftrag verhindert ?
    for (int i = N_COMMANDS-1; i >= 0; i--) { // wg fullIdx rueckwaerts damit letzte freie stelle kleinsten idx im auftrags array bekommt
        if (activeCommands[i].active) {
            COMMAND_DEBUG_PRINT("Auftrag aktiv:");
            COMMAND_DEBUG_PRINTLN(i);

            if (cmdBlocksCurSrcTarget(activeCommands[i])) { // curSrc ODER curTarget bereits im Einsatz ?
                return -4;
            } else if (curTarget == c1) {
                if (curSrc == cC && cmdBlocksCin1(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin1(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cH && cmdBlocksHin1(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c2) {
                if (curSrc == cC && cmdBlocksCin2(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin2(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cH && cmdBlocksHin2(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c3) {
                if (curSrc == cC && cmdBlocksCin3(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin3(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cH && cmdBlocksHin3(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c4) {
                if (curSrc == cC && cmdBlocksCin4(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin4(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cH && cmdBlocksHin4(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cL && cmdBlocksLin4(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c5) {
                if (curSrc == cC && cmdBlocksCin5(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin5(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cJ && cmdBlocksJin5(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c6) {
                if (curSrc == cC && cmdBlocksCin6(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin6(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cJ && cmdBlocksJin6(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cL && cmdBlocksLin6(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c7) {
                if (curSrc == cC && cmdBlocksCin7(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin7(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cJ && cmdBlocksJin7(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c8) {
                if (curSrc == cC && cmdBlocksCin8(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin8(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cJ && cmdBlocksJin8(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cL && cmdBlocksLin8(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c9) {
                if (curSrc == cC && cmdBlocksCin9(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin9(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cJ && cmdBlocksJin9(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cL && cmdBlocksLin9(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c10) {
                if (curSrc == cC && cmdBlocksCin10(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin10(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cJ && cmdBlocksJin10(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c11) {
                if (curSrc == cC && cmdBlocksCin11(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin11(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cJ && cmdBlocksJin11(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c12) {
                if (curSrc == cK && cmdBlocksKin12(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cL && cmdBlocksLin12(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c13) {
                if (curSrc == cC && cmdBlocksCin13(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin13(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cK && cmdBlocksKin13(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cJ && cmdBlocksJin13(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cR && cmdBlocksRin13(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c14) {
                if (curSrc == cC && cmdBlocksCin14(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin14(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cK && cmdBlocksKin14(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cJ && cmdBlocksJin14(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cR && cmdBlocksRin14(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c15) {
                if (curSrc == cC && cmdBlocksCin15(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin15(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cJ && cmdBlocksJin15(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c16) {
                if (curSrc == cC && cmdBlocksCin16(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin16(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cJ && cmdBlocksJin16(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c17) {
                if (curSrc == cC && cmdBlocksCin17(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin17(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cJ && cmdBlocksJin17(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c18) {
                if (curSrc == cC && cmdBlocksCin18(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin18(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cJ && cmdBlocksJin18(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c19) {
                if (curSrc == cC && cmdBlocksCin19(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cD && cmdBlocksDin19(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cJ && cmdBlocksJin19(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == c20) {
                if (curSrc == cK && cmdBlocksKin20(activeCommands[i])) {
                    return -4;
                } else if (curSrc == cL && cmdBlocksLin20(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == cA) {
                if (curSrc == c1 && cmdBlocks1inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c2 && cmdBlocks2inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c3 && cmdBlocks3inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c4 && cmdBlocks4inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c5 && cmdBlocks5inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c6 && cmdBlocks6inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c7 && cmdBlocks7inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c8 && cmdBlocks8inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c9 && cmdBlocks9inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c10 && cmdBlocks10inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c11 && cmdBlocks11inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c13 && cmdBlocks13inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c14 && cmdBlocks14inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c15 && cmdBlocks15inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c16 && cmdBlocks16inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c17 && cmdBlocks17inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c18 && cmdBlocks18inA(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c19 && cmdBlocks19inA(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == cB) {
                if (curSrc == c1 && cmdBlocks1inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c2 && cmdBlocks2inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c3 && cmdBlocks3inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c4 && cmdBlocks4inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c5 && cmdBlocks5inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c6 && cmdBlocks6inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c7 && cmdBlocks7inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c8 && cmdBlocks8inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c9 && cmdBlocks9inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c10 && cmdBlocks10inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c11 && cmdBlocks11inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c13 && cmdBlocks13inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c14 && cmdBlocks14inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c15 && cmdBlocks15inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c16 && cmdBlocks16inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c17 && cmdBlocks17inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c18 && cmdBlocks18inB(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c19 && cmdBlocks19inB(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == cF) {
                if (curSrc == c5 && cmdBlocks5inF(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c6 && cmdBlocks6inF(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c7 && cmdBlocks7inF(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c8 && cmdBlocks8inF(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c9 && cmdBlocks9inF(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c10 && cmdBlocks10inF(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c11 && cmdBlocks11inF(activeCommands[i])) {
                    return -4;
                // 13inF -> 13inT
                } else if (curSrc == c13 && cmdBlocks13inT(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c14 && cmdBlocks14inT(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c15 && cmdBlocks15inT(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c16 && cmdBlocks16inT(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c17 && cmdBlocks17inT(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c18 && cmdBlocks18inT(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c19 && cmdBlocks19inT(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == cG) {
                if (curSrc == c1 && cmdBlocks1inG(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c2 && cmdBlocks2inG(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c3 && cmdBlocks3inG(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c4 && cmdBlocks4inG(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c13 && cmdBlocks13inG(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c14 && cmdBlocks14inG(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c15 && cmdBlocks15inG(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c16 && cmdBlocks16inG(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c17 && cmdBlocks17inG(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c18 && cmdBlocks18inG(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c19 && cmdBlocks19inG(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == cK) {
                if (curSrc == c12 && cmdBlocks12inK(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c13 && cmdBlocks13inK(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c14 && cmdBlocks14inK(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c20 && cmdBlocks20inK(activeCommands[i])) {
                    return -4;
                } 
            } else if (curTarget == cL) {
                if (curSrc == c4 && cmdBlocks4inL(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c6 && cmdBlocks6inL(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c8 && cmdBlocks8inL(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c9 && cmdBlocks9inL(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c12 && cmdBlocks12inL(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c20 && cmdBlocks20inL(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == cR) {
                if (curSrc == c13 && cmdBlocks13inR(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c14 && cmdBlocks14inR(activeCommands[i])) {
                    return -4;
                }
            } else if (curTarget == cT) {
                if (curSrc == c13 && cmdBlocks13inT(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c14 && cmdBlocks14inT(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c15 && cmdBlocks15inT(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c16 && cmdBlocks16inT(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c17 && cmdBlocks17inT(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c18 && cmdBlocks18inT(activeCommands[i])) {
                    return -4;
                } else if (curSrc == c19 && cmdBlocks19inT(activeCommands[i])) {
                    return -4;
                }
            }
        } else { // stelle merken an der noch platz ist 
            fullIdx = i;
        }
    }
    if (fullIdx < 0) { // voll
        return -2;
    }

    // 3. wird kombi durch gleis belegt verhindert ?
    if (curTarget == c1 && getRailInput1bel()) {
        return -3;
    } else if (curTarget == c2 && getRailInput2bel()) {
        return -3;
    } else if (curTarget == c3 && getRailInput3bel()) {
        return -3;
    } else if (curTarget == c4 && getRailInput4bel() && curSrc != cL) {
        return -3;
    } else if (curTarget == c5 && getRailInput5bel()) {
        return -3;
    } else if (curTarget == c6 && getRailInput6bel() && curSrc != cL) {
        return -3;
    } else if (curTarget == c7 && getRailInput7bel()) {
        return -3;
    } else if (curTarget == c8 && getRailInput8bel() && curSrc != cL) {
        return -3;
    } else if (curTarget == c9 && getRailInput9bel() && curSrc != cL) {
        return -3;
    } else if (curTarget == c10 && getRailInput10bel()) {
        return -3;
    } else if (curTarget == c11 && getRailInput11bel()) {
        return -3;
    } else if (curTarget == c12 && getRailInput12bel() && curSrc != cL) {
        return -3;
    } else if (curTarget == c13 && getRailInput13bel() && curSrc != cK && curSrc != cR) {
        return -3;
    } else if (curTarget == c14 && getRailInput14bel() && curSrc != cK && curSrc != cR) {
        return -3;
    } else if (curTarget == c15 && getRailInput15bel()) {
        return -3;
    } else if (curTarget == c16 && getRailInput16bel()) {
        return -3;
    } else if (curTarget == c17 && getRailInput17bel()) {
        return -3;
    } else if (curTarget == c18 && getRailInput18bel()) {
        return -3;
    } else if (curTarget == c19 && getRailInput19bel() && curSrc != cM) {
        return -3;
    } else if (curTarget == cA && getRailInputAbel()) {
        return -3;
    } else if (curTarget == cB && getRailInputBbel()) {
        return -3;
    } else if (curTarget == cF) {
        if (getRailInputFbel()) {
            return -3;
        } else if (getRailInputTbel()) {
            return -3;
        }
    } else if (curTarget == cG) {
        if (getRailInputSbel()) {
            return -3;
        } else if (curSrc == c1 || curSrc == c2 || curSrc == c3 || curSrc == c4) {
            if (getRailInputGbel2()) {
                return -3;
            }
        } else if (curSrc == c13 || curSrc == c14 || curSrc == c15 || curSrc == c16 || curSrc == c17 || curSrc == c18 || curSrc == c19 ) {
            if (getRailInputGbel()) {
                return -3;
            }
        }
    } else if (curTarget == cK && getRailInputKbel()) {
        return -3;
    } else if (curTarget == cL && getRailInputLbel()) {
        return -3;
    } else if (curTarget == cN && getRailInputNbel()) {
        return -3;
    // } else if (curTarget == cR && getRailInputRbel()) { AKTUELL keine belegt meldung
    //     return -3;
    } else if (curTarget == cT && getRailInputTbel()) {
        return -3;
    } else if (curSrc == cH && getRailInputSbel()) {
        return -3;
    }

    // kombination gueltig ?
    // nichts spricht dagegen ?
    // dann auftrag akzeptieren
    if (fullIdx >= 0 && fullIdx <= N_COMMANDS) { // nur sicherheit, sollte eigtl immer gegeben sein
        activeCommands[fullIdx].active = true;
        activeCommands[fullIdx].src = curSrc;
        activeCommands[fullIdx].target = curTarget;
        activeCommands[fullIdx].railReleaseState = false;
        activeCommands[fullIdx].railCombi = cmd;
        setOut[activeCommands[fullIdx].railCombi](HIGH); // hier den ausgang setzen / relais einschalten

        // einfahrtsignal schalten ?
        if (curSrc == cC) {
            setCein(HIGH);
        } else if (curSrc == cD) {
            setDein(HIGH);
        } else if (curSrc == cH) {
            setHein(HIGH);
        } else if (curSrc == cJ) {
            setJein(HIGH);
        }

        // gleissperrsignal schalten ?
        if (curSrc == cK) {
            setKgsp(HIGH);
            activeCommands[fullIdx].gspTime = millis();
        } else if (curSrc == cL) {
            setLgsp(HIGH);
            activeCommands[fullIdx].gspTime = millis();
        } else if (curSrc == cM || curTarget == cM) {
            setMgsp(HIGH);
            activeCommands[fullIdx].gspTime = millis();
        } else if (curSrc == cR) {
            setRgsp(HIGH);
            activeCommands[fullIdx].gspTime = millis();
        } else if (curSrc == c12 || curSrc == c20) {
            set12gsp(HIGH);
            activeCommands[fullIdx].gspTime = millis();
        } else {
            activeCommands[fullIdx].gspTime = 0;
        }

        Serial.print("Auftrag Nr ");
        Serial.print(fullIdx);
        Serial.print(" akzeptiert. Quelle = ");
        Serial.print(curSrc);
        Serial.print(". Ziel = ");
        Serial.print(curTarget);
        Serial.print(" gsp Zeit = ");
        Serial.println(activeCommands[fullIdx].gspTime);
    }

    return 1;
}

/** 
 * mit binaerer suche treffer in maximal 5 operationen.
 * sind mehrere bits gesetzt wird nur die position des niederwertigsten
 * ausgegeben.
 * @return -1 wenn kein bit gesetzt, sonst bit position
 */
int8_t getBitPosInt32(uint32_t x) {
    if (x == 0) {
        return -1;
    }
    if (x & 0xFFFF) { // bit in rechter haelfte gesetzt?
        if (x & 0xFF) { // bit in rechter haelfte gesetzt?
            if (x & 0xF) { // bit in rechter haelfte gesetzt?
                if (x & 0x3) { // bit in rechter haelfte gesetzt?
                    if (x & 0x1) { // bit in rechter haelfte gesetzt?
                        return 0;
                    } else { // bit in linker haelfte gesetzt
                        return 1;
                    }
                } else { // bit in linker haelfte gesetzt => 0xC
                    if (x & 0x4) { // bit in rechter haelfte gesetzt?
                        return 2;
                    } else { // bit in linker haelfte gesetzt
                        return 3;
                    }
                }
            } else { // bit in linker haelfte gesetzt => 0xF0
                if (x & 0x30) { // bit in rechter haelfte gesetzt?
                    if (x & 0x10) { // bit in rechter haelfte gesetzt?
                        return 4;
                    } else { // bit in linker haelfte gesetzt
                        return 5;
                    }
                } else { // bit in linker haelfte gesetzt => 0xC0
                    if (x & 0x40) { // bit in rechter haelfte gesetzt?
                        return 6;
                    } else { // bit in linker haelfte gesetzt
                        return 7;
                    }
                }
            }
        } else { // bit in linker haelfte gesetzt => 0xFF00
            if (x & 0xF00) { // bit in rechter haelfte gesetzt?
                if (x & 0x300) { // bit in rechter haelfte gesetzt?
                    if (x & 0x100) { // bit in rechter haelfte gesetzt?
                        return 8;
                    } else { // bit in linker haelfte gesetzt
                        return 9;
                    }
                } else { // bit in linker haelfte gesetzt => 0xC00
                    if (x & 0x400) { // bit in rechter haelfte gesetzt?
                        return 10;
                    } else { // bit in linker haelfte gesetzt
                        return 11;
                    }
                }
            } else { // bit in linker haelfte gesetzt => 0xF000
                if (x & 0x3000) { // bit in rechter haelfte gesetzt?
                    if (x & 0x1000) { // bit in rechter haelfte gesetzt?
                        return 12;
                    } else { // bit in linker haelfte gesetzt => 
                        return 13;
                    }
                } else { // bit in linker haelfte gesetzt
                    if (x & 0x4000) { // bit in rechter haelfte gesetzt?
                        return 14;
                    } else { // bit in linker haelfte gesetzt
                        return 15;
                    }
                }
            }   
        }
    } else { // bit in linker haelfte gesetzt => 0xFFFF0000
        if (x & 0xFF0000) { // bit in rechter haelfte gesetzt?
            if (x & 0xF0000) { // bit in rechter haelfte gesetzt?
                if (x & 0x30000) { // bit in rechter haelfte gesetzt?
                    if (x & 0x10000) { // bit in rechter haelfte gesetzt?
                        return 16;
                    } else { // bit in linker haelfte gesetzt
                        return 17;
                    }
                } else { // bit in linker haelfte gesetzt => 0xC0000
                    if (x & 0x40000) { // bit in rechter haelfte gesetzt?
                        return 18;
                    } else { // bit in linker haelfte gesetzt
                        return 19;
                    }
                }
            } else { // bit in linker haelfte gesetzt => 0xF00000
                if (x & 0x300000) { // bit in rechter haelfte gesetzt?
                    if (x & 0x100000) { // bit in rechter haelfte gesetzt?
                        return 20;
                    } else { // bit in linker haelfte gesetzt
                        return 21;
                    }
                } else { // bit in linker haelfte gesetzt => 0xC00000
                    if (x & 0x400000) { // bit in rechter haelfte gesetzt?
                        return 22;
                    } else { // bit in linker haelfte gesetzt
                        return 23;
                    }
                }
            }
        } else { // bit in linker haelfte gesetzt => 0xFF000000
            if (x & 0xF000000) { // bit in rechter haelfte gesetzt?
                if (x & 0x3000000) { // bit in rechter haelfte gesetzt?
                    if (x & 0x1000000) { // bit in rechter haelfte gesetzt?
                        return 24;
                    } else { // bit in linker haelfte gesetzt
                        return 25;
                    }
                } else { // bit in linker haelfte gesetzt => 0xC000000
                    if (x & 0x4000000) { // bit in rechter haelfte gesetzt?
                        return 26;
                    } else { // bit in linker haelfte gesetzt
                        return 27;
                    }
                }
            } else { // bit in linker haelfte gesetzt => 0xF0000000
                if (x & 0x30000000) { // bit in rechter haelfte gesetzt?
                    if (x & 0x10000000) { // bit in rechter haelfte gesetzt?
                        return 28;
                    } else { // bit in linker haelfte gesetzt => 
                        return 29;
                    }
                } else { // bit in linker haelfte gesetzt
                    if (x & 0x40000000) { // bit in rechter haelfte gesetzt?
                        return 30;
                    } else { // bit in linker haelfte gesetzt
                        return 31;
                    }
                }
            }   
        }
    }
}

void CCommand::updateSrcTarget()
{
    int8_t bitPos1_32 = getBitPosInt32(cmdInputs1_32);
    int8_t bitPosA_Z = getBitPosInt32(cmdInputsA_Z);
    
    if (bitPos1_32 < 0 && bitPosA_Z < 0) {
        oldSrc = curSrc;
        curSrc = cNone;
        oldTarget = curTarget;
        curTarget = cNone;
        return;
    }
    oldSrc = curSrc;
    oldTarget = curTarget;
    if (curSrc == cNone && curTarget == cNone) {
        // 1-32 gedrueckt und nicht A-Z gedrueckt ?
        if (bitPos1_32 >= 0 && bitPosA_Z < 0) {
            curSrc = (eRail)bitPos1_32;
        // 1-32 nicht gedrueckt und A-Z gedrueckt ?
        } else if (bitPos1_32 < 0 && bitPosA_Z >= 0) {
            curSrc = (eRail)(bitPosA_Z+32);
        }
    } else if (curSrc != cNone && curTarget == cNone) {
        if (curSrc < 32) { // quelle = 1-32 ?
            // dann als ziel nur A-Z zulassen
            if (bitPosA_Z >= 0) {
                curTarget = (eRail)(bitPosA_Z+32);
            }
        } else if (curSrc >= 32) {// quelle = A-Z ?
            // dann als ziel nur 1-32 zulassen
            if (bitPos1_32 >= 0 ) {
                curTarget = (eRail)bitPos1_32;
            }
        }
    }
    
}
void CCommand::finishCmdByIdx(uint8_t idx)
{
    // COMMAND_DEBUG_PRINT("loesche idx ");
    // COMMAND_DEBUG_PRINTLN(idx);
    if (idx >= 0 && idx <= N_COMMANDS) {
        finishCmd(activeCommands[idx]);
    }
}
void CCommand::resetAllCmds()
{
    for (int i = 0; i < N_COMMANDS; i++) { 
        finishCmd(activeCommands[i]);
    }
}

void CCommand::finishCmd(commandStruct &cmd)
{
    if (cmd.src == cC) {
        setCein(LOW);
    } else if (cmd.src == cD) {
        setDein(LOW);
    } else if (cmd.src == cH) {
        setHein(LOW);
    } else if (cmd.src == cJ) {
        setJein(LOW);
    } 
    activeCmdCount--;
    cmd.active = false;
    setOut[cmd.railCombi](LOW); // hier den ausgang zuruecksetzen / relais ausschalten
}

void CCommand::checkAndFinishRunningCommand() 
{
    uint8_t activeCount = 0;
    for (int i = N_COMMANDS - 1; i >= 0; i--) { // wg fullIdx rueckwaerts damit letzte freie stelle kleinsten idx im auftrags array bekommt
        if (activeCommands[i].active) {
            activeCount++;
            // COMMAND_DEBUG_PRINT("check active[");
            // COMMAND_DEBUG_PRINT(i);
            // COMMAND_DEBUG_PRINT("]: src=");
            // COMMAND_DEBUG_PRINT(activeCommands[i].src);
            // COMMAND_DEBUG_PRINT(" target=");
            // COMMAND_DEBUG_PRINTLN(activeCommands[i].target);

            // gleissperrsignal nach zeit zuruecknehmen
            if (activeCommands[i].gspTime > 0 && millis() - activeCommands[i].gspTime > MS_GSP) {
                Serial.println("gleissperrzeit abgelaufen");
                if (activeCommands[i].src == cK) {
                    setKgsp(LOW);
                } else if (activeCommands[i].src == cL) {
                    setLgsp(LOW);
                } else if (activeCommands[i].src == cM || activeCommands[i].target == cM) {
                    setMgsp(LOW);
                } else if (activeCommands[i].src == cR) {
                    setRgsp(LOW);
                } else if (activeCommands[i].src == c12 || activeCommands[i].src == c20) {
                    set12gsp(LOW);
                }
            }

            if (activeCommands[i].target == c1 ) {
                if (activeCommands[i].src == cN || activeCommands[i].src == cH) {
                    if (getRailInput1re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput1li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c2) {
                if (activeCommands[i].src == cN || activeCommands[i].src == cH) {
                    if (getRailInput2re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput2li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c3) {
                if (activeCommands[i].src == cN || activeCommands[i].src == cH) {
                    if (getRailInput3re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput3li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c4) {
                if (activeCommands[i].src == cN || activeCommands[i].src == cH) {
                    if (getRailInput4re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput4li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c5) {
                if (activeCommands[i].src == cJ) {
                    if (getRailInput5re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput5li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c6) {
                if (activeCommands[i].src == cJ) {
                    if (getRailInput6re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput6li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c7) {
                if (activeCommands[i].src == cJ) {
                    if (getRailInput7re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput7li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c8) {
                if (activeCommands[i].src == cJ) {
                    if (getRailInput8re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput8li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c9) {
                if (activeCommands[i].src == cJ) {
                    if (getRailInput9re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput9li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c10) {
                if (activeCommands[i].src == cJ) {
                    if (getRailInput10re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput10li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c11) {
                if (activeCommands[i].src == cJ) {
                    if (getRailInput11re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput11li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c12) {
                    if (getRailInput12li()) {finishCmd(activeCommands[i]);}
            } else if (activeCommands[i].target == c13) {
                if (activeCommands[i].src == cJ) {
                    if (getRailInput13re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput13li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c14) {
                if (activeCommands[i].src == cJ) {
                    if (getRailInput14re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput14li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c15) {
                if (activeCommands[i].src == cJ) {
                    if (getRailInput15re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput15li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c16) {
                if (activeCommands[i].src == cJ) {
                    if (getRailInput16re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput16li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c17) {
                if (activeCommands[i].src == cJ) {
                    if (getRailInput17re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput17li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c18) {
                if (activeCommands[i].src == cJ) {
                    if (getRailInput18re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput18li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c19) {
                if (activeCommands[i].src == cJ) {
                    if (getRailInput19re()) {finishCmd(activeCommands[i]);}
                } else {
                    if (getRailInput19li()) {finishCmd(activeCommands[i]);}
                }
            } else if (activeCommands[i].target == c20) {
                    if (getRailInput20li()) {finishCmd(activeCommands[i]);}
            } else if (activeCommands[i].target == cA) {
                // negative flanke von ausfahrtsgleis setzt auftrag zurueck
                if (activeCommands[i].railReleaseState && !getRailInputAbel()) {
                    finishCmd(activeCommands[i]);
                } else {
                    activeCommands[i].railReleaseState = getRailInputAbel();
                }
            } else if (activeCommands[i].target == cB) {
                // negative flanke von ausfahrtsgleis setzt auftrag zurueck
                if (activeCommands[i].railReleaseState && !getRailInputBbel()) {
                    finishCmd(activeCommands[i]);
                } else {
                    activeCommands[i].railReleaseState = getRailInputBbel();
                }
            } else if (activeCommands[i].target == cK) {
                    if (getRailInputKre()) {finishCmd(activeCommands[i]);}
            } else if (activeCommands[i].target == cL) {
                    if (getRailInputLre()) {finishCmd(activeCommands[i]);}
            } else if (activeCommands[i].target == cG) {
                if (activeCommands[i].src == c1 || activeCommands[i].src == c2 || activeCommands[i].src == c3 || activeCommands[i].src == c4) {
                    // negative flanke von ausfahrtsgleis setzt auftrag zurueck
                    if (activeCommands[i].railReleaseState && !getRailInputGbel2()) {
                        finishCmd(activeCommands[i]);
                    } else {
                        activeCommands[i].railReleaseState = getRailInputGbel2();
                    }
                } else if (activeCommands[i].src == c13 || activeCommands[i].src == c14 || activeCommands[i].src == c15 || activeCommands[i].src == c16 || activeCommands[i].src == c17 || activeCommands[i].src == c18 || activeCommands[i].src == c19 ) {
                    // negative flanke von ausfahrtsgleis setzt auftrag zurueck
                    if (activeCommands[i].railReleaseState && !getRailInputGbel()) {
                        finishCmd(activeCommands[i]);
                    } else {
                        activeCommands[i].railReleaseState = getRailInputGbel();
                    }
                }
            } else if (activeCommands[i].target == cF) {
                if (activeCommands[i].src == c13 || activeCommands[i].src == c14 || activeCommands[i].src == c15 || activeCommands[i].src == c16 || activeCommands[i].src == c17 || activeCommands[i].src == c18 || activeCommands[i].src == c19 ) {
                    // negative flanke von ausfahrtsgleis setzt auftrag zurueck
                    if (activeCommands[i].railReleaseState && !getRailInputTbel()) {
                        finishCmd(activeCommands[i]);
                    } else {
                        activeCommands[i].railReleaseState = getRailInputTbel();
                    }
                } else {
                    // negative flanke von ausfahrtsgleis setzt auftrag zurueck
                    if (activeCommands[i].railReleaseState && !getRailInputFbel()) {
                        finishCmd(activeCommands[i]);
                    } else {
                        activeCommands[i].railReleaseState = getRailInputFbel();
                    }  
                }   
            } else if (activeCommands[i].target == cM) {
                    if (getRailInputMre()) {finishCmd(activeCommands[i]);}
            } else if (activeCommands[i].target == cN) {
                    // negative flanke von ausfahrtsgleis setzt auftrag zurueck
                if (activeCommands[i].railReleaseState && !getRailInputNbel()) {
                    finishCmd(activeCommands[i]);
                } else {
                    activeCommands[i].railReleaseState = getRailInputNbel();
                }
            } else if (activeCommands[i].target == cR) {
                    if (getRailInputRre()) {finishCmd(activeCommands[i]);}
            } else if (activeCommands[i].target == cT) {
                // negative flanke von ausfahrtsgleis setzt auftrag zurueck
                if (activeCommands[i].railReleaseState && !getRailInputTbel()) {
                    finishCmd(activeCommands[i]);
                } else {
                    activeCommands[i].railReleaseState = getRailInputTbel();
                }        
            }
        }
    }
    activeCmdCount = activeCount;
}