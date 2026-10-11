#include <Arduino.h>

extern "C" {
#include "ch32v00x_flash.h"
}

void setup() {
    FLASH_Unlock();

    FLASH_EraseOptionBytes();

    FLASH_UserOptionByteConfig(
        OB_IWDG_SW,
        OB_STOP_NoRST,
        OB_STDBY_NoRST,
        OB_RST_NoEN
    );

    FLASH_Lock();
}

void loop() {
}