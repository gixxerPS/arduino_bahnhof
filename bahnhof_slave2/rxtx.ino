#include "rxtx.h"

// vollstaendige nachrichten
const uint8_t MSG_STX = 0x16;
const uint8_t MSG_ETX = 0x19;
const uint8_t MSG_PING = 0x14;
const uint8_t MSG_INPUTS = 0x13;


const uint8_t CMD_LOW_NIBBLE = 0x40;
const uint8_t CMD_HIGH_NIBBLE = 0x50;

const uint8_t MASK_LOW_NIBBLE = 0xF;
const uint8_t MASK_HIGH_NIBBLE = 0xF0;

static uint32_t totalRxMsgCounter = 0;
static RXTX::E_CODES receivedCode = RXTX::E_CODES::NONE; // waehrend des empfangens merken fuer anschluss aktionen in loop

void RXTX::setup() {
    Serial1.begin(38400);
}

void RXTX::sendData(uint8_t* data, uint8_t length)
{
    Serial1.write(MSG_STX);
    for (int i = 0; i < length; i++) {
        Serial1.write(CMD_LOW_NIBBLE  | (data[i] & MASK_LOW_NIBBLE));
        Serial1.write(CMD_HIGH_NIBBLE | ((data[i] & MASK_HIGH_NIBBLE) >> 4)); // maskieren eigtl nicht noetig da mit 0en aufgefuellt wird
    }
    Serial1.write(MSG_ETX);
}

void RXTX::sendPing() 
{
    Serial1.write(MSG_STX);
    Serial1.write(MSG_PING);
    Serial1.write(MSG_ETX);
}

void RXTX::sendRequestInputs() 
{
    Serial1.write(MSG_STX);
    Serial1.write(MSG_INPUTS);
    Serial1.write(MSG_ETX);
}

uint32_t RXTX::getTotalRxMsgCnt()
{
    return totalRxMsgCounter;
}

// E_CODES decodeCode(uint8_t byte)
// {
//     E_CODES ret = E_CODES::NONE;
//     // code ist im high nibble eincodiert
//     uint8_t codeNibble = byte & MASK_HIGH_NIBBLE;
//     uint8_t dataNibble = byte & MASK_LOW_NIBBLE;
//     if (codeNibble == 0x1) { // low nibble ist code
//         if (dataNibble == 0x2) {
//             ret = E_CODES::NACK;
//         } else if (dataNibble == 0x3) {
//             ret = E_CODES::REQ_INPUTS;
//         } else if (dataNibble == 0x4) {
//             ret = E_CODES::PINGG;
//         } else if (dataNibble == 0x9) {
//             ret = E_CODES::ETX;
//         } else if (dataNibble == 0x6) {
//             ret = E_CODES::STX;
//         }
//     } 
//     return ret;
// }


RXTX::E_CODES RXTX::getReceivedCode() 
{
    E_CODES ret = receivedCode;
    receivedCode = E_CODES::NONE; // nur einmalig lesen!
    return ret;
}
bool receivedDataHighNibble(uint8_t data)
{
    return ((data & 0xF0) == CMD_HIGH_NIBBLE);
}
bool receivedDataLowNibble(uint8_t data)
{
    return ((data & 0xF0) == CMD_LOW_NIBBLE);
}
bool receivedCodeSendInputs(uint8_t data) 
{
    return (data == MSG_INPUTS);
}

void RXTX::receiveData(uint8_t* data) 
{
    int serialRxData;
    static uint8_t serialRxIdx = 0;
    static unsigned long serialRxTime;
    static uint8_t nibbleCnt = 0;
    static uint32_t msgByteCnt = 0;
    static bool rxActive;
    if (Serial1.available()) {
        if (!rxActive) { // uebertragung noch nicht gestartet
            serialRxData = Serial1.read(); // lesen auch wenn uebertragung nicht aktiv leert gleichzeitig den empfangspuffer
            if (serialRxData == MSG_STX) { // startsignal empfangen ?
                rxActive = true;
                receivedCode = E_CODES::NONE;
                serialRxIdx = 0;
                serialRxTime = millis();
            }
        } else { // uebertragung gestartet
            //if (millis() - serialRxTime > 10) { // warte 10ms fuer uebertragung (10byte = 80 bit + 10*(start,stop,paritaet) = 110 bit / 38400/s = 0.003 s)
                while (Serial1.available()) {
                    serialRxData = Serial1.read();
                    /* Empfangene Daten interpretieren.
                     * eigtl muesste die komplette nachricht in einen buffer geschrieben
                     * werden und wenn stx und etx komplett sind die nachricht auswerten.
                     * ABER keep it simple. hier wird direkt angefangen die daten zu interpretieren.
                     * VORTEIL: wir sparen uns das umkopieren des buffers (auch wenn das bei den paar
                     * daten recht fix gehen duerfte)
                     */
                    if (serialRxData != MSG_ETX) {
                        if (receivedCodeSendInputs(serialRxData)) {
                            receivedCode = E_CODES::REQ_INPUTS;
                        } else if (receivedDataHighNibble(serialRxData)) {
                            data[serialRxIdx] |= (serialRxData & MASK_LOW_NIBBLE) << 4;
                            nibbleCnt++;
                        } else if (receivedDataLowNibble(serialRxData)) {
                            data[serialRxIdx] = 0; // alte daten loeschen
                            data[serialRxIdx] |= (serialRxData & MASK_LOW_NIBBLE);
                            nibbleCnt++;
                        }
                        if (nibbleCnt >= 2) { // byte komplett empfangen ?
                            serialRxIdx++;
                            nibbleCnt = 0;
                        }
                    } else { // msg == MSG_ETX => uebertragung fertig => merker zuruecksetzen
                        rxActive = false;
                        serialRxTime = 0;
                        totalRxMsgCounter++;
                        msgByteCnt = 0;
                    }
                }
            //}
        }
    }
}