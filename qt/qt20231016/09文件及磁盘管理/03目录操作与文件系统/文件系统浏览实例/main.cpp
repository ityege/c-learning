#include <QDebug>
#include <QApplication>
#include "fileview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    FileView f;
    f.show();
    return a.exec();
}
