#include "dockwindows.h"
#include <QTextEdit>
#include <QDockWidget>

DockWindows::DockWindows(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle(QObject::tr("Dockwindows"));//设置主窗口的标题栏文字
    QTextEdit *te=new QTextEdit(this);//定义一个QTextEdit 对象作为主窗口
    te->setText(QObject::tr("Main Window"));
    te->setAlignment(Qt::AlignCenter);
    setCentralWidget(te);//将此编辑框设为主窗口的中央窗体
    //停靠窗口1
    QDockWidget *dock=new QDockWidget(QObject::tr("DockWindowl"),this);
    //void setFeatures(DockWidgetFeatures features)
    //参数 QDockWidget::DockWidgetFeatures 指定停靠窗体的特性，包括以下几种参数。
    //QDockWidget::DockWidgetClosable: 停靠窗体可关闭。
    //QDockWidget::DockWidgetMovable: 停靠窗体可移动。
    //QDockWidget::DockWidgetFloatable: 停靠窗体可浮动
    //QDockWidget::AllDockWidgetFeatures: 此参数表示拥有停靠窗体的所有特性。
    //QDockWidget::NoDockWidgetFeatures: 不可移动、不可关闭、不可浮动。
    //此参数可采用或(|)的方式对停靠窗体进行特性的设定。
    dock->setFeatures(QDockWidget::DockWidgetMovable);
    //void setAllowedAreas(Qt::DockWidgetAreas  areas)
    //参数 Qt::DockWidgetAreas 指定了停靠窗体可停靠的区域，包括以下几种参数。
    //Qt::LeftDockWidgetArea: 可在主窗口的左侧停靠。
    //Qt::RightDockWidgetArea:可在主窗口的右侧停靠。
    //Qt::TopDockWidgetArea: 可在主窗口的顶端停靠。
    //Qt::BottomDockWidgetArea: 可在主窗口的底部停靠。
    //Qt::AlIDockWidgetArea: 可在主窗口任意 (以上四个)部位停靠。
    //Qt::NoDockWidgetArea: 只可停靠在插入处。
    //各区域设定也可采用或(|)的方式进行。
    //可移动
    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    QTextEdit *te1 =new QTextEdit();
    te1->setText(QObject::tr("Windowl,The dock widget can be moved betweendocks by theuser" ""));
    dock->setWidget(te1);
    addDockWidget(Qt::RightDockWidgetArea,dock);
    //停靠窗口2
    dock=new QDockWidget(QObject::tr("Dockwindow2"),this);
    dock->setFeatures(QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable);//可关闭、可浮动
    QTextEdit *te2 =new QTextEdit();
    te2->setText(QObject::tr("Window2,The dock widget can be detached from themain window,""and floated as an independent window, and can be closed"));
    dock->setWidget(te2);
    addDockWidget(Qt::RightDockWidgetArea,dock);
    //停靠窗口3
    dock=new QDockWidget(QObject::tr("DockWindow3"),this);
    dock->setFeatures(QDockWidget::AllDockWidgetFeatures);//全部特性
    QTextEdit *te3 =new QTextEdit();
    te3->setText(QObject::tr("window3,The dock widget can be closed,moved,andfloated"));
    dock->setWidget(te3);
    addDockWidget(Qt::RightDockWidgetArea,dock);
}

DockWindows::~DockWindows()
{

}
