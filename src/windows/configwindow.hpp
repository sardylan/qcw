#ifndef __QCW_WINDOWS_CONFIGWINDOW_H
#define __QCW_WINDOWS_CONFIGWINDOW_H

#include <QDialog>

#include <config.hpp>

namespace Ui {
    class ConfigWindow;
}

class ConfigWindow : public QDialog {
Q_OBJECT

public:
    explicit ConfigWindow(QWidget *parent = 0);

    ~ConfigWindow();

private:
    Ui::ConfigWindow *ui;
    Config *config;

    void signalConnect();

    void initUi();

    void load();

    void save();

private slots:

    void handleOK();

    void handleApply();

    void handleClose();

    void handleReset();
};

#endif
