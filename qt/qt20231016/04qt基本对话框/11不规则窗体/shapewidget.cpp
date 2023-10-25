#include "shapewidget.h"
//添加的头文件
#include<QMouseEvent>
#include<QPainter>
#include<QPixmap>
#include<QBitmap>
ShapeWidget::ShapeWidget(QWidget *parent) :
    QWidget(parent)
{
    QPixmap pix;
    pix.load("123.png",0,Qt::AvoidDither|Qt::ThresholdDither|Qt::ThresholdAlphaDither);
    resize(pix.size());
    setMask(QBitmap(pix.mask()));

}
void ShapeWidget::mousePressEvent(QMouseEvent *event){

    if(event->button()==Qt::LeftButton){
        dragPosition =event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    if(event->button()==Qt::RightButton){
        close();
    }

}
void ShapeWidget::mouseMoveEvent(QMouseEvent *event){

    if(event->buttons()&Qt::LeftButton){

        move(event->globalPos()-dragPosition);
        event->accept();
    }

}
void ShapeWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(0,0,QPixmap("123.png"));

}
