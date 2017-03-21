#include <QDebug>
#include <QOpenGLWidget>

#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    helper = new Helper();
    glWidget = new GLWidget(helper, this);
    config = Config::getInstance();
    timer = new QTimer();

    signalConnect();
    initOpenGL();
    initTimer();
    initUi();
}

MainWindow::~MainWindow() {
    delete timer;
    delete ui;
}

void MainWindow::signalConnect() {
    connect(ui->actionFileExit, SIGNAL(triggered()), this, SLOT(applicationClose()));
    connect(ui->actionSetupConfig, SIGNAL(triggered()), this, SLOT(showConfigWindow()));
    connect(ui->actionSetupRun, SIGNAL(triggered()), this, SLOT(toogleSerialPort()));
}

void MainWindow::initOpenGL() {
    ui->stackedWidget->addWidget(glWidget);
}

void MainWindow::initTimer() {
    connect(timer, SIGNAL(timeout()), this, SLOT(animateOpenGL()));
}

void MainWindow::initUi() {
    toogleLamp(ui->keyStatus, false);
}

void MainWindow::newKeyStatus(bool status) {
    toogleLamp(ui->keyStatus, status);
}

void MainWindow::newSerialStatus(bool status) {
    ui->actionSetupRun->setChecked(status);

    if (status)
        showStatusBarMessage(QString("Serial port \"%1\" opened").arg(config->getPortName()));
    else
        showStatusBarMessage("Serial closed");
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
    if (ui->actionSetupRun->isChecked()) {
        ui->serialPortText->setText(config->getPortName());
        emit newActionRun(ui->actionSetupRun->isChecked());
    } else {
        ui->serialPortText->setText("");
        emit newActionRun(ui->actionSetupRun->isChecked());
    }
}

void MainWindow::animateOpenGL() {
}

void MainWindow::showStatusBarMessage(QString message) {
    ui->statusBar->showMessage(message, 5000);
}

void MainWindow::showConfigWindow() {
    emit actionConfig();
}
