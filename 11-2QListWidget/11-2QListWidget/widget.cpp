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
    // qDebug() << "count(): " << ui->mListWidget->count();

    for (unsigned int i{}; i < ui->mListWidget->count(); ++i) {
        // as QListWidget is pre-built it contains own Model and convenient methods
        // qDebug() << ui->mListWidget->item(i)->text();

        // but it is also possible to dig into implementation like going down here
        // from high-level item(i)->text() abstraction to low-level item(i)->data(int)
        QListWidgetItem* item_ptr = ui->mListWidget->item(i);

        // w/e inner Qt usage but while having pretty regular setters
        // there is only single getter data()
        // by sending int/enum_member you get concrete ListWidgetItem field
        // like to get ListWidgetItem.Display you should call data(0)
        // or for ListWidgetItem.Tooltip - data(3);
        // no idea about such OP getter or '1 method to get all class fields'
        // also this getter returns QVariant abstract data for further interpretation
        QVariant data = item_ptr->data(Qt::DisplayRole);
        qDebug() << data.toString();

        item_ptr->setToolTip("Elem#" + QString::number(i));
        data = item_ptr->data(Qt::ToolTipRole);
        qDebug() << data.toString();
    }
}

void Widget::on_addItemButton_clicked()
{
    ui->mListWidget->addItem("hello_there");
}
