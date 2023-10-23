#include <QApplication>
#include <QDebug>
#include "palette.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    Palette p;
    p.show();
    return a.exec();
}
