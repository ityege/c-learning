#include <QDebug>
#include <QApplication>
#include "eventfilter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    EventFilter m;
    m.show();
    return a.exec();
}
