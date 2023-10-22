#ifndef DIALOG_H
#define DIALOG_H


#include <QDialog>
#include <QGridLayout>
#include "msgboxdlg.h"

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QDialog *parent = 0);

signals:

public slots:
    void showMsgDlg();

private:
    QGridLayout *mainLayout;
    QPushButton *msgBtn;
    MsgBoxDlg *msgDlg;
};

#endif // DIALOG_H
