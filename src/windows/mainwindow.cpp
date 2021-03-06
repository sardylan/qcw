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
#include <encoder.hpp>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    glWidget = new GLWidget(this);
    statusBarWidgets = new StatusBarWidgets();

    status = Status::getInstance();
    config = Config::getInstance();

    signalConnect();
    initOpenGL();
    initUi();
    initStatusBar();
}

MainWindow::~MainWindow() {
    delete ui;
    delete statusBarWidgets;
    delete glWidget;
}

void MainWindow::signalConnect() {
    connect(ui->actionFileExit, SIGNAL(triggered()), this, SLOT(applicationClose()));
    connect(ui->actionSetupConfig, SIGNAL(triggered()), this, SLOT(showConfigWindow()));
    connect(ui->actionSetupRun, SIGNAL(triggered()), this, SLOT(toogleSerialPort()));
    connect(ui->actionHelpAbout, SIGNAL(triggered()), this, SLOT(showAboutWindow()));

    connect(ui->clearLineButton, SIGNAL(clicked()), this, SLOT(clearLine()));
    connect(ui->clearTextButton, SIGNAL(clicked()), this, SLOT(clearText()));

    connect(ui->timerIntervalSlider, SIGNAL(valueChanged(int)), this, SLOT(updateLineInterval(int)));

    connect(ui->encoderSpeedSlider, SIGNAL(valueChanged(int)), this, SLOT(updateEncoderSpeed(int)));

    connect(ui->playButton, SIGNAL(clicked()), this, SLOT(tooglePlayer()));
    connect(ui->morseText, SIGNAL(selectionChanged()), this, SLOT(emitNewSelectedText()));
}

void MainWindow::initOpenGL() {
    ui->stackedWidget->addWidget(glWidget);
}

void MainWindow::initUi() {
    toogleLamp(ui->keyStatus, false);

    ui->timerIntervalSlider->setMinimum(GLWIDGET_TIMER_MILLIS_MIN);
    ui->timerIntervalSlider->setMaximum(GLWIDGET_TIMER_MILLIS_MAX);
    ui->timerIntervalSlider->setValue(GLWIDGET_TIMER_MILLIS_DEFAULT);
    ui->timerIntervalSlider->setTickInterval((GLWIDGET_TIMER_MILLIS_MAX - GLWIDGET_TIMER_MILLIS_MIN) / 10);

    ui->encoderSpeedSlider->setMinimum(MORSE_ENCODER_TIMER_MILLIS_MIN);
    ui->encoderSpeedSlider->setMaximum(MORSE_ENCODER_TIMER_MILLIS_MAX);
    ui->encoderSpeedSlider->setValue(MORSE_ENCODER_TIMER_MILLIS_DEFAULT);
    ui->encoderSpeedSlider->setTickInterval((MORSE_ENCODER_TIMER_MILLIS_MAX - MORSE_ENCODER_TIMER_MILLIS_MIN) / 10);
}

void MainWindow::initStatusBar() {
    ui->statusBar->addPermanentWidget(statusBarWidgets->habSerial);
    ui->statusBar->addPermanentWidget(statusBarWidgets->time);
}

void MainWindow::newKeyStatus(bool status) {
    toogleLamp(ui->keyStatus, status);
    glWidget->setKeyStatus(status);
}

void MainWindow::newEncoderStatus(bool status) {
    ui->playButton->setChecked(status);
}

void MainWindow::newSerialStatus() {
    ui->actionSetupRun->setChecked(status->isSerialOpened());

    if (status->isSerialOpened())
        glWidget->start();
    else
        glWidget->stop();

    statusBarWidgets->updateFromConfig();
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

void MainWindow::updateLineInterval(int value) {
    glWidget->setTimerMillis(value);
}

void MainWindow::updateEncoderSpeed(int value) {
    emit newEncoderSpeed(value);
}

void MainWindow::emitNewSelectedText() {
    QString selectedText = ui->morseText->textCursor().selectedText();
    emit newSelectedText(selectedText);
}

void MainWindow::tooglePlayer() {
    emit newActionPlayer(ui->playButton->isChecked());
}