#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QDialog>
#include <QDialog>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

#include "server.h"
class TcpServer : public QDialog
{
    Q_OBJECT
public:
    explicit TcpServer(QWidget *parent = 0,Qt::WindowFlags f=0);

signals:

public slots:
void slotCreateServer();
void updateServer(QString,int);

private:
    QListWidget *ContentListWidget;
    QLabel *PortLabel;
    QLineEdit *PortLineEdit;
    QPushButton *CreateBtn;
    QGridLayout *mainLayout;


    int port;
    Server*server;


};

#endif // TCPSERVER_H
