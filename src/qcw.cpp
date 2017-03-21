#include <QDebug>
#include <config/manager.hpp>
#include <windows/configwindow.hpp>

#include "qcw.hpp"

int main(int argc, char *argv[]) {
    QCoreApplication::setApplicationName(APPLICATION_NAME);
    QCoreApplication::setApplicationVersion(APPLICATION_VERSION);
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);

    QCw qCw(argc, argv);
    qCw.prepare();
    return qCw.run();
}

QCw::QCw(int &argc, char **argv) : QApplication(argc, argv) {
    config = Config::getInstance();
    serialHandler = new SerialHandler();
    mainWindow = new MainWindow();
}

QCw::~QCw() {
    delete mainWindow;
    delete serialHandler;
    delete config;
}

void QCw::prepare() {
    ConfigManager::load();
    ConfigManager::save();

    connect(serialHandler, SIGNAL(newStatus(bool)), mainWindow, SLOT(newSerialStatus(bool)));
    connect(serialHandler, SIGNAL(newEvent(bool)), mainWindow, SLOT(newKeyStatus(bool)));

    connect(mainWindow, SIGNAL(newActionRun(bool)), this, SLOT(newActionRun(bool)));
    connect(mainWindow, SIGNAL(actionConfig()), this, SLOT(showConfigWindow()));
}

int QCw::run() {
    mainWindow->show();

    return exec();
}

void QCw::newActionRun(bool status) {
    if (status)
        serialHandler->start(config->getPortName(), config->getPortSpeed());
    else
        serialHandler->stop();
}

void QCw::showConfigWindow() {
    ConfigWindow configWindow;

    configWindow.exec();
}