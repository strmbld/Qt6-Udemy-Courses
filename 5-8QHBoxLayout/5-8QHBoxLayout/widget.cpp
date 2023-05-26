#include <QHBoxLayout>

#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QHBoxLayout* layout = new QHBoxLayout(this); // setting parent for automatic memory management

    layout->addWidget(ui->oneButton);
    layout->addWidget(ui->twoButton);
    layout->addWidget(ui->threeButton);
    layout->addWidget(ui->fourButton);
    layout->addWidget(ui->fiveButton);

    //setLayout(layout); // this method delegates memory management to runtime if you haven't set parent in new QHBoxLayout(this) call; nothing special most likely, same result
}

Widget::~Widget()
{
    delete ui;
}

