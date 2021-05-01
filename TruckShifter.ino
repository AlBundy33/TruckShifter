#include <Arduino.h>
#include <Joystick.h>

#define COMFORT_SHIFT 18
#define SPLITTER      19
#define RANGE         20

#define DEBOUNCE 50

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

unsigned long ms_cs = 0;
unsigned long ms_splitter = 0;
unsigned long ms_range = 0;

void loop() {
    int cs = !digitalRead(COMFORT_SHIFT);
    int splitter = !digitalRead(SPLITTER);
    int range = !digitalRead(RANGE);

    // debounce
    if (cs) {
        if (ms_cs == 0)
            ms_cs = millis();
        else if (ms_cs < DEBOUNCE)
            cs = LOW;
    }
    if (splitter) {
        if (ms_splitter == 0)
            ms_splitter = millis();
        else if (ms_splitter < DEBOUNCE)
            splitter = LOW;
    }
    if (range) {
        if (ms_range == 0)
            ms_range = millis();
        else if (ms_range < DEBOUNCE)
            range = LOW;
    }

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