#ifndef __QCW_OPENGL_GLWIDGET_H
#define __QCW_OPENGL_GLWIDGET_H

#include <QOpenGLWidget>
#include <QTimer>

class GLWidget : public QOpenGLWidget {
Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);

    void setKeyStatus(bool keyStatus);

public slots:

    void start();

    void stop();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    bool keyStatus;
    QTimer *timer;
    QList<bool> points;

    void initTimer();

private slots:

    void animate();
};

#endif