#ifndef __QCW_CONFIG_CONFIG_H
#define __QCW_CONFIG_CONFIG_H

#include <QtCore/QString>
#include <QtSerialPort/QSerialPort>

class Config {

private:
    Config();

    static Config *instance;

    QString portName;
    QSerialPort::BaudRate portSpeed;

public:
    static Config *getInstance();

    const QString &getPortName() const;

    void setPortName(const QString &portName);

    QSerialPort::BaudRate getPortSpeed() const;

    void setPortSpeed(QSerialPort::BaudRate portSpeed);

};

#endif
