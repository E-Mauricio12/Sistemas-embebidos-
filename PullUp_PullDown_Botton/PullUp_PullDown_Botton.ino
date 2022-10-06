//Sánchez Ortega Eduardo Mauricio
//Sistemas embebidos en la nube.
//05-oct-2022

//Se controla el encendido y apagado, de dos led diferentes, conectados a un boton en conexión  pullup y otro boton en conexión pulldown, respectivamente.

//se definen los pines a utilizar por los correspondientes leds y botones.
//Boton pullDown
  #define botton_1 32
  #define led_1 15

//Boton pullUp
  #define botton_2 35
  #define led_2 2

void setup() {
  Serial.begin(9600); //se inicia la comunicación serial
  pinMode(botton_1,INPUT); //se definen los pines correspondientes a los botones como pin de entrada, es decir, recibirá una señal
  pinMode(led_1,OUTPUT); // se definen los pines correspondientes a los led como pin salida (HIGH,LOW)
  pinMode(botton_2,INPUT);
  pinMode(led_2,OUTPUT);
}

void loop() {
  //se impirme en monitor seria el valor de entrada en los pines correspondientes a los botones.
  Serial.println(digitalRead(botton_1));
  Serial.println(digitalRead(botton_2));
  Serial.println("-------------------");
  //delay(1000);

// Se definen el proceso para el encendido y apagado en cada led.
//boton en conexión pulldown
  if(digitalRead(botton_1)==1){
    digitalWrite(led_1,HIGH); //led enciende
    }
  else{
    digitalWrite(led_1,LOW);} //led apaga
    
//boton en conexión pullup   
  if(digitalRead(botton_2)==0){
    digitalWrite(led_2,LOW);
    }
  else{
    digitalWrite(led_2,HIGH);}
}
