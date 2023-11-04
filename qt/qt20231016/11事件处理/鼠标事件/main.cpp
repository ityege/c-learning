#include <QDebug>
#include <QApplication>
#include "mouseevent.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    MouseEvent m;
    m.show();
    return a.exec();
}
