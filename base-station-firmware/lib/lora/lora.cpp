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
        Serial.println(F("[LORA] success!"));
    }
    else
    {
        Serial.print(F("[LORA] failed, code "));
        Serial.println(state);
        while (true)
            ;
    }

    // set the function that will be called
    // when new packet is received
    radio.setDio1Action(setFlag);

    radio.startReceive();

}

void radio_receive() {
     // check if the previous operation finished
    if (operationDone) {
        // reset flag
        operationDone = false;

        radio.startReceive();

        String str;
        int state = radio.readData(str);

        if (state == RADIOLIB_ERR_NONE) {


            // packet was successfully received
            Serial.println(F("[SX1262] Received packet!"));

            // print data of the packet
            Serial.print(F("[SX1262] Data:\t\t"));
            Serial.println(str);

            // print RSSI (Received Signal Strength Indicator)
            Serial.print(F("[SX1262] RSSI:\t\t"));
            Serial.print(radio.getRSSI());
            Serial.println(F(" dBm"));

            // print SNR (Signal-to-Noise Ratio)
            Serial.print(F("[SX1262] SNR:\t\t"));
            Serial.print(radio.getSNR());
            Serial.println(F(" dB"));

           
        }

    }
}