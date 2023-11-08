#ifndef TIMERTHREAD_H
#define TIMERTHREAD_H

#include <QThread>
#include <QtNetwork>
#include <QTcpSocket>
class TimerThread : public QThread
{
    Q_OBJECT
public:
    explicit TimerThread(int socketDescriptorr,QObject *parent = 0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketError);
public slots:

private:
    int socketDescriptor;
};

#endif // TIMERTHREAD_H
