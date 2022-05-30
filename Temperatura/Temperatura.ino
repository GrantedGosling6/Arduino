#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal Mi_LCD (rs, en, d4, d5, d6, d7);

const int   LM35=A0;
const int bot1=2;
const int bot2=3;
const int pot=A1;
const int SalPWM=5;

void setup() {
  // put your setup code here, to run once:

  Mi_LCD.begin(16, 2);
  pinMode(bot1,INPUT_PULLUP);
  pinMode(bot2,INPUT_PULLUP);
  pinMode(SalPWM,OUTPUT);
  Mi_LCD.print("Pract. Arduino");
  Mi_LCD.setCursor(0, 1);
  Mi_LCD.print("Banderas/Espinosa");
  delay(1000);
  Mi_LCD.clear();
  Mi_LCD.print("Oprime boton");
  delay(100);
  //bool val1=digitalRead(bot1);
  //bool val2=digitalRead(bot2);
  //while((digitalRead(bot1)==HIGH)&&(digitalRead(bot2)==HIGH));
}

void loop() {
 float temp=analogRead(LM35);
 int porc=map(temp,0,305,0,100);
 temp=(5.0*temp*100.0)/1024.0;
 Mi_LCD.clear();

  
if(temp>=0 && temp<=15){
  Mi_LCD.print("Temperatura=");
  Mi_LCD.print(temp);
  Mi_LCD.print("C");
  Mi_LCD.setCursor(0, 1);
  Mi_LCD.print("Baja ");
  Mi_LCD.print(porc);
  Mi_LCD.print("%");
  delay(100);
}else if(temp>=16 && temp<=25){
  Mi_LCD.print("Temperatura=");
  Mi_LCD.print(temp);
  Mi_LCD.print("C");
  Mi_LCD.setCursor(0, 1);
  Mi_LCD.print("Normal ");
    Mi_LCD.print(porc);
  Mi_LCD.print("%");
  delay(100);
}else if(temp>=26 && temp<=35){
    Mi_LCD.print("Temperatura=");
  Mi_LCD.print(temp);
  Mi_LCD.print("C");
  Mi_LCD.setCursor(0, 1);
  Mi_LCD.print("Alta ");
    Mi_LCD.print(porc);
  Mi_LCD.print("%");
  delay(100);
}else if(temp>=36 && temp<=45){
      Mi_LCD.print("Temperatura=");
  Mi_LCD.print(temp);
  Mi_LCD.print("C");
  Mi_LCD.setCursor(0, 1);
  Mi_LCD.print("Muy Alta ");
    Mi_LCD.print(porc);
  Mi_LCD.print("%");
  delay(100);
}else if(temp>=46){
        Mi_LCD.print("Temperatura=");
  Mi_LCD.print(temp);
  Mi_LCD.print("C");
  Mi_LCD.setCursor(0, 1);
  Mi_LCD.print("Extrema ");
    Mi_LCD.print(porc);
  Mi_LCD.print("%");
  delay(100);
}


 
 
  

  
}
