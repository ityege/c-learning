#include <QApplication>
#include "dockwindows.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    DockWindows  dock;
    dock.show();
    return a.exec();
}
