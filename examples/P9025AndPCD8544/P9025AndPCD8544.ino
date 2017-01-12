#include <P9025A.h>
#include <PCD8544.h>


static PCD8544 lcd;
static P9025A pwr;

 unsigned int Vrect;
 unsigned int IOut;
 unsigned int CoilFreq;


void setup() {
  lcd.begin(84, 48);
  pwr.begin();

}


void loop() {
  // Write a piece of text on the first line...
  lcd.setCursor(0, 0);
  lcd.print("#WirelessPower Contest 2017");

  
  lcd.setCursor(0, 3);
  Vrect = pwr.getVrectVoltage();
  lcd.print("Vrect: ");lcd.print(Vrect*5*(1.8/4096));lcd.print(" V ");

  IOut = pwr.getIoutCurrent();
  lcd.print("IOut: ");lcd.print(IOut*(1.8/4096));lcd.print(" A  ");

  CoilFreq = pwr.getCoilFrequency();
  lcd.print("Freq: ");lcd.print(65536/CoilFreq);lcd.print(" Hz");

  delay(500);
}