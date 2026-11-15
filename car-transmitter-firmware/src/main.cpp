#include <Arduino.h>
#include "vesc.h"
#include "hall.h"
#include "lora.h"

#define MAX_PACKETS_PER_SECOND 20

void setup()
{
    Serial.begin(115200);

    delay(1000);

    vesc_setup();
    hall_setup();
    radio_setup();

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH); // LOW turns the light on, HIGH turns it off
}

unsigned long time_prev = 0;
unsigned long time_now = 0;

void loop()
{
    unsigned long time_start = micros();

    data_packet data = {0};

    // Get vesc values
    boolean vesc_success = vesc_populate(&data);
    digitalWrite(LED_BUILTIN, vesc_success ? LOW : HIGH); // LOW turns the light on, HIGH turns it off
    // Light being on means we are successfully getting vesc data

    // Get hall effect sensor data
#ifdef TACHO_FROM_HALL
    data.tacho = hall_getTacho();
#endif

    // TODO get joulemeter values

    // TODO update bluetooth

    // Send it all away
    radio_send(&data);

    // Wait for next process
    delayMicroseconds((1000 * 1000 / MAX_PACKETS_PER_SECOND) - (micros() - time_start));
}