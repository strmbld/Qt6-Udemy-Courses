#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new QStringListModel(this);

    QStringList list;
    list << "some_text_1" << "some_text_2" << "some_text_3" << "some_text_4" << "some_text_5";

    model->setStringList(list);

    ui->listView->setModel(model);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_showDataButton_clicked()
{
//    QStringList list = model->stringList();
//    qDebug() << "Current data: " << list;

    // QAbstractItemModel usage
    for (int i = 0; i < model->rowCount(QModelIndex()); ++i) {
        auto index = model->index(i, 0, QModelIndex());
        auto data = model->data(index); // or auto data = index.data(Qt::DisplayRole);
        qDebug() << data.toString();
    }
}
