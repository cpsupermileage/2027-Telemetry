#include "sd-logger.h"

SPIClass SD_SPIHandle(HSPI);

void SD_setup()
{
    // initialize the SD card
    Serial.print(F("[SD] Initializing ... "));

    


    // Initialize the second SPI for use with the SD card
    SD_SPIHandle.begin(SDCARD_SCLK, SDCARD_MISO, SDCARD_MOSI);

    if (!SD.begin(SDCARD_CS, SD_SPIHandle)) {
        Serial.println("Card Mount Failed");
        return;
    }
    uint8_t cardType = SD.cardType();

    if (cardType == CARD_NONE) {
        Serial.println("No SD card attached");
        return;
    }

    Serial.print("SD Card Type: ");
    if (cardType == CARD_MMC) {
        Serial.println("MMC");
    } else if (cardType == CARD_SD) {
        Serial.println("SDSC");
    } else if (cardType == CARD_SDHC) {
        Serial.println("SDHC");
    } else {
        Serial.println("UNKNOWN");
    }


}
