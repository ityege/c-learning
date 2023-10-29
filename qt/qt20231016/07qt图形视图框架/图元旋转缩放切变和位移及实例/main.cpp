#include <QApplication>
#include <QDebug>
#include "mainwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    MainWidget w;
    w.show();

    return a.exec();
}
