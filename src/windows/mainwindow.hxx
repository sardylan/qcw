#ifndef __QCW_MAINWINDOW_H
#define __QCW_MAINWINDOW_H

#include <QMainWindow>

#include "serialhandler.hxx"

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
