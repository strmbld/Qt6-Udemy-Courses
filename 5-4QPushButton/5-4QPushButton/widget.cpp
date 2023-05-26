#include <QPushButton>
#include <QDebug>

#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QFont button_font("Times", 20, QFont::Bold);
    // Clicked signal
    QPushButton* button1 = new QPushButton("Button1", this);
    button1->setMinimumSize(200, 100);
    button1->setFont(button_font);
    connect(button1, &QPushButton::clicked, [=](){ qDebug() << "Button1 clicked!"; });
    // Pressed signal
    QPushButton* button2 = new QPushButton("Button2", this);
    button2->setMinimumSize(200, 100);
    button2->move(205,0);
    button2->setFont(button_font);
    connect(button2, &QPushButton::pressed, [=](){ qDebug() << "Button2 pressed!"; });
    // Released signal
    connect(button2, &QPushButton::released, [=](){ qDebug() << "Button2 released!"; });
}

Widget::~Widget()
{
}

