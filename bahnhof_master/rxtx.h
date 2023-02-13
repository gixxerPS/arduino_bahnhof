#ifndef RXTX_H
#define RXTX_H
namespace RXTX
{
enum class E_CODES {
    NONE,
    STX,
    ETX,
    ACK,
    NACK,
    REQ_INPUTS,
    PINGG // PING gibts schon iwo in arduino
};

void setup();

/*!
 *
 */
void sendData(uint8_t* data, uint8_t length);

/*!
 * ACHTUNG: es findet keine pruefung der puffergroesse statt.
 * das heisst wenn mehr daten geschickt werden als der puffer gross ist kommt es 
 * zu zugriffsfehlern.
 * wertet auch code aus wenn empfangen.
 */
void receiveData(uint8_t* data);
void sendPing();
void sendRequestInputs();

/*!
 * Anzahl insgesamt empfangener Nachrichten
 */
uint32_t getTotalRxMsgCnt(); 

E_CODES getReceivedCode();
}
#endif