#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // setup label styling
    // just 'boilerplate' to make background color changes work
    ui->mLabel->setAutoFillBackground(true);
    // working with Palette boilerplate (retrieve, change, apply)
    // retrieve label palette
    QPalette palette = ui->mLabel->palette();
    // modify this palette
    palette.setColor(QPalette::Window, Qt::blue); // window~background
    palette.setColor(QPalette::WindowText, Qt::red); // windowText~foreground~text color
    // re-apply palette for changes
    ui->mLabel->setPalette(palette);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_activeButton_clicked()
{
    QPalette::ColorGroup activeButtonColorGroup = ui->activeButton->palette().currentColorGroup();
    QPalette::ColorGroup disabledButtonColorGroup = ui->disabledButton->palette().currentColorGroup();

    qDebug() << "Active button color group: " << activeButtonColorGroup;
    qDebug() << "Disabled button color group: " << disabledButtonColorGroup;
}
