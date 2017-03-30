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
#include <QTimer>
#include <QQueue>
#include <QHash>

#define MORSE_ENCODER_TIMER_MILLIS_DEFAULT 90

class MorseEncoder : public QObject {
Q_OBJECT

public:
    explicit MorseEncoder(QObject *parent = 0);

    ~MorseEncoder();

public slots:

    void start();

    void stop();

    void setText(QString text);

    void setSpeed(int speed);

private:

    QTimer *timer;
    QString text;
    int timerMillis;
    int position;
    QQueue<bool> symbols;
    QHash<QChar, QList<int>> morseTable;

    void initTimer();

    void updateTimerInterval();

private slots:

    void sendSymbol();

signals:

    void newStatus(bool status);

    void newEvent(bool keyStatus);
};

#endif
