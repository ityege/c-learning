#include <QApplication>
#include <QDebug>
#include "progressdlg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    ProgressDlg d;
    d.show();
    return a.exec();
}
