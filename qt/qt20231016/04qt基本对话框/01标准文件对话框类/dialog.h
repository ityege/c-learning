#ifndef DIALOG_H
#define DIALOG_H

#include <QObject>
#include <QDialog>
#include <QLineEdit>
#include <QGridLayout>
class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QDialog *parent = 0);

signals:

public slots:
    void showFile();
private:
    QPushButton *fileBtn;
    QLineEdit *fileLineEdit;
    QGridLayout *mainLayout;

};

#endif // DIALOG_H
