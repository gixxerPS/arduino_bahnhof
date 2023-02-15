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