#include "dialog.h"
#include <QFontDialog>

Dialog::Dialog(QDialog *parent) :
    QDialog(parent)
{
    fontBtn=new QPushButton;//创建控件的对象
    fontBtn->setText(tr("字体标准对话框实例"));
    fontLineEdit=new QLineEdit;//显示更改的字符串
    // 设置水平和垂直方向的大小策略为Expanding
    fontLineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    fontLineEdit->setText(QObject::tr("welcome!"));
    //添加布局管理
    mainLayout=new QGridLayout(this);//布局设计
    mainLayout->addWidget(fontBtn,2,0);
    mainLayout->addWidget(fontLineEdit,2,1);

    //最后添加事件关联
    connect(fontBtn,SIGNAL(clicked()),this,SLOT(showFont()));//事件关联

}
void Dialog::showFont(){
    bool ok;
    QFont f = QFontDialog::getFont(&ok);
    if (ok){
        fontLineEdit->setFont(f);
    }

}

