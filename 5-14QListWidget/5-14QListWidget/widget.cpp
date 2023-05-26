#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection); // default is single

    ui->listWidget->addItem("Item1");
    ui->listWidget->addItem("Item2");
    ui->listWidget->addItem("Item3");

    QStringList list;
    list << "Item4" << "Item5";
    list.append("Item6");
    list.append("Item7");

    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_addButton_clicked()
{
    ui->listWidget->addItem("Another item");
}

void Widget::on_removeButton_clicked()
{
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void Widget::on_showSelectedButton_clicked()
{
    QList<QListWidgetItem*> list = ui->listWidget->selectedItems();

    for (int i = 0; i < list.size(); ++i) {
        qDebug() << "Selected item: " << list[i]->text() << " , row number: " << ui->listWidget->row(list[i]);
    }
}
