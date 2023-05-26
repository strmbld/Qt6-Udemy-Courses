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


QString InfoDialog::position() const
{
    return m_position;
}

QString InfoDialog::favorite_os() const
{
    return m_favorite_os;
}

void InfoDialog::on_okButton_clicked()
{
    QString position = ui->positionLineEdit->text();

    if(position.isEmpty()) {
        reject();

        return;
    }

    m_position = position;

    if(ui->windowsRadioButton->isChecked()) {
        m_favorite_os = ui->windowsRadioButton->text();

        accept();

        return;
    }

    if(ui->linuxRadioButton->isChecked()) {
        m_favorite_os = ui->linuxRadioButton->text();

        accept();

        return;
    }

    m_favorite_os = ui->macRadioButton->text();

    accept();
}

void InfoDialog::on_cancelButton_clicked()
{
    reject();
}
