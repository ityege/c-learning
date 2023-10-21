#include <QApplication>

#include<Qsplitter>
#include<QTextEdit>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    QFont font("ZYSong18030",12);
    a.setFont(font);
    //主分割窗口
    QSplitter *splitterMain =new QSplitter(Qt::Horizontal,0);//水平分割
    QTextEdit *textLeft =new QTextEdit(QObject::tr("Left Widget"),splitterMain);
    textLeft->setAlignment(Qt::AlignCenter);//设定QTextEdit中文字的对齐方式
    //右部分分制窗口
    QSplitter *splitterRight=new QSplitter(Qt::Vertical,splitterMain);
    //splitterRight->setOpaqueResize(false):
    //调用 setOpaqueResize(bool)方法用于设定分割窗口的分割条在拖曳时是否实时更新显示，
    //若设为 true 则实时更新显示，若设为 false 则在拖曳时只显示一条灰色的粗线条，
    //在拖曳到位并释放鼠标后再显示分割条。默认设置为 true。
    splitterRight->setOpaqueResize(false);
    QTextEdit *textUp =new QTextEdit(QObject::tr("Top Widget"),splitterRight);
    textUp->setAlignment(Qt::AlignCenter);
    QTextEdit *textBottom=new QTextEdit(QObject::tr("Bottom Widget"),splitterRight);
    textBottom->setAlignment(Qt::AlignCenter);
    //splitterMain->setStretchFactor(1,1):
    //调用 setStretchFactor()方法用于设定可伸缩控件，
    //它的第 1个参数用于指定设置的控件序号，控件序号按插入的先后次序从0起依次编号:
    //第2个参数为大于0的值，表示此控件为可伸缩控件。
    //此实例中设定右部分分割窗口为可伸缩控件，当整个对话框的宽度发生改变时，
    //左部的文件编辑框宽度保持不变，右部的分割窗口宽度随整个对话框大小的改变进行调整。
    splitterMain->setStretchFactor(1,1);
    splitterMain->setWindowTitle(QObject::tr("Splitter"));
    splitterMain->show();

    return a.exec();
}
