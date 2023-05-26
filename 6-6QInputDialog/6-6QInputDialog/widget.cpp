#include <QInputDialog>

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


void Widget::on_clickButton_clicked()
{
    // ~QDoubleSpinBox
//    bool ok;
//    double d = QInputDialog::getDouble(this, "getDouble()",
//                                       "Amount: ", 22.8, -1000, 1000, 3, &ok);

//    if(!ok) qDebug() << "Invalid input!";

//    qDebug() << "Input: " << d;

    // ~QComboBox
    QStringList items;
    items << "Spring" << "Summer" << "Fall" << "Winter";

    bool ok;
    QString choice = QInputDialog::getItem(this, "getItem()",
                                           "Season: ", items, 0, false, &ok);

    qDebug() << choice;
}
