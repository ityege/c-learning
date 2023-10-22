#ifndef MSGBOXDLG_H
#define MSGBOXDLG_H

#include <QDialog>
#include<QLabel>
#include <QPushButton>
#include<QGridLayout>


class MsgBoxDlg : public QDialog
{
    Q_OBJECT
public:
    explicit MsgBoxDlg(QDialog *parent = 0);

signals:

public slots:
    void showQuestionMsg();
    void showInformationMsg();
    void showWarningMsg();
    void showCriticalMsg();
    void showAboutMsg();
    void showAboutQtMsg();
private:
    QLabel *label;
    QPushButton *questionBtn;
    QPushButton *informationBtn;
    QPushButton *warningBtn;
    QPushButton *criticalBtn;
    QPushButton *aboutBtn;
    QPushButton *aboutQtBtn;
    QGridLayout *mainLayout;


};

#endif // MSGBOXDLG_H
