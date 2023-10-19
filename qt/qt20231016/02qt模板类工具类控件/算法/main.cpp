#include <QDebug>

void test1(){
    double a=-19.3,b=9.7;
    double c=qAbs(a);
    double max=qMax(b,c);
    int bn=qRound(b);
    int cn=qRound(c);
    //c=19.3
    //max=c=19.3
    //bn=10
    //cn=19
    qDebug()<<"a="<<a;
    qDebug()<<"b="<<b;
    qDebug()<<"c=gAbs(a)= "<<c;
    qDebug()<<"qMax(b,c)= "<<max;
    qDebug()<<"bn=qRound(b)= "<<bn;
    qDebug()<<"cn=qRound(c)= "<<cn;
    qSwap(bn,cn);
    qDebug()<<"gSwap(bn,cn):"<<"bn="<<bn<<"cn="<<cn;
}

int main(int argc, char *argv[])
{
    auto p=test1;
    p();
    return 0;
}
