#ifndef PROGRESSDLG_H
#define PROGRESSDLG_H

#include <QDialog>
//添加的头文件
#include <QLabel>
#include <QLineEdit>
#include <QProgressBar>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>

class ProgressDlg : public QDialog
{
    Q_OBJECT
public:
    explicit ProgressDlg(QDialog *parent = 0);

signals:

public slots:
    void startProgress();
private:
    QLabel*FileNum;
    QLineEdit*FileNumLineEdit;
    QLabel*ProgressType;
    QComboBox*comboBox;
    QProgressBar *progressBar;
    QPushButton *starBtn;
    QGridLayout *mainLayout;
};

#endif // PROGRESSDLG_H
