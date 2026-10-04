#include "vesc.h"

VescUart conn; // object that will recive all the values from vesc

void vesc_setup()
{
    Serial.println("[VESC] Initializing...");

#ifdef VESC_INVERT_TX_RX
    Serial1.begin(VESC_BAUD_RATE, SERIAL_8N1, TX, RX);
#else
    Serial1.begin(VESC_BAUD_RATE, SERIAL_8N1, RX, TX);
#endif
    conn.setSerialPort(&Serial1);

    Serial.println("[VESC] Serial initialized!");
}

void vesc_get_values(void (*callback)(VescUart::dataPackage))
{
    conn.getVescValues();
    callback(conn.data);
}
