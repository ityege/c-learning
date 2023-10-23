#ifndef DIALOG_H
#define DIALOG_H


#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QDialog *parent = 0);

signals:

public slots:
    void showCustomDlg();

private:
    QPushButton *CustomBtn;
    QLabel *label;
    QGridLayout *mainLayout;
};

#endif // DIALOG_H
