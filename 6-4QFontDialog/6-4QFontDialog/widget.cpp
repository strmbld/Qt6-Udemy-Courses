#include <QFontDialog>

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


void Widget::on_chooseFontButton_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(
                &ok, QFont("Helvetica [Cronyx]", 10), this);

    if(!ok) {
        // dialog has been canceled; font set to initial value (helvetica)
        ui->label->setFont(font);

        return;
    }

    // font set successfully
    ui->label->setFont(font);
}

