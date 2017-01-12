#include <P9025A.h>

P9025A pwr;

void setup() {
  Serial.begin(9600);
  pwr.begin();
}

void loop() {
  unsigned int CoilFreq;
  CoilFreq = pwr.getCoilFrequency();
  Serial.println(65536/CoilFreq);
  delay(500);
}
