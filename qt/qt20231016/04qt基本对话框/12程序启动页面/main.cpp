#include <QApplication>
#include <QDebug>
#include "splashsreen.h"
#include<QPixmap>
#include <QSplashScreen>
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    QPixmap pixmap("123.png");
    //创建一个启动页面对象
    QSplashScreen splash(pixmap);
    //显示启动图片
    splash.show();
    //使程序在显示启动画面的同时仍能响应鼠标等其他事件。
    a.processEvents();
    //启动界面
    SplashSreen w;
    w.show();
    //表示在主窗体对象初始化完成后，结束启动画面
    splash.finish(&w);
    return a.exec();
}
