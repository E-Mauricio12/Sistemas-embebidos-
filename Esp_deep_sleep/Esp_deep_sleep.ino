RTC_DATA_ATTR int bootcount = 0; //esto se va a aguardar dentro d ela memoería del RTC
                                //esta memoría si se mantiene tras un deep sleep
#define uS_TO_S_FACTOR 1000000 //el factor de conversión s a us.
#define TIME_TO_SLEEP 5 // Tiempo que el ESP va a dormir, en s. 
#define led_pin 34
#define pin_boton 33

void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();
  switch(wakeup_reason){
    case ESP_SLEEP_WAKEUP_EXT0:
        Serial.println("Inicio causado por señal en el RTC_IO (periféricos delRTC)");
    break;

    case ESP_SLEEP_WAKEUP_EXT1:
        Serial.println("Inicio causado por señal en el RTC_CTNL");
    break;

    case ESP_SLEEP_WAKEUP_TIMER:
        Serial.println("Inicio causado por señal en un timer");
    break;

    case ESP_SLEEP_WAKEUP_TOUCHPAD:
        Serial.println("Inicio causado por señal e un pin touch (periféricos del RTC)");
    break;

    case ESP_SLEEP_WAKEUP_ULP:
        Serial.println("Inicio causado por la señal lanzada por el ULP Coprocessor");
    break;
        
    default:
      Serial.printf("El inicio de no fue causado por ninguna razón coconocida");  
    }
  }
  
//cuando se vuelve de un deep sleep, el programa arranca desde el setup.
void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(led_pin,OUTPUT);
  pinMode(pin_boton,INPUT);
  bootcount++;
  Serial.println("boot number: " + String(bootcount));
  print_wakeup_reason();

  //Cofiguración de light sleep
  esp_sleep_enable_ext0_wakeup((gpio_num_t)pin_boton,HIGH);//aqui se indica el pin a través del cual se va a recibir la señal con la cual queremos despertar
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP*uS_TO_S_FACTOR);
  Serial.println("Configurando ESP32 para dormir por " +String(TIME_TO_SLEEP) + "segundos.");
  //if(bootcount%2 == 0){
    Serial.println("ESP32 se va a dormir ahora.");
    esp_deep_sleep_start();
  //}
  Serial.println("esta linea no se escribe jamás");
}

void loop(){
  digitalWrite(led_pin,LOW);
  esp_light_sleep_start();
  
  digitalWrite(led_pin,HIGH);
  delay(500);
  print_wakeup_reason();
}
