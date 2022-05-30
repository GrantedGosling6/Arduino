#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal Mi_LCD (rs, en, d4, d5, d6, d7);
int valor;
const int boton=3;
const byte rxPin =17;
const byte txPin = 16;
SoftwareSerial mySerial (rxPin, txPin);

void setup() {
  // put your setup code here, to run once:
  pinMode(boton, INPUT_PULLUP);
  mySerial.begin(9600);
  Serial.begin(9600);
  Mi_LCD.begin(16, 2);
  Mi_LCD.print("COMUNICACION");
  Mi_LCD.setCursor(0, 1);
  Mi_LCD.print("SERIAL");
  delay(1000);
  attachInterrupt(digitalPinToInterrupt(boton), BT, FALLING);

}


void loop() {

 valor = analogRead(A1);


        Mi_LCD.clear();
    Mi_LCD.print("POT: ");
    int valorajustado=Ajuste();
    Mi_LCD.print(valorajustado);
    Serial.print("POT= ");
    Serial.println(valorajustado);
    delay(200);
 


//    bool valor1=digitalRead(boton);
//if(valor1==LOW){
// 
//   
//   mySerial.print("Temperatura recibida: ");
//    mySerial.println(valorajustado);
//    delay(100);
//  
//}


}


int Ajuste(){
  int temp=map(valor,0,1023,0,100);
  return temp;
}

void BT(){


    if(mySerial.available() > 0)  
  {
    int valorajustado=Ajuste();
    
    mySerial.print("Temperatura recibida: ");
    mySerial.println(valorajustado);
    delay(1000);
  }

    int valorajustado=Ajuste();
    
    mySerial.print("Temperatura recibida: ");
    mySerial.println(valorajustado);
    delay(1000);
    

}
