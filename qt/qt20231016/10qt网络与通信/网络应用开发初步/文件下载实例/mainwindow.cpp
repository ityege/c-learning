#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startRequest(QUrl url){
    qDebug()<<"这里执行了3";
    qDebug()<<url;
    manager = new QNetworkAccessManager(this);
    reply = manager->get(QNetworkRequest(url));
    qDebug()<<"这里执行了4";
    connect(reply,SIGNAL(readyRead()),this,SLOT(httpReadyRead()));
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this ,SLOT(updateDataReadProgress(qint64,qint64)));
    connect(reply,SIGNAL(finished()),this,SLOT(httpFinished()));
}
void MainWindow::httpReadyRead(){
    qDebug()<<"这里执行了5";
    if(file)file->write(reply->readAll());
    qDebug()<<"这里执行了6";
}

void MainWindow::updateDataReadProgress(qint64 bytesRead,qint64 totalBytes){
    qDebug()<<"这里执行了7";
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRead);
    qDebug()<<"这里执行了8";
}

void MainWindow::httpFinished(){
    qDebug()<<"这里执行了9";
    ui->progressBar->hide();
    file->flush();
    file->close();
    reply->deleteLater();
    reply=0;
    delete file;
    file=0;
    qDebug()<<"这里执行了10";
}

void MainWindow::on_pushButton_clicked(){
    url = ui->lineEdit->text();
    QFileInfo info(url.path());
    QString fileName(info.fileName());
    file=new QFile(fileName);
    if(!file->open(QIODevice::WriteOnly)){
        qDebug()<<"file open error";
        delete file;
        file=0;
        return;
    }
    qDebug()<<"这里执行了1";
    startRequest(url);
    qDebug()<<"这里执行了2";
    ui->progressBar->setValue(0);
    ui->progressBar->show();

}
