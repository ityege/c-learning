#ifndef SVGWIDGET_H
#define SVGWIDGET_H

#include <QSvgWidget>
#include <QtSvg>
#include <QSvgWidget>
#include <QSvgRenderer>

class SvgWidget : public QSvgWidget
{
    Q_OBJECT
public:
    explicit SvgWidget(QWidget *parent = 0);
    void wheelEvent(QWheelEvent *);//响应鼠标的滚轮事件，使 SVG 图片能够通过鼠标滚轮的滚动进行缩放
private:
    QSvgRenderer *render;//用于图片显示尺寸的确定
signals:

public slots:

};

#endif // SVGWIDGET_H
