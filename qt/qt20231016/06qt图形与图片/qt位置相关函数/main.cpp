#include <QApplication>
#include <QDebug>
#include "geometry.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    Geometry g;
    g.show();

    return a.exec();
}
