#include "config.hpp"

Config *Config::instance = nullptr;

Config *Config::getInstance() {
    if (instance == 0)
        instance = new Config();

    return instance;
}

Config::Config() {
    portName = "/dev/ttyACM0";
}

const QString &Config::getPortName() const {
    return portName;
}

void Config::setPortName(const QString &portName) {
    Config::portName = portName;
}
