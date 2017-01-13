# P9025AC
Created by Luigi Conte (luigi.conte@hotmail.com) for #WirelessPowerContest (http://contest.open-electronics.org/challenge-wireless-power/).
This is an arduino library that shows the parameters of wireless power receiver.
Some sketches use lcd Philips PCD8544 library (https://github.com/carlosefr/pcd8544).
Installation
============

Download the latest zip file from [clone or download] button. Then open it from the `Sketch > Include Library > Add .ZIP Library...` menu inside the Arduino IDE and a new "P9025AC
" entry should appear in the `Sketch > Include Library` and `File > Examples` menus.
Be shure to use the last arduino IDE (I tested it on Version 1.8.0).

Connections
===========

P9025AC Pin       | Arduino Pin
------------------|------------
Pin GND           | GND Pin
Pin (SDA)         | Analog Pin A4
Pin (SCL)         | Analog Pin A5

Very important is connect I2CR pin of P9025AC to +5V (VCC). If I2CR pin is connected to GND (You can check it with a tester) you must connect it to +5V to use my library.
To be shure I2C communication working and to check P9025AC i2c address (it should be 0x25h), just run CheckI2CDevAddress.ino sketch.If you will get 0x25h, should not be problem with use this library.
If you non get response from P9025AC, check i2c connections and be shure that SDA and SCK lines are connectet with pull-up resistor to +5V source (and not to the Ground).
If CheckI2CDevAddress.ino return a device address different to 0x25h, to use this library, you should open P9025A.h file and replace " #define P9025A_ADDRESS (0x25)" value 0x25 with your P9025A address updated from CheckI2CDevAddress.ino skatch.
