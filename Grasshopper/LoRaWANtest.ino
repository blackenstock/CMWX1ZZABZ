#include "LoRaWAN.h"

const char *appEui = "70B3D57ED00093FB";
const char *appKey = "D3FC12149485EA7B9A4D8F5B6484830E";
const char *devEui = "0101010101010101";

void setup( void )
{
    LoRaWAN.begin(REGION_US915); // for US, select appropriate region
    LoRaWAN.setSubBand(2); // for TTN

    LoRaWAN.joinOTAA(appEui, appKey, devEui);
}

void loop( void )
{
    delay(10000);

    if (LoRaWAN.connected())
    {
        LoRaWAN.beginPacket(3);
        LoRaWAN.write(0xef);
        LoRaWAN.write(0xbe);
        LoRaWAN.write(0xad);
        LoRaWAN.write(0xde);
        LoRaWAN.endPacket();
    }
}
