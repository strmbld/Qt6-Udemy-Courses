#include "widget.h"
#include "./ui_widget.h"
#include "infodialog.h"


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


void Widget::on_provideInfoButton_clicked()
{
    InfoDialog* dialog = new InfoDialog(this);

    // dialog->exec(); // modal view

    // dialog->show(); // non-modal view

    // modal view
//    auto res = dialog->exec();

//    if(res == QDialog::Rejected) {
//        ui->infoLabel->setText("Dialog has been rejected!");

//        return;
//    }

//    QString position = dialog->position();
//    QString os = dialog->favorite_os();

//    // qDebug() << "Dialog accepted; position: " << position << "; os: " << os;

//    ui->infoLabel->setText("Your position: " + position + "; selected OS: " + os);

    // non-modal view
    dialog->show();

    connect(dialog, &InfoDialog::accepted, [=](){
       QString position = dialog->position();
       QString os = dialog->favorite_os();

       ui->infoLabel->setText("Your position: " + position + "; selected OS: " + os);
    });
    connect(dialog, &InfoDialog::rejected, [=](){
       ui->infoLabel->setText("Dialog has been rejected!");
    });

    // dialog->raise(); ?????????
    // dialog->activateWindow();????????
}
