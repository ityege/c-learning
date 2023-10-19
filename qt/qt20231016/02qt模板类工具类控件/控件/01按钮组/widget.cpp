#include "widget.h"
#include "ui_widget.h"
#include <QApplication>
#include <QPushButton>
#include <QFont>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    //这两行代码用于设置窗口的最小尺寸和最大尺寸。在这种情况下，窗口的宽度和高度都被设置为200个像素，因此窗口将具有固定的尺寸。
    setMinimumSize(200,120);
    setMaximumSize(200,120);
    QPushButton *quit = new QPushButton( "Quit", this);
    //这行代码用于设置 quit 按钮的位置和大小。在这里，quit 按钮的左上角坐标为 (62, 40)，宽度为 75，高度为 30。
    quit->setGeometry(62,40,75,30);
    //字体设置为 Times New Roman，大小为 18，加粗。
    quit->setFont( QFont("Times",18,QFont::Bold ));
    //将 quit 按钮的 clicked 信号与 qApp 对象的 quit() 槽函数进行关联。
    connect(quit,SIGNAL(clicked()), qApp,SLOT(quit()) );
}

Widget::~Widget()
{
    delete ui;
}
