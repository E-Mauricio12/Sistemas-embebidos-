#define uS_TO_S_FACTOR 1000000 //el factor de conversión s a us.
#define TIME_TO_SLEEP 10 // Tiempo que el ESP va a dormir, en s. 
#define led_pin 12

void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();
  switch(wakeup_reason){
    case ESP_SLEEP_WAKEUP_EXT0:
        Serial.println("Inicio causado por señal en el RTC_IO (periféricos del RTC)");
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
  
void setup() {
  Serial.begin(115200);
  pinMode(led_pin,OUTPUT);
  //Cofiguración de light sleep
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP*uS_TO_S_FACTOR);
  Serial.println("Configurando ESP32 para dormir por " +String(TIME_TO_SLEEP) + "segundos.");
}

void loop(){
  digitalWrite(led_pin,LOW);
  esp_light_sleep_start();
  
  digitalWrite(led_pin,HIGH);
  delay(500);
  print_wakeup_reason();
}
