 /*!
  * file ReadForINT.ino
  * 
  * Connect BMP388 to IIC/SPI interface of Arduino, download the program.
  * INT pin connect pin4
  * @n Open serial monitor, the data could be checked. 
  *
  * Copyright   [DFRobot](http://www.dfrobot.com), 2016
  * Copyright   GNU Lesser General Public License
  *
  * version  V0.1
  * date  2018-5-29
  */
  
#include "DFRobot_BMP388.h"
#include "DFRobot_BMP388_I2C.h"
#include "DFRobot_BMP388_SPI.h"
#include "Wire.h"
#include "SPI.h"
#include "bmp3_defs.h"

/* If BMP388_I2C is 1, connect BMP388 to SPI interface of Arduino, else connect I2C interface*/
#define BMP388_I2C 0

#if BMP388_I2C
DFRobot_BMP388_I2C bmp388;
#else
DFRobot_BMP388_SPI bmp388(3);
#endif

void setup(){
  /* Initialize the serial port */
  Serial.begin(9600);
  /* Initialize bmp388 */
  if(bmp388.begin()){
    Serial.println("Initialize error!");
    while(1);
  }
  /* connect pin4 with INT pin, set pin4 mode*/
  pinMode(4, INPUT);
}

void loop(){
  /* config INT and read INT pin */
  if(bmp388.INTReadPin(4)){
    /*Read temperature and pressure*/
    float temperature = bmp388.readTemperature();
    float pressure = bmp388.readPressure();
    Serial.print("temperature : ");
    Serial.print(temperature);
    Serial.print(" C");
    Serial.print("   pressure : ");
    Serial.print(pressure);
    Serial.println(" Pa");
    delay(100);
  }
}