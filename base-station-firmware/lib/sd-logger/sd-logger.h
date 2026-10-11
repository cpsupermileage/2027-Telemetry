#ifndef SD_LOGGER_H_
#define SD_LOGGER_H_

#include "FS.h"
#include "SD.h"
#include "SPI.h"

#define SDCARD_MOSI                 15
#define SDCARD_MISO                 2
#define SDCARD_SCLK                 14
#define SDCARD_CS                   13

void SD_setup();

#endif