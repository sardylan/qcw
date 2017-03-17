#include <QApplication>

#include "mainwindow.hxx"

int main(int argc, char *argv[]) {
    QCoreApplication::setApplicationName("qcw");

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
