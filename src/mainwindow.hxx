#ifndef __QCW_MAINWINDOW_H
#define __QCW_MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>

#include "serialhandler.hxx"

QT_CHARTS_USE_NAMESPACE

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SerialHandler *serialHandler;

    QChart *chart;
    QChartView *chartView;

    void signalConnect();

    void initSerialHandler();

    void initChart();

    void initUi();

private slots:

    void applicationClose();

    void toogleLamp(QWidget *lamp, bool status);

    void toogleSerialPort();

    void newKeyStatus(int status);
};

#endif
