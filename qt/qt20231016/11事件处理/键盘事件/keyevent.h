#ifndef KEYEVENT_H
#define KEYEVENT_H

#include<QWidget>
#include<QKeyEvent>
#include<QPaintEvent>

class KeyEvent : public QWidget
{
    Q_OBJECT
public:
    explicit KeyEvent(QWidget *parent = 0);

    void drawPix();
    void keyPressEvent(QKeyEvent *);
    void paintEvent(QPaintEvent *);


signals:

public slots:


private:
    QPixmap *pix;
    QImage image;
    int startX;
    int startY;
    int width;
    int height;
    int step;

};

#endif // KEYEVENT_H
