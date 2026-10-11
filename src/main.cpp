

#include <Arduino.h>

#include "display.h"
#include "button.h"

#define BUTTON_PIN PD0

void blink();
void iterate();

void setup() {

    displayBegin();
    buttonBegin(BUTTON_PIN);

    displayClear();

}

void loop() {

    blink();

    iterate();

}

void blink() {

    while (1) {
        static bool frameFlag = false;

        ButtonEvent event = buttonTick();
        if (event == BUTTON_SHORT_PRESS) {
            return;
        }

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

void iterate() {

    int8_t row;
    int8_t col;

    while (1) {

        ButtonEvent event = buttonTick();
        if (event == BUTTON_SHORT_PRESS) {
            return;
        }
        
        static uint32_t pixelTimer = millis();
        if (millis() - pixelTimer >= 200) {
            pixelTimer = millis();

            displayClear();

            frameBuffer[row] = (1 << (7 - col));

            col++;

            if (col >= 8) {
                col = 0;
                row++;

                if (row >= 8) {
                    row = 0;
                }
            }
        }
        static uint32_t drawTimer = micros();
        if (micros() - drawTimer >= 200) {
            drawTimer = micros();
            displayUpdate();
        }
    }
    
}