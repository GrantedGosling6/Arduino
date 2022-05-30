#include <Wire.h>

volatile int No_pzas;

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
   Serial.begin(9600); 
}

byte x = 1;

void loop() {

  No_pzas=map(analogRead(A1),0,1023,0,100);


  
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write("POT is ");        // sends five bytes
  Wire.write(No_pzas);              // sends one byte
  Wire.endTransmission();    // stop transmitting

  
  delay(500);


   Wire.requestFrom(8, 8);    // request 12 bytes from slave device #8

  while (1 < Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
       Serial.print(c);         // print the character

  }

  int x=Wire.read();
  Serial.println(x);

  delay(500);
}
