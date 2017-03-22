/*
 * qCw
 * Copyright (C) 2017  Luca Cireddu
 * sardylan@gmail.com
 * http://www.lucacireddu.it
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#define PIN_LED_GENERIC 13
#define PIN_LED_DOT 6
#define PIN_LED_DASH 5

#define PIN_OUTPUT_SOUND 7

#define PIN_TONE 0
#define PIN_SPEED 4

#define PIN_KEY_DOT 3
#define PIN_KEY_DASH 4
#define PIN_KEY_MANUAL 2

#define WAIT_SOUND_MIN 150
#define WAIT_SOUND_MAX 1000

#define WAIT_PULSE_MIN 40
#define WAIT_PULSE_MAX 150

#define KEY_CHAR_ON "#"
#define KEY_CHAR_OFF "#"

bool sound = false;
bool dir = false;

bool lastKeyStatus = false;

unsigned long inTimer = 0;
bool inDot = false;
bool inDash = false;
bool inWait = false;

void setup() {
    pinMode(PIN_LED_GENERIC, OUTPUT);
    pinMode(PIN_LED_DOT, OUTPUT);
    pinMode(PIN_LED_DASH, OUTPUT);

    pinMode(PIN_OUTPUT_SOUND, OUTPUT);

    pinMode(PIN_KEY_DOT, INPUT);
    pinMode(PIN_KEY_DASH, INPUT);
    pinMode(PIN_KEY_MANUAL, INPUT);

    digitalWrite(PIN_LED_GENERIC, LOW);
    digitalWrite(PIN_LED_DOT, LOW);
    digitalWrite(PIN_LED_DASH, LOW);

    Serial.begin(115200, SERIAL_8N1);
}

void loop() {
    bool pinKeyDot = digitalRead(PIN_KEY_DOT);
    bool pinKeyDash = digitalRead(PIN_KEY_DASH);
    bool pinKeyManual = digitalRead(PIN_KEY_MANUAL);

    if (pinKeyDot || pinKeyDash || pinKeyManual) {
        if (pinKeyManual) {
            ledDot(true);
            ledDash(true);
            sound = true;
        } else {
            ledDot(pinKeyDot);
            ledDash(pinKeyDash);
        }
    } else {
        ledDot(false);
        ledDash(false);
        sound = false;
    }

    pulse(pinKeyDot, pinKeyDash);

    doSound();
    ledGeneric(sound);
    serial(sound);
}

void ledGeneric(bool enable) {
    digitalWrite(PIN_LED_GENERIC, enable);
}

void ledDot(bool enable) {
    digitalWrite(PIN_LED_DOT, enable);
}

void ledDash(bool enable) {
    digitalWrite(PIN_LED_DASH, enable);
}

void pulse(bool dot, bool dash) {
    int wait = WAIT_PULSE_MIN + (int) ((WAIT_PULSE_MAX - WAIT_PULSE_MIN) * ((float) analogRead(PIN_SPEED) / 1024));

    if (inDot || inDash || inWait) {
        sound = inDot || inDash;

        if (inWait) {
            sound = false;

            if (millis() - inTimer > wait) {
                inTimer = millis();
                inWait = false;
            }
        } else if ((millis() - inTimer) > (inDash ? wait : wait * 3)) {
            inTimer = millis();
            sound = false;
            inDot = false;
            inDash = false;
            inWait = true;
        }
    } else if (dot || dash) {
        inTimer = millis();
        sound = true;

        if (dash)
            inDash = true;
        else
            inDot = true;
    }
}

void doSound() {
    int wait = WAIT_SOUND_MIN + (int) ((WAIT_SOUND_MAX - WAIT_SOUND_MIN) * ((float) analogRead(PIN_TONE) / 1024));

    if (!dir) {
        dir = true;
        digitalWrite(PIN_OUTPUT_SOUND, sound);
    } else {
        dir = false;
        digitalWrite(PIN_OUTPUT_SOUND, LOW);
    }

    delayMicroseconds(wait);
}

void serial(bool keyStatus) {
    if (keyStatus == lastKeyStatus)
        return;

    lastKeyStatus = keyStatus;

    if (lastKeyStatus)
        Serial.write(KEY_CHAR_ON);
    else
        Serial.write(KEY_CHAR_OFF);
}
