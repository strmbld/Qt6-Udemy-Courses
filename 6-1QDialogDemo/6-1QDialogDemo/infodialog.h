#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::InfoDialog *ui;

    QString m_position;
    QString m_favorite_os;

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();


    QString position() const;
    QString favorite_os() const;

private slots:
    void on_okButton_clicked();
    void on_cancelButton_clicked();

};

#endif // INFODIALOG_H
