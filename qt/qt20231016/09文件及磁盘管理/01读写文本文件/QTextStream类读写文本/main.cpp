#include <QFile>
#include <QtDebug>
#include <QDir>
#include <QTextStream>

int main(void)
{

    QFile data("test.txt");
    if(data.open(QFile::WriteOnly|QFile::Truncate))
    {
        QTextStream out(&data);
        out<<QObject::tr("score:")<<qSetFieldWidth(10)<<left<<90<<endl;


    }
    return 0;
}
