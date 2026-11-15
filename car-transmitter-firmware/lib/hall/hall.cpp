#include "hall.h"

unsigned long interruptCount = 0;
unsigned long time_now = 0;
unsigned long time_prev = 0;
unsigned long tacho;

void hall_setup()
{
    // Attaches hall interrupt to pin, RISING also seems to work
    // This will never run the network stack because it runs on core 0, while all this runs on core 1
    attachInterrupt(HALL_PIN, hall_isr, FALLING);
    pinMode(HALL_PIN, INPUT_PULLUP);
    Serial.print(F("[HALL] Initialized"));
}

// Must keep this function very short and simple because it interrupts the main thread
void hall_isr()
{
    interruptCount++;
    time_now = micros();

    if ((time_now - time_prev) >= HALL_MIN_TRIGGER_TIME)
    {
        tacho++;
    }

    time_prev = time_now;
}

unsigned long hall_getTacho()
{
    return tacho;
}
unsigned long hall_getInterruptCount()
{
    return interruptCount;
}