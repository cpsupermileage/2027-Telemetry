#include "sd-logger.h"

SPIClass SD_SPIHandle(HSPI);

int file_index = 0; 

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

   if (!SD.exists("/index")) {
        Serial.println("[SD] index file dosen't exist");
        file_index = 0; 
   }else {
        File f = SD.open ("/index", FILE_READ); 
        f.readBytes((char*)&file_index , sizeof(int));
        f.close(); 

        Serial.print("[SD] Read from index file ");
        Serial.println(file_index);
   }

   file_index++;

   File f = SD.open("/index" , FILE_WRITE);
   f.write((uint8_t*)&file_index , sizeof(int));
   f.close();

   Serial.print("[SD] Set Index file to ");
   Serial.println(file_index);
}

void SD_write(uint8_t *data,int len) {
    char buf[8];
    sprintf(buf, "/%06d", file_index);
    File f = SD.open(buf, FILE_APPEND);
    f.write(data, len);
    f.close();

    Serial.printf("[SD] Wrote %d bytes to file %s \n", len , buf);
} 
