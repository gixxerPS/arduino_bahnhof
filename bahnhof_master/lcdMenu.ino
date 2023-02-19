#include "lcdMenu.h"

using namespace MYLCD;

String MYLCD::railCombiEnum2Str(CCommand::eCMD railCombi) 
{
    switch(railCombi) {
        case CCommand:: i1_IN_A: return  "1inA";
        case CCommand:: i2_IN_A: return  "2inA";
        case CCommand:: i3_IN_A: return  "3inA";
        case CCommand:: i4_IN_A: return  "4inA";
        case CCommand:: i5_IN_A: return  "5inA";
        case CCommand:: i6_IN_A: return  "6inA";
        case CCommand:: i7_IN_A: return  "7inA";
        case CCommand:: i8_IN_A: return  "8inA";
        case CCommand:: i9_IN_A: return  "9inA";
        case CCommand::i10_IN_A: return "10inA";
        case CCommand::i11_IN_A: return "11inA";
        case CCommand::i12_IN_A: return "12inA";
        case CCommand::i13_IN_A: return "13inA";
        case CCommand::i14_IN_A: return "14inA";
        case CCommand::i15_IN_A: return "15inA";
        case CCommand::i16_IN_A: return "16inA";
        case CCommand::i17_IN_A: return "17inA";
        case CCommand::i18_IN_A: return "18inA";
        case CCommand::i19_IN_A: return "19inA";
        case CCommand:: i1_IN_B: return  "1inB";
        case CCommand:: i2_IN_B: return  "2inB";
        case CCommand:: i3_IN_B: return  "3inB";
        case CCommand:: i4_IN_B: return  "4inB";
        case CCommand:: i5_IN_B: return  "5inB";
        case CCommand:: i6_IN_B: return  "6inB";
        case CCommand:: i7_IN_B: return  "7inB";
        case CCommand:: i8_IN_B: return  "8inB";
        case CCommand:: i9_IN_B: return  "9inB";
        case CCommand::i10_IN_B: return "10inB";
        case CCommand::i11_IN_B: return "11inB";
        case CCommand::i12_IN_B: return "12inB";
        case CCommand::i13_IN_B: return "13inB";
        case CCommand::i14_IN_B: return "14inB";
        case CCommand::i15_IN_B: return "15inB";
        case CCommand::i16_IN_B: return "16inB";
        case CCommand::i17_IN_B: return "17inB";
        case CCommand::i18_IN_B: return "18inB";
        case CCommand::i19_IN_B: return "19inB";
        case CCommand::iC_IN_1 : return "Cin1";
        case CCommand::iC_IN_2 : return "Cin2";
        case CCommand::iC_IN_3 : return "Cin3";
        case CCommand::iC_IN_4 : return "Cin4";
        case CCommand::iC_IN_5 : return "Cin5";
        case CCommand::iC_IN_6 : return "Cin6";
        case CCommand::iC_IN_7 : return "Cin7";
        case CCommand::iC_IN_8 : return "Cin8";
        case CCommand::iC_IN_9 : return "Cin9";
        case CCommand::iC_IN_10: return "Cin10";
        case CCommand::iC_IN_11: return "Cin11";
        case CCommand::iC_IN_12: return "Cin12";
        case CCommand::iC_IN_13: return "Cin13";
        case CCommand::iC_IN_14: return "Cin14";
        case CCommand::iC_IN_15: return "Cin15";
        case CCommand::iC_IN_16: return "Cin16";
        case CCommand::iC_IN_17: return "Cin17";
        case CCommand::iC_IN_18: return "Cin18";
        case CCommand::iC_IN_19: return "Cin19";
        case CCommand::iD_IN_1 : return "Din1";
        case CCommand::iD_IN_2 : return "Din2";
        case CCommand::iD_IN_3 : return "Din3";
        case CCommand::iD_IN_4 : return "Din4";
        case CCommand::iD_IN_5 : return "Din5";
        case CCommand::iD_IN_6 : return "Din6";
        case CCommand::iD_IN_7 : return "Din7";
        case CCommand::iD_IN_8 : return "Din8";
        case CCommand::iD_IN_9 : return "Din9";
        case CCommand::iD_IN_10: return "Din10";
        case CCommand::iD_IN_11: return "Din11";
        case CCommand::iD_IN_12: return "Din12";
        case CCommand::iD_IN_13: return "Din13";
        case CCommand::iD_IN_14: return "Din14";
        case CCommand::iD_IN_15: return "Din15";
        case CCommand::iD_IN_16: return "Din16";
        case CCommand::iD_IN_17: return "Din17";
        case CCommand::iD_IN_18: return "Din18";
        case CCommand::iD_IN_19: return "Din19";
        case CCommand::i5_IN_F: return "5inF";
        case CCommand::i6_IN_F: return "6inF";
        case CCommand::i7_IN_F: return "7inF";
        case CCommand::i8_IN_F: return "8inF";
        case CCommand::i9_IN_F: return "9inF";
        case CCommand::i10_IN_F: return "10inF";
        case CCommand::i11_IN_F: return "11inF";
        case CCommand::i12_IN_T: return "12inT";
        case CCommand::i13_IN_T: return "13inT";
        case CCommand::i14_IN_T: return "14inT";
        case CCommand::i15_IN_T: return "15inT";
        case CCommand::i16_IN_T: return "16inT";
        case CCommand::i17_IN_T: return "17inT";
        case CCommand::i18_IN_T: return "18inT";
        case CCommand::i19_IN_T: return "19inT";
        case CCommand:: i1_IN_G: return  "1inG";
        case CCommand:: i2_IN_G: return  "2inG";
        case CCommand:: i3_IN_G: return  "3inG";
        case CCommand:: i4_IN_G: return  "4inG";
        case CCommand::i13_IN_G: return "13inG";
        case CCommand::i14_IN_G: return "14inG";
        case CCommand::i15_IN_G: return "15inG";
        case CCommand::i16_IN_G: return "16inG";
        case CCommand::i17_IN_G: return "17inG";
        case CCommand::i18_IN_G: return "18inG";
        case CCommand::i19_IN_G: return "19inG";
        case CCommand::iH_IN_1 : return "Hin1";
        case CCommand::iH_IN_2 : return "Hin2";
        case CCommand::iH_IN_3 : return "Hin3";
        case CCommand::iH_IN_4 : return "Hin4";
        case CCommand::iJ_IN_5 : return "Jin5";
        case CCommand::iJ_IN_6 : return "Jin6";
        case CCommand::iJ_IN_7 : return "Jin7";
        case CCommand::iJ_IN_8 : return "Jin8";
        case CCommand::iJ_IN_9 : return "Jin9";
        case CCommand::iJ_IN_10: return "Jin10";
        case CCommand::iJ_IN_11: return "Jin11";
        case CCommand::iJ_IN_12: return "Jin12";
        case CCommand::iJ_IN_13: return "Jin13";
        case CCommand::iJ_IN_14: return "Jin14";
        case CCommand::iJ_IN_15: return "Jin15";
        case CCommand::iJ_IN_16: return "Jin16";
        case CCommand::iJ_IN_17: return "Jin17";
        case CCommand::iJ_IN_18: return "Jin18";
        case CCommand::iJ_IN_19: return "Jin19";
        case CCommand::i12_IN_K: return "12inK";
        case CCommand::i20_IN_K: return "20inK";
        case CCommand::i13_IN_K: return "13inK";
        case CCommand::i14_IN_K: return "14inK";
        case CCommand:: i4_IN_L: return  "4inL";
        case CCommand:: i6_IN_L: return  "6inL";
        case CCommand:: i8_IN_L: return  "8inL";
        case CCommand:: i9_IN_L: return  "9inL";
        case CCommand:: i12_IN_L: return  "12inL";
        case CCommand:: i20_IN_L: return  "20inL";
        case CCommand::i13_IN_R: return "13inR";
        case CCommand::i14_IN_R: return "14inR";
        case CCommand::iK_IN_12: return "Kin12";
        case CCommand::iK_IN_20: return "Kin20";
        case CCommand::iK_IN_13: return "Kin13";
        case CCommand::iK_IN_14: return "Kin14";
        case CCommand::iR_IN_13: return "Rin13";
        case CCommand::iR_IN_14: return "Rin14";
        case CCommand::i19_IN_M: return "19inM";
        case CCommand::iM_IN_19: return "Min19";
        case CCommand::i1_IN_N: return "1inN";
        case CCommand::iN_IN_1: return "Nin1";
    }
}

void MYLCD::setup()
{
    lcd.init();
    lcd.setCursor(0, 0);
    lcd.print("Diddis Bahnhof");
    lcd.setCursor(0, 1);
    lcd.print("Version V0.1.0");
    lcd.backlight();

    tasteLinks.setDebounceTime(50); // [ms]
    // tasteOben.setDebounceTime(50); // [ms]
    tasteSelect.setDebounceTime(50); // [ms]
}

void MYLCD::loop()
{
    
    static uint8_t currentMenuItem = 0;
    static uint8_t previousMenuItem = 1;
    static unsigned long selLangMsStart = 0;
    static unsigned long linksLangMsStart = 0;
    static uint8_t selCmd;
    static bool select;
    static bool tasteLinksLongPress;
    static bool tasteLinksLongPressEdge;
    static bool tasteSelectLongPress;
    static bool tasteSelectLongPressEdge;
    static uint8_t activeCmdCountOld = 0;
    static bool activeOld;

    tasteLinks.loop();
    // tasteOben.loop();
    tasteSelect.loop();

    // select lang gedrueckt ?
    tasteSelectLongPressEdge = false;
    if (tasteSelect.isPressed()) {
        selLangMsStart = millis(); // timer starten
    } else if  (LOW == tasteSelect.getState() && selLangMsStart > 0 && millis() - selLangMsStart > 1000) { // immer noch gedrueckt ?
        tasteSelectLongPress = true;
        tasteSelectLongPressEdge = true;
        selLangMsStart = 0;
    } else if (tasteSelect.isReleased()) {
        tasteSelectLongPress = false;
    }

    // links lang gedrueckt ?
    tasteLinksLongPressEdge = false;
    if (tasteLinks.isPressed()) {
        linksLangMsStart = millis(); // timer starten
    } else if  (LOW == tasteLinks.getState() && linksLangMsStart > 0 && millis() - linksLangMsStart > 1000) { // immer noch gedrueckt ?
        tasteLinksLongPress = true;
        tasteLinksLongPressEdge = true;
        linksLangMsStart = 0;
    } else if (tasteLinks.isReleased()) {
        tasteLinksLongPress = false;
    }
    
    // blaettern wenn sel lang gedrueckt
    if (LOW == tasteSelect.getState() && tasteSelectLongPressEdge) {
        currentMenuItem++;
        if (currentMenuItem >= NUM_MENU_ITEMS) {
            currentMenuItem = 0;
        }
    }

    bool lcdRefresh = false;        
    // tastendruecke / zustaende schnell erfassen 
    // anzeige nur bei aenderung aktualisieren um unnoetiges
    // flackern zu vermeiden
    switch(currentMenuItem) {
        case 0:
            if (currentMenuItem != previousMenuItem) { // seite gewechselt ?
                selCmd = 0; // bei 0 wieder anfangen
                select = false;
                lcdRefresh = true;
                lcd.clear();
            }
            if (CCommand::activeCommands[selCmd].active != activeOld) {
                activeOld = CCommand::activeCommands[selCmd].active;
                lcdRefresh = true;
                
            }
            if (tasteLinksLongPressEdge) {
                select = ! select;
                lcdRefresh = true;
            }
            if (tasteLinks.isReleased()) {
                selCmd++;
                if (selCmd >= CCommand::N_COMMANDS) {
                    selCmd = 0;
                }
                select = false;
                lcdRefresh = true;
            }
            if (select) { // loeschen = ja angewaehlt?
                if (tasteSelect.isReleased()) {
                    CCommand::finishCmdByIdx(selCmd);
                }
            }
            //========================================
            // ab hier print etc
            //========================================
            if (lcdRefresh) { // seite aktualisieren ?
                lcd.setCursor(0, 0);
                lcd.print("Auftr:");
                lcd.print(selCmd+1);
                lcd.print(" ");
                if (CCommand::activeCommands[selCmd].active) {
                    lcd.print(railCombiEnum2Str(CCommand::activeCommands[selCmd].railCombi));
                } else {
                    lcd.print("        ");
                }
                lcd.setCursor(0, 1);
                lcd.print("loeschen? ");
                if (select) {
                    lcd.print("ja  ");
                } else {
                    lcd.print("nein");
                }
            }
        break;
        case 1:
            if (currentMenuItem != previousMenuItem) {// seite gewechselt ?
                lcdRefresh = true;
                select = false;
                selCmd = 0; // bei 0 wieder anfangen
                lcd.clear();
            } else if (activeCmdCountOld != CCommand::getActiveCmdCount()) { // oder anzahl hat sich geandert ? 
                activeCmdCountOld = CCommand::getActiveCmdCount();
                lcdRefresh = true;
            }
            if (tasteLinksLongPressEdge) {
                CCommand::resetAllCmds();
                lcdRefresh = true;
            }
            //========================================
            // ab hier print etc
            //========================================
            if (lcdRefresh) { // seite aktualisieren ?
                lcd.setCursor(0, 0);
                lcd.print(CCommand::getActiveCmdCount());
                lcd.print(" Auftraege");
                lcd.setCursor(0, 1);
                lcd.print("Alle loeschen? ");
                if (select) {
                    lcd.print("ja  ");
                } else {
                    lcd.print("nein");
                }
            }
        break;
        case 2:
            if (currentMenuItem != previousMenuItem) {// seite gewechselt ?
                lcdRefresh = true;
                lcd.clear();
            }
            //========================================
            // ab hier print etc
            //========================================
            if (lcdRefresh) { // seite aktualisieren ?
                lcd.setCursor(0, 1);
                lcd.print("1 in A: ");
            }
        break;
    }

    previousMenuItem = currentMenuItem;

}
