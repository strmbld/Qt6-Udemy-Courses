#include <QMessageBox>

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


void Widget::on_myButton_clicked()
{
    // qDebug() << "Clicked!";

//    QMessageBox msgBox;
//    msgBox.setText("Clicked");
//    msgBox.setWindowTitle("MessageBox");
//    msgBox.exec();

    int buttonCode = QMessageBox::information(this, "Message", "Clicked!");
    qDebug() << buttonCode;
}

