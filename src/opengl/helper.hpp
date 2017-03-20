#ifndef __QCW_OPENGL_HELPER_H
#define __QCW_OPENGL_HELPER_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>

class Helper {

public:
    Helper();

    void paint(QPainter *painter, QPaintEvent *event, int elapsed);

private:
    QBrush background;
    QBrush brush;
    QPen pen;
};

#endif