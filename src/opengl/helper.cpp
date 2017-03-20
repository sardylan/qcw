#include "helper.hpp"

#include <QDebug>
#include <QPainter>
#include <QPaintEvent>

Helper::Helper() {
    QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

    background = QBrush(QColor(255, 255, 255));

    brush = QBrush(gradient);
    pen = QPen(Qt::black);
    pen.setWidth(5);
}

 void Helper::paint(QPainter *painter, QPaintEvent *event, int elapsed) {
    painter->fillRect(event->rect(), background);

    painter->setBrush(brush);
    painter->setPen(pen);
    painter->translate(0, 0);

    for (int x = 0; x < painter->window().width(); x++) {
        painter->save();
        painter->drawPoint(QPoint(x, 15));
        painter->restore();
    }
}