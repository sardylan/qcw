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

#include "serialhandler.hpp"

SerialHandler::SerialHandler(QObject *parent) : QObject(parent) {
    serialPort = new QSerialPort();
    lastStatus = false;

    connect(serialPort, SIGNAL(readyRead()), this, SLOT(readData()));
}

SerialHandler::~SerialHandler() {
    delete (serialPort);
}

void SerialHandler::start(QString portName, QSerialPort::BaudRate baudRate) {
    serialPort->setPortName(portName);
    serialPort->setBaudRate(baudRate);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (serialPort->open(QIODevice::ReadWrite))
            emit newStatus(true);
}

void SerialHandler::stop() {
    if (serialPort->isOpen())
        serialPort->close();

    emit newStatus(false);
}

void SerialHandler::readData() {
    char c;

    while (serialPort->bytesAvailable() > 0) {
        serialPort->read(&c, 1);

        switch (c) {
            case '#':
                emitNewStatus(true);
                break;

            default:
                emitNewStatus(false);
        }
    }
}

void SerialHandler::emitNewStatus(bool newStatus) {
    if (newStatus == lastStatus)
        return;

    lastStatus = newStatus;
    emit newEvent(newStatus);
}

void SerialHandler::writeData(bool keyStatus) {
    if (!serialPort->isOpen()) {
        return;
    }

    if (keyStatus == lastStatus)
        return;

    lastStatus = keyStatus;

    QByteArray byteArray;
    if (keyStatus)
        byteArray.append('#');
    else
        byteArray.append(' ');

    serialPort->write(byteArray);
    serialPort->flush();
}