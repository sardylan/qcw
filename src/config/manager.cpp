#include <QtCore/QSettings>

#include "manager.hpp"
#include "config.hpp"
#include "default.hpp"

void ConfigManager::load() {
    Config *config = Config::getInstance();
    QSettings settings;

    settings.beginGroup("serial");
    config->setPortName(settings.value("portName", CONFIG_PORTNAME_DEFAULT).toString());
    config->setPortSpeed(settings.value("portSpeed", CONFIG_PORTSPEED_DEFAULT).value<QSerialPort::BaudRate>());
    settings.endGroup();
}

void ConfigManager::save() {
    Config *config = Config::getInstance();
    QSettings settings;

    settings.beginGroup("serial");
    settings.setValue("portName", config->getPortName());
    settings.setValue("portSpeed", config->getPortSpeed());
    settings.endGroup();

    settings.sync();
}
