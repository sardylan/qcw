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

#include <QDebug>
#include <QPainter>
#include <QPaintEvent>

#include "glwidget.hpp"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {
    timer = new QTimer();

    keyStatus = false;
    tickShiftSmall = 0;
    tickShiftBig = 0;
    timerMillis = TIMER_MILLIS_DEFAULT;

    setAutoFillBackground(false);

    initTimer();
    updateTimerInterval();
}

void GLWidget::initTimer() {
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
    timer->setSingleShot(false);
}

void GLWidget::start() {
    timer->start();
}

void GLWidget::stop() {
    timer->stop();
}

void GLWidget::clear() {
    points.clear();
    tickShiftSmall = 0;
    tickShiftBig = 0;
}

void GLWidget::animate() {
    points.append(keyStatus);

    QPainter painter;
    painter.begin(this);
    while (points.size() > painter.window().width())
        points.removeFirst();
    painter.end();

    update();
}

void GLWidget::paintEvent(QPaintEvent *event) {
    QBrush whiteBrush = QBrush(Qt::white);
    QBrush blackBrush = QBrush(Qt::black);

    QPen whitePen = QPen(Qt::white);
    whitePen.setWidth(0);

    QPen blackPen = QPen(Qt::black);
    blackPen.setWidth(0);

    QPen greyPen = QPen(Qt::lightGray);
    blackPen.setWidth(0);

    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(event->rect(), whiteBrush);
    painter.translate(0, 0);

    int shiftLimitSmall = TICK_INTERVAL_SMALL;
    int shiftLimitBig = TICK_INTERVAL_SMALL * TICK_INTERVAL_BIG;

    if (points.size() == painter.window().width()) {
        tickShiftSmall++;
        if (tickShiftSmall == shiftLimitSmall)
            tickShiftSmall = 0;
        tickShiftBig++;
        if (tickShiftBig == shiftLimitBig)
            tickShiftBig = 0;
    }

    for (int x = 0; x < points.size(); x++) {
        painter.save();

        painter.setPen(points.at(x) ? blackPen : whitePen);
        painter.drawPoint(QPoint(x, 12));
        painter.drawPoint(QPoint(x, 13));
        painter.drawPoint(QPoint(x, 14));
        painter.drawPoint(QPoint(x, 15));
        painter.drawPoint(QPoint(x, 16));

        painter.setPen(greyPen);

        if ((x + tickShiftSmall) % shiftLimitSmall == 0)
            painter.drawPoint(QPoint(x, 22));

        if ((x + tickShiftBig) % shiftLimitBig == 0) {
            painter.drawPoint(QPoint(x, 23));
            painter.drawPoint(QPoint(x, 24));
        }

        painter.drawPoint(QPoint(x, 21));

        painter.restore();
    }

    painter.end();
}

void GLWidget::setKeyStatus(bool keyStatus) {
    GLWidget::keyStatus = keyStatus;
}

int GLWidget::getTimerMillis() const {
    return timerMillis;
}

void GLWidget::setTimerMillis(int timerMillis) {
    GLWidget::timerMillis = timerMillis;
    updateTimerInterval();
}

void GLWidget::updateTimerInterval() {
    timer->setInterval(timerMillis);
}