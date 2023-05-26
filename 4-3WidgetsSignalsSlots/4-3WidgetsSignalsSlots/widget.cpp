#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    // String notation:
//    auto hBar_signal = SIGNAL(valueChanged(int));
//    // with default built-in signal and slot; no additional code required!
//    connect(ui->horizontalSlider, hBar_signal, ui->progressBar, SLOT(setValue(int)));
//    // with custom callback(slot); requires code - private slots field and slot declaration in header file, slot function implementation in cpp
//    connect(ui->horizontalSlider, hBar_signal, this, SLOT(respond(int)));

    // Functor notation:
    // with regular slots
//    connect(ui->horizontalSlider, &QSlider::valueChanged, ui->progressBar, &QProgressBar::setValue);
//    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &Widget::respond);
    // with lambdas
    connect(ui->horizontalSlider, &QSlider::valueChanged, [=](){
        ui->progressBar->setValue(ui->horizontalSlider->value());
        respond(ui->horizontalSlider->value());}
    );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::respond(int val)
{
    qDebug() << val;
}

