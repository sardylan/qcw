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

#ifndef __QCW_MORSECODEC_ENCODER_H
#define __QCW_MORSECODEC_ENCODER_H

#include <QObject>
#include <QtCore/QTimer>

#define MORSE_ENCODER_TIMER_MILLIS_DEFAULT 200

class MorseEncoder : public QObject {
Q_OBJECT

public:
    explicit MorseEncoder(QObject *parent = 0);

    ~MorseEncoder();

    const QString &getText() const;

    void setText(const QString &text);

    int getSpeed() const;

    void setSpeed(int speed);

    void start();

    void stop();

private:

    QString text;
    int timerMillis;

    QTimer *timer;
    int position;
    int pulseLength;

    void initTimer();

    void updateTimerInterval();

private slots:

    void sendChar();

signals:

//    void newStatus(bool status);

    void newEvent(bool keyStatus);
};

#endif
