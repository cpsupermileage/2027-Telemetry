#ifndef COMMON_H
#define COMMON_H

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
    char error; // uint8_t

    // From hall effect sensor
    long tacho;

    float pdbVolts;
    float pdbCurrent;
};

#endif