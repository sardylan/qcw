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

#ifndef __QCW_QCW_H
#define __QCW_QCW_H

#include <QApplication>

#include <handler/serialhandler.hpp>
#include <windows/mainwindow.hpp>

#include <config/config.hpp>
#include <config/status.hpp>
#include <morsecodec/encoder.hpp>

#define APPLICATION_NAME "qCw"
#define APPLICATION_VERSION "0.99.2"

#define ORGANIZATION_NAME "The HellNet.org"
#define ORGANIZATION_DOMAIN "thehellnet.org"

class QCw : public QApplication {
Q_OBJECT

public:

    explicit QCw(int &argc, char **argv);

    ~QCw();

    void prepare();

    int run();

private:
    Status *status;
    Config *config;
    SerialHandler *serialHandler;
    MainWindow *mainWindow;
    MorseEncoder *morseEncoder;

private slots:

    void newActionRun(bool status);

    void showConfigWindow();

    void showAboutWindow();

    void newSerialStatus(bool newStatus);
};

#endif
