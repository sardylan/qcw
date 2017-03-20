#ifndef __QCW_OPENGL_GLWIDGET_H
#define __QCW_OPENGL_GLWIDGET_H

#include <QOpenGLWidget>

#include "helper.hpp"

class GLWidget : public QOpenGLWidget {
Q_OBJECT

public:
    GLWidget(Helper *helper, QWidget *parent);

public slots:

    void animate();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Helper *helper;
    int elapsed;
};

#endif