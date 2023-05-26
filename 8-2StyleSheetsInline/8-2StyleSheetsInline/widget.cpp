#include "widget.h"
#include "./ui_widget.h"
#include "somedialog.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // setting stylesheet to one elem
    // ui->clickButton->setStyleSheet("QPushButton{background-color : yellow; color : red;}"); // full notation with selector specified
    ui->clickButton->setStyleSheet("background-color : yellow; color : red;"); // short notation with selector omitted
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_clickButton_clicked()
{
    SomeDialog* dialog = new SomeDialog(this);
    // setting stylesheet on widget level
    dialog->setStyleSheet("QPushButton{background-color : yellow; color : red;}");

    dialog->exec();
}
