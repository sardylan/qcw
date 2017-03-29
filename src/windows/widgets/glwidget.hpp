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

#ifndef __QCW_WINDOWS_WIDGETS_GLWIDGET_H
#define __QCW_WINDOWS_WIDGETS_GLWIDGET_H

#include <QOpenGLWidget>
#include <QTimer>

#define GLWIDGET_TIMER_MILLIS_DEFAULT 10
#define GLWIDGET_TICK_INTERVAL_SMALL 25
#define GLWIDGET_TICK_INTERVAL_BIG 4

class GLWidget : public QOpenGLWidget {
Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);

    ~GLWidget();

    void setKeyStatus(bool keyStatus);

    int getTimerMillis() const;

    void setTimerMillis(int timerMillis);

public slots:

    void start();

    void stop();

    void clear();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    bool keyStatus;
    QTimer *timer;
    QList<bool> points;
    int timerMillis;
    int tickShiftSmall;
    int tickShiftBig;

    void initTimer();

private slots:

    void animate();

    void updateTimerInterval();
};

#endif