
 
// Incluimos la libreria para utilizar I2C
#include <Wire.h>
 
// Relé en pin 13
const int RelePin = 8; 
const int RelePinRPI3 = 7;
 
void setup() {
  // Se comunicara via I2C como esclavo con la dirección  #8
  Wire.begin(0x8);
               
  Wire.onReceive(receiveEvent);
    pinMode(RelePinRPI3, OUTPUT);
  digitalWrite(RelePinRPI3, LOW);
  delay (1000);
  digitalWrite(RelePinRPI3, HIGH);
  
  
  
  
  // Establece el pin 13 como salida y apaga el Relé
  pinMode(RelePin, OUTPUT);
  digitalWrite(RelePin, LOW);

}
 
// Esta funcion solo se ejecuta cuando recive informacion del maestro (Raspberrypi3)
void receiveEvent(int howMany) {
  while (Wire.available()) { 
    char c = Wire.read(); // recibe un byte como caracter
    digitalWrite(RelePin, c);
    
    
   
  }
}
void loop() {
  delay(100);
}
