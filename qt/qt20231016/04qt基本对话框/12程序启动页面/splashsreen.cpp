#include "splashsreen.h"

SplashSreen::SplashSreen(QMainWindow *parent) :
    QMainWindow(parent)
{
    setWindowTitle("Splash Example");
    QTextEdit *edit=new QTextEdit;
    edit->setText("Splash Example!");
    setCentralWidget(edit);
    resize(600,450);
    //启动的时候睡眠一会,用于显示开机界面
    Sleep(10000);
}
