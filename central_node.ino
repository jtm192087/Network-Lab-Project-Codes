/*
Author : Priyanka Singh
Title : I2C MASTER CODE 
Description : I2C Communication between 1 Master and 4 Slaves
*/

#include<Wire.h>                     //Library for I2C Communication functions
#include<LiquidCrystal.h>            //Library for LCD display function

LiquidCrystal lcd(12,11,5,4,3,2);    //Define LCD Module Pins (RS,EN,D4,D5,D6,D7)
char store[100];
char str[4];

void setup() 
{ 
  lcd.begin(16,2);                 //Initilize LCD display
  
  lcd.setCursor(0,0);
  lcd.print("Welcome ");
  delay(100);
  lcd.setCursor(0,0);
  lcd.print("Wireless Node");
  lcd.setCursor(0,1);
  lcd.print("   Network");
  delay(100);
 
  Serial.begin(9600);              //Begins Serial Communication at 9600 baud rate
  Wire.begin();                    //Begins I2C communication at pin (A4,A5)
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending req to A");
  delay(100);
  Wire.requestFrom(8,1);   // request 1 byte from slave arduino (8)
    
  if (Wire.available()) 
  { 
    lcd.setCursor(0,1);
    lcd.print("Node A Found");
    delay(100);
    byte MasterReceive = Wire.read();// receive a byte from the slave arduino and store in MasterReceive
    int a = MasterReceive ;
    lcd.clear(); 
    lcd.setCursor(0,0);              //Sets Currsor at line one of LCD
    lcd.print("Smoke : ");           
    lcd.setCursor(0,1);              
    lcd.print(MasterReceive);        //Prints SlaveVal: in LCD
    
    //Serial.println(a);
    itoa(a, str, 10);
    //Serial.println(str);
    strcat(store,"NodeA_smoke:");
    strcat(store,str);
    Serial.println(store);
  
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Node A not found");
    strcat(store,"NodeA_smoke:");
    strcat(store,"invalid");
    Serial.println(store);
  }    
  delay(100);
  
  /////////////////////////////////////////
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending req to B");
  delay(100);
  Wire.requestFrom(9,1);             // request 1 byte from slave arduino (9)
    
  if (Wire.available()) 
  { 
    lcd.setCursor(0,1);
    lcd.print("Node B Found");
    delay(100);
    byte MasterReceive = Wire.read();// receive a byte from the slave arduino and store in MasterReceive
    int a = MasterReceive ;
    lcd.clear(); 
    lcd.setCursor(0,0);              //Sets Currsor at line one of LCD
    lcd.print("Smoke : ");           
    lcd.setCursor(0,1);              
    lcd.print(MasterReceive);        //Prints SlaveVal: in LCD
 
    //Serial.println(a);
    itoa(a, str, 10);
    //Serial.println(str);
    strcat(store,";NodeB_smoke:");
    strcat(store,str);
    Serial.println(store);
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Node B not found");
    strcat(store,";NodeB_smoke:");
    strcat(store,"invalid");
    Serial.println(store);
  }    
  delay(100);
 
  /////////////////////////////////////////
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending req to C");
  delay(100);
  Wire.requestFrom(10,1);             // request 1 byte from slave arduino (10)
    
  if (Wire.available()) 
  { 
    lcd.setCursor(0,1);
    lcd.print("Node C Found");
    delay(100);
    byte MasterReceive = Wire.read();// receive a byte from the slave arduino and store in MasterReceive
    int a = MasterReceive ;
    lcd.clear(); 
    lcd.setCursor(0,0);              //Sets Currsor at line one of LCD
    lcd.print("Smoke : ");           
    lcd.setCursor(0,1);              
    lcd.print(MasterReceive);        //Prints SlaveVal: in LCD
  
    //Serial.println(a);
    itoa(a, str, 10);
    //Serial.println(str);
    strcat(store,";NodeC_smoke:");
    strcat(store,str);
    Serial.println(store);
  
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Node C not found");  
    strcat(store,";NodeC_smoke:");
    strcat(store,"invalid");
    Serial.println(store);
  }    
  delay(100);
  
  
  /////////////////////////////////////////
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending req to D");
  delay(100);
  Wire.requestFrom(11,2);             // request 1 byte from slave arduino (11)
    
  if (Wire.available()) 
  { 
    lcd.setCursor(0,1);
    lcd.print("Node D Found");
    delay(100);
    byte MasterReceive_smoke = Wire.read();// receive a byte from the slave arduino and store in MasterReceive
    int a = MasterReceive_smoke ;
    //byte MasterReceive_temp = Wire.read();
    lcd.clear(); 
    lcd.setCursor(0,0);              //Sets Currsor at line one of LCD
    lcd.print("Smoke : ");           
    lcd.setCursor(9,0);              
    lcd.print(MasterReceive_smoke);        //Prints SlaveVal: in LCD
    /*
    lcd.setCursor(0,1);              //Sets Currsor at line one of LCD
    lcd.print("Temp : ");           
    lcd.setCursor(8,1);              
    lcd.print(MasterReceive_temp);        //Prints SlaveVal: in LCD
    */
  
    //Serial.println(a);
    itoa(a, str, 10);
    //Serial.println(str);
    strcat(store,";NodeD_smoke:");
    strcat(store,str);
    Serial.println(store);

  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Node D not found");
    strcat(store,";NodeD_smoke:");
    strcat(store,"invalid");
    Serial.println(store);
  }    
  delay(100);
  
  
  /////////////////////////////////////////
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Sending req to E");
  delay(100);
  Wire.requestFrom(12,1);             // request 1 byte from slave arduino (10)
    
  if (Wire.available()) 
  { 
    lcd.setCursor(0,1);
    lcd.print("Node E Found");
    delay(100);
    byte MasterReceive = Wire.read();// receive a byte from the slave arduino and store in MasterReceive
    lcd.clear(); 
    lcd.setCursor(0,0);              //Sets Currsor at line one of LCD
    lcd.print("Smoke : ");           
    lcd.setCursor(0,1);              
    lcd.print(MasterReceive);        //Prints SlaveVal: in LCD
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Node E not found");  
    strcat(store,";NodeE_smoke:");
    strcat(store,"invalid");
    Serial.println(store);
  }    
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Data collected");
  lcd.setCursor(0,1);
  lcd.print("Successfully");
  
  Serial.println("*******************************************");
  Serial.println("Data Collected Successfully by the Central Node");
  Serial.println("*******************************************");
  Serial.println("");
  
  delay(100);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   Sending to");
  lcd.setCursor(0,1);
  lcd.print(" Control Center");
  
  Serial.println("*******************************************");
  Serial.println("Sending data to Control Center ");
  Serial.println("*******************************************");
  
 // Serial.println(strlen(store));
  for (int i=0; i< strlen(store);i++)
    {
    Wire.beginTransmission(13);       // start transmit to slave arduino (8)
    Wire.write(store[i]);               // sends one byte converted POT value to slave
    Wire.endTransmission();           // stop transmitting
    }
  
    Serial.println("");
  
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   Data sent");
  lcd.setCursor(0,1);
  lcd.print(" successfully");
  
  Serial.println("*******************************************");
  Serial.println("Data successfully sent to Control Center ");
  Serial.println("*******************************************");
  
  strcpy(store, "");
  
  delay(1000);
}