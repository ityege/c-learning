#include <QDebug>
#include <QApplication>
#include "networkinfomation.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    NetworkInfomation w;
    w.show();
    return a.exec();
}
