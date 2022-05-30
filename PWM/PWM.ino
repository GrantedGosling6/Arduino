#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal Mi_LCD (rs, en, d4, d5, d6, d7);
const int Led=5;
const int Pot=A1;
const int boton=2;
const int brillo=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Led,OUTPUT);
  pinMode(boton,INPUT);
  Mi_LCD.begin(16, 2);
  Mi_LCD.print("      PWM");
  Mi_LCD.setCursor(0, 1);
  Mi_LCD.print("    EXAMEN");
  delay(1000);
  while((digitalRead(boton)==HIGH));
}

void loop() {

analogWrite(Led, 191);
  
   // if( digitalRead(boton==LOW) ){

  for (int brillo = 0; brillo <= 255; brillo++) {
        Mi_LCD.clear();
    Mi_LCD.print("Encendiendo");
    delay(100);
    analogWrite(Led, brillo);
    delay(10);


  }

          Mi_LCD.clear();
    Mi_LCD.print("Encendido");
    delay(100);
  delay(5000);

          for( int brillo = 255 ; brillo >= 0 ; brillo--){
                Mi_LCD.clear();
    Mi_LCD.print("Apagando");
    delay(100);
      analogWrite(Led, brillo);
      delay(10);
    }

            Mi_LCD.clear();
    Mi_LCD.print("Apagado");
    delay(100);
  delay(3000);
    //}//else if(digitalRead(boton==HIGH)){
       //   for( int brillo = 255 ; brillo >= 0 ; brillo--){
      //analogWrite(Led, brillo);
      //delay(50);
    //}
    //delay(3000);
    //}

  
  //int x=analogRead(Pot);
  //int porc=map(x,0,1023,0,100);
  //int valor=map(porc,0,100,0,255);
 // analogWrite(Led,valor);
  //Mi_LCD.clear();
 // Mi_LCD.print("Led=");
  //Mi_LCD.print(porc);
  //Mi_LCD.print("%");
  //delay(100);
}
