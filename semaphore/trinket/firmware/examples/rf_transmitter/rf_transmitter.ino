#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

void setup()
{
    Serial.begin(115200);
    if (!driver.init())
         Serial.println("Initialization failed");
}

void loop()
{
    const char *msg = "Hello World!!";
    driver.send((uint8_t *)msg, strlen(msg) + 1);
    driver.waitPacketSent();
    delay(1000);
}
