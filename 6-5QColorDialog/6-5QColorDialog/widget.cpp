#include <QColorDialog>
#include <QFontDialog>

#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->mLabel->setAutoFillBackground(true);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_textColorButton_clicked()
{
    QPalette palette = ui->mLabel->palette();
    QColor color = palette.color(QPalette::WindowText);
    QColor chosenColor = QColorDialog::getColor(color, this, "Choose text color");

    if(!chosenColor.isValid()) {
        qDebug() << "Invalid color!";

        return;
    }

    palette.setColor(QPalette::WindowText, chosenColor);
    ui->mLabel->setPalette(palette);
}

void Widget::on_backgroundColorButton_clicked()
{
    QPalette palette = ui->mLabel->palette();
    QColor color = palette.color(QPalette::Window);
    QColor chosenColor = QColorDialog::getColor(color, this, "Choose text color");

    if(!chosenColor.isValid()) {
        qDebug() << "Invalid color!";

        return;
    }

    palette.setColor(QPalette::Window, chosenColor);
    ui->mLabel->setPalette(palette);
}

void Widget::on_fontButton_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(
                &ok, QFont("Helvetica [Cronyx]", 10), this);

    if(!ok) {
        // dialog has been canceled; font set to initial value (helvetica)
        // ui->label->setFont(font);

        return;
    }

    // font set successfully
    ui->mLabel->setFont(font);
}
