#include <QMessageBox>
#include <QLabel>
#include <QPushButton>

#include "rockwidget.h"


RockWidget::RockWidget(QWidget *parent)
    : QWidget{parent}
{
    QLabel* label = new QLabel(this);
    label->setText("My label");
    label->move(50, 50);

    QPalette label1Palette;
    label1Palette.setColor(QPalette::Window, Qt::yellow);
    label1Palette.setColor(QPalette::WindowText, Qt::blue);
    QFont label1Font("Times", 20, QFont::Bold);

    QLabel* label1 = new QLabel(this);
    label1->setAutoFillBackground(true);
    label1->setText("Colored label");
    label1->setFont(label1Font);
    label1->setPalette(label1Palette);
    label1->move(100, 100);

    QPalette label2Palette;
    label1Palette.setColor(QPalette::Window, Qt::green);
    label1Palette.setColor(QPalette::WindowText, Qt::black);

    QLabel* label2 = new QLabel(this);
    label2->setAutoFillBackground(true);
    label2->setText("Colored label 2");
    label2->setFont(label1Font);
    label2->setPalette(label2Palette);
    label2->move(100, 150);
    QFont label2Font("Times", 20, QFont::Bold);
    label2->setFont(label2Font);

    QPushButton* button = new QPushButton(this);
    QFont buttonFont("Times", 30, QFont::Bold);
    button->setText("Click");
    button->setFont(buttonFont);
    button->move(100, 250);
    connect(button, SIGNAL(clicked()), this, SLOT(button_clicked()));
}


void RockWidget::button_clicked()
{
   QMessageBox::information(this, "Message", "Button clicked!");
}

QSize RockWidget::sizeHint() const
{
    return QSize(500, 500);
}
