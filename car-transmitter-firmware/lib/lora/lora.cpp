// Based off https://github.com/radiolib-org/RadioBoards/blob/main/examples/RadioLib_Simple/RadioLib_Simple.ino
#include <lora.h>

// create a new RadioLib module
// "Radio" will be set to the correct module type,
// and "RadioModule" will have the correct pins
SX1262 radio = new Module(RADIO_CS_PIN, RADIO_DIO1_PIN, RADIO_RST_PIN, RADIO_BUSY_PIN);

#define SMV_SYNC_WORD 0xB4

// save transmission states between loops
int transmissionState = RADIOLIB_ERR_NONE;

// flag to indicate that a packet was sent or received
volatile bool operationDone = false;

void setFlag(void)
{
    // we sent or received a packet, set the flag
    operationDone = true;
}

void radio_setup()
{
    // initialize the radio
    Serial.print(F("[LORA] Initializing ... "));
    SPI.begin(RADIO_SCLK_PIN, RADIO_MISO_PIN, RADIO_MOSI_PIN);
    // Values based on Long Fast from https://meshtastic.org/docs/overview/radio-settings/
    int state = radio.begin(915.0F, 250.0F, 11U, 5U, SYNC_WORD, 22);
    if (state == RADIOLIB_ERR_NONE)
    {
        Serial.println(F("success!"));
    }
    else
    {
        Serial.print(F("failed, code "));
        Serial.println(state);
        while (true)
            ;
    }
}

// Blocking
void radio_send(data_packet *data)
{

    Serial.print(F("[LORA] transmitting... "));

    int state = radio.transmit((uint8_t *)data, sizeof(*data), 0);

    if (state == RADIOLIB_ERR_NONE)
    {
        // the packet was successfully transmitted
        Serial.println(F("success!"));
    }
    else if (state == RADIOLIB_ERR_PACKET_TOO_LONG)
    {
        // the supplied packet was longer than 256 bytes
        Serial.println(F("too long!"));
    }
    else if (state == RADIOLIB_ERR_TX_TIMEOUT)
    {
        // timeout occured while transmitting packet
        Serial.println(F("timeout!"));
    }
    else
    {
        // some other error occurred
        Serial.print(F("failed, code "));
        Serial.println(state);
    }
}