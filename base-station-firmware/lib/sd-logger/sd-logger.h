#ifndef SD_LOGGER_H_
#define SD_LOGGER_H_

#include "FS.h"
#include "SD.h"
#include "SPI.h"

#define SDCARD_MOSI                 11
#define SDCARD_MISO                 2
#define SDCARD_SCLK                 14
#define SDCARD_CS                   13

void SD_setup();
void SD_write(uint8_t *data,int len);

#endif