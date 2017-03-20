#include "serialhandler.hpp"

SerialHandler::SerialHandler(QObject *parent) : QObject(parent) {
    serialPort = new QSerialPort();

    connect(serialPort, SIGNAL(readyRead()), this, SLOT(readData()));
}

SerialHandler::~SerialHandler() {
    delete (serialPort);
}

void SerialHandler::start(QString portName) {
    serialPort->setPortName(portName);
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    bool status = serialPort->open(QIODevice::ReadWrite);
    emit newStatus(status);
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
        case '.':
            emit newEvent(1);
            break;
        case '-':
            emit newEvent(2);
            break;
        default:
            emit newEvent(0);
    }
}