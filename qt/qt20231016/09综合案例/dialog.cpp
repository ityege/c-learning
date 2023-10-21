#include "dialog.h"
#include "ui_dialog.h"
#include <QRegExpValidator>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->lineEdit->setValidator(new QRegExpValidator(regExp,this));
    connect(ui->okButton,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(reject()));
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(on_lineEdit_textChanged()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lineEdit_textChanged(){
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}
