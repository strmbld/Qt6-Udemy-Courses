#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // First Name form field
    QLabel* first_name_label = new QLabel("First Name", this);
    first_name_label->setMinimumSize(70, 50);
    first_name_label->move(10, 10);

    QLineEdit* first_name_line_edit = new QLineEdit(this);
    first_name_line_edit->setMinimumSize(200, 50);
    first_name_line_edit->move(100, 10);
    // Last Name form field
    QLabel* last_name_label = new QLabel("Last Name", this);
    last_name_label->setMinimumSize(70, 50);
    last_name_label->move(10, 70);

    QLineEdit* last_name_line_edit = new QLineEdit(this);
    last_name_line_edit->setMinimumSize(200, 50);
    last_name_line_edit->move(100, 70);
    // City form field
    QLabel* city_label = new QLabel("City", this);
    city_label->setMinimumSize(70, 50);
    city_label->move(10, 130);

    QLineEdit* city_line_edit = new QLineEdit(this);
    city_line_edit->setMinimumSize(200, 50);
    city_line_edit->move(100, 130);
    // Submit button
    QFont button_font("Times", 20, QFont::Bold);
    QPushButton* submit_button = new QPushButton("Submit", this);
    submit_button->setFont(button_font);
    submit_button->move(100, 190);
    connect(submit_button, &QPushButton::clicked, [=](){
       QString first_name = first_name_line_edit->text();
       QString last_name = last_name_line_edit->text();
       QString city = city_line_edit->text();

       if(first_name.isEmpty() || last_name.isEmpty() || city.isEmpty())
       {
           qDebug() << "One of the fields is empty!";

           return;
       }

       qDebug() << "First Name: " << first_name << Qt::endl
                << "Last Name: " << last_name << Qt::endl
                << "City: " << city << Qt::endl
                   ;
    });

    // QLineEdit signals interaction
    // cursorPositionChanged
    connect(first_name_line_edit, &QLineEdit::cursorPositionChanged, [=](){
        qDebug() << "Current cursor position: " << first_name_line_edit->cursorPosition();
    });
    // editingFinished
    connect(first_name_line_edit, &QLineEdit::editingFinished, [=](){
        qDebug() << "Editing finished";
    });
    // returnPressed
    connect(first_name_line_edit, &QLineEdit::returnPressed, [=](){
        qDebug() << "Return pressed!";
    });
    // selectionChanged
    connect(first_name_line_edit, &QLineEdit::selectionChanged, [=](){
        qDebug() << "Selection Changed!";
    });
    // textChanged
    connect(first_name_line_edit, &QLineEdit::textChanged, [=](){
        qDebug() << "Text changed to: " << first_name_line_edit->text();
    });
    // textEdited
    connect(first_name_line_edit, &QLineEdit::textEdited, [=](){
        qDebug() << "Text edited and changed to: " << first_name_line_edit->text();
    });

    // last_name_line_edit->setText("Enter your last name");

    first_name_line_edit->setPlaceholderText("First Name");
    last_name_line_edit->setPlaceholderText("Last Name");
    city_line_edit->setPlaceholderText("Your city");
}

Widget::~Widget()
{
}

