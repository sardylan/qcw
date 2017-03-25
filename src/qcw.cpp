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

#include <QDebug>
#include <config/manager.hpp>
#include <windows/configwindow.hpp>
#include <windows/aboutwindow.hpp>

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
    status = Status::getInstance();
    config = Config::getInstance();

    serialHandler = new SerialHandler();
    mainWindow = new MainWindow();
}

QCw::~QCw() {
    delete mainWindow;
    delete serialHandler;
}

void QCw::prepare() {
    ConfigManager::load();
    ConfigManager::save();

    connect(serialHandler, SIGNAL(newEvent(bool)), mainWindow, SLOT(newKeyStatus(bool)));

    connect(serialHandler, SIGNAL(newStatus(bool)), this, SLOT(newSerialStatus(bool)));

    connect(mainWindow, SIGNAL(newActionRun(bool)), this, SLOT(newActionRun(bool)));
    connect(mainWindow, SIGNAL(actionConfig()), this, SLOT(showConfigWindow()));
    connect(mainWindow, SIGNAL(actionAbout()), this, SLOT(showAboutWindow()));
}

int QCw::run() {
    mainWindow->show();

    return QApplication::exec();
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

void QCw::showAboutWindow() {
    AboutWindow aboutWindow;
    aboutWindow.exec();
}

void QCw::newSerialStatus(bool newStatus) {
    status->setSerialOpened(newStatus);
    mainWindow->newSerialStatus();
}