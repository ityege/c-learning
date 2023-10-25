#include <QApplication>
#include <QDebug>
#include "extensiondlg.h"
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    ExtensionDlg e;
    e.show();
    return a.exec();
}
