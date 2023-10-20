#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QDateTime>
#include <QFont>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QTimer>
//1 QDateTime
void test1(Widget *widget){
    // 创建 QLabel
    QLabel *label = new QLabel("当前时间:", widget);

    // 创建 QDateTime
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QLabel *datetimeLabel = new QLabel(currentDateTime.toString(), widget);

    // 创建垂直布局管理器
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(label);
    layout->addWidget(datetimeLabel);

    // 将布局管理器设置为窗口的布局
    widget->setLayout(layout);
}
// 定时器超时时执行的槽函数
void Widget::handleTimerTimeout()
{
    // 在定时器超时时执行的操作
    QMessageBox::information(this, "Timer", "定时器 超时了!");
}

//2 Qtimer 类
void test2(Widget *widget){
    // 创建 QTimer
    QTimer *timer = new QTimer(widget);

    // 设置定时器的时间间隔，单位为毫秒
    int interval = 1000; // 1 秒
    timer->setInterval(interval);

    // 连接定时器的超时信号到槽函数
    widget->connect(timer, &QTimer::timeout, widget, &Widget::handleTimerTimeout);

    // 启动定时器
    timer->start();
}
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    test2(this);

}

Widget::~Widget()
{
    delete ui;
}
