#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QFrame>
#include "pixitem.h"


class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);

    void createControlFrame();

signals:

public slots:

    void slotRotate(int);
    void slotScale(int);
    void slotShear(int);
    void slotTranslate(int);

private:
    int angle;
    qreal scaleValue;
    qreal shearValue;
    qreal translateValue;
    QGraphicsView *view;
    QFrame*ctrlFrame;
    PixItem *pixItem;
};

#endif // MAINWIDGET_H
