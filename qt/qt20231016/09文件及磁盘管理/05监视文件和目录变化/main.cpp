#include <QDebug>
#include <QApplication>
#include "watcher.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    Watcher f;
    f.show();
    return a.exec();
}
