#include <Arduino.h>
#include <lora.h>

void setup()
{
  Serial.begin(115200);

  delay(2000);
  radio_setup();
}

void loop()
{
  // whatever else here - transmitting, receiving etc.
}