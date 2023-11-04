#include "udpclient.h"
#include <QMessageBox>
#include <QHostAddress>
#include <QDebug>

UdpClient::UdpClient(QWidget *parent,Qt::WindowFlags f) :
    QDialog(parent,f)
{
    setWindowTitle(tr("uDP Client"));

    ReceiveTextEdit = new QTextEdit(this);
    CloseBtn = new QPushButton(tr("Close"),this);

    mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(ReceiveTextEdit);
    mainLayout->addWidget(CloseBtn);


    connect(CloseBtn,SIGNAL(clicked()),this,SLOT(CloseBtnClicked()));
    port=5555;
    udpSocket = new QUdpSocket(this);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    bool result=udpSocket->bind(port);

    if(!result){
        QMessageBox::information(this,tr("error"),tr("udpcreate socket error!"));
        return;
    }

}

void UdpClient::CloseBtnClicked(){
    close();
}

void UdpClient::dataReceived(){
    while(udpSocket->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());

        udpSocket->readDatagram(datagram.data(),datagram.size());
        QString msg=QString::fromUtf8(datagram.data());
        qDebug()<<msg;
        ReceiveTextEdit->insertPlainText(msg);
    }

}



