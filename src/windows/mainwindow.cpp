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
#include <QOpenGLWidget>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    glWidget = new GLWidget(this);
    config = Config::getInstance();

    signalConnect();
    initOpenGL();
    initUi();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::signalConnect() {
    connect(ui->actionFileExit, SIGNAL(triggered()), this, SLOT(applicationClose()));
    connect(ui->actionSetupConfig, SIGNAL(triggered()), this, SLOT(showConfigWindow()));
    connect(ui->actionSetupRun, SIGNAL(triggered()), this, SLOT(toogleSerialPort()));
    connect(ui->actionHelpAbout, SIGNAL(triggered()), this, SLOT(showAboutWindow()));

    connect(ui->clearLineButton, SIGNAL(clicked()), this, SLOT(clearLine()));
    connect(ui->clearTextButton, SIGNAL(clicked()), this, SLOT(clearText()));
}

void MainWindow::initOpenGL() {
    ui->stackedWidget->addWidget(glWidget);
}

void MainWindow::initUi() {
    toogleLamp(ui->keyStatus, false);
}

void MainWindow::newKeyStatus(bool status) {
    toogleLamp(ui->keyStatus, status);

    ui->morseText->moveCursor(QTextCursor::End);
    ui->morseText->insertPlainText(status ? "#" : "-");
    ui->morseText->moveCursor(QTextCursor::End);

    glWidget->setKeyStatus(status);
}

void MainWindow::newSerialStatus(bool status) {
    ui->actionSetupRun->setChecked(status);

    if (status) {
        showStatusBarMessage(QString("Serial port \"%1\" opened").arg(config->getPortName()));
        glWidget->start();
    } else {
        showStatusBarMessage("Serial closed");
        glWidget->stop();
    }

    ui->actionSetupConfig->setEnabled(!status);
}

void MainWindow::applicationClose() {
    QApplication::quit();
}

void MainWindow::toogleLamp(QWidget *lamp, bool status) {
    QString style = "background-color: rgba(255, 0, 0, 0); color: rgba(255, 0, 0, 0);";

    if (status)
        style = "background-color: rgba(255, 0, 0, 255); color: rgba(255, 0, 0, 0);";

    lamp->setStyleSheet(style);
}

void MainWindow::toogleSerialPort() {
    emit newActionRun(ui->actionSetupRun->isChecked());
}

void MainWindow::showStatusBarMessage(QString message) {
    ui->statusBar->showMessage(message, 5000);
}

void MainWindow::showConfigWindow() {
    emit actionConfig();
}

void MainWindow::showAboutWindow() {
    emit actionAbout();
}

void MainWindow::clearLine() {
    glWidget->clear();
}

void MainWindow::clearText() {
    ui->morseText->clear();
}