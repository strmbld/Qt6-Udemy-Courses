#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->comboBox->addItem("Earth");
    ui->comboBox->addItem("Venus");
    ui->comboBox->addItem("Mars");
    ui->comboBox->addItem("Pluto");
    ui->comboBox->addItem("Saturn");

    ui->comboBox->setEditable(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_captureButton_clicked()
{
    qDebug() << "Current item: " << ui->comboBox->currentText() << "; index: " << ui->comboBox->currentIndex();
}

void Widget::on_setButton_clicked()
{
    ui->comboBox->setCurrentIndex(3); // out of range exceptions ofc
}

void Widget::on_listButton_clicked()
{
    qDebug() << "comboBox.count(): " << ui->comboBox->count();

    for (int i = 0; i < ui->comboBox->count(); ++i) {
        qDebug() << i << " - " << ui->comboBox->itemText(i);
    }
}
