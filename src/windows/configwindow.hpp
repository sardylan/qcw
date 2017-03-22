/*
 * qCw
 * Copyright (C) 2017  Luca Cireddu
 * sardylan@gmail.com
 * http://www.lucacireddu.it
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

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
