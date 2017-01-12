#include <P9025A.h>

P9025A pwr;

void setup() {
  Serial.begin(9600);
  pwr.begin();
}

void loop() {
  unsigned int IOut;
  IOut = pwr.getIoutCurrent();
  Serial.println(IOut*(1.8/4096));
  delay(500);
}
