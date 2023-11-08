#include "timerthread.h"
#include<QDateTime>
#include<QByteArray>
#include<QDataStream>


TimerThread::TimerThread(int socketDescriptorr,QObject *parent) :
    QThread(parent),socketDescriptor(socketDescriptor)
{

}
void TimerThread::run(){
    QTcpSocket tcpSocket;
    if(!tcpSocket.setSocketDescriptor(socketDescriptor)){
        emit error(tcpSocket.error());
        return;
    }

    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_3);

    uint time2u = QDateTime::currentDateTime().toTime_t();
    out<<time2u;

    tcpSocket.write(block);
    tcpSocket.disconnectFromHost();
    tcpSocket.waitForDisconnected();


}
