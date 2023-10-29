#ifndef SVGWINDOW_H
#define SVGWINDOW_H

#include <QScrollArea>
#include "svgwidget.h"

class SvgWindow : public QScrollArea
{
    Q_OBJECT
public:
    explicit SvgWindow(QWidget *parent = 0);
    void setFile(QString);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
private:
    SvgWidget*svgWidget;
    QPoint mousePressPos;
    QPoint scrollBarValuesOnMousePress;
signals:

public slots:

};

#endif // SVGWINDOW_H
