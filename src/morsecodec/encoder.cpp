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

#include "encoder.hpp"

MorseEncoder::MorseEncoder(QObject *parent) : QObject(parent) {
    timer = new QTimer();
    text = "";
    timerMillis = MORSE_ENCODER_TIMER_MILLIS_DEFAULT;
    pulseLength = -1;

    initTimer();
    updateTimerInterval();
}

MorseEncoder::~MorseEncoder() {
    delete timer;
}

void MorseEncoder::initTimer() {
    connect(timer, SIGNAL(timeout()), this, SLOT(sendChar()));
    timer->setSingleShot(false);
}

const QString &MorseEncoder::getText() const {
    return text;
}

void MorseEncoder::setText(const QString &text) {
    MorseEncoder::text = text;
}

int MorseEncoder::getSpeed() const {
    return timerMillis;
}

void MorseEncoder::setSpeed(int speed) {
    MorseEncoder::timerMillis = speed;
    updateTimerInterval();
}

void MorseEncoder::updateTimerInterval() {
    timer->setInterval(timerMillis);
}

void MorseEncoder::start() {
    emit newEvent(false);
    timer->start();
}

void MorseEncoder::stop() {
    timer->stop();
    emit newEvent(false);
}

void MorseEncoder::sendChar() {
    pulseLength--;

    if (pulseLength < -1)
        pulseLength = -1;

    switch (pulseLength) {
        case 0:
            emit newEvent(false);
            break;
        case -1:
            pulseLength = 3;
            emit newEvent(true);
            break;
        default:
            emit newEvent(true);
    }
}