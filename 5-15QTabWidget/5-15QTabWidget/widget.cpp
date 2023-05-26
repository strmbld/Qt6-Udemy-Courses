#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    // widget for custom page in tab widget
    QWidget* widgetForAnotherTab = new QWidget(this);

    QVBoxLayout* layout = new QVBoxLayout(widgetForAnotherTab);

    layout->addWidget(new QPushButton("Button1", widgetForAnotherTab));
    layout->addWidget(new QPushButton("Button2", widgetForAnotherTab));
    layout->addWidget(new QPushButton("Button3", widgetForAnotherTab));
    QPushButton* button4 = new QPushButton("Button4", widgetForAnotherTab);
    connect(button4, &QPushButton::clicked, [=](){ qDebug() << "Button4 from custom tab is clicked!"; });

    layout->addWidget(button4);
    layout->addSpacerItem(new QSpacerItem(100, 200));

    ui->tabWidget->insertTab(4, widgetForAnotherTab, "Tab 4");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_3_clicked()
{
    qDebug() << "Tab 3 button clicked!";
}

