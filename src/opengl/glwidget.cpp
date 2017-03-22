#include <QDebug>
#include <QPainter>
#include <QPaintEvent>

#include "glwidget.hpp"

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent) {
    timer = new QTimer();

    keyStatus = false;
    setAutoFillBackground(false);

    initTimer();
}

void GLWidget::initTimer() {
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
    timer->setInterval(10);
    timer->setSingleShot(false);
}

void GLWidget::start() {
    timer->start();
}

void GLWidget::stop() {
    timer->stop();
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
    whitePen.setWidth(5);

    QPen blackPen = QPen(Qt::black);
    blackPen.setWidth(5);

    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(event->rect(), whiteBrush);
    painter.translate(0, 0);

    for (int x = 0; x < points.size(); x++) {
        painter.save();
        painter.setPen(points.at(x) ? blackPen : whitePen);
        painter.drawPoint(QPoint(x, 15));
        painter.restore();
    }

    painter.end();
}

void GLWidget::setKeyStatus(bool keyStatus) {
    GLWidget::keyStatus = keyStatus;
}
