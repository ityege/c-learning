#include <QDebug>
#include <QVariant>
#include <QColor>
void test1(){
    QList<QString> list;
    {
        QString str("This is a test string");
        list<<str;
    }

    qDebug()<<list[0];

}

void test2(){
    QList<int> list;
    list<<1<<2<<3<<4<<5;
    QListIterator<int> i(list);
    for(;i.hasNext();)
        qDebug()<<i.next();
}
void test3(){
    QList<int> list;
    QMutableListIterator<int> i(list);
    for(int j=0;j<10;++j)
        i.insert(j);
    for(i.toFront();i.hasNext();)
        qDebug()<<i.next();
    qDebug()<<"+++++++++++++++++++++";
    for(i.toBack();i.hasPrevious();)
        if(i.previous()%2==0)
            i.remove();
        else
            i.setValue(i.peekNext()*10);
    for(i.toFront();i.hasNext();)
        qDebug()<<i.next() ;

}
void test4(){
    QList<int> list;
    for(int j=0;j<10;j++)
        list.insert(list.end(),j);
    QList<int>::iterator i;
    for(i=list.begin();i!=list.end();++i){
        qDebug()<<(*i);
        *i=(*i)*10;
    }
    QList<int>::const_iterator ci;
    for(ci=list.constBegin();ci!=list.constEnd();++ci)
        qDebug()<<*ci;
}


void test5(){
    QMap<QString,QString> map;
    map.insert("beijing","111");
    map.insert("shanghai","021");
    map.insert("nanjing","025");
    QMapIterator<QString,QString> i(map);
    for(;i.hasNext();)
        qDebug()<<i.key()<<"  "<<i.next().value();
    QMutableMapIterator<QString,QString> mi(map);
    if(mi.findNext("111"))
        mi.setValue("010");
    QMapIterator<QString,QString> modi(map);
    qDebug()<<"";
    for(;modi.hasNext();)
        qDebug()<<modi.key()<<"  "<<modi.next().value();

}

void test6(){
    QMap<QString,QString> map;
    map.insert("beijing","111");
    map.insert("shanghai","021");
    map.insert("jinan","0531");
    QMap<QString,QString>::const_iterator i;
    for(i=map.constBegin();i!=map.constEnd();++i)
        qDebug()<<i.key()<<" "<<i.value();
    QMap<QString,QString>::iterator mi;
    mi=map.find("beijing");
    if(mi!=map.end())
        mi.value()="010";
    QMap<QString,QString>::const_iterator modi;
    qDebug()<<"";
    for(modi=map.constBegin();modi!=map.constEnd();++modi)
        qDebug()<<modi.key()<<" "<<modi.value();
}


int main(int argc, char *argv[])
{
    auto p=test6;
    p();
    return 0;
}
