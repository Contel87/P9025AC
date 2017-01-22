/**************************************************************************/
/*!
    @file     P9025A.h
    @author   Conte Luigi
    @license  GPL 3.0 (see license.txt)

    This program is wrote for the #WirelessPowerContest.
    It use I2C line of P9024A to communicate with Arduino UNO.

    @section  HISTORY

    v1.0  - First release (January 2017)
    V1.1 - Coil Frequency unit corrected: in V1.0 Coil frequency value was in Hz... True value is Khz (As QI 1.1 Specifications).
*/
/**************************************************************************/


#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>

/*================================================================
    I2C ADDRESS/BITS
    ------------------------------------------------------------*/
    #define P9025A_ADDRESS              (0x25) //P9025A Address
/*==============================================================*/

/*================================================================
    POINTER REGISTER
    ------------------------------------------------------------*/
    #define P9025A_VRECT_VOLTAGE_REG0        (0x40)
/*==============================================================*/
    #define P9025A_VRECT_VOLTAGE_REG1        (0x41)
/*==============================================================*/
    #define P9025A_IOUT_CURRENT_REG2         (0x42)
/*==============================================================*/
    #define P9025A_IOUT_CURRENT_REG3         (0x43)
/*==============================================================*/
    #define P9025A_COIL_FREQUENCY_REG4       (0x44)
/*==============================================================*/
    #define P9025A_COIL_FREQUENCY_REG5       (0x45)
/*==============================================================*/

class P9025A
{
protected:
   uint8_t   m_i2cAddress;


 public:
  P9025A(uint8_t i2cAddress = P9025A_ADDRESS);
  void begin(void);
  int16_t   getVrectVoltage();
  int16_t   getIoutCurrent();
  int16_t   getCoilFrequency();

 private:
};
