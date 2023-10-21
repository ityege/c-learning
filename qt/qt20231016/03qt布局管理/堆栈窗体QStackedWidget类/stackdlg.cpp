#include "stackdlg.h"
#include <QHBoxLayout>

StackDlg::StackDlg(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(QObject::tr("Stackedwidget"));
    //左边QListWidget,里面放三个字符串
    list =new QListWidget(this);
    list->insertItem(0,QObject::tr("windowl"));
    list->insertItem(1,QObject::tr("window2"));
    list->insertItem(2,QObject::tr("window3r"));
    //右边QStackedWidget,里面放着三个Label
    label1 =new QLabel(QObject::tr("windowTest1"));
    label2 =new QLabel(QObject::tr("windowTest2"));
    label3=new QLabel(QObject::tr("windowTest3"));
    stack=new QStackedWidget(this);
    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);
    //将两个放在一个水平布局管理器里面
    //创建了一个水平布局管理器 QHBoxLayout 对象
    QHBoxLayout *mainLayout =new QHBoxLayout(this);
    //设置了布局的边距（margin）为 5 个像素
    mainLayout->setMargin(5);
    //设置了布局的间距（spacing）为 5 个像素。
    mainLayout->setSpacing(5);
    //addWidget() 函数用于向布局添加部件。
    //第二行代码中的 0 参数表示部件的拉伸因子（stretch factor），
    //而 Qt::AlignHCenter 则表示部件在水平方向上居中对齐。
    mainLayout->addWidget(list);
    mainLayout->addWidget(stack,0,Qt::AlignHCenter);
    //这两行代码设置了部件的拉伸因子。
    //拉伸因子决定了部件在布局中所占据的空间比例。
    //在这里，list 部件的拉伸因子为 1，stack 部件的拉伸因子为 3，意味着 stack 部件将占据 list 部件的三倍空间。
    mainLayout->setStretchFactor(list,1);
    mainLayout->setStretchFactor(stack,3);
    connect(list,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));
}
