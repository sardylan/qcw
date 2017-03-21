#include "configwindow.hpp"
#include "ui_configwindow.h"

ConfigWindow::ConfigWindow(QWidget *parent) : QDialog(parent), ui(new Ui::ConfigWindow) {
    ui->setupUi(this);
    config = Config::getInstance();

    signalConnect();
    initUi();
    loadConfig();
}

ConfigWindow::~ConfigWindow() {
    delete ui;
}

void ConfigWindow::signalConnect() {

}

void ConfigWindow::initUi() {
    ui->serialPortCombo->clear();
}

void ConfigWindow::loadConfig() {

}
