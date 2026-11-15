#ifndef HALL_H
#define HALL_H

#include <Arduino.h>

#define TACHO_FROM_HALL // Use the tacho value we calculate from the hall effect sensor instead of the vesc-given value
#define HALL_PIN D4     // If using tacho from hall sensor, must specify pin

#define HALL_MIN_TRIGGER_TIME 50000 // Min time in us for a magnet pass to count as a real pass.

void hall_setup();
void hall_task(void *parameter);
unsigned long hall_getTacho();
unsigned long hall_getInterruptCount();

#endif