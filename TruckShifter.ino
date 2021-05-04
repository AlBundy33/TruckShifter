#include <Arduino.h>
#include <Joystick.h>

#define COMFORT_SHIFT 18
#define SPLITTER      19
#define RANGE         20

#define SHORT_PRESS 250

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,
                   JOYSTICK_TYPE_JOYSTICK, 4, 0,
                   false, false, false, false, false, false,
                   false, false, false, false, false);

unsigned long cs_press_time = 0L;

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
    unsigned long cs_pressed;

    if (cs == HIGH)
    {
      if (cs_press_time == 0L)
        cs_press_time = millis();
    }

    if (cs_press_time > 0)
      cs_pressed = millis() - cs_press_time;
    else
      cs_pressed = 0L;

    if (cs == LOW)
      cs_press_time = 0L;

    if (cs_pressed > SHORT_PRESS)
    {
      // long press
      Joystick.setButton(1, HIGH);
    }
    else if (cs == LOW && cs_pressed > 0 && cs_pressed <= SHORT_PRESS)
    {
      // short press
      Joystick.setButton(0, HIGH);
      delay(100);
    }

    if (cs == LOW)
    {
      // set both functions to LOW
      Joystick.setButton(0, LOW);
      Joystick.setButton(1, LOW);
    }

    Joystick.setButton(2, splitter);
    Joystick.setButton(3, range);

    Serial.print(cs);
    Serial.print("\t");
    Serial.print(splitter);
    Serial.print("\t");
    Serial.print(range);
    Serial.println();
}
