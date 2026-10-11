

#include <Arduino.h>

#include "display.h"

#define BUTTON_PIN PD0

void blink();

void setup() {

    displayBegin();

    blink();

}

void loop() {

}

void blink() {

    while (1) {
        static bool frameFlag = false;

        static uint32_t flagTimer = millis();
        if (millis() - flagTimer >= 1000) {
            flagTimer = millis();
            frameFlag = !frameFlag;
        }

        if (frameFlag) {
            frameBuffer[0] = 0b11111111;
        }
        else {
            frameBuffer[0] = 0b00000000;
        }
        
        static uint32_t updateTimer = micros();
        if (micros() - updateTimer >= 500) {
            updateTimer = micros();
            displayUpdate();
        }
    }
    

    
    
}