#include <SoftwareSerial.h>

const int Led1=2, Led2=3, Led3=4,Led4=5;

void setup(){
  pinMode(Led1,OUTPUT);
  pinMode(Led2,OUTPUT);
  pinMode(Led3,OUTPUT);
  pinMode(Led4,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  while(Serial.available()>0){
    char dato=Serial.read();
    if(dato=='1'){
      digitalWrite(Led1,HIGH);
    }
        if(dato=='2'){
      digitalWrite(Led2,HIGH);
    }
        if(dato=='3'){
      digitalWrite(Led3,HIGH);
    }
        if(dato=='4'){
      digitalWrite(Led4,HIGH);
    }
    delay(1);
  }
  digitalWrite(Led1,LOW);
  
  digitalWrite(Led2,LOW);
  
  digitalWrite(Led3,LOW);
  
  digitalWrite(Led4,LOW);
}
