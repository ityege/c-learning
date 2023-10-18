#include <QString>
#include <QDebug>

void test1(){
    QString str1="Welcome ";
    str1=str1+"to you! ";
    qDebug()<<str1;
    QString str2="hello, ";
    str2+="World! ";
    qDebug()<<str2;
}

void test2(){
    QString str1="Welcome ";
    QString str2="to ";
    str1.append(str2);
    str1.append("you! ");
    qDebug()<<str1;
}
void test3(){
    QString str;
    str.sprintf("%s"," Welcome ");
    qDebug()<<str;
    str.sprintf("%s", " to you! ");
    qDebug()<<str;
    str.sprintf("%s %s","Welcome","to you! ");
    qDebug()<<str;
}
void test4(){
    QString str;
    str=QString("%1 was born in %2").arg("张三").arg(1949);
    qDebug()<<str;
}


void test5(){

    QString str ="       Welcome  \t  to   \n    you!      ";
    str=str.trimmed();
    qDebug()<<str;

}

void test6(){
    QString str="Welcome to you! ";
    qDebug()<<str.startsWith("Welcome",Qt::CaseSensitive);
    qDebug()<<str.startsWith("you",Qt::CaseSensitive);
}

void test7(){
    QString str="Welcome to you!";
    qDebug()<<str.contains("Welcome",Qt::CaseSensitive);//返回 true;
}

void test8(){
    QString str="125";
    bool ok;
    qDebug()<<ok;
    int hex=str.toInt(&ok,16);
    qDebug()<<ok<<"-->"<<hex;
    ok=false;
    qDebug()<<ok;
    int dec=str.toInt(&ok,10);
    qDebug()<<ok<<"-->"<<dec;
    //ok=true,hex=293
    //ok=true,dec=125
}

void test9(){
    QString str="欢 迎 你 ! ";
    QByteArray ba=str.toUtf8();
    qDebug()<<ba;
    ba.append("你 好,世 界 !");
    qDebug()<<ba.data();

}
void test10(){
    qDebug()<<QString().isNull();
    qDebug()<<QString().isEmpty();
    qDebug()<<QString("").isNull();
    qDebug()<<QString("").isEmpty();
    //结果为 true
    //结果为 true
    //结果为 false
    //结果为 true
}
int main(int argc, char *argv[])
{
    auto p=test10;
    p();
    return 0;
}
