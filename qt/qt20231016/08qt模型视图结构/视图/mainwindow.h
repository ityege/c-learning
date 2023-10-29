#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QstandardItemModel>
#include <QTableView>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QSplitter>
#include"histogramview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void createAction();
    void createMenu();
    void setupModel();
    void setupView();

    void openFile(QString);
signals:

public slots:
    void slotOpen();

private:
    QMenu *fileMenu;
    QAction *openAct;
    QStandardItemModel *model;
    QTableView *table;
    QSplitter*splitter;

    HistogramView *histogram;

};

#endif // MAINWINDOW_H
