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
    connect(ui->actionRunOpen, SIGNAL(triggered()), this, SLOT(toogleSerialPort()));
}

void MainWindow::applicationClose() {
    QApplication::quit();
}

void MainWindow::initSerialHandler() {
    serialHandler = new SerialHandler();
    connect(serialHandler, SIGNAL(newEvent(int)), this, SLOT(newKeyStatus(int)));
}

void MainWindow::initChart() {
    chart = new QChart();
    chart->legend()->hide();
    chart->setTitle("OpenGL Accelerated Series");
    chart->setMaximumHeight(20);

    const int pointCount = 10000;

    QList<QXYSeries *> seriesList;

    QXYSeries *series = new QScatterSeries();
    QScatterSeries *scatter = static_cast<QScatterSeries *>(series);
    scatter->setColor(QColor("black"));
    scatter->setMarkerSize(1);
    seriesList.append(series);
    series->setUseOpenGL(true);
    chart->addSeries(series);
}

void MainWindow::initUi() {
    chartView = new QChartView(chart);
    chartView->setFixedHeight(30);
    ui->dataLayout->addWidget(chartView, 1, 3, Qt::AlignTop);
    toogleLamp(ui->dotLamp, false);
    toogleLamp(ui->dashLamp, false);
}

void MainWindow::toogleLamp(QWidget *lamp, bool status) {
    QString style = "background-color: rgba(255, 0, 0, 0); color: rgba(255, 0, 0, 0);";

    if (status)
        style = "background-color: rgba(255, 0, 0, 255); color: rgba(255, 0, 0, 0);";

    lamp->setStyleSheet(style);
}

void MainWindow::toogleSerialPort() {
    if (ui->actionRunOpen->isChecked()) {
        serialHandler->start(ui->serialCombo->currentText());
    } else {
        serialHandler->stop();
    }
}

void MainWindow::newKeyStatus(int status) {
    switch (status) {
        case 1:
            toogleLamp(ui->dotLamp, true);
            break;
        case 2:
            toogleLamp(ui->dashLamp, true);
            break;
        default:
            toogleLamp(ui->dotLamp, false);
            toogleLamp(ui->dashLamp, false);
    }
}
