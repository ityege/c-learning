#include <QApplication>
#include <QDebug>
#include <QTextCodec>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    //在较新的版本中，Qt 使用 Unicode 编码（UTF-8）来处理文本和翻译，因此不再需要显式地设置编码。
    //QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    Dialog d;
    d.show();
    return a.exec();
}
