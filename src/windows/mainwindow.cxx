#include <QtCharts/QXYSeries>
#include <QtCharts/QScatterSeries>
#include "mainwindow.hxx"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    initSerialHandler();
    initChart();
    signalConnect();
    initUi();
}

MainWindow::~MainWindow() {
    delete serialHandler;
    delete ui;
}

void MainWindow::signalConnect() {
    connect(ui->actionFileExit, SIGNAL(triggered()), this, SLOT(applicationClose()));
    connect(ui->actionSetupRun, SIGNAL(triggered()), this, SLOT(toogleSerialPort()));
}

void MainWindow::applicationClose() {
    QApplication::quit();
}

void MainWindow::initSerialHandler() {
    serialHandler = new SerialHandler();
    connect(serialHandler, SIGNAL(newEvent(int)), this, SLOT(newKeyStatus(int)));
}

void MainWindow::initChart() {
}

void MainWindow::initUi() {
    toogleLamp(ui->dotLabel, false);
    toogleLamp(ui->dashLabel, false);
}

void MainWindow::toogleLamp(QWidget *lamp, bool status) {
    QString style = "background-color: rgba(255, 0, 0, 0); color: rgba(255, 0, 0, 0);";

    if (status)
        style = "background-color: rgba(255, 0, 0, 255); color: rgba(255, 0, 0, 0);";

    lamp->setStyleSheet(style);
}

void MainWindow::toogleSerialPort() {
    QString serialPortName = "/dev/ttyACM0";

    if (ui->actionSetupRun->isChecked()) {
        ui->serialPortText->setText(serialPortName);
        serialHandler->start(serialPortName);
    } else {
        ui->serialPortText->setText("");
        serialHandler->stop();
    }
}

void MainWindow::newKeyStatus(int status) {
    switch (status) {
        case 1:
            toogleLamp(ui->dotLabel, true);
            break;
        case 2:
            toogleLamp(ui->dashLabel, true);
            break;
        default:
            toogleLamp(ui->dotLabel, false);
            toogleLamp(ui->dashLabel, false);
    }
}
