#include "drawer.h"
#include<QGroupBox>
#include<QVBoxLayout>

Drawer::Drawer(QWidget *parent,Qt::WindowFlags f)
    :QToolBox(parent,f)
{
    setWindowTitle(tr("My QQ"));//设置主窗体的标题
    toolBtn1_1 =new QToolButton;
    toolBtn1_1->setText(tr("张三"));
    toolBtn1_1->setIcon(QPixmap("123.png"));
    toolBtn1_1->setIconSize(QPixmap("123.png").size());
    toolBtn1_1->setAutoRaise(true);
    toolBtn1_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_2 =new QToolButton;
    toolBtn1_2->setText(tr("李四"));
    toolBtn1_2->setIcon(QPixmap("123.png"));
    toolBtn1_2->setIconSize(QPixmap("123.png").size());
    toolBtn1_2->setAutoRaise(true);
    toolBtn1_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_3 =new QToolButton;
    toolBtn1_3->setText(tr("王五"));
    toolBtn1_3->setIcon(QPixmap("123.png"));
    toolBtn1_3->setIconSize(QPixmap("123.png").size());
    toolBtn1_3->setAutoRaise(true);
    toolBtn1_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_4 =new QToolButton;
    toolBtn1_4->setText(tr("小赵"));
    toolBtn1_4->setIcon(QPixmap("123.png"));
    toolBtn1_4->setIconSize(QPixmap("123.png").size());
    toolBtn1_4->setAutoRaise(true);
    toolBtn1_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn1_5 =new QToolButton;
    toolBtn1_5->setText(tr("小孙"));
    toolBtn1_5->setIcon(QPixmap("123.png"));
    toolBtn1_5->setIconSize(QPixmap("123.png").size());
    toolBtn1_5->setAutoRaise(true);
    toolBtn1_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBoxl=new QGroupBox;

    QVBoxLayout *layoutl=new QVBoxLayout(groupBoxl);//(groupBox1);

    layoutl->setMargin(10);//布局中各窗体的显示间距
    layoutl->setAlignment(Qt::AlignHCenter);//布局中各窗体的显示位置
    layoutl->addWidget(toolBtn1_1);
    layoutl->addWidget(toolBtn1_2);
    layoutl->addWidget(toolBtn1_3);
    layoutl->addWidget(toolBtn1_4);
    layoutl->addWidget(toolBtn1_5);
    layoutl->addStretch();//插入一个占位符

    toolBtn2_1 =new QToolButton;
    toolBtn2_1->setText(tr("小王"));
    toolBtn2_1->setIcon(QPixmap("123.png"));
    toolBtn2_1->setIconSize(QPixmap("123.png").size());
    toolBtn2_1->setAutoRaise(true);
    toolBtn2_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn2_2 =new QToolButton;
    toolBtn2_2->setText(tr("小张"));
    toolBtn2_2->setIcon(QPixmap("123.png"));
    toolBtn2_2->setIconSize(QPixmap("123.png").size());
    toolBtn2_2->setAutoRaise(true);
    toolBtn2_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox2=new QGroupBox;
    //垂直分布
    QVBoxLayout *layout2=new QVBoxLayout(groupBox2);
    layout2->setMargin(10);
    layout2->setAlignment(Qt::AlignHCenter);
    layout2->addWidget(toolBtn2_1);
    layout2->addWidget(toolBtn2_2);

    toolBtn3_1 =new QToolButton;
    toolBtn3_1->setText(tr("小陈"));
    toolBtn3_1->setIcon(QPixmap("123.png"));
    toolBtn3_1->setIconSize(QPixmap("123.png").size());
    toolBtn3_1->setAutoRaise(true);
    toolBtn3_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    too1Btn3_2 =new QToolButton;
    too1Btn3_2->setText(tr("小李"));
    too1Btn3_2->setIcon(QPixmap("123.png"));
    too1Btn3_2->setIconSize(QPixmap("123.png").size());
    too1Btn3_2->setAutoRaise(true);
    too1Btn3_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox3=new QGroupBox;
    QVBoxLayout *layout3=new QVBoxLayout(groupBox3);
    layout3->setMargin(10);
    layout3->setAlignment(Qt::AlignHCenter);
    layout3->addWidget(toolBtn3_1);
    layout3->addWidget(too1Btn3_2);

    this->addItem((QWidget*)groupBoxl,tr("我的好友"));
    this->addItem((QWidget*)groupBox2,tr("陌生人"));
    this->addItem((QWidget*)groupBox3,tr("黑名单"));
}
