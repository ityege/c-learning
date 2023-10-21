#include "content.h"
#include <QObject>

Content::Content(QWidget *parent) :
    QFrame(parent)
{
    //右边的content QStackedwidget
    stack =new QStackedWidget(this);
    //对堆栈窗口的显示风格进行设置。
    stack->setFrameStyle(QFrame::Panel|QFrame::Raised);

    //放进去3个对象
    baseInfo =new BaseInfo();
    contact =new Contact();
    detail =new Detail();
    stack->addWidget(baseInfo);
    stack->addWidget(contact);
    stack->addWidget(detail);

    AmendBtn =new QPushButton(tr("修改"));
    CloseBtn=new QPushButton(tr("关闭"));
    //关联两个按钮的水平布局管理器
    QHBoxLayout *BtnLayout =new QHBoxLayout;
    // 添加一个弹簧
    BtnLayout->addStretch(1);
    BtnLayout->addWidget(AmendBtn);
    BtnLayout->addWidget(CloseBtn);
    //采用垂直布局管理器去关联整个页面布局
    QVBoxLayout *RightLayout =new QVBoxLayout(this);
    //setMargin() 和 setSpacing()是这两个布局管理器类的函数，
    //用于设置布局的边距和间距。
    RightLayout->setMargin(10);
    RightLayout->setSpacing(6);

    //将上面三个对象和两个按钮添加进去
    RightLayout->addWidget(stack);
    RightLayout->addLayout (BtnLayout);

}
