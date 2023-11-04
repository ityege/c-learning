#ifndef UDPSERVER_H
#define UDPSERVER_H


#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QudpSocket>
#include <QTimer>


class UdpServer : public QDialog
{
    Q_OBJECT
public:
    explicit UdpServer(QWidget *parent = 0,Qt::WindowFlags f=0);

signals:

public slots:
    void StartBtnClicked();
    void timeout();


private:
    QLabel *TimerLabel;
    QLineEdit *TextLineEdit;
    QPushButton *StartBtn;
    QVBoxLayout *mainLayout;


    int port;
    bool isStarted;
    QUdpSocket *udpSocket;
    QTimer *timer;
};

#endif // UDPSERVER_H
