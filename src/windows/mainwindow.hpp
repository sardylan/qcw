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

#ifndef __QCW_WINDOWS_MAINWINDOW_H
#define __QCW_WINDOWS_MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <glwidget.hpp>
#include <config.hpp>
#include <status.hpp>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:

    void newSerialStatus();

    void newKeyStatus(bool status);

private:

    Ui::MainWindow *ui;

    GLWidget *glWidget;

    Status *status;

    Config *config;

    void signalConnect();

    void initOpenGL();

    void initUi();

    void showStatusBarMessage(QString message);

private slots:

    void applicationClose();

    void toogleLamp(QWidget *lamp, bool status);

    void toogleSerialPort();

    void showConfigWindow();

    void showAboutWindow();

    void clearLine();

    void clearText();

signals:

    void newActionRun(bool);

    void actionConfig();

    void actionAbout();
};

#endif
