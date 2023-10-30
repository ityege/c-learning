#include <QFile>
#include <QtDebug>
#include <QDir>
#include <QTextStream>
#include <QDataStream>
#include <QDate>
#include<QStringList>

qint64 du(const QString &path){
    QDir dir(path);
    qint64 size=0;
    foreach(QFileInfo fileInfo,dir.entryInfoList(QDir::Files)){
        size += fileInfo.size();
    }
    foreach(QString subDir,dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot))
    {
        size += du(path+QDir::separator()+subDir);

    }
    char unit='B';
    qint64 curSize=size;
    if(curSize>1024){
        curSize/=1024;
        unit ='K';
        if(curSize>1024){
            curSize/=1024;
            unit ='M';
            if(curSize>1024){
                curSize/=1024;
                unit ='G';
            }
        }
    }
    qDebug()<<curSize<<unit<<"\t"<<qPrintable(path)<<endl;
    return size;
}



int main(void)
{
    QString path = QDir::currentPath();
    qDebug()<<path<<endl;
    du(path);
    return 0;
}
