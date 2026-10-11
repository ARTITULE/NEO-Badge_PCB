#include "display.h"

const uint8_t rows[8] = {
    PC0, PC1, PC2, PC3,
    PC4, PC5, PC6, PC7
};

const uint8_t cols[8] = {
    PD2, PD3, PD4, PD5,
    PD6, PD7, PA1, PA2
};

static uint8_t currentRow = 0;

uint8_t frameBuffer[8] = {0};

void displayBegin() {

    for (int8_t i = 0; i < 8; i++) {
        pinMode(rows[i], OUTPUT);
        pinMode(cols[i], OUTPUT);

        digitalWrite(rows[i], LOW);
        digitalWrite(cols[i], HIGH);
    }

}

void displayClear() {

    for (int8_t i = 0; i < 8; i++) {
        frameBuffer[i] = 0;
    }

}

void displayUpdate() {

    digitalWrite(rows[currentRow], LOW);

    currentRow ++;

    if (currentRow >= 8) {
        currentRow = 0;
    }

    uint8_t rowData = frameBuffer[currentRow];

    for (int col = 0; col < 8; col++) {
        if (rowData & (1 << (7 - col))) {
            digitalWrite(cols[col], LOW);
        }
        else {
            digitalWrite(cols[col], HIGH);
        }
    }

    digitalWrite(rows[currentRow], HIGH);

}