//Sánchez Ortega Eduardo Mauricio
//sistemas embebidos en la nube
//5-oct-2022

//Se obtiene el valor de la temperatura (°C) y la presión (Pa) a partir del sensor bmp180. Los datos obtenidos por dicho sensor se
 //muestran en el monitor serie y, a su vez, se almacenan en un archivo .csv, creado y guardado en una sd con el uso de un módulo microsd 

//LIBRERÍAS
 #include <sd_defines.h>
 #include <SD.h>
 #include <sd_diskio.h>
 #include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;
File datos;

//VARIABLES
 char payload[50]; //datos a escribir en sd y serial

//variables para los datos del sensor
 float temperatura;
 float presion;
 
//se define el pin a ser usado por el led
 #define led_azul 2

//se define la función que controla el encendido y apagado del led, con el fin de servir como un indicador.
void parpadeo(){
  digitalWrite(led_azul,HIGH);
  delay(100);
  digitalWrite(led_azul,LOW);
  delay(100);
  }

void setup(){
  Serial.begin(115200); //Se inicia comunicación serial
  bmp.begin(); //se inicializa el sensor, dirección: 0x77
  pinMode(led_azul,OUTPUT); //se define el comportamiento del sensor.
  
//definición de variables en las que se van a almanecar los datos obetnidos por el sensor. 
  temperatura = bmp.readTemperature(); 
  presion = bmp.readPressure();

//en caso de haber un problema con el módulo bmp, se ejecuta el siguiente aviso.
  if(!bmp.begin()){
    Serial.println("Problemas con el sensor barométrico");
    while (1){}
    }
  SD.begin(); //inicializa SD
}

void loop() {
//DATOS A IMPRIMIR EN EL MONITOR SERIE
  //medición de temperatura en °C
  //Serial.println(temperatura);
  //medición de presión en pascales
  //Serial.println(presion);
  //Serial.println("---------------");

//SE ESCRIBEN LOS DATOS EN PAYLOAD
  //       "temperatura: presion: "
  sprintf(payload,"%.2f,%.2f",temperatura,presion); //función para escribir, con cierto formato, los datos provenientes del sensor
  Serial.println(payload); //se imprime, en monitor serie, los datos en el formato dado con la funcipon sprintf
  
//SE ABRE ARCHIVO Y SE ESCRIBE
  datos = SD.open("/Datos_SensorBMP.csv", FILE_APPEND); //se crea un archivo en la memoria sd
  datos.println(payload); //los datos provenientes de la función 'sprintf' son escritos en el archivo creado
  parpadeo(); //se ejecuta la función definida anteriormente
  
//SE CIERRA EL ARCHIVO
  datos.close();
  
//TIEMPO DE RETARDO ENTRE CADA LECTURA
  delay(1000);  
}
