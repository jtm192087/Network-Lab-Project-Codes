/*
Author : Priyanka Singh
Title : I2C Slave CODE (Address 13)
Description : I2C Communication between Control Center and Central Node
*/


#include<Wire.h>                          //Library for I2C Communication functions
#include<LiquidCrystal.h>                 //Library for LCD display function
LiquidCrystal lcd(12,11,5,4,3,2);    //Define LCD Module Pins (RS,EN,D4,D5,D6,D7)

int i=0;
char val[100];

void receiveEvent (int howMany)                    //This Function is called when Slave receives value from master
{
  lcd.setCursor(0,0);
  lcd.print("Receiving data");
  lcd.setCursor(0,1);
  lcd.print("from central nod");
  char SlaveReceived = Wire.read();   
  val[i] = SlaveReceived ;
  Serial.print(val[i]);
   i++;
  if (i==79)
  {
  Serial.println("\n");
  Serial.println("Data received from Central Node: "); 
  Serial.println(val);
  Serial.println("\n");
  i=0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Data collected");
  lcd.setCursor(0,1);
  lcd.print("Successfully");
  
  //Serial.println("*******************************************");
  Serial.println("Data Collected Successfully");
  Serial.println("*******************************************");  
    
    delay(1000);  
    
  }
}


void setup() 

{
  lcd.begin(16,2);                        //Initilize LCD display
  lcd.setCursor(0,0);                     //Sets Cursor at first line of Display 
  lcd.print("Control Center");            //Prints CIRCUIT DIGEST in LCD 
  Serial.begin(9600);                     //Begins Serial Communication at 9600 baud rate
  Wire.begin(13);                          //Begins I2C communication with Slave Address as 8 at pin (A4,A5)
  Wire.onReceive(receiveEvent);           //Function call when Slave receives value from master
//  Wire.onRequest(requestEvent);           //Function call when Master request value from Slave
} 



void loop(void) 
{
  delay(100); 
}


