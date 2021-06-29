#include <Arduino.h>
#include "Wire.h"

void setup()
{
  Wire.begin();
  Serial.begin(9600);
  //delay(10);
}

void loop()
{
  Wire.beginTransmission(0x68);
  delay(10); // delay for logic Analyzer 
  Wire.write(0x75); // who am i  // 70 return 
  delay(10);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 8);
  delay(10);

  int a = Wire.read();
  Serial.println(a, HEX);
  delay(10);
}
