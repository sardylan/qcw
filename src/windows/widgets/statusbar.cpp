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

#include <QDateTime>

#include "statusbar.hpp"

StatusBarWidgets::StatusBarWidgets(QObject *parent) : QObject(parent) {
    status = Status::getInstance();
    config = Config::getInstance();

    time = new QLabel();
    initLabelStyle(time);
    initTime();

    habSerial = new QLabel();
    initLabelStyle(habSerial);
    initHabSerial();

    timeTimer = new QTimer();
    initTimeTimer();

    updateFromConfig();
}

StatusBarWidgets::~StatusBarWidgets() {
    delete time;
}

void StatusBarWidgets::initLabelStyle(QLabel *label) {
    label->setFrameShape(QFrame::StyledPanel);
//    label->setFrameShadow(QFrame::Sunken);
    label->setAlignment(Qt::AlignCenter);
    label->setMinimumWidth(50);
    label->setStyleSheet("padding-left: 3px; padding-right: 3px;");
}

void StatusBarWidgets::initTime() {
    time->setText("time");
}

void StatusBarWidgets::initHabSerial() {
    habSerial->setText("habSerial");
}

void StatusBarWidgets::initTimeTimer() {
    timeTimer->setInterval(1000);
    timeTimer->setSingleShot(false);
    timeTimer->setTimerType(Qt::VeryCoarseTimer);
    timeTimer->start();
    connect(timeTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
    updateTime();
}

void StatusBarWidgets::updateTime() {
    time->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
}

void StatusBarWidgets::updateFromConfig() {
    QString text;

    text = QString("<strong>Arduino:</strong> %1 %2 %3")
            .arg(config->getPortName())
            .arg(config->getPortSpeed())
            .arg(serialPortParams(QSerialPort::Data8, QSerialPort::NoParity, QSerialPort::OneStop));
    habSerial->setText(text);
    habSerial->setEnabled(status->isSerialOpened());
}

QString StatusBarWidgets::serialPortParams(QSerialPort::DataBits dataBits, QSerialPort::Parity parity,
                                           QSerialPort::StopBits stopBits) {
    QString dataBitsString;
    QString parityString;
    QString stopBitsString;

    switch (dataBits) {
        case QSerialPort::Data5:
            dataBitsString = "5";
            break;
        case QSerialPort::Data6:
            dataBitsString = "6";
            break;
        case QSerialPort::Data7:
            dataBitsString = "7";
            break;
        case QSerialPort::Data8:
            dataBitsString = "8";
            break;
        default:
            dataBitsString = "#";
    }

    switch (parity) {
        case QSerialPort::NoParity:
            parityString = "N";
            break;
        case QSerialPort::OddParity:
            parityString = "O";
            break;
        case QSerialPort::EvenParity:
            parityString = "E";
            break;
        case QSerialPort::SpaceParity:
            parityString = "S";
            break;
        case QSerialPort::MarkParity:
            parityString = "M";
            break;
        default:
            dataBitsString = "#";
    }

    switch (stopBits) {
        case QSerialPort::OneStop:
            stopBitsString = "1";
            break;
        case QSerialPort::OneAndHalfStop:
            stopBitsString = "1.5";
            break;
        case QSerialPort::TwoStop:
            stopBitsString = "2";
            break;
        default:
            dataBitsString = "#";
    }

    return QString("%1-%2-%3")
            .arg(dataBitsString)
            .arg(parityString)
            .arg(stopBits);
}
