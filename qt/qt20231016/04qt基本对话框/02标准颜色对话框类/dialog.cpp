#include "dialog.h"
#include <QColorDialog>

Dialog::Dialog(QDialog *parent) :
    QDialog(parent)
{
    colorBtn=new QPushButton;//创建各个控件的对象
    colorBtn->setText(QObject::tr("颜色标准对话框实例"));

    colorFrame=new QFrame;
    colorFrame->setFixedSize(500, 500); // 设置colorFrame的大小为50x50
    colorFrame->setFrameShape(QFrame::Box);
    colorFrame->setAutoFillBackground(true);

    mainLayout=new QGridLayout(this);//布局设计
    mainLayout->addWidget(colorBtn,1,0);//布局设计
    mainLayout->addWidget(colorFrame,1,1);

    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));//事件关联

}
void Dialog::showColor(){
    QColor c = QColorDialog::getColor(Qt::blue);
    if(c.isValid()){
        colorFrame->setPalette(QPalette(c));
    }

}

