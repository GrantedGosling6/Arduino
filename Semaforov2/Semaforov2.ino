const int boton=2;
const int Led1=4;//verde
const int Led2=5;//amarillo
const int Led3=6;//rojo
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal Mi_LCD (rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  pinMode(Led1,OUTPUT);
  pinMode(boton,INPUT_PULLUP);
  pinMode(Led2,OUTPUT);
  pinMode(Led3,OUTPUT);
 Mi_LCD.begin(16, 2);
  Mi_LCD.print("   BOTONES  ");
  Mi_LCD.setCursor(0, 1);
  Mi_LCD.print("    FER");
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  Mi_LCD.clear();
bool valor=digitalRead(boton);

do {
  // statement block
    Mi_LCD.print("EMERGENCIA");
    digitalWrite(Led1,HIGH);
    digitalWrite(Led2,HIGH);
    digitalWrite(Led3,HIGH);
    delay(500);
    digitalWrite(Led1,LOW);
    digitalWrite(Led2,LOW);
    digitalWrite(Led3,LOW);
    Mi_LCD.clear();
} while (valor==LOW);



do {
  // statement block
  Mi_LCD.print("NORMAL");
  digitalWrite(Led1,HIGH);
  delay(10000);
  for(int i=0; i<=5; i++){//inicia parpadeo de verde
    delay(100);
    digitalWrite(Led1,HIGH);
    delay(100);
    digitalWrite(Led1,LOW);
  }//finaliza parpadeo verde
  digitalWrite(Led1,LOW);
  digitalWrite(Led2,HIGH);
  delay(5000);
  digitalWrite(Led2,LOW);
  digitalWrite(Led3,HIGH);
  delay(10000);
  digitalWrite(Led3,LOW);   
  Mi_LCD.clear();
} while (valor==HIGH);





    
  
  

}
