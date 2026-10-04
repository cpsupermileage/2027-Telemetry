// Based off https://github.com/radiolib-org/RadioBoards/blob/main/examples/RadioLib_Simple/RadioLib_Simple.ino

// include RadioLib
#include <RadioLib.h>

// automatically detect which board is being used
#define RADIO_BOARD_AUTO

// now include RadioBoards
// this must be included AFTER RadioLib!
#include <RadioBoards.h>

// create a new RadioLib module
// "Radio" will be set to the correct module type,
// and "RadioModule" will have the correct pins
Radio radio = new RadioModule();

#define SMV_SYNC_WORD 0xB4

void radio_setup()
{
    // initialize the radio
    Serial.print(F("[Radio] Initializing ... "));
    // Values based on Long Fast from https://meshtastic.org/docs/overview/radio-settings/
    int state = radio.begin(915.0F, 250.0F, 11U, 5U, SMV_SYNC_WORD, 22);
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
