#include "oled.h" 

SSD1306Wire display(0x3c, I2C_SDA, I2C_SCL);

void oled_setup() {
    Serial.println(F("[OLED] Initializing ... "));
// Initialising the UI will init the display too.
    display.init();

    display.flipScreenVertically();

    display.drawString(16, 16, "hello world");
    display.display();
}