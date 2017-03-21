#include "serialhandler.hpp"

SerialHandler::SerialHandler(QObject *parent) : QObject(parent) {
    serialPort = new QSerialPort();

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
    serialPort->read(&c, 1);

    switch (c) {
        case '#':
            emit newEvent(true);
            break;
        default:
            emit newEvent(false);
    }
}