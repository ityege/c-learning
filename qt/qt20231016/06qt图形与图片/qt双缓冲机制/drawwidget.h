#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>

//添加的头文件
#include <QtGui>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QResizeEvent>
#include<QColor>
#include<QPixmap>
#include<QPoint>
#include<QPainter>
#include<QPalette>

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

signals:

public slots:
    void setStyle(int);
    void setWidth(int);
    void setColor(QColor);
    void clear();


private:
    QPixmap *pix;
    QPoint startPos;
    QPoint endPos;
    int style;
    int weight;
    QColor color;


};

#endif // DRAWWIDGET_H
