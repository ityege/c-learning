#include <QApplication>
#include <QDebug>
#include "shapewidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    ShapeWidget e;
    e.show();
    return a.exec();
}
