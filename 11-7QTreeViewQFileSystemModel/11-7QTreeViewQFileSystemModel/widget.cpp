#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QString path = "E:/";

//    dir_model = new QFileSystemModel(this);
//    dir_model->setFilter(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);
//    dir_model->setRootPath(path);

//    ui->mTreeView->setModel(dir_model);
//    ui->mListView->setModel(dir_model); // useless here

    standard_item_tree_model = new QStandardItemModel(this);
    QStandardItem* parentItem = standard_item_tree_model->invisibleRootItem();

    for (int i = 0; i < 4; ++i) {
        QStandardItem* item = new QStandardItem(QString("item %0").arg(i));
        parentItem->appendRow(item);
        parentItem = item;
    }

    ui->mTreeView->setModel(standard_item_tree_model);
    ui->mListView->setModel(standard_item_tree_model);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_readDataButton_clicked()
{
//    qDebug() << "Row count: " << dir_model->rowCount(QModelIndex());
//    qDebug() << "Column count: " << dir_model->columnCount(QModelIndex());
//    auto index = dir_model->index(0, 0, QModelIndex());
//    auto data = index.data(Qt::DisplayRole);
//    qDebug() << "data: " << data.toString();

    qDebug() << "Row count: " << standard_item_tree_model->rowCount(QModelIndex());
    qDebug() << "Column count: " << standard_item_tree_model->columnCount(QModelIndex());
    auto index = standard_item_tree_model->index(0, 0, QModelIndex());
    auto data = index.data(Qt::DisplayRole);
    qDebug() << "data: " << data.toString();
}
