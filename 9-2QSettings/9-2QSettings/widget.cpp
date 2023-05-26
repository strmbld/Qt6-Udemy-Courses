#include <QSettings>
#include <QColorDialog>

#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // init with black color
    for (int i = 0; i < 9; ++i) {
        m_color_list.append(Qt::black);
    }

    // on_loadButton_clicked();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::save_color(QString key, QColor color)
{
    int red = color.red();
    int green = color.green();
    int blue = color.blue();

    QSettings settings("ThisApp", "MySettings");

    // boilerplate for settings:
    // settings("company/app_name", "owner/app_name");
    // beginGroup("group_name")
    // setValue(key, value)  -- beware QVariant value type when load/read settings
    // ...
    // endgroup();

    settings.beginGroup("ButtonColor");
    settings.setValue(key + "r", red);
    settings.setValue(key + "g", green);
    settings.setValue(key + "b", blue);
    settings.endGroup();
}

QColor Widget::load_color(QString key)
{
    int red;
    int green;
    int blue;

    QSettings settings("ThisApp", "MySettings");

    settings.beginGroup("ButtonColor");

    red = settings.value(key + "r", QVariant(0)).toInt();
    green = settings.value(key + "g", QVariant(0)).toInt();
    blue = settings.value(key + "b", QVariant(0)).toInt();

    settings.endGroup();

    return QColor(red, green, blue);
}

void Widget::set_loaded_color(QString key, int index, QPushButton *button)
{
    QColor color = load_color(key);
    m_color_list[index] = color;
    QString css = QString("background-color : %1").arg(color.name());
    button->setStyleSheet(css);
}

void Widget::on_buttonOne_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[0], this, "Choose Background Color");

    if(!color.isValid()) {

        return;
    }

    m_color_list[0] = color; // save changes in memory
    QString css = QString("background-color : %1").arg(color.name());
    ui->buttonOne->setStyleSheet(css);
}

void Widget::on_buttonTwo_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[1], this, "Choose Background Color");

    if(!color.isValid()) {

        return;
    }

    m_color_list[1] = color; // save changes in memory
    QString css = QString("background-color : %1").arg(color.name());
    ui->buttonTwo->setStyleSheet(css);
}

void Widget::on_buttonThree_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[2], this, "Choose Background Color");

    if(!color.isValid()) {

        return;
    }

    m_color_list[2] = color; // save changes in memory
    QString css = QString("background-color : %1").arg(color.name());
    ui->buttonThree->setStyleSheet(css);
}

void Widget::on_buttonFour_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[3], this, "Choose Background Color");

    if(!color.isValid()) {

        return;
    }

    m_color_list[3] = color; // save changes in memory
    QString css = QString("background-color : %1").arg(color.name());
    ui->buttonFour->setStyleSheet(css);
}

void Widget::on_buttonFive_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[4], this, "Choose Background Color");

    if(!color.isValid()) {

        return;
    }

    m_color_list[4] = color; // save changes in memory
    QString css = QString("background-color : %1").arg(color.name());
    ui->buttonFive->setStyleSheet(css);
}

void Widget::on_buttonSix_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[5], this, "Choose Background Color");

    if(!color.isValid()) {

        return;
    }

    m_color_list[5] = color; // save changes in memory
    QString css = QString("background-color : %1").arg(color.name());
    ui->buttonSix->setStyleSheet(css);
}

void Widget::on_buttonSeven_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[6], this, "Choose Background Color");

    if(!color.isValid()) {

        return;
    }

    m_color_list[6] = color; // save changes in memory
    QString css = QString("background-color : %1").arg(color.name());
    ui->buttonSeven->setStyleSheet(css);
}

void Widget::on_buttonEight_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[7], this, "Choose Background Color");

    if(!color.isValid()) {

        return;
    }

    m_color_list[7] = color; // save changes in memory
    QString css = QString("background-color : %1").arg(color.name());
    ui->buttonEight->setStyleSheet(css);
}

void Widget::on_buttonNine_clicked()
{
    QColor color = QColorDialog::getColor(m_color_list[8], this, "Choose Background Color");

    if(!color.isValid()) {

        return;
    }

    m_color_list[8] = color; // save changes in memory
    QString css = QString("background-color : %1").arg(color.name());
    ui->buttonNine->setStyleSheet(css);
}

void Widget::on_saveButton_clicked()
{
    save_color("buttonOne", m_color_list[0]);
    save_color("buttonTwo", m_color_list[1]);
    save_color("buttonThree", m_color_list[2]);
    save_color("buttonFour", m_color_list[3]);
    save_color("buttonFive", m_color_list[4]);
    save_color("buttonSix", m_color_list[5]);
    save_color("buttonSeven", m_color_list[6]);
    save_color("buttonEight", m_color_list[7]);
    save_color("buttonNine", m_color_list[8]);
}

void Widget::on_loadButton_clicked()
{
    set_loaded_color("buttonOne", 0, ui->buttonOne);
    set_loaded_color("buttonTwo", 1, ui->buttonTwo);
    set_loaded_color("buttonThree", 2, ui->buttonThree);
    set_loaded_color("buttonFour", 3, ui->buttonFour);
    set_loaded_color("buttonFive", 4, ui->buttonFive);
    set_loaded_color("buttonSix", 5, ui->buttonSix);
    set_loaded_color("buttonSeven", 6, ui->buttonSeven);
    set_loaded_color("buttonEight", 7, ui->buttonEight);
    set_loaded_color("buttonNine", 8, ui->buttonNine);
}
