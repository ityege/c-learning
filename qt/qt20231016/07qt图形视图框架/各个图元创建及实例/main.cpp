#include <QApplication>
#include <QDebug>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    MainWindow m;
    m.show();

    return a.exec();
}
