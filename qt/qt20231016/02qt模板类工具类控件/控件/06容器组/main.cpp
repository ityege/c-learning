#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QTableView>

//创建窗口
void test1(){

    QWidget *window=new QWidget();
    window->resize(320,240);
    window->show();

    QPushButton *button=new QPushButton("点击这里",window);
    button->move(100,100);
    button->show();

}

//使用布局
void test2(){
    QWidget *window=new QWidget();
    window->resize(320,240);
    window->show();

    QLabel *label= new QLabel("姓名:");
    QLineEdit *lineEdit = new QLineEdit();
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    window->setLayout(layout);
}

void test3(){
    QWidget *window=new QWidget();
    window->resize(320,240);
    window->show();

    QLabel *queryLabel = new QLabel("查询:");
    QLineEdit *queryEdit = new QLineEdit();
    QTableView *resultView = new QTableView();

    //QHBoxLayout 是 Qt 中的一个布局管理器，用于在水平方向上进行部件的布局。
    QHBoxLayout *queryLayout = new QHBoxLayout();
    queryLayout->addWidget(queryLabel);
    queryLayout->addWidget(queryEdit);
    //布局管理器可以嵌套
    //QVBoxLayout 是 Qt 中的一个布局管理器，用于在垂直方向上进行部件的布局。
    QVBoxLayout *mainLayout = new QVBoxLayout ();
    mainLayout->addLayout(queryLayout);
    mainLayout->addWidget(resultView);
    window->setLayout(mainLayout);
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    test3();
    return a.exec();
}
