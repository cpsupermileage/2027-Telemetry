#ifndef LORA_H_
#define LORA_H_

#include <RadioLib.h>
#include "sd-logger.h"
#define RADIO_SCLK_PIN              5
#define RADIO_MISO_PIN              3
#define RADIO_MOSI_PIN              6
#define RADIO_CS_PIN                7
#define RADIO_RST_PIN               8
#define RADIO_DIO1_PIN              33
#define RADIO_BUSY_PIN              34

#define SYNC_WORD 0xB4

void radio_setup();
void radio_receive();
#endif