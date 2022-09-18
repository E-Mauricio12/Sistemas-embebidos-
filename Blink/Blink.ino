//Sistemas embebidos
//Sánchez Ortega Eduardo Mauricio
//06-sept-22
//Este sketch enciende y apaga un led, conectado al pin 23 del ESP32, cada medio segundo.

int pin_led =23;

void setup(){
  pinMode(pin_led, OUTPUT);
}

void loop(){
  digitalWrite(pin_led, HIGH);
  delay(500);                       
  digitalWrite(pin_led, LOW);    
  delay(500);                       
}
