#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>
#include <QAbstractButton>


namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::InfoDialog *ui;

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

private slots:

    void on_buttonBox_clicked(QAbstractButton *button);
};

#endif // INFODIALOG_H
