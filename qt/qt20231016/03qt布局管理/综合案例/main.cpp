#include <QApplication>
#include <QDebug>
#include "content.h"
#include<QTextCodec>
#include<QSplitter>
#include<QListWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    QFont font("AR PL KaitiM GB",12);
    a.setFont(font);//设置整个程序采用的字体与字号
    QSplitter *splitterMain =new QSplitter(Qt::Horizontal,0);//新建一个水平分割窗对象,作为主布局框
    //setOpaqueResize(true) 用于指定分割器的大小调整是不透明的，
    //也就是在调整大小时不显示中间的调整线。这样可以提供更平滑的用户体验。
    splitterMain->setOpaqueResize(true);
    //左边QListWidget,里面放的是String
    QListWidget *list =new QListWidget(splitterMain);
    list->insertItem(0,QObject::tr("基本信息"));
    list->insertItem(1,QObject::tr("联系方式"));
    list->insertItem(2,QObject::tr("详细资料"));
    //右边
    Content *content =new Content(splitterMain);
    //通过信号将两边串联起来
    QObject::connect(list,SIGNAL(currentRowChanged(int)),content->stack,SLOT(setCurrentIndex(int)));
    splitterMain->setWindowTitle(QObject::tr("修改用户资料"));
    //设置最小和最大尺寸与当前尺寸保持一致
    splitterMain->setMinimumSize(splitterMain->minimumSize());
    splitterMain->setMaximumSize(splitterMain->maximumSize());

    splitterMain->show();
    return a.exec();
}
