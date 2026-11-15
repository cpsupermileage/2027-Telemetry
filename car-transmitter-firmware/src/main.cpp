#include <Arduino.h>
#include "vesc.h"
#include "hall.h"
#include "lora.h"

void setup()
{
  Serial.begin(115200);

  delay(1000);

  vesc_setup();
  hall_setup();
  radio_setup();
}

void loop()
{
  // whatever else here - transmitting, receiving etc.
  delay(1000);
}