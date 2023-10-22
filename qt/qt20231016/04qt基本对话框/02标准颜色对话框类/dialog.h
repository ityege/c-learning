#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFrame>
#include <QPushButton>
#include <QGridLayout>
class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QDialog *parent = 0);

signals:

public slots:
    void showColor();
private:
    QPushButton *colorBtn;
    QFrame *colorFrame;
    QGridLayout *mainLayout;

};

#endif // DIALOG_H
