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


void Widget::on_listItemsButton_clicked()
{
    for (int i = 0; i < ui->mTableWidget->rowCount(); ++i) {
        for (int j = 0; j < ui->mTableWidget->columnCount(); ++j) {
            auto item_ptr = ui->mTableWidget->item(i, j); // possible nullptr

            if(!item_ptr) {
                qDebug() << "No Data";

                continue;
            }

            QVariant data = item_ptr->data(Qt::DisplayRole);
            qDebug() << data.toString();
        }
    }
}

void Widget::on_setItemButton_clicked()
{
    ui->mTableWidget->insertRow(ui->mTableWidget->rowCount());
    ui->mTableWidget->insertColumn(ui->mTableWidget->columnCount());

    QTableWidgetItem* newItem = new QTableWidgetItem("hello_there");
    ui->mTableWidget->setItem(ui->mTableWidget->rowCount() - 1, ui->mTableWidget->columnCount() - 1, newItem);
}
