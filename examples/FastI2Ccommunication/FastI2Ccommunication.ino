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

 static P9025A pwr;

 unsigned int Vrect;
 unsigned int IOut;
 unsigned int CoilFreq;


void setup() {

  pwr.begin();
  Wire.setClock (400000L);
  Serial.begin(9600);
}

void loop() {

  Vrect = pwr.getVrectVoltage();
  Serial.print("Vrect: ");Serial.print(Vrect*5*(1.8/4096));Serial.print(" V ");

  IOut = pwr.getIoutCurrent();
  Serial.print("IOut: ");Serial.print(IOut*(1.8/4096));Serial.print(" A ");

  CoilFreq = pwr.getCoilFrequency();
  Serial.print("Freq: ");Serial.print(65536/CoilFreq);Serial.println(" KHz");

}
