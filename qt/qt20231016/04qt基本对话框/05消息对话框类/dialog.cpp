#include "dialog.h"


Dialog::Dialog(QDialog *parent) :
    QDialog(parent)
{
    msgBtn =new QPushButton;//创建控件的对象
    msgBtn->setText(QObject::tr("标准消息对话框实例"));
    //添加布局管理
    mainLayout=new QGridLayout(this);//布局设计
    mainLayout->addWidget(msgBtn,0,0);

    //最后添加事件关联
    connect(msgBtn,SIGNAL(clicked()),this,SLOT(showMsgDlg()));//事件关联

}
void Dialog::showMsgDlg(){
    msgDlg=new MsgBoxDlg(this);
    msgDlg->show();
}

