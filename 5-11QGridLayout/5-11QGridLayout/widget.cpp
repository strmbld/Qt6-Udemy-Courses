#include <QGridLayout>

#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QGridLayout* layout = new QGridLayout(this);
    // addWidget(btn, row, column, row_span, column_span)
    // First row
    layout->addWidget(ui->button1, 0, 0);
    layout->addWidget(ui->button2, 0, 1);
    layout->addWidget(ui->button3, 0, 2, 2, 1); // Row span: 2; Column span: 1; had to fix vertical policy in editor
    // Second row
    layout->addWidget(ui->button4, 1, 0);
    layout->addWidget(ui->button5, 1, 1);
    // Third row
    layout->addWidget(ui->button7, 2, 0, 1, 2); // Row span: 1; Column span: 2
    layout->addWidget(ui->button9, 2, 2);
}

Widget::~Widget()
{
    delete ui;
}

