#ifndef DIALOG_H
#define DIALOG_H


#include <QDialog>
#include <QGridLayout>
#include "inputdlg.h"

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QDialog *parent = 0);

signals:

public slots:
    void showInputDlg();

private:
    QGridLayout *mainLayout;
    QPushButton *inputBtn;
    InputDlg *inputDlg;
};

#endif // DIALOG_H
