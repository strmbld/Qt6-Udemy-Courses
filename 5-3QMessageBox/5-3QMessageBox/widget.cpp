#include <QPushButton>
#include <QDebug>
#include <QMessageBox>

#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* button = new QPushButton(this);
    button->setText("Click");
    button->move(200, 200);
    // connect(button, &QPushButton::clicked, [=](){ hard_way(); });
    // connect(button, &QPushButton::clicked, [=](){ easy_critical(); });
    // connect(button, &QPushButton::clicked, [=](){ easy_information(); });
    connect(button, &QPushButton::clicked, [=](){ with_decisions(); });
}

Widget::~Widget()
{
}


void Widget::with_decisions()
{
    int res = QMessageBox::warning(this, "Warning Message Title", "Something happened. This is the warning.", QMessageBox::Ok | QMessageBox::Cancel);

    if(res == QMessageBox::Ok)
        QMessageBox::information(this,"Clicked Ok", "Button Code: " + QString::number(res), QMessageBox::Ok);

    if(res == QMessageBox::Cancel)
        QMessageBox::information(this,"Clicked Cancel", "Button Code: " + QString::number(res), QMessageBox::Ok);
}

void Widget::easy_information()
{
    int res = QMessageBox::information(this, "Message Title", "Something happened", QMessageBox::Ok | QMessageBox::Cancel);
}

void Widget::easy_critical()
{
    int res = QMessageBox::critical(this, "Message Title", "Something happened", QMessageBox::Ok | QMessageBox::Cancel);
}

void Widget::hard_way()
{
    QMessageBox msgBox;
    msgBox.setMinimumSize(700, 200);
    msgBox.setWindowTitle("Message Title");
    msgBox.setText("Something happend");
    msgBox.setInformativeText("Wanna do something about this?");
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);

    int res = msgBox.exec();
}
