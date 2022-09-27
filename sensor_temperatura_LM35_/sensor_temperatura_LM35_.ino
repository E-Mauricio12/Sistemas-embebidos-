//Sánchez Ortega Eduardo Mauricio
//25/spet/22
//Este sketch mide, a partir de un sensor de temperatura LM35, la temperatura del medio.

#define ADC_Vref_mV    5000.0  // voltaje de referencia en milivolts
#define ADC_resolucion 4096.0 // resolución del esp32
#define pin_sensor_LM35       35 //pin que resive la señal del sensor

void setup() {
  Serial.begin(9600);
}

void loop() {
  // se lee el valor captado por el sensor LM35
  int adc_Val = analogRead(pin_sensor_LM35);
  
  // se convierte el valor anterior en un valor de voltaje, en milivolts
  float milliVolt = adc_Val * (ADC_Vref_mV / ADC_resolucion);
  
  // se convierte el valor de voltaje en el correspondiente valor en temperatura (°C)
  float tempC = milliVolt / 10;

  //Serial.print("Temperatura: ");
  Serial.println(tempC);   
  //Serial.println("°C");
  delay(500);
}
