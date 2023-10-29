#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "svgwindow.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void createMenu();
signals:

public slots:
    void slotOpenFile();
private:
    SvgWindow *svgWindow;//用于调用相关函数传递选择的文件名

};

#endif // MAINWINDOW_H
