#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setHeaderLabels(QStringList() << "Id" << "Name");

    QTreeWidgetItem* item1 = new QTreeWidgetItem(ui->treeWidget);
    item1->setText(0, "11");
    item1->setText(1, "some text");

    QTreeWidgetItem* item2 = new QTreeWidgetItem(ui->treeWidget);
    item2->setText(0, "22");
    item2->setText(1, "some text2");

    QTreeWidgetItem* item3 = new QTreeWidgetItem(item2); // or empty constructor with calling later item2->addChild(item3);
    item3->setText(0, "33");
    item3->setText(1, "some text3");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_listItemsButton_clicked()
{
    // too lazy to fix this mess; after surgery after all
    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); ++i) {
        auto item = ui->treeWidget->topLevelItem(i);

        if(item) {
            qDebug() << item->data(0, Qt::DisplayRole).toString() << ", "
                     << item->data(1, Qt::DisplayRole).toString();

            if(item->childCount() != 0) {
                for (int j = 0; j < item->childCount(); ++j) {
                    qDebug() << "---" << item->child(j)->data(0, Qt::DisplayRole).toString() << ", "
                                      << item->child(j)->data(1, Qt::DisplayRole).toString();
                }
            }
        }
    }
}
