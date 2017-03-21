#ifndef __QCW_QCW_H
#define __QCW_QCW_H

#include <QApplication>

#include <handler/serialhandler.hpp>
#include <windows/mainwindow.hpp>

#include <config/config.hpp>

#define APPLICATION_NAME "QCw"
#define APPLICATION_VERSION "0.0.1"

#define ORGANIZATION_NAME "The HellNet.org"
#define ORGANIZATION_DOMAIN "ham.thehellnet.org"

class QCw : public QApplication {
Q_OBJECT

public:

    explicit QCw(int &argc, char **argv);

    ~QCw();

    void prepare();

    int run();

public slots:

    void newActionRun(bool status);

    void showConfigWindow();

private:
    Config *config;
    SerialHandler *serialHandler;
    MainWindow *mainWindow;

};

#endif
