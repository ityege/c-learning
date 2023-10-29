#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QDialog>
//添加的头文件
#include<QLabel>
#include <QGridLayout>

class Geometry : public QDialog
{
    Q_OBJECT
public:
    explicit Geometry(QWidget *parent = 0);
    void updateLabel();

signals:

public slots:

private:
    QLabel *xLabel;
    QLabel *xValueLabel;
    QLabel *yLabel;
    QLabel *yValueLabel;
    QLabel *FrmLabel;
    QLabel *FrmValueLabel;
    QLabel *posLabel;
    QLabel *posValueLabel;
    QLabel *geoLabel;
    QLabel *geoValueLabel;
    QLabel *widthLabel;
    QLabel *widthValueLabel;
    QLabel *heightLabel;
    QLabel *heightValueLabel;
    QLabel *rectLabel;
    QLabel *rectValueLabel;
    QLabel *sizeLabel;
    QLabel *sizeValueLabel;
    QGridLayout *mainLayout;
protected:
    void moveEvent(QMoveEvent *);
    void resizeEvent(QResizeEvent *);
};

#endif // GEOMETRY_H
