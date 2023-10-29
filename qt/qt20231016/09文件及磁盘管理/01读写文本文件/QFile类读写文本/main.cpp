#include <QFile>
#include <QtDebug>
#include <QDir>
int main(void)
{

    QFile file("textFilel.txt");
    if(file.open(QIODevice::ReadOnly))
    {

        char buffer[2048];
        qint64 lineLen= file.readLine(buffer,sizeof(buffer));
        if(lineLen!=-1)
            qDebug()<<"数据:"<<buffer;
    }
    else{

        qDebug() << "文件打开失败:" << file.errorString()<<QDir::currentPath();
    }

    return 0;
}
