# arduino_bahnhof/drehscheibe

## funktionen
- Abstellgleis 1-12
- Einfahrtsgleis A (Schlot voraus), B (Tender voraus)
- Ausfahrtsgleis C

## eingaenge
- 15x Anwahltaster
- 15x Positionsschalter
- 15x Besetztsignal
- 1x Resettaster
- 1x Drehrichtungstaster
- 1x Drehfreigabe
- 15x Endschalter (optional)

=> 48 DI (direkt an Controller)

## ausgaenge
- 1x Rechtsdrehen
- 1x Linksdrehen
- 12x Ziel-/Torrelais
- 15x LED f Anwahl

=> 29 DO (8er Relaismodul und 2x PCF8575 i2c portexpander)

## hardware
- 1x arduino mega pro mini
- 1x 8er Relaismodule -> 8 DO
- 4x 8er Eingaenge direkt / Pullup -> 32 DI

8-fach Relais-Module
====================
INx = false => relais AN
INx = true  => relais AUS
JD-VCC, GND = Last 5V versorgung fuer relais => 2. netzteil
VCC, GND = Steuerspannung