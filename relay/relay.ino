const int RELAY_PIN = 13;  // establecemos el numero del pin que vamos a usar 


void setup() {
  // establecemos el pin como salida.
  pinMode(RELAY_PIN, OUTPUT);
}

// la función loop va a estar corriendo siempre y prendiendo y apagando el pin donde ubicamos el relay
void loop() {
  digitalWrite(RELAY_PIN, HIGH);
  delay(500);
  digitalWrite(RELAY_PIN, LOW);
  delay(500);
}
