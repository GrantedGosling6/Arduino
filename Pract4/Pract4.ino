#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal Mi_LCD (rs, en, d4, d5, d6, d7);

const int BE=2;
const int Sensor=3;
volatile int BI=4;
const int motor=5;
const int Led=13;
volatile int cont=0;
volatile int No_pzas;

void setup() {
  // put your setup code here, to run once:
  pinMode(BE, INPUT_PULLUP);
 pinMode(Sensor, INPUT_PULLUP);
  pinMode(BI, INPUT_PULLUP);
   pinMode(motor, OUTPUT);
    pinMode(Led, OUTPUT);
 
  attachInterrupt(digitalPinToInterrupt(Sensor),piezas,FALLING);
    attachInterrupt(digitalPinToInterrupt(BE),error,FALLING);
  Mi_LCD.begin(16,2);
 
}


void loop() {
  // put your main code here, to run repeatedly:
 Mi_LCD.clear();
 Mi_LCD.print("Oprime Inicio");
 while(digitalRead(BI)==HIGH);
 Mi_LCD.clear();
 Mi_LCD.print("Configurando");
 Ajustar_Entrada();
 Cuenta_5_0();
 digitalWrite(motor,HIGH);
 
do{
  Mi_LCD.clear();
  Mi_LCD.print("No de piezas: ");
  Mi_LCD.setCursor(0,1);
  Mi_LCD.print(cont);
  delay(100);
}while(cont<No_pzas);

Mi_LCD.clear();
Mi_LCD.print("Piezas completas");
digitalWrite(motor,LOW);
cont=0;
delay(1000);

 
}

void Ajustar_Entrada (void){
   while(digitalRead(BI)==LOW);
   do{
    No_pzas=map(analogRead(A1),0,1023,10,25);
    Mi_LCD.clear();
 Mi_LCD.print("Piezas a contar");
 Mi_LCD.setCursor(0,1);
  Mi_LCD.print(No_pzas);
  delay(200);

  }while(digitalRead(BI)==HIGH);

}

  void Cuenta_5_0 (){

  for(int i=5; i > 0; i--){
    Mi_LCD.clear();
   Mi_LCD.print("Iniciando: ");
  
     Mi_LCD.setCursor(0,1);
     Mi_LCD.print(i);
     delay(100);
 
  }
}


void piezas(){
  cont++;
}

void error(){
  digitalWrite(motor,LOW);
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
  Mi_LCD.print(No_pzas);
    for(int i=0; i<500; i++){
    delayMicroseconds(1000);
  }
  }
  while(1);
}
