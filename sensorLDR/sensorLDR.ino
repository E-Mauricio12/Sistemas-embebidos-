//Sánchez Ortega Eduardo Mauricio
//25/spet/22
//medición del valor de la resistencia a partir de la incidencia de luz en el sensor

#define pin_sensorLuz 34

void setup() {
  Serial.begin(9600); //incia comunicación serial
}

void loop() {
  int medicion = analogRead(pin_sensorLuz);
  Serial.println(medicion);
  delay(1000);
}
