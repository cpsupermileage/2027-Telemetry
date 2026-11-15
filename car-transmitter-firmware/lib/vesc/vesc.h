#ifndef VESC_H_
#define VESC_H_

#include <HardwareSerial.h>
#include <VescUart.h>
#include "common.h"

#define VESC_BAUD_RATE 9600

#define VESC_SWITCH_TX_RX false    // false for UC, true for prototype, switches the TX/RX pins (NOT polarity)
#define VESC_INVERT_TX_RX false    // true for new (Idika 2027) vesc with weird optocuplers, false everywhere else
#define VESC_AUTO_TX_RX            // uncomment this to figure out the serial connection switching and inversion automatically (NOT BAUD RATE)
#define VESC_AUTO_MAX_ATTEMPTS 160 // Each attempt takes ~100ms, cycling 4 different variations (switched/non-switched and inverted/non-inverted)

void vesc_setup();
bool vesc_populate(data_packet *data);

#endif