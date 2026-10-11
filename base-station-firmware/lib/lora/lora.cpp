// Based off https://github.com/radiolib-org/RadioBoards/blob/main/examples/RadioLib_Simple/RadioLib_Simple.ino
#include <lora.h>

// create a new RadioLib module
// "Radio" will be set to the correct module type,
// and "RadioModule" will have the correct pins
SX1262 radio = new Module(RADIO_CS_PIN, RADIO_DIO1_PIN, RADIO_RST_PIN, RADIO_BUSY_PIN);

#define SMV_SYNC_WORD 0xB4

void radio_setup()
{
    // initialize the radio
    Serial.print(F("[LORA] Initializing ... "));
    SPI.begin(RADIO_SCLK_PIN, RADIO_MISO_PIN, RADIO_MOSI_PIN);
    // Values based on Long Fast from https://meshtastic.org/docs/overview/radio-settings/
    int state = radio.begin(915.0F, 250.0F, 11U, 5U, SYNC_WORD, 22);
    if (state == RADIOLIB_ERR_NONE)
    {
        Serial.println(F("[LORA] success!"));
    }
    else
    {
        Serial.print(F("[LORA] failed, code "));
        Serial.println(state);
        while (true)
            ;
    }
}
