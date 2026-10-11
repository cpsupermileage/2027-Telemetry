#include <Arduino.h>
#include "lora.h"
#include "sd-logger.h"
#include "oled.h" 



void setup() {
  Serial.begin(115200);
  delay(2000);
  SD_setup();
  radio_setup();
  oled_setup();

}

void loop() {
  
}

