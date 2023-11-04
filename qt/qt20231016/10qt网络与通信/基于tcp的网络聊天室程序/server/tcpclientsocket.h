#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QTcpSocket>

class TcpClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TcpClientSocket(QObject *parent = 0);

signals:
    void updateClients(QString,int);
    void disconnected(int);
public slots:
    void dataReceived();
    void slotDisconnected();

};

#endif // TCPCLIENTSOCKET_H
