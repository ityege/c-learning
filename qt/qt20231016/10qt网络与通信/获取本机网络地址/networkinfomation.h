#ifndef NETWORKINFOMATION_H
#define NETWORKINFOMATION_H

#include<Qwidget>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QGridLayout>
#include<QMessageBox>
#include<QHostInfo>
#include<QNetworkInterface>

class NetworkInfomation : public QWidget
{
    Q_OBJECT
public:
    explicit NetworkInfomation(QWidget *parent = 0);

    void getHostInformation();

signals:

public slots:
    void slotDetail();
private:
    QLabel *hostLabel;
    QLineEdit *LineEditLocalHostName;
    QLabel *ipLabel;
    QLineEdit *LineEditAddress;
    QPushButton *detailBtn;
    QGridLayout *mainLayout;

};

#endif // NETWORKINFOMATION_H
