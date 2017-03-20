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

    void start(QString portName);

    void stop();

private:

    QSerialPort *serialPort;

private slots:

    void readData();

signals:

    void newStatus(bool status);

    void newEvent(int key);

};

#endif
