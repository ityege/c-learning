#include <QDebug>
#include <QApplication>
#include "keyevent.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    KeyEvent m;
    m.show();
    return a.exec();
}
