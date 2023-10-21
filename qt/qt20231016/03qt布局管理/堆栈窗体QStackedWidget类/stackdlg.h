#ifndef STACKDLG_H
#define STACKDLG_H

#include <QDialog>
#include <QListWidget>
#include <QStackedwidget>
#include <QLabel>

class StackDlg : public QDialog
{
    Q_OBJECT
public:
    explicit StackDlg(QWidget *parent = 0);

signals:

public slots:
private:
    QListWidget *list;
    QStackedWidget *stack;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;

};

#endif // STACKDLG_H
