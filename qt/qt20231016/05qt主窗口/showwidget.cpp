#include "showwidget.h"

ShowWidget::ShowWidget(QWidget *parent) :
    QWidget(parent)
{
    imageLabel =new QLabel;
    imageLabel->setScaledContents(true);

    text =new QTextEdit;

    //水平布局,左边放Label右边放一个textEdit
    QHBoxLayout *mainLayout =new QHBoxLayout(this);
    mainLayout->addWidget(imageLabel);
    mainLayout->addWidget(text);
}
