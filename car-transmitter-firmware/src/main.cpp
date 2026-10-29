#include <Arduino.h>
#include "lora.h"
#include "vesc.h"

void setup()
{
  Serial.begin(115200);

  delay(1000);

  vesc_setup();
  radio_setup();

  Serial.println("Sent!");
}

void loop()
{
  // whatever else here - transmitting, receiving etc.
  delay(1000);
}