#include <QDebug>
#include <QApplication>
#include "fileinfo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    FileInfo f;
    f.show();
    return a.exec();
}
