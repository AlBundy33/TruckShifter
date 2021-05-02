#include <Arduino.h>
#include <Joystick.h>

#define COMFORT_SHIFT 18
#define SPLITTER      19
#define RANGE         20

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,
                   JOYSTICK_TYPE_JOYSTICK, 3, 0,
                   false, false, false, false, false, false,
                   false, false, false, false, false);

void setup() {
    pinMode(COMFORT_SHIFT, INPUT_PULLUP);
    pinMode(SPLITTER, INPUT_PULLUP);
    pinMode(RANGE, INPUT_PULLUP);
    Serial.begin(9600);
    Joystick.begin();
}

void loop() {
    int cs = !digitalRead(COMFORT_SHIFT);
    int splitter = !digitalRead(SPLITTER);
    int range = !digitalRead(RANGE);

    Joystick.setButton(0, cs);
    Joystick.setButton(1, splitter);
    Joystick.setButton(2, range);

    Serial.print(cs);
    Serial.print("\t");
    Serial.print(splitter);
    Serial.print("\t");
    Serial.print(range);
    Serial.println();
}
