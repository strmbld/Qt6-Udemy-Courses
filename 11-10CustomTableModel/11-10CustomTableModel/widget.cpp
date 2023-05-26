#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_model = new CustomTableModel(this);

    ui->mListView->setModel(m_model);
    ui->mTableView->setModel(m_model);
    ui->mTreeView->setModel(m_model);
}

Widget::~Widget()
{
    delete ui;
}
