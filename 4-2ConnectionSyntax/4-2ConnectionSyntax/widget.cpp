#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // UI Connections setup

    // SIGNAL ~ event; SLOT ~ callback

    // (btw generated code is ugly; only puts generated names in private slots in header file and implementation here
    // but naming is terrible and shouldn't be changed for automatic parsing)

    // String notation
    // connect(ui->myButton, SIGNAL(clicked()), this, SLOT(change_text()));

    // Functor notation:
    // with regular slots
    // connect(ui->myButton, &QPushButton::clicked, this, &Widget::change_text);
    // with lambda
    connect(ui->myButton, &QPushButton::clicked, [=](){ ui->myLabel->setText("Changed with lambda"); });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_text()
{
    ui->myLabel->setText("Changed text");
}

