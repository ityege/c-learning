#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFrame>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QDialog *parent = 0);

signals:

public slots:
    void showFont();
private:
    QPushButton *fontBtn;
    QLineEdit *fontLineEdit;
    QGridLayout *mainLayout;

};

#endif // DIALOG_H
