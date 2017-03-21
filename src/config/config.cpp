#include "config.hpp"
#include "default.hpp"

Config *Config::instance = nullptr;

Config *Config::getInstance() {
    if (instance == 0)
        instance = new Config();

    return instance;
}

Config::Config() {
    portName = CONFIG_PORTNAME_DEFAULT;
    portSpeed = CONFIG_PORTSPEED_DEFAULT;
}

const QString &Config::getPortName() const {
    return portName;
}

void Config::setPortName(const QString &portName) {
    Config::portName = portName;
}

QSerialPort::BaudRate Config::getPortSpeed() const {
    return portSpeed;
}

void Config::setPortSpeed(QSerialPort::BaudRate portSpeed) {
    Config::portSpeed = portSpeed;
}
