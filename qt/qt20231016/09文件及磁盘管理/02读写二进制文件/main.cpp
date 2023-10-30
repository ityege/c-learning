#include <QFile>
#include <QtDebug>
#include <QDir>
#include <QTextStream>
#include <QDataStream>
#include <QDate>

int main(void)
{

    QFile file("binary.dat");
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QDataStream out(&file);//将数据序列化
    out << QString(QObject::tr("周何骏:"));//字符串序列化
    out << QDate::fromString("1994/09/25","yyyy/MM/dd");
    out << (qint32)19;//整数序列化
    file.close();

    file.setFileName("binary.dat");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"error!";
        return -1;
    }
    QDataStream in(&file);//从文件中读出数据
    QString name;
    QDate birthday;
    qint32 age;
    in >> name >> birthday >> age; //获取字符串和整数
    qDebug() << name << birthday << age;
    file.close();
    return 0;
}
