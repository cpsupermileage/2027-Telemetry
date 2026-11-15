#include "vesc.h"

VescUart conn; // object that will recive all the values from vesc

void vesc_setup()
{
    Serial.println(F("[VESC] Initializing..."));

    conn.setSerialPort(&Serial1);

#ifdef VESC_AUTO_TX_RX
    Serial.printf("[VESC] Automatically configuring serial... (max attempts: %d)\n", VESC_AUTO_MAX_ATTEMPTS);
    bool hasReceived = false;
    int attempt = 0;
    while (!hasReceived && attempt < VESC_AUTO_MAX_ATTEMPTS)
    {
        // Use the least significant bit (a & 0b01) to determine if its switched, and the next bit for if its inverses (a >> 1)
        Serial1.begin(VESC_BAUD_RATE, SERIAL_8N1, attempt & 0b01 ? TX : RX, attempt & 0b01 ? RX : TX, attempt >> 1);
        // Attempt to get fw version, timeouts after 100ms (defined by _TIMEOUT or in VescUart class constructor)
        hasReceived == conn.getFWversion();
        Serial.printf("[VESC] RX/TX attempt: %d switch: %d invert: %s success: %d \n", attempt, attempt & 0b01, attempt >> 1, hasReceived);
    }
    if (!hasReceived)
    {
        Serial.printf("[VESC] ERROR: Could not automatically determine serial configuration. Falling back to switch: %d invert: %d\n", VESC_SWITCH_TX_RX, VESC_INVERT_TX_RX);
        Serial1.begin(VESC_BAUD_RATE, SERIAL_8N1, VESC_SWITCH_TX_RX ? TX : RX, VESC_SWITCH_TX_RX ? RX : TX, VESC_INVERT_TX_RX);
    }
#else

    Serial1.begin(VESC_BAUD_RATE, SERIAL_8N1, VESC_SWITCH_TX_RX ? TX : RX, VESC_SWITCH_TX_RX ? RX : TX, VESC_INVERT_TX_RX);

#endif

    Serial.println(F("[VESC] Serial initialized!"));
    bool gotFWVersion = conn.getFWversion();
    if (gotFWVersion)
        Serial.printf("[VESC] Firmware Version: %d.%d\n", conn.fw_version.major, conn.fw_version.minor);
    else
        Serial.println(F("[VESC] ERROR: Could not receive firmware version\n"));
}

void vesc_get_values()
{
    conn.getVescValues();
}
