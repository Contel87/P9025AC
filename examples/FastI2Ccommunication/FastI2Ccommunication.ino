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
  Serial.print("Freq: ");Serial.print(65536/CoilFreq);Serial.println(" Hz");

}
