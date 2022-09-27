//Este skecth enciende un led cuando el resistor, a partir de luz, no recibé ninguna señal.
  //caso contrario se apaga el led al recibir un señal de luz.

#define pin_sensorLuz 34
int pin_led =23;

void setup() {
  Serial.begin(9600); //incia comunicación serial
  pinMode(pin_led, OUTPUT);
  
}

void loop() {
  int medicion = analogRead(pin_sensorLuz);
  Serial.println(medicion);
  delay(1000);
  if(medicion == 0){
     digitalWrite(pin_led, HIGH);
  }
  else{                       
     digitalWrite(pin_led, LOW);    
  } 
}
