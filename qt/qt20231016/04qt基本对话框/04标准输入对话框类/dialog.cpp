#include "dialog.h"


Dialog::Dialog(QDialog *parent) :
    QDialog(parent)
{
    inputBtn =new QPushButton;
    //创建控件的对象
    inputBtn->setText(QObject::tr("标准输入对话框实例"));
    //添加布局管理
    mainLayout=new QGridLayout(this);//布局设计
    mainLayout->addWidget(inputBtn,0,0);

    //最后添加事件关联
    connect(inputBtn,SIGNAL(clicked()),this,SLOT(showInputDlg()));//事件关联

}
void Dialog::showInputDlg(){
    inputDlg=new InputDlg(this);
    inputDlg->show();
}

