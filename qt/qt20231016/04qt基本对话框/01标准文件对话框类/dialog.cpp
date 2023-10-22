#include "dialog.h"
#include<QGridLayout>
#include<QFileDialog>
#include<QPushButton>

Dialog::Dialog(QDialog *parent) :
    QDialog(parent)
{
    setWindowTitle(QObject::tr("各种标准对话框的实例"));
    fileBtn=new QPushButton;  //各个控件对象的初始化
    fileBtn->setText(QObject::tr("文件标准对话框实例"));
    fileLineEdit=new QLineEdit;  //用来显示选择的文件名

    mainLayout=new QGridLayout(this);//布局设计
    mainLayout->addWidget(fileBtn,0,0);
    mainLayout->addWidget(fileLineEdit,0,1);
    //添加事件关联
    connect(fileBtn,SIGNAL(clicked()),this,SLOT(showFile()));//事件关联
}

void Dialog::showFile(){

    QString s= QFileDialog::getOpenFileName(this,"open filesdialog","/","C++ files(*.cpp)::C files(*.c)::Head files(*.h)");
    fileLineEdit->setText(s);
}
