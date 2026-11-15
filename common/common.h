#ifndef COMMON_H
#define COMMON_H

#include "Arduino.h"
#include "datatypes.h"

// SMV
// define the data struct globally, make it accessible to everything
struct data_packet
{
    // VSEC Values
    float tempMOSFET;
    float tempMotor;
    float motorCurrent;
    float inputCurrent;
    float dutyCycle;
    float volts;
    float wattHours;
    uint32_t error;

    // From hall effect sensor
    long tacho;

    // From joulemeter
    float pdbVolts;
    float pdbCurrent;
};

#endif