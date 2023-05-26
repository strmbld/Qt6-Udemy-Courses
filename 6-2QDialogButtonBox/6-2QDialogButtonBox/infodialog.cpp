#include "infodialog.h"
#include "ui_infodialog.h"


InfoDialog::InfoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoDialog)
{
    ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
    delete ui;
}

void InfoDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    QDialogButtonBox::StandardButton stdButton = ui->buttonBox->standardButton(button);

    if(stdButton == QDialogButtonBox::Ok) {
        accept();

        qDebug() << "Ok button clicked!";

        return;
    }

    if(stdButton == QDialogButtonBox::Save) {
        qDebug() << "Save button clicked!";

        return;
    }

    if(stdButton == QDialogButtonBox::SaveAll) {
        qDebug() << "SaveAll button clicked!";

        return;
    }

    if(stdButton == QDialogButtonBox::Open) {
        qDebug() << "Open button clicked!";

        return;
    }

    if(stdButton == QDialogButtonBox::Cancel) {
        reject();

        qDebug() << "Cancel button clicked!";

        return;
    }
}
