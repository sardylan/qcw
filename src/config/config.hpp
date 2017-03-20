#ifndef __QCW_CONFIG_CONFIG_H
#define __QCW_CONFIG_CONFIG_H

#include <QtCore/QString>

class Config {

public:
    static Config *getInstance();

    const QString &getPortName() const;

    void setPortName(const QString &portName);

private:
    Config();

    static Config *instance;

    QString portName;

};

#endif
