#include <Wire.h>
#include "AGTimerR4.h"

int adt7410I2CAddress = 0x48;   
AGTimerR4 timer; 

void setup(void) {            
  Serial.begin(115200);         
  Wire.begin();                  
  timer.init(1000000, readTemp);
  timer.start();
}

void readTemp(void) {
  uint16_t uiVal;
  float fVal;
  int iVal;

  Wire.requestFrom(adt7410I2CAddress, 2);   

  uiVal = (uint8_t)Wire.read() << 8;   
  uiVal |= Wire.read();                 

  uiVal >>= 3;                          

  if (uiVal & 0x1000) {               
    iVal = uiVal - 0x2000;
  }
  else {
    iVal = uiVal;
  }

  fVal = (float)iVal / 16.0;
  Serial.println(String(fVal, 2));
}

void loop(){

}