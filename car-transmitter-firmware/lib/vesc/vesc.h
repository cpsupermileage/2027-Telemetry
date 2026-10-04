#ifndef VESC_H_
#define VESC_H_

#include <HardwareSerial.h>
#include "VescUart.h"

#define VESC_BAUD_RATE 9600
#define VESC_INVERT_TX_RX // Comment for UC, uncomment for prototype

void vesc_setup();
void vesc_get_values();

#endif