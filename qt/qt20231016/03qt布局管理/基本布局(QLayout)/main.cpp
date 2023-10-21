#include <QApplication>
#include "dialog.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    QString currentPath = QApplication::applicationDirPath();
    qDebug() << "Current path: " << currentPath;
    Dialog d;
    d.show();
    return a.exec();
}
