/**************************************************************************/
/*!
    @file     P9025A.CPP
    @author   Conte Luigi
    @license  GPL 3.0 (see license.txt)

    This program is wrote for the #WirelessPowerContest.
    I used I2C line of P9025A to communicate with Arduino UNO.

    @section  HISTORY

    v1.0  - First release (January 2017)
*/
/**************************************************************************/


#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>

#include "P9025A.h"

static uint8_t i2cread(void) {
  #if ARDUINO >= 100
  return Wire.read();
  #else
  return Wire.receive();
  #endif
}

static void i2cwrite(uint8_t x) {
  #if ARDUINO >= 100
  Wire.write((uint8_t)x);
  #else
  Wire.send(x);
  #endif
}

/**************************************************************************/
/*!
    IDTP9025A has I2C address that is set (usually!) to default 0x25h
*/
/**************************************************************************/
P9025A::P9025A(uint8_t i2cAddress)
{
   m_i2cAddress = i2cAddress;
}

/**************************************************************************/
/*!
    Begin I2C Communication
*/
/**************************************************************************/
void P9025A::begin() {
  Wire.begin();
}

/**************************************************************************/
/*!
    Read 2 registers value (to convert it into 10bit or 12bit value)
*/
/**************************************************************************/

static uint16_t readRegister(uint8_t i2cAddress, uint8_t reg1, uint8_t reg2) {
  Wire.beginTransmission(i2cAddress);
  i2cwrite(reg1);
  Wire.endTransmission(0);
  Wire.requestFrom(i2cAddress, (uint8_t)1);
  uint8_t lsb = i2cread();  
  Wire.beginTransmission(i2cAddress);
  i2cwrite(reg2);
  Wire.endTransmission(0);
  Wire.requestFrom(i2cAddress, (uint8_t)1);
  uint8_t msb = i2cread();
  uint16_t val = (lsb <<8 | msb);
   return val;
}


/**************************************************************************/
/*!
    @brief  Read Vrect Voltage value from coil (Full wave rectifier).
	The regulation circuit regulates the voltage of the 7V rectifier,
	by sending the Control Error Packets instruction to the transmitter.
	The LDO output is activated and the power is supplied to the load,
	after Vrect reached 7V.
*/
/**************************************************************************/
int16_t P9025A::getVrectVoltage()
{
  uint16_t res = readRegister(m_i2cAddress, P9025A_VRECT_VOLTAGE_REG0, P9025A_VRECT_VOLTAGE_REG1) >>4;//Shift out bit 3:0 of Reg41
    return res;
}

/**************************************************************************/
/*!
    @brief Read Current used from load connected to the OUT pin of P9025A (OUT)
*/
/**************************************************************************/
int16_t P9025A::getIoutCurrent()
{
  uint16_t res = readRegister(m_i2cAddress, P9025A_IOUT_CURRENT_REG2, P9025A_IOUT_CURRENT_REG3) >> 4; //Shift out bit 3:0 of Reg43
    return res;
}

/**************************************************************************/
/*!
    @brief  Read Coil Frequency
*/
/**************************************************************************/
int16_t P9025A::getCoilFrequency()
{
  uint16_t res = readRegister(m_i2cAddress, P9025A_COIL_FREQUENCY_REG4, P9025A_COIL_FREQUENCY_REG5) >> 6; //Shift out bit 5:0 of Reg45
    return res;
}

