#include <QPixmap>

#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->mTextLabel->move(100, 30);

    QPixmap mImage(":/images/capture.png");
    ui->mImageLabel->move(0, 70);
    ui->mImageLabel->setPixmap(mImage.scaled(400, 400));
}

Widget::~Widget()
{
    delete ui;
}

