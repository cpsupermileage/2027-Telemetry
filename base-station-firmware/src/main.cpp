#include <Arduino.h>
#include "lora.h"
#include "sd-logger.h"



void setup() {
  Serial.begin(115200);
  delay(2000);
  SD_setup();
  radio_setup();

}

void loop() {
  
}

