#include "form.h"
#include "ui_form.h"
#include "QTableWidget"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    Creation2();
}

Form::~Form()
{
    delete ui;
}

void Form::Creation2()
{
    QTableWidget table1(4,3);
    table1.setGeometry(QRect(0,0,300,250));
    table1.show();
    //table1.exec();
}
