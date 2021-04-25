#include <Arduino.h>

#define COMFORT_SHIFT PIN0
#define SPLITTER      PIN1
#define RANGE         PIN2

void setup() {
    pinMode(COMFORT_SHIFT, INPUT);
    pinMode(RANGE, INPUT);
    pinMode(SPLITTER, INPUT);
    Serial.begin(9600);
}

void loop() {
    Serial.print(digitalRead(COMFORT_SHIFT));
    Serial.print("\t");
    Serial.print(digitalRead(SPLITTER));
    Serial.print("\t");
    Serial.print(digitalRead(RANGE));
    Serial.println();
}