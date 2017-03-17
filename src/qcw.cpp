#include <QApplication>

#include "qcw.hxx"
#include "mainwindow.hxx"

int main(int argc, char *argv[]) {
    QCoreApplication::setApplicationName(APPLICATION_NAME);
    QCoreApplication::setApplicationVersion(APPLICATION_VERSION);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
