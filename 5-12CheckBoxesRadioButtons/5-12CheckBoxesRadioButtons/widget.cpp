#include <QButtonGroup>

#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // checkboxes group emulating radiobutton (exclusiveness effect)
    QButtonGroup* buttonGroup1 = new QButtonGroup(this);
    buttonGroup1->addButton(ui->windowsCheckBox);
    buttonGroup1->addButton(ui->macCheckBox);
    buttonGroup1->addButton(ui->linuxCheckBox);
    buttonGroup1->setExclusive(true); // !
    // this has drawback - you can't uncheck checked checkbox anymore by another click
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_windowsCheckBox_toggled(bool checked)
{
    if(checked) {
        qDebug() << "Windows checkbox is checked!";

        return;
    }

    qDebug() << "Windows checkbox is unchecked!";
}

void Widget::on_beerCheckBox_toggled(bool checked)
{
    if(checked) {
        qDebug() << "Beer checkbox is checked!";

        return;
    }

    qDebug() << "Beer checkbox is unchecked!";
}

void Widget::on_grabDataButton_clicked()
{
    if(ui->beerCheckBox->isChecked()) {
        qDebug() << "Beer checkbox is checked!";

        return;
    }

    qDebug() << "Beer checkbox is unchecked!";
}

void Widget::on_setDataButton_clicked()
{
    ui->beerCheckBox->setChecked(true);
}

