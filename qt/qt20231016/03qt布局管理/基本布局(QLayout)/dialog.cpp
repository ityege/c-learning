#include "dialog.h"
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QPushButton>
#include<QFrame>
#include<QGridLayout>
#include<QPixmap>
#include<QHBoxLayout>
#include<QDebug>
#include <QDir>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(QObject::tr("UserInfo"));
    /************左侧***************************/
    UserNameLabel =new QLabel(QObject::tr("用户名:"));
    UserNameLineEdit =new QLineEdit;
    NameLabel =new QLabel(QObject::tr("姓名:"));
    NameLineEdit =new QLineEdit;
    SexLabel =new QLabel(QObject::tr("性别:"));
    SexComboBox =new QComboBox;
    SexComboBox->addItem(QObject::tr("女"));
    SexComboBox->addItem(QObject::tr("男"));
    DepartmentLabel =new QLabel(QObject::tr("部门:"));
    DepartmentTextEdit =new QTextEdit;
    AgeLabel =new QLabel(QObject::tr("年龄:"));
    AgeLineEdit =new QLineEdit;
    OtherLabel =new QLabel(QObject::tr("备注:"));
    //OtherLabel->setFrameStyle(QFrame::Panel/QFrame::Sunken):
    //设置控件的风格。
    //setFrameStyle0是 QFrame 的方法，参数以或(|)的方式设定控件的面板风格，
    //由形状(QFrame::Shape) 和阴影 (QFrame::shadow)两项配合设定。
    //其中，形状包括六种，分别是 NoFrame、Panel、Box、HLine、VLine 及 WinPanel;
    //阴影包括三种，分别是 Plain、Raised 和 Sunken。
    OtherLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    //网格排列布局 左侧布局
    LeftLayout =new QGridLayout();
    LeftLayout->addWidget(UserNameLabel,0,0);//用户名
    LeftLayout->addWidget(UserNameLineEdit,0,1);
    LeftLayout->addWidget(NameLabel,1,0);//姓名
    LeftLayout->addWidget(NameLineEdit,1,1);
    LeftLayout->addWidget(SexLabel,2,0);//性别
    LeftLayout->addWidget(SexComboBox,2,1);
    LeftLayout->addWidget(DepartmentLabel,3,0);//部门
    LeftLayout->addWidget(DepartmentTextEdit,3,1);
    LeftLayout->addWidget(AgeLabel,4,0);//年龄
    LeftLayout->addWidget(AgeLineEdit,4,1);
    LeftLayout->addWidget(OtherLabel,5,0,1,2);//其他
    //LeftLayout->setColumnStretch(0,1)、LeftLayout->setColumnStretch(1,3):
    //设定两列分别占用空间的比例，本例设定为 1:3。即使对话框框架大小改变了，两列之间的宽度比依然保持不变。
    LeftLayout->setColumnStretch(0,1);
    LeftLayout->setColumnStretch(1,3);
    /*******************右侧**************************/
    HeadLabel =new QLabel(QObject::tr("头像: "));//右上角部分
    HeadIconLabel =new QLabel;//这个Label显示图片
    qDebug()<<QDir::currentPath();
    QPixmap icon("123.png");
    qDebug()<<icon.isNull();
    HeadIconLabel->setPixmap(icon);
    HeadIconLabel->resize(icon.width(),icon.height());
    UpdateHeadBtn =new QPushButton(QObject::tr("更新"));

    //水平方向布局管理器,完成右上侧头像选自去的布局
    TopRightLayout =new QHBoxLayout();
    //设定各个控件之间的间距为 20
    TopRightLayout->setSpacing(20);
    TopRightLayout->addWidget(HeadLabel);
    TopRightLayout->addWidget(HeadIconLabel);
    TopRightLayout->addWidget(UpdateHeadBtn);

    IntroductionLabel =new QLabel(QObject::tr("个人说明:"));//右下角部分
    IntroductionTextEdit =new QTextEdit;

    //垂直方向布局管理器,完成下方两个按钮的布局
    RightLayout =new QVBoxLayout();
    RightLayout->setMargin(10);
    RightLayout->addLayout(TopRightLayout);
    RightLayout->addWidget(IntroductionLabel);
    RightLayout->addWidget(IntroductionTextEdit);
    /******************底部*****************/
    OkBtn=new QPushButton(QObject::tr("确定"));
    CancelBtn =new QPushButton(QObject::tr("取消"));

    //水平方向布局管理器,完成下方两个按钮的布局
    ButtomLayout =new QHBoxLayout();
    //ButtomLayout->addStretch():
    //在按之前插入一个占位符，使两个按钮能够靠右对齐，
    //并且在整个对话框的大小发生改变时，保证按钮的大小不发生变化。
    ButtomLayout->addStretch();
    ButtomLayout->addWidget(OkBtn);
    ButtomLayout->addWidget(CancelBtn);
    /**********************************/
    //主布局管理器 网格布局管理器
    QGridLayout *mainLayout =new QGridLayout(this);
    //设置对话框的边距为15
    mainLayout->setMargin(15);
    //设置布局中子部件之间的间距
    mainLayout->setSpacing(10);

    mainLayout->addLayout(LeftLayout,0,0);
    mainLayout->addLayout(RightLayout,0,1);
    mainLayout->addLayout(ButtomLayout,1,0,1,2);
    //mainLayout->setSizeConstraint(QLayout::SetFixedSize):
    //设定最优化显示，并且使用户无法改变对话框的大小。
    //所谓最优化显示，即控件都按其 sizeHint()的大小显示。
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

}

Dialog::~Dialog()
{

}
