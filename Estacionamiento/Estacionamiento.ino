#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal Mi_LCD (rs, en, d4, d5, d6, d7);

const int SensorE=2;
const int SensorS=3;

const int LedE=4;
const int LedS=5;
volatile int cont=0;
volatile int No_autos;

void setup() {
  // put your setup code here, to run once:
  pinMode(SensorE, INPUT);
 pinMode(SensorS, INPUT);

    pinMode(LedE, OUTPUT);

    pinMode(LedS, OUTPUT);
 
  attachInterrupt(digitalPinToInterrupt(SensorE),AutosE,RISING);
    attachInterrupt(digitalPinToInterrupt(SensorS),error,RISING);
  Mi_LCD.begin(16,2);
 
}


void loop() {
  // put your main code here, to run repeatedly:
 Mi_LCD.clear();
 Mi_LCD.print("Bienvenido");
 while(digitalRead(SensorE)==LOW);
 Mi_LCD.clear();
 Mi_LCD.print("Estacionamiento");
Sensor_Entrada();
 
 digitalWrite(LedE,HIGH);
 
do{
  Mi_LCD.clear();
  Mi_LCD.print("No de autos: ");
  Mi_LCD.setCursor(0,1);
  Mi_LCD.print(cont);
  delay(100);
}while(cont>=25);

Mi_LCD.clear();
Mi_LCD.print("Estacionamiento lleno");
digitalWrite(LedS,LOW);

delay(1000);

 
}

void Sensor_Entrada (void){
   while(digitalRead(SensorE)==LOW);
   do{
   
    Mi_LCD.clear();
 Mi_LCD.print("Bienvenido!");
 Mi_LCD.setCursor(0,1);
  Mi_LCD.print(No_autos);
  delay(1000);

  }while(digitalRead(SensorE)==HIGH);

}

  void Cuenta_5_0 (){

  for(int i=5; i > 0; i--){
    Mi_LCD.clear();
   Mi_LCD.print("Autos: ");
     Mi_LCD.setCursor(0,1);
     Mi_LCD.print(i);
     delay(100);
 
  }
}


void AutosE(){
  cont++;
}

void error(){
  digitalWrite(LedS,LOW);
  do{
  Mi_LCD.clear();
  Mi_LCD.print("Error");
  for(int i=0; i<500; i++){
    delayMicroseconds(1000);
  }
  Mi_LCD.setCursor(0,1);
  Mi_LCD.print("No.depzas");
  Mi_LCD.print(cont);
  Mi_LCD.print(" de ");
  Mi_LCD.print(No_autos);
    for(int i=0; i<500; i++){
    delayMicroseconds(1000);
  }
  }
  while(1);
}
