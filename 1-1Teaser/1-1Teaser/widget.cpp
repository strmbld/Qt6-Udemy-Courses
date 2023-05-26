#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_submitButton_clicked()
{
    qDebug() << '\n'
             << "Last Name: " << ui->lastNameLineEdit->text() << '\n'
             << "First Name: " << ui->firstNameLineEdit->text() << '\n'
             << "Message: " << ui->messageTextEdit->toPlainText() << '\n'
                ;
}

