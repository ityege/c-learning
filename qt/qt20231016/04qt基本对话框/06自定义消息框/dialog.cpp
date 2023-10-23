#include "dialog.h"


Dialog::Dialog(QDialog *parent) :
    QDialog(parent)
{
    CustomBtn =new QPushButton;
    CustomBtn->setText(tr("用户自定义消息对话框实例"));
    label =new QLabel;
    label->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    //添加布局管理
    mainLayout=new QGridLayout(this);
    mainLayout->addWidget(CustomBtn,0,0);
    mainLayout->addWidget(label,0,1);
    connect(CustomBtn,SIGNAL(clicked()),this,SLOT(showCustomDlg()));

}
void Dialog::showCustomDlg(){
    label->setText(tr("Custom Message Box"));
    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle(tr("用户自定义消息框")); //设置消息框的标题

    QPushButton *yesBtn=customMsgBox.addButton(tr("Yes"),QMessageBox::ActionRole);
    QPushButton *noBtn=customMsgBox.addButton(tr("No"),QMessageBox::ActionRole);
    QPushButton *cancelBtn=customMsgBox.addButton(QMessageBox::Cancel);

    customMsgBox.setText(tr("这是一个用户自定义消息框!"));
    customMsgBox.setIconPixmap(QPixmap("123.png"));
    customMsgBox.exec();
    if(customMsgBox.clickedButton()==yesBtn)
    {
        label->setText("Custom Message Box/Yes");
    }
    if(customMsgBox.clickedButton()==noBtn)

    {
        label->setText("Custom Message Box/No");

    }

    if(customMsgBox.clickedButton()==cancelBtn)
    {
        label->setText("Custom Message Box/Cancel");
    }

    return;

}

