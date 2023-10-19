#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //这段代码将创建一个Widget对象w，并将其位置和大小设置为(100, 100)和(200, 120)。
    //setGeometry()函数用于设置窗口的位置和大小。
    w.setGeometry(100,100,200,120);
    w.show();

    return a.exec();
}
