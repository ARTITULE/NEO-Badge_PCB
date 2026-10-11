
/*
// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
*/

#include <Arduino.h>

#define ROW_0 PC0
#define COLUMN_0 PD2

void setup() {
    pinMode(ROW_0, OUTPUT);
    pinMode(COLUMN_0, OUTPUT);
}

void loop() {
    digitalWrite(ROW_0, HIGH);
    digitalWrite(COLUMN_0, LOW);
    delay(250);

    digitalWrite(ROW_0, LOW);
    digitalWrite(COLUMN_0, HIGH);
    delay(250);
}