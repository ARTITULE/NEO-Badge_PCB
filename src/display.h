#pragma once
#include <Arduino.h>

extern const uint8_t rows[8];
extern const uint8_t cols[8];

extern uint8_t frameBuffer[8];

void displayBegin();
void displayClear();
void displayUpdate();