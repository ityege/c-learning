#include "timeserver.h"
#include "timerthread.h"
#include "dialog.h"
TimeServer::TimeServer(QObject *parent) :
    QTcpServer(parent)
{
    dlg=(Dialog *)parent;
}

void TimeServer::incomingConnection(int socketDescriptor){

    TimerThread *thread = new TimerThread(socketDescriptor,0);

    connect(thread,SIGNAL(finished()),dlg,SLOT(slotShow()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()),Qt::DirectConnection);
    thread->start();
}

