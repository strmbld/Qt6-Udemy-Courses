#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Setup Random and secret number
    std::srand(std::time(nullptr));
    secret_number = std::rand() % 10 + 1; // enforce [1;10] range
    // qDebug() << "Generated Secret number: " << secret_number;

    // Setup UI
    ui->startOverButton->setDisabled(true);
    ui->messageLabel->setText(""); // or clear()
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_guessButton_clicked()
{
    // qDebug() << "Guess Button clicked";

    guess_number = ui->guessNumberSpinBox->value();
    // qDebug() << "User Guess number: " << guess_number; // QString::number(guess_number)

    if(guess_number == secret_number){
        ui->messageLabel->setText(END);
        // Update buttons
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);

        return;
    }

    return guess_number > secret_number
              ? ui->messageLabel->setText(GUESS_HIGHER)
              : ui->messageLabel->setText(GUESS_LOWER);
}

void Widget::on_startOverButton_clicked()
{
    // qDebug() << "StartOver Button clicked";

    // reset UI
    ui->guessButton->setDisabled(false);
    ui->startOverButton->setDisabled(true);
    ui->guessNumberSpinBox->setValue(1);
    //ui->messageLabel->setText("");
    ui->messageLabel->clear();
    // generate new secret number
    secret_number = rand() % 10 + 1;
}

