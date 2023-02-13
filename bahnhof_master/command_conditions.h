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

#endif