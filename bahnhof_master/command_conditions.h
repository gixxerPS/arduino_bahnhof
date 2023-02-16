#ifndef COMMAND_CONDITIONS_H
#define COMMAND_CONDITIONS_H

#include "command.h"

using namespace CCommand;

/* wird quelle ODER ziel vom neuen auftrag bereits angesteuert?
 * dann brauchen wir gar nicht weiter gucken => NOK
 * Beispiel:
 * 1inA soll angewaehlt werden (curSrc=1, curTarget=A)
 * 15inA aktiv (cmd.src=15, cmd.target=A)
 * spart schon mal 1800 einzelabfragen :)
 */
bool cmdBlocksCurSrcTarget(const commandStruct &cmd)
{
    // bidirektional pruefen
    if (curSrc == cmd.src || curSrc == cmd.target) {
        return true;
    } else if (curTarget == cmd.src || curTarget == cmd.target) {
        return true;
    } else {
        return false;
    }
}

//=============================================================================
// helpers
//=============================================================================
bool is1To6(eRail r) { 
    bool nok = false;
    if (r == c1) {
        nok = true;
    } else if (r == c2) {
        nok = true;
    } else if (r == c3) {
        nok = true;
    } else if (r == c4) {
        nok = true;
    } else if (r == c5) {
        nok = true;
    } else if (r == c6) {
        nok = true;
    }
    return nok;
}
bool is1To11(eRail r) { 
    bool nok = false;
    if (r == c1) {
        nok = true;
    } else if (r == c2) {
        nok = true;
    } else if (r == c3) {
        nok = true;
    } else if (r == c4) {
        nok = true;
    } else if (r == c5) {
        nok = true;
    } else if (r == c6) {
        nok = true;
    } else if (r == c7) {
        nok = true;
    } else if (r == c8) {
        nok = true;
    } else if (r == c9) {
        nok = true;
    } else if (r == c10) {
        nok = true;
    } else if (r == c11) {
        nok = true;
    } 
    return nok;
}

bool is1To19(eRail r) { 
    bool nok = false;
    if (r == c1) {
        nok = true;
    } else if (r == c2) {
        nok = true;
    } else if (r == c3) {
        nok = true;
    } else if (r == c4) {
        nok = true;
    } else if (r == c5) {
        nok = true;
    } else if (r == c6) {
        nok = true;
    } else if (r == c7) {
        nok = true;
    } else if (r == c8) {
        nok = true;
    } else if (r == c9) {
        nok = true;
    } else if (r == c10) {
        nok = true;
    } else if (r == c11) {
        nok = true;
    } else if (r == c13) {
        nok = true;
    } else if (r == c14) {
        nok = true;
    } else if (r == c15) {
        nok = true;
    } else if (r == c16) {
        nok = true;
    } else if (r == c17) {
        nok = true;
    } else if (r == c18) {
        nok = true;
    } else if (r == c19) {
        nok = true;
    }
    return nok;
}
bool is7To9(eRail r) { 
    bool nok = false;
    if (r == c7) {
        nok = true;
    } else if (r == c8) {
        nok = true;
    } else if (r == c9) {
        nok = true;
    }
    return nok;
}
bool is7To11(eRail r) { 
    bool nok = false;
    if (r == c7) {
        nok = true;
    } else if (r == c8) {
        nok = true;
    } else if (r == c9) {
        nok = true;
    } else if (r == c10) {
        nok = true;
    } else if (r == c11) {
        nok = true;
    }
    return nok;
}
bool is7To19(eRail r) { 
    bool nok = false;
    if (r == c7) {
        nok = true;
    } else if (r == c8) {
        nok = true;
    } else if (r == c9) {
        nok = true;
    } else if (r == c10) {
        nok = true;
    } else if (r == c11) {
        nok = true;
    } else if (r == c13) {
        nok = true;
    } else if (r == c14) {
        nok = true;
    } else if (r == c15) {
        nok = true;
    } else if (r == c16) {
        nok = true;
    } else if (r == c17) {
        nok = true;
    } else if (r == c18) {
        nok = true;
    } else if (r == c19) {
        nok = true;
    }
    return nok;
}
bool is13To19(eRail r) { 
    bool nok = false;
    if (r == c13) {
        nok = true;
    } else if (r == c14) {
        nok = true;
    } else if (r == c15) {
        nok = true;
    } else if (r == c16) {
        nok = true;
    } else if (r == c17) {
        nok = true;
    } else if (r == c18) {
        nok = true;
    } else if (r == c19) {
        nok = true;
    }
    return nok;
}
//=============================================================================
// conditions
//=============================================================================

//============================================================================
// in1
//============================================================================
bool cmdBlocksCin1(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin1(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Din..
        nok = true;
    } else if (cmd.target == cB) { // alle ..inB
        nok = true;
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocksHin1(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cG) { // alle ..inG
        nok = true;
    }
    return nok;
}
//============================================================================
// in2
//============================================================================
bool cmdBlocksCin2(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA && cmd.src == c1) { // ..inA
        nok = true;
    } else if (cmd.target == cB && cmd.src == c1) { // ..inB
        nok = true;
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin2(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA && cmd.src == c1) { // ..inA
        nok = true;
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocksHin2(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cG && cmd.src != c1) { // alle ..inG ausser 1inG
        nok = true;
    }
    return nok;
}
//============================================================================
// in3
//============================================================================
bool cmdBlocksCin3(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        }
    } else if (cmd.target == cB ) { // ..inB
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        }
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin3(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        }
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocksHin3(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cG && cmd.src != c1 && cmd.src != c2) { // alle ..inG ausser 1inG
        nok = true;
    }
    return nok;
}
//============================================================================
// in4
//============================================================================
bool cmdBlocksCin4(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        } else if (cmd.src == c3) {
            nok = true;
        }
    } else if (cmd.target == cB ) { // ..inB
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        } else if (cmd.src == c3) {
            nok = true;
        }
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin4(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        } else if (cmd.src == c3) {
            nok = true;
        }
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocksHin4(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cG && is13To19(cmd.src)) { // alle ..inG ausser 1inG
        nok = true;
    }
    return nok;
}
//============================================================================
// in5
//============================================================================
bool cmdBlocksCin5(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        } else if (cmd.src == c3) {
            nok = true;
        } else if (cmd.src == c4) {
            nok = true;
        }
    } else if (cmd.target == cB ) { // ..inB
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        } else if (cmd.src == c3) {
            nok = true;
        } else if (cmd.src == c4) {
            nok = true;
        }
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin5(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        } else if (cmd.src == c3) {
            nok = true;
        } else if (cmd.src == c4) {
            nok = true;
        }
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    }
    return nok;
}
bool cmdBlocksJin5(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cF ) { // alle ..inF
        nok = true;
    } else if (cmd.target == cT ) { // alle ..inT
        nok = true;
    }
    return nok;
}
//============================================================================
// in6
//============================================================================
bool cmdBlocksCin6(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        } else if (cmd.src == c3) {
            nok = true;
        } else if (cmd.src == c4) {
            nok = true;
        } else if (cmd.src == c5) {
            nok = true;
        }
    } else if (cmd.target == cB ) { // ..inB
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        } else if (cmd.src == c3) {
            nok = true;
        } else if (cmd.src == c4) {
            nok = true;
        } else if (cmd.src == c5) {
            nok = true;
        }
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin6(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        } else if (cmd.src == c3) {
            nok = true;
        } else if (cmd.src == c4) {
            nok = true;
        } else if (cmd.src == c5) {
            nok = true;
        }
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    }
    return nok;
}
bool cmdBlocksJin6(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cF && cmd.src != c5) { // alle ..inF ausser
        nok = true;
    } else if (cmd.target == cT ) { // alle ..inT
        nok = true;
    }
    return nok;
}
//============================================================================
// in7
//============================================================================
bool cmdBlocksCin7(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        nok = true;
    } else if (cmd.target == cB && is1To11(cmd.src)) { // ..inB
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin7(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        nok = true;
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    }
    return nok;
}
bool cmdBlocksJin7(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cF && cmd.src != c5 && cmd.src != c6) { // alle ..inF ausser
        nok = true;
    } else if (cmd.target == cT ) { // alle ..inT
        nok = true;
    }
    return nok;
}
//============================================================================
// in8
//============================================================================
bool cmdBlocksCin8(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        nok = true;
    } else if (cmd.target == cB && is1To11(cmd.src)) { // ..inB
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin8(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        nok = true;
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    }
    return nok;
}
bool cmdBlocksJin8(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cF && cmd.src != c5 && cmd.src != c6 && cmd.src != c7) { // alle ..inF ausser
        nok = true;
    } else if (cmd.target == cT ) { // alle ..inT
        nok = true;
    }
    return nok;
}
//============================================================================
// in9
//============================================================================
bool cmdBlocksCin9(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        nok = true;
    } else if (cmd.target == cB && is1To11(cmd.src)) { // ..inB
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin9(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        nok = true;
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    }
    return nok;
}
bool cmdBlocksJin9(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cF && cmd.src != c5 && cmd.src != c6 && cmd.src != c7 && cmd.src != c8) { // alle ..inF ausser
        nok = true;
    } else if (cmd.target == cT ) { // alle ..inT
        nok = true;
    }
    return nok;
}
//============================================================================
// in10
//============================================================================
bool cmdBlocksCin10(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        nok = true;
    } else if (cmd.target == cB && is1To11(cmd.src)) { // ..inB
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin10(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        nok = true;
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    }
    return nok;
}
bool cmdBlocksJin10(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cF && cmd.src != c5 && cmd.src != c6 && cmd.src != c7 && cmd.src != c8) { // alle ..inF ausser
        nok = true;
    } else if (cmd.target == cT ) { // alle ..inT
        nok = true;
    }
    return nok;
}
//============================================================================
// in11
//============================================================================
bool cmdBlocksCin11(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        nok = true;
    } else if (cmd.target == cB && is1To11(cmd.src)) { // ..inB
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin11(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        nok = true;
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    }
    return nok;
}
bool cmdBlocksJin11(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cF && cmd.src != c5 && cmd.src != c6 && cmd.src != c7 && cmd.src != c8) { // alle ..inF ausser
        nok = true;
    } else if (cmd.target == cT ) { // alle ..inT
        nok = true;
    }
    return nok;
}
//============================================================================
// in12
//============================================================================
bool cmdBlocksKin12(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA && is13To19(cmd.src)) { // ..inA
        nok = true;
    } else if (cmd.target == cB && is13To19(cmd.src)) { // ..inB
        nok = true;
    } else if (cmd.src == cC && is13To19(cmd.target)) {
        nok = true;
    } else if (cmd.src == cD && is13To19(cmd.target)) {
        nok = true;
    } else if (cmd.target == cL && cmd.src == c20) { // alle 20inL
        nok = true;
    } else if (cmd.src == cK ) { 
        nok = true;
    }
    return nok;
}
//============================================================================
// in13
//============================================================================
bool cmdBlocksCin13(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        nok = true;
    } else if (cmd.target == cB) { // ..inB
        nok = true;
    } else if (cmd.src == cK) { // alle Kin.. 
        nok = true;
    } else if (cmd.target == cK && cmd.src != c14) { // alle ..inK ausser
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    } else if (cmd.target == cR ) { 
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin13(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        nok = true;
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.src == cK) { 
        nok = true;
    } else if (cmd.target == cK && cmd.src != c14) { // alle ..inK ausser
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    } else if (cmd.src == cR) { 
        nok = true;
    } else if (cmd.target == cR) {
        nok = true;
    }
    return nok;
}
bool cmdBlocksKin13(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA && is13To19(cmd.src)) { // alle ..inA
        nok = true;
    } else if (cmd.target == cB && is13To19(cmd.src)) { // alle ..inT
        nok = true;
    } else if (cmd.src == cC && is13To19(cmd.target)) { 
        nok = true;
    } else if (cmd.src == cD && is13To19(cmd.target)) { 
        nok = true;
    } else if (cmd.src == cR) { 
        nok = true;
    } else if (cmd.target == cL) { 
        if (cmd.src == c12) {
            nok = true;
        } else if (cmd.src == c20) {
            nok = true;
        }
    } else if (cmd.target == cR) { 
        if (cmd.src == c13) {
            nok = true;
        } else if (cmd.src == c14) {
            nok = true;
        }
    }
    return nok;
}
bool cmdBlocksJin13(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cG && is13To19(cmd.src)) { // alle ..inG
        nok = true;
    } else if (cmd.target == cT && is13To19(cmd.src)) { // alle ..inT
        nok = true;
    }
    return nok;
}
bool cmdBlocksRin13(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA && is13To19(cmd.src)) { // alle ..inA
        nok = true;
    } else if (cmd.target == cB && is13To19(cmd.src)) { // alle ..inT
        nok = true;
    } else if (cmd.src == cC && is13To19(cmd.target)) { 
        nok = true;
    } else if (cmd.src == cD && is13To19(cmd.target)) { 
        nok = true;
    } else if (cmd.src == cR) { 
        nok = true;
    } else if (cmd.src == cK) { 
        if (cmd.target == c14) {
            nok = true;
        }
    } else if (cmd.target == cR) { 
        if (cmd.src == c14) {
            nok = true;
        } else if (cmd.src == c20) {
            nok = true;
        }
    } else if (cmd.target == cK) { 
        if (cmd.src == c14) {
            nok = true;
        }
    }
    return nok;
}

//============================================================================
// in14
//============================================================================
bool cmdBlocksCin14(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        nok = true;
    } else if (cmd.target == cB) { // ..inB
        nok = true;
    } else if (cmd.src == cK) { // alle Kin.. 
        nok = true;
    } else if (cmd.target == cK && cmd.src != c14) { // alle ..inK ausser
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    } else if (cmd.target == cR ) { 
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin14(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        nok = true;
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.src == cK) { 
        nok = true;
    } else if (cmd.target == cK && cmd.src != c14) { // alle ..inK ausser
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    } else if (cmd.src == cR) { 
        nok = true;
    } else if (cmd.target == cR) {
        nok = true;
    }
    return nok;
}
bool cmdBlocksKin14(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA && is13To19(cmd.src)) { // alle ..inA
        nok = true;
    } else if (cmd.target == cB && is13To19(cmd.src)) { // alle ..inT
        nok = true;
    } else if (cmd.src == cC && is13To19(cmd.target)) { 
        nok = true;
    } else if (cmd.src == cD && is13To19(cmd.target)) { 
        nok = true;
    } else if (cmd.src == cR) { 
        nok = true;
    } else if (cmd.target == cL) { 
        if (cmd.src == c12) {
            nok = true;
        } else if (cmd.src == c20) {
            nok = true;
        }
    } else if (cmd.target == cR) { 
        if (cmd.src == c13) {
            nok = true;
        } else if (cmd.src == c14) {
            nok = true;
        }
    }
    return nok;
}
bool cmdBlocksJin14(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cG && is13To19(cmd.src)) { // alle ..inG
        nok = true;
    } else if (cmd.target == cT && is13To19(cmd.src)) { // alle ..inT
        nok = true;
    }
    return nok;
}
bool cmdBlocksRin14(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA && is13To19(cmd.src)) { // alle ..inA
        nok = true;
    } else if (cmd.target == cB && is13To19(cmd.src)) { // alle ..inT
        nok = true;
    } else if (cmd.src == cC && is13To19(cmd.target)) { 
        nok = true;
    } else if (cmd.src == cD && is13To19(cmd.target)) { 
        nok = true;
    } else if (cmd.src == cR) { 
        nok = true;
    } else if (cmd.src == cK) { 
        if (cmd.target == c13) {
            nok = true;
        }
    } else if (cmd.target == cR) { 
        if (cmd.src == c13) {
            nok = true;
        } else if (cmd.src == c20) {
            nok = true;
        }
    } else if (cmd.target == cK) { 
        if (cmd.src == c13) {
            nok = true;
        }
    }
    return nok;
}
//============================================================================
// in15
//============================================================================
bool cmdBlocksCin15(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        nok = true;
    } else if (cmd.target == cB) { // ..inB
        nok = true;
    } else if (cmd.src == cK) { // alle Kin.. 
        nok = true;
    } else if (cmd.target == cK && cmd.src != c14) { // alle ..inK ausser
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    } else if (cmd.target == cR ) { 
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin15(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        nok = true;
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.src == cK) { 
        nok = true;
    } else if (cmd.target == cK && cmd.src != c14) { // alle ..inK ausser
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    } else if (cmd.src == cR) { 
        nok = true;
    } else if (cmd.target == cR) {
        nok = true;
    }
    return nok;
}
bool cmdBlocksJin15(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cG && is13To19(cmd.src)) { // alle ..inG
        nok = true;
    } else if (cmd.target == cT && is13To19(cmd.src)) { // alle ..inT
        nok = true;
    }
    return nok;
}
//============================================================================
// in16
//============================================================================
bool cmdBlocksCin16(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        nok = true;
    } else if (cmd.target == cB) { // ..inB
        nok = true;
    } else if (cmd.src == cK) { // alle Kin.. 
        nok = true;
    } else if (cmd.target == cK && cmd.src != c14) { // alle ..inK ausser
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    } else if (cmd.target == cR ) { 
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin16(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        nok = true;
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.src == cK) { 
        nok = true;
    } else if (cmd.target == cK && cmd.src != c14) { // alle ..inK ausser
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    } else if (cmd.src == cR) { 
        nok = true;
    } else if (cmd.target == cR) {
        nok = true;
    }
    return nok;
}
bool cmdBlocksJin16(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cG && is13To19(cmd.src)) { // alle ..inG
        nok = true;
    } else if (cmd.target == cT && is13To19(cmd.src)) { // alle ..inT
        nok = true;
    }
    return nok;
}
//============================================================================
// in17
//============================================================================
bool cmdBlocksCin17(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        nok = true;
    } else if (cmd.target == cB) { // ..inB
        nok = true;
    } else if (cmd.src == cK) { // alle Kin.. 
        nok = true;
    } else if (cmd.target == cK && cmd.src != c14) { // alle ..inK ausser
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    } else if (cmd.target == cR ) { 
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin17(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        nok = true;
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.src == cK) { 
        nok = true;
    } else if (cmd.target == cK && cmd.src != c14) { // alle ..inK ausser
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    } else if (cmd.src == cR) { 
        nok = true;
    } else if (cmd.target == cR) {
        nok = true;
    }
    return nok;
}
bool cmdBlocksJin17(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cG && is13To19(cmd.src)) { // alle ..inG
        nok = true;
    } else if (cmd.target == cT && is13To19(cmd.src)) { // alle ..inT
        nok = true;
    }
    return nok;
}
//============================================================================
// in18
//============================================================================
bool cmdBlocksCin18(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        nok = true;
    } else if (cmd.target == cB) { // ..inB
        nok = true;
    } else if (cmd.src == cK) { // alle Kin.. 
        nok = true;
    } else if (cmd.target == cK && cmd.src != c14) { // alle ..inK ausser
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    } else if (cmd.target == cR ) { 
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin18(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        nok = true;
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.src == cK) { 
        nok = true;
    } else if (cmd.target == cK && cmd.src != c14) { // alle ..inK ausser
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    } else if (cmd.src == cR) { 
        nok = true;
    } else if (cmd.target == cR) {
        nok = true;
    }
    return nok;
}
bool cmdBlocksJin18(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cG && is13To19(cmd.src)) { // alle ..inG
        nok = true;
    } else if (cmd.target == cT && is13To19(cmd.src)) { // alle ..inT
        nok = true;
    }
    return nok;
}
//============================================================================
// in19
//============================================================================
bool cmdBlocksCin19(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cA ) { // ..inA
        nok = true;
    } else if (cmd.target == cB) { // ..inB
        nok = true;
    } else if (cmd.src == cK) { // alle Kin.. 
        nok = true;
    } else if (cmd.target == cK && cmd.src != c14) { // alle ..inK ausser
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    } else if (cmd.target == cR ) { 
        nok = true;
    }
    return nok;
}
bool cmdBlocksDin19(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.target == cA) { // ..inA
        nok = true;
    } else if (cmd.target == cB ) { // ..inB
        nok = true;
    } else if (cmd.src == cK) { 
        nok = true;
    } else if (cmd.target == cK && cmd.src != c14) { // alle ..inK ausser
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser
        nok = true;
    } else if (cmd.src == cR) { 
        nok = true;
    } else if (cmd.target == cR) {
        nok = true;
    }
    return nok;
}
bool cmdBlocksJin19(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cG && is13To19(cmd.src)) { // alle ..inG
        nok = true;
    } else if (cmd.target == cT && is13To19(cmd.src)) { // alle ..inT
        nok = true;
    }
    return nok;
}
//============================================================================
// in20
//============================================================================
bool cmdBlocksKin20(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA && is13To19(cmd.src)) { // ..inA
        nok = true;
    } else if (cmd.target == cB && is13To19(cmd.src)) { // ..inB
        nok = true;
    } else if (cmd.src == cC && is13To19(cmd.target)) {
        nok = true;
    } else if (cmd.src == cD && is13To19(cmd.target)) {
        nok = true;
    } else if (cmd.target == cL && cmd.src == c12) { //  12inL
        nok = true;
    } else if (cmd.src == cK ) { 
        nok = true;
    }
    return nok;
}
//============================================================================
// inA
//============================================================================
bool cmdBlocks1inA(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cB) { // alle ..inB
        nok = true;
    } else if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocks2inA(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cB) { // alle ..inB
        nok = true;
    } else if (cmd.src == cC && cmd.target != c1) { // alle Cin..ausser Cin1
        nok = true;
    } else if (cmd.src == cD && cmd.target != c1) { // alle Din.. ausser Din1
        nok = true;
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocks3inA(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cB) { // alle ..inB
        nok = true;
    } else if (cmd.src == cC && cmd.target != c1 && cmd.target != c2) { // alle Cin..ausser Cin1
        nok = true;
    } else if (cmd.src == cD && cmd.target != c1 && cmd.target != c2) { // alle Din.. ausser Din1
        nok = true;
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocks4inA(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cB) { // alle ..inB
        nok = true;
    } else if (cmd.src == cC && cmd.target != c1 && cmd.target != c2 && cmd.target != c3) { // alle Cin..ausser Cin1
        nok = true;
    } else if (cmd.src == cD && cmd.target != c1 && cmd.target != c2 && cmd.target != c3) { // alle Din.. ausser Din1
        nok = true;
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocks5inA(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cB) { // alle ..inB
        nok = true;
    } else if (cmd.src == cC && cmd.target != c1 && cmd.target != c2 && cmd.target != c3 && cmd.target != c4) { // alle Cin..ausser Cin1
        nok = true;
    } else if (cmd.src == cD && cmd.target != c1 && cmd.target != c2 && cmd.target != c3 && cmd.target != c4) { // alle Din.. ausser Din1
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser 4inL
        nok = true;
    }
    return nok;
}
bool cmdBlocks6inA(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cB) { // alle ..inB
        nok = true;
    } else if (cmd.src == cC && cmd.target != c1 && cmd.target != c2 && cmd.target != c3 && cmd.target != c4 && cmd.target != c5) { // alle Cin..ausser Cin1
        nok = true;
    } else if (cmd.src == cD && cmd.target != c1 && cmd.target != c2 && cmd.target != c3 && cmd.target != c4 && cmd.target != c5) { // alle Din.. ausser Din1
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser 4inL
        nok = true;
    }
    return nok;
}
bool cmdBlocks7To11inA(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cB) { // alle 7..19inB
        if (is7To19(cmd.src)) {
            nok = true;
        }
    } else if (cmd.src == cC) { 
        if (is7To19(cmd.target)) {
            nok = true;
        }
    } else if (cmd.src == cD) { 
        if (is7To19(cmd.target)) {
            nok = true;
        }
    } else if (cmd.target == cL && cmd.src != c4 && cmd.src != c6) { // alle ..inL ausser 4inL
        nok = true;
    }
    return nok;
}
bool cmdBlocks7inA(const commandStruct &cmd) {
    return cmdBlocks7To11inA(cmd);
}
bool cmdBlocks8inA(const commandStruct &cmd) {
    return cmdBlocks7To11inA(cmd);
}
bool cmdBlocks9inA(const commandStruct &cmd) {
    return cmdBlocks7To11inA(cmd);
}
bool cmdBlocks10inA(const commandStruct &cmd) {
    return cmdBlocks7To11inA(cmd);
}
bool cmdBlocks11inA(const commandStruct &cmd) {
    return cmdBlocks7To11inA(cmd);
}
bool cmdBlocks13To119inA(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cB) { // alle 13..19inB oder 7..9inB
        if (is7To9(cmd.src)) {
            nok = true;
        } else if (is13To19(cmd.src)) {
            nok = true;
        }
    } else if (cmd.src == cC) { 
        if (is13To19(cmd.target)) {
            nok = true;
        }
    } else if (cmd.src == cD) { 
        if (is13To19(cmd.target)) {
            nok = true;
        }
    } else if (cmd.src == c12 && cmd.target == cK) {
        nok = true;
    } else if (cmd.src == c20 && cmd.target == cK) {
        nok = true;
    } else if (cmd.src == c12 && cmd.target == cL) {
        nok = true;
    } else if (cmd.src == c20 && cmd.target == cL) {
        nok = true;
    } else if (cmd.src == c13 && cmd.target == cR) {
        nok = true;
    } else if (cmd.src == c14 && cmd.target == cR) {
        nok = true;
    } else if (cmd.src == cK) {
        nok = true;
    } else if (cmd.src == cR) {
        nok = true;
    }
    return nok;
}
bool cmdBlocks13inA(const commandStruct &cmd) {
    return cmdBlocks13To119inA(cmd);
}
bool cmdBlocks14inA(const commandStruct &cmd) {
    return cmdBlocks13To119inA(cmd);
}
bool cmdBlocks15inA(const commandStruct &cmd) {
    return cmdBlocks13To119inA(cmd);
}
bool cmdBlocks16inA(const commandStruct &cmd) {
    return cmdBlocks13To119inA(cmd);
}
bool cmdBlocks17inA(const commandStruct &cmd) {
    return cmdBlocks13To119inA(cmd);
}
bool cmdBlocks18inA(const commandStruct &cmd) {
    return cmdBlocks13To119inA(cmd);
}
bool cmdBlocks19inA(const commandStruct &cmd) {
    return cmdBlocks13To119inA(cmd);
}


//============================================================================
// inB
//============================================================================
bool cmdBlocks1inB(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA) { // ..inA
        if (is1To6(cmd.src)) {
            nok = true;
        }
    } else if (cmd.src == cC) { // alle Cin..
        nok = true;
    } else if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocks2inB(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA) { // ..inA
        if (is1To6(cmd.src)) {
            nok = true;
        }
    } else if (cmd.src == cC && cmd.target != c1) { // alle Cin..ausser Cin1
        nok = true;
    } else if (cmd.src == cD && cmd.target != c1) { // alle Din.. ausser Din1
        nok = true;
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocks3inB(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA) { // ..inA
        if (is1To6(cmd.src)) {
            nok = true;
        }
    } else if (cmd.src == cC && cmd.target != c1 && cmd.target != c2) { // alle Cin..ausser Cin1
        nok = true;
    } else if (cmd.src == cD ) { // alle Din.. 
        nok = true;
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocks4inB(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA) { // ..inA
        if (is1To6(cmd.src)) {
            nok = true;
        }
    } else if (cmd.src == cC && cmd.target != c1 && cmd.target != c2 && cmd.target != c3) { // alle Cin..ausser Cin1
        nok = true;
    } else if (cmd.src == cD) { // alle Din.. 
        nok = true;
    } else if (cmd.target == cL) { // alle ..inL
        nok = true;
    }
    return nok;
}
bool cmdBlocks5inB(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA) { // ..inA
        if (is1To6(cmd.src)) {
            nok = true;
        }
    } else if (cmd.src == cC && cmd.target != c1 && cmd.target != c2 && cmd.target != c3 && cmd.target != c4) { // alle Cin..ausser Cin1
        nok = true;
    } else if (cmd.src == cD ) { // alle Din.. 
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser 4inL
        nok = true;
    }
    return nok;
}
bool cmdBlocks6inB(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA) { // ..inA
        if (is1To6(cmd.src)) {
            nok = true;
        }
    } else if (cmd.src == cC && cmd.target != c1 && cmd.target != c2 && cmd.target != c3 && cmd.target != c4 && cmd.target != c5) { // alle Cin..ausser Cin1
        nok = true;
    } else if (cmd.src == cD) { // alle Din..
        nok = true;
    } else if (cmd.target == cL && cmd.src != c4) { // alle ..inL ausser 4inL
        nok = true;
    }
    return nok;
}
bool cmdBlocks7To11inB(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA) { // alle 7..19inB
            nok = true;
    } else if (cmd.src == cC) { 
        if (is7To19(cmd.target)) {
            nok = true;
        }
    } else if (cmd.src == cD) { 
            nok = true;
    } else if (cmd.target == cL && cmd.src != c4 && cmd.src != c6) { // alle ..inL ausser 4inL
        nok = true;
    }
    return nok;
}
bool cmdBlocks7inB(const commandStruct &cmd) {
    return cmdBlocks7To11inB(cmd);
}
bool cmdBlocks8inB(const commandStruct &cmd) {
    return cmdBlocks7To11inB(cmd);
}
bool cmdBlocks9inB(const commandStruct &cmd) {
    return cmdBlocks7To11inB(cmd);
}
bool cmdBlocks10inB(const commandStruct &cmd) {
    return cmdBlocks7To11inB(cmd);
}
bool cmdBlocks11inB(const commandStruct &cmd) {
    return cmdBlocks7To11inB(cmd);
}
bool cmdBlocks13To19inB(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA) { // alle ..inA 
            nok = true;
    } else if (cmd.src == cC) { 
        if (is13To19(cmd.target)) {
            nok = true;
        }
    } else if (cmd.src == cD) { 
            nok = true;
    } else if (cmd.src == c12 && cmd.target == cK) {
        nok = true;
    } else if (cmd.src == c20 && cmd.target == cK) {
        nok = true;
    } else if (cmd.src == c12 && cmd.target == cL) {
        nok = true;
    } else if (cmd.src == c20 && cmd.target == cL) {
        nok = true;
    } else if (cmd.src == c13 && cmd.target == cR) {
        nok = true;
    } else if (cmd.src == c14 && cmd.target == cR) {
        nok = true;
    } else if (cmd.src == cK) {
        nok = true;
    } else if (cmd.src == cR) {
        nok = true;
    }
    return nok;
}
bool cmdBlocks13inB(const commandStruct &cmd) {
    return cmdBlocks13To19inB(cmd);
}
bool cmdBlocks14inB(const commandStruct &cmd) {
    return cmdBlocks13To19inB(cmd);
}
bool cmdBlocks15inB(const commandStruct &cmd) {
    return cmdBlocks13To19inB(cmd);
}
bool cmdBlocks16inB(const commandStruct &cmd) {
    return cmdBlocks13To19inB(cmd);
}
bool cmdBlocks17inB(const commandStruct &cmd) {
    return cmdBlocks13To19inB(cmd);
}
bool cmdBlocks18inB(const commandStruct &cmd) {
    return cmdBlocks13To19inB(cmd);
}
bool cmdBlocks19inB(const commandStruct &cmd) {
    return cmdBlocks13To19inB(cmd);
}

//============================================================================
// inF
//============================================================================
bool cmdBlocks5inF(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cT) { // ..inT
        nok = true;
    }
    return nok;
}
bool cmdBlocks6inF(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cT) { // ..inT
        nok = true;
    } else if (cmd.src == cJ) { // Jin
        if (cmd.target == c5) {
            nok = true;
        } else if (cmd.target == c6) {
            nok = true;
        }
    }
    return nok;
}
bool cmdBlocks7inF(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cT) { // ..inT
        nok = true;
    } else if (cmd.src == cJ) { // Jin
        if (cmd.target == c5) {
            nok = true;
        } else if (cmd.target == c6) {
            nok = true;
        }
    }
    return nok;
}
bool cmdBlocks8inF(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cT) { // ..inT
        nok = true;
    } else if (cmd.src == cJ) { // Jin
        if (cmd.target == c5) {
            nok = true;
        } else if (cmd.target == c6) {
            nok = true;
        } else if (cmd.target == c7) {
            nok = true;
        }
    }
    return nok;
}
bool cmdBlocks9inF(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cT) { // ..inT
        nok = true;
    } else if (cmd.src == cJ) { // Jin
        if (cmd.target == c5) {
            nok = true;
        } else if (cmd.target == c6) {
            nok = true;
        } else if (cmd.target == c7) {
            nok = true;
        } else if (cmd.target == c8) {
            nok = true;
        } else if (cmd.target == c9) {
            nok = true;
        } else if (cmd.target == c10) {
            nok = true;
        } else if (cmd.target == c11) {
            nok = true;
        }
    }
    return nok;
}
bool cmdBlocks10inF(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cT) { // ..inT
        nok = true;
    } else if (cmd.src == cJ) { // Jin
        if (cmd.target == c5) {
            nok = true;
        } else if (cmd.target == c6) {
            nok = true;
        } else if (cmd.target == c7) {
            nok = true;
        } else if (cmd.target == c8) {
            nok = true;
        } else if (cmd.target == c9) {
            nok = true;
        } else if (cmd.target == c10) {
            nok = true;
        } else if (cmd.target == c11) {
            nok = true;
        }
    }
    return nok;
}
bool cmdBlocks11inF(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cT) { // ..inT
        nok = true;
    } else if (cmd.src == cJ) { // Jin
        if (cmd.target == c5) {
            nok = true;
        } else if (cmd.target == c6) {
            nok = true;
        } else if (cmd.target == c7) {
            nok = true;
        } else if (cmd.target == c8) {
            nok = true;
        } else if (cmd.target == c9) {
            nok = true;
        } else if (cmd.target == c10) {
            nok = true;
        } else if (cmd.target == c11) {
            nok = true;
        }
    }
    return nok;
}
//============================================================================
// inG
//============================================================================
bool cmdBlocks1inG(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cH) { // Hin
        nok = true;
    } 
    return nok;
}
bool cmdBlocks2inG(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cH) { // Hin
        nok = true;
    } 
    return nok;
}
bool cmdBlocks3inG(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cH) { // Hin
        nok = true;
    } 
    return nok;
}
bool cmdBlocks4inG(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.src == cH) { // Hin
        nok = true;
    } 
    return nok;
}
bool cmdBlocks13To19inG(const commandStruct &cmd) 
{
    bool nok = false; // also ok = default
    if (cmd.target == cT) { // ..inT
        nok = true;
    } else if (cmd.src == cH) { // Hin
        nok = true;
    } else if (cmd.src == cJ) { // Jin
        nok = true;
    } 
    return nok;
}
bool cmdBlocks13inG(const commandStruct &cmd) {
    return cmdBlocks13To19inG(cmd);
}
bool cmdBlocks14inG(const commandStruct &cmd) {
    return cmdBlocks13To19inG(cmd);
}
bool cmdBlocks15inG(const commandStruct &cmd) {
    return cmdBlocks13To19inG(cmd);
}
bool cmdBlocks16inG(const commandStruct &cmd) {
    return cmdBlocks13To19inG(cmd);
}
bool cmdBlocks17inG(const commandStruct &cmd) {
    return cmdBlocks13To19inG(cmd);
}
bool cmdBlocks18inG(const commandStruct &cmd) {
    return cmdBlocks13To19inG(cmd);
}
bool cmdBlocks19inG(const commandStruct &cmd) {
    return cmdBlocks13To19inG(cmd);
}
//============================================================================
// inK
//============================================================================
bool cmdBlocks12To20inK(const commandStruct &cmd) 
{
    bool nok = false; // also ok = default
    if (cmd.target == cA) { // ..inA
        if (is13To19(cmd.src)) {
            nok = true;
        }
    } else if (cmd.target == cB) { // ..inB
        if (is13To19(cmd.src)) {
            nok = true;
        }
    } else if (cmd.target == cC) { // ..inB
        if (is13To19(cmd.src)) {
            nok = true;
        }
    } else if (cmd.target == cD) { // ..inB
        if (is13To19(cmd.src)) {
            nok = true;
        }
    }
    return nok;
}
bool cmdBlocks12inK(const commandStruct &cmd) {
    return cmdBlocks12To20inK(cmd);
}
bool cmdBlocks13inK(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmdBlocks12To20inK(cmd)) {
        nok = true;
    } else if (cmd.src == cR) {
        nok = true;
    } else if (cmd.target == cR) {
        nok = true;
    }
    return nok;
}
bool cmdBlocks14inK(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmdBlocks12To20inK(cmd)) {
        nok = true;
    } else if (cmd.src == cR) {
        nok = true;
    } else if (cmd.target == cR) {
        nok = true;
    }
    return nok;
}
bool cmdBlocks20inK(const commandStruct &cmd) {
    return cmdBlocks12To20inK(cmd);
}
//============================================================================
// inL
//============================================================================
bool cmdBlocks4inL(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA) {
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        } else if (cmd.src == c3) {
            nok = true;
        }
    } else if (cmd.target == cB) {
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        } else if (cmd.src == c3) {
            nok = true;
        }
    } else if (cmd.src == cC) {
        if (cmd.target == c1) {
            nok = true;
        } else if (cmd.target == c2) {
            nok = true;
        } else if (cmd.target == c3) {
            nok = true;
        }
    } else if (cmd.src == cD) {
        if (cmd.target == c1) {
            nok = true;
        } else if (cmd.target == c2) {
            nok = true;
        } else if (cmd.target == c3) {
            nok = true;
        } else if (cmd.target == c5) {
            nok = true;
        } else if (cmd.target == c6) {
            nok = true;
        }
    } else if (cmd.target == cL) {
         nok = true;
    }
    return nok;
}
bool cmdBlocks6To9inL(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA) {
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        } else if (cmd.src == c3) {
            nok = true;
        } else if (cmd.src == c4) {
            nok = true;
        } else if (cmd.src == c5) {
            nok = true;
        }
    } else if (cmd.target == cB) {
        if (cmd.src == c1) {
            nok = true;
        } else if (cmd.src == c2) {
            nok = true;
        } else if (cmd.src == c3) {
            nok = true;
        } else if (cmd.src == c4) {
            nok = true;
        } else if (cmd.src == c5) {
            nok = true;
        }
    } else if (cmd.src == cC) {
        nok = true;
    } else if (cmd.src == cD) {
        nok = true;
    } else if (cmd.target == cL) {
         nok = true;
    }
    return nok;
}
bool cmdBlocks6inL(const commandStruct &cmd) {
    return cmdBlocks6To9inL(cmd);
}
bool cmdBlocks8inL(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmdBlocks6To9inL(cmd)) {
        nok = true;
    } else if (cmd.target == cA && is7To11(cmd.src)) {
        nok = true;
    } else if (cmd.target == cB && is7To11(cmd.src)) {
        nok = true;
    }
    return nok;
}
bool cmdBlocks9inL(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmdBlocks6To9inL(cmd)) {
        nok = true;
    } else if (cmd.target == cA && is7To11(cmd.src)) {
        nok = true;
    } else if (cmd.target == cB && is7To11(cmd.src)) {
        nok = true;
    }
    return nok;
}
bool cmdBlocks12inL(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA) {
        nok = true;
    } else if (cmd.target == cB) {
        nok = true;
    } else if (cmd.src == cC) {
        nok = true;
    } else if (cmd.src == cD) {
        nok = true;
    } else if (cmd.target == cK) {
        nok = true;
    } else if (cmd.src == cK) {
        nok = true;
    }
    return nok;
}
bool cmdBlocks20inL(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA) {
        nok = true;
    } else if (cmd.target == cB) {
        nok = true;
    } else if (cmd.src == cC) {
        nok = true;
    } else if (cmd.src == cD) {
        nok = true;
    } else if (cmd.target == cK) {
        nok = true;
    } else if (cmd.src == cK) {
        nok = true;
    }
    return nok;
}
//============================================================================
// inR
//============================================================================
bool cmdBlocks13inR(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA && is13To19(cmd.src)) {
        nok = true;
    } else if (cmd.target == cB && is13To19(cmd.src)) {
        nok = true;
    } else if (cmd.src == cC && is13To19(cmd.target)) {
        nok = true;
    } else if (cmd.src == cD && is13To19(cmd.target)) {
        nok = true;
    } else if (cmd.target == cK) {
        if (cmd.src == c13) {
            nok = true;
        } else if (cmd.src == c14) {
            nok = true;
        }
    } else if (cmd.target == cR) {
        if (cmd.src == c13) {
            nok = true;
        } else if (cmd.src == c14) {
            nok = true;
        }
    } else if (cmd.src == cK) {
        if (cmd.target == c13) {
            nok = true;
        } else if (cmd.target == c14) {
            nok = true;
        }
    }
    return nok;
}
bool cmdBlocks14inR(const commandStruct &cmd) {
    bool nok = false; // also ok = default
    if (cmd.target == cA && is13To19(cmd.src)) {
        nok = true;
    } else if (cmd.target == cB && is13To19(cmd.src)) {
        nok = true;
    } else if (cmd.src == cC && is13To19(cmd.target)) {
        nok = true;
    } else if (cmd.src == cD && is13To19(cmd.target)) {
        nok = true;
    } else if (cmd.target == cK) {
        if (cmd.src == c13) {
            nok = true;
        } else if (cmd.src == c14) {
            nok = true;
        }
    } else if (cmd.target == cR) {
        if (cmd.src == c13) {
            nok = true;
        } else if (cmd.src == c14) {
            nok = true;
        }
    } else if (cmd.src == cK) {
        if (cmd.target == c13) {
            nok = true;
        } else if (cmd.target == c14) {
            nok = true;
        }
    }
    return nok;
}
//============================================================================
// inT
//============================================================================
bool cmdBlocks13To19inT(const commandStruct &cmd) 
{
    bool nok = false; // also ok = default
    if (cmd.target == cG) { // ..inG
        if (is13To19(cmd.src)) {
            nok = true;
        }
    } else if (cmd.src == cJ) { // Jin
        nok = true;
    } else if (cmd.target == cF) { // ..inF
        nok = true;
    } else if (cmd.target == cT) { // ..inT
        nok = true;
    }
    return nok;
}
bool cmdBlocks13inT(const commandStruct &cmd) {
    return cmdBlocks13To19inT(cmd);
}
bool cmdBlocks14inT(const commandStruct &cmd) {
    return cmdBlocks13To19inT(cmd);
}
bool cmdBlocks15inT(const commandStruct &cmd) {
    return cmdBlocks13To19inT(cmd);
}
bool cmdBlocks16inT(const commandStruct &cmd) {
    return cmdBlocks13To19inT(cmd);
}
bool cmdBlocks17inT(const commandStruct &cmd) {
    return cmdBlocks13To19inT(cmd);
}
bool cmdBlocks18inT(const commandStruct &cmd) {
    return cmdBlocks13To19inT(cmd);
}
bool cmdBlocks19inT(const commandStruct &cmd) {
    return cmdBlocks13To19inT(cmd);
}


#endif