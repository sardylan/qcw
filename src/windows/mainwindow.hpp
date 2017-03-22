#ifndef __QCW_WINDOWS_MAINWINDOW_H
#define __QCW_WINDOWS_MAINWINDOW_H

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

    void newKeyStatus(bool status);

    void newSerialStatus(bool status);

private:

    Ui::MainWindow *ui;

    GLWidget *glWidget;

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

signals:

    void newActionRun(bool);

    void actionConfig();
};

#endif
