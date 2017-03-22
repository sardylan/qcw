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

#ifndef __QCW_SERIALHANDLER_H
#define __QCW_SERIALHANDLER_H

#include <QObject>
#include <QSerialPort>

class SerialHandler : public QObject {
Q_OBJECT

public:
    explicit SerialHandler(QObject *parent = 0);

    ~SerialHandler();

public slots:

    void start(QString portName, QSerialPort::BaudRate baudRate);

    void stop();

private:

    QSerialPort *serialPort;

private slots:

    void readData();

signals:

    void newStatus(bool status);

    void newEvent(bool keyStatus);

};

#endif
