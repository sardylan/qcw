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
#include "table.hpp"

MorseEncoder::MorseEncoder(QObject *parent) :
        QObject(parent),
        morseTable(initMorseTable()) {
    timer = new QTimer();
    text = "";
    timerMillis = MORSE_ENCODER_TIMER_MILLIS_DEFAULT;
    symbols.clear();

    initTimer();
    updateTimerInterval();
}

MorseEncoder::~MorseEncoder() {
    delete timer;
}

void MorseEncoder::initTimer() {
    connect(timer, SIGNAL(timeout()), this, SLOT(sendSymbol()));
    timer->setSingleShot(false);
}

void MorseEncoder::setText(QString text) {
    MorseEncoder::text = text;
    position = 0;
}

void MorseEncoder::setSpeed(int speed) {
    if (speed >= MORSE_ENCODER_TIMER_MILLIS_MIN && speed <= MORSE_ENCODER_TIMER_MILLIS_MAX)
        MorseEncoder::timerMillis = speed;

    updateTimerInterval();
}

void MorseEncoder::updateTimerInterval() {
    timer->setInterval(MORSE_ENCODER_TIMER_MILLIS_MAX - (timerMillis - MORSE_ENCODER_TIMER_MILLIS_MIN));
}

void MorseEncoder::start() {
    emit newStatus(true);
    emit newEvent(false);
    timer->start();
}

void MorseEncoder::stop() {
    timer->stop();
    position = 0;
    emit newEvent(false);
    emit newStatus(false);
}

void MorseEncoder::sendSymbol() {
    if (symbols.isEmpty()) {
        if (position == text.length()) {
            stop();
            return;
        }

        QChar c = text.at(position).toUpper();
        position++;

        if (c == ' ') {
            symbols.enqueue(false);
            symbols.enqueue(false);
            symbols.enqueue(false);
            symbols.enqueue(false);
        } else {
            QList<int> symbs = morseTable.value(c);

            QList<int>::iterator iterator;
            for (iterator = symbs.begin(); iterator != symbs.end(); ++iterator) {
                int size = *iterator;

                switch (size) {
                    case DOT:
                        symbols.enqueue(true);
                        break;
                    case DASH:
                        symbols.enqueue(true);
                        symbols.enqueue(true);
                        symbols.enqueue(true);
                        break;
                    default:
                        break;
                }

                symbols.enqueue(false);
            }

            symbols.enqueue(false);
            symbols.enqueue(false);
        }
    }

    emit newEvent(symbols.dequeue());
}