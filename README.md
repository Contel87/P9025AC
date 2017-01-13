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
