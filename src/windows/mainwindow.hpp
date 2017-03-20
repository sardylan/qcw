#ifndef __QCW_MAINWINDOW_H
#define __QCW_MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include <config.hpp>
#include <glwidget.hpp>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:

    void newKeyStatus(int status);

    void newSerialStatus(bool status);

private:

    Ui::MainWindow *ui;

    Helper *helper;
    GLWidget *glWidget;

    Config *config;
    QTimer *timer;

    void signalConnect();

    void initOpenGL();

    void initTimer();

    void initUi();

    void showStatusBarMessage(QString message);

private slots:

    void applicationClose();

    void toogleLamp(QWidget *lamp, bool status);

    void toogleSerialPort();

    void animateOpenGL();

signals:

    void newActionRun(bool);
};

#endif
