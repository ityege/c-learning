#include <QApplication>
#include <QDebug>
#include "qlcdnumber.h"
/***
 * tmd 不能编译,QLCDNumber不能继承,感觉可能ide抽风了.
 *
 **/
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    DigiClock clock;
    clock.show();
    return a.exec();
}
