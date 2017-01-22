/**************************************************************************/
/*!
    @file     P9025A.CPP
    @author   Conte Luigi
    @license  GPL 3.0 (see license.txt)
    This program is wrote for the #WirelessPowerContest.
    I used I2C line of P9025A to communicate with Arduino UNO.
    @section  HISTORY
    v1.0  - First release (January 2017)
    V1.1 - Coil Frequency unit corrected: in V1.0 Coil frequency value was in Hz... True value is Khz (As QI 1.1 Specifications).
*/
/**************************************************************************/

#include <P9025A.h>

P9025A pwr;

void setup() {
  Serial.begin(9600);
  pwr.begin();
}

void loop() {
  unsigned int CoilFreq;
  CoilFreq = pwr.getCoilFrequency();
  Serial.print(65536/CoilFreq);Serial.println(" Khz");
  delay(500);
}
