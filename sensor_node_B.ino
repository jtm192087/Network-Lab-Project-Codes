/*
Author : Priyanka Singh
Title : I2C Slave CODE (Address 9) 
Description : I2C Communication between Central Node and Sensor Node B
*/


#include<Wire.h>                          //Library for I2C Communication functions
#include<LiquidCrystal.h>                 //Library for LCD display function


void requestEvent()                                //This Function is called when Master wants value from slave
{
  for (int i=0;i<2;i++)
  {
  digitalWrite(A2,HIGH);
  delay(1);
  digitalWrite(A2,LOW);
  delay(1);
  }
  int smoke_value = analogRead(A0);
  byte SlaveSend = map(smoke_value,0,1023,0,127);    // Convert potvalue digital value (0 to 1023) to (0 to 127)
  Wire.write(SlaveSend);                          // sends one byte converted POT value to master
}


void setup() 
{
  Serial.begin(9600);                     //Begins Serial Communication at 9600 baud rate
  Wire.begin(9);                          //Begins I2C communication with Slave Address as 8 at pin (A4,A5)
  Wire.onRequest(requestEvent);           //Function call when Master request value from Slave
} 


void loop(void) 
{
  delay(100);
}