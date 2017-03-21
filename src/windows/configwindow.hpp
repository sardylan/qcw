#ifndef __QCW_CONFIGWINDOW_H
#define __QCW_CONFIGWINDOW_H

#include <QDialog>

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

    void signalConnect();

    void initUi();
};

#endif
