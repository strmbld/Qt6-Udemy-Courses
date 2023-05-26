#include <QDir>
#include <QMessageBox>
#include <QFileDialog>

#include "widget.h"
#include "./ui_widget.h"


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


void Widget::on_chooseDirButton_clicked()
{
    QString foldername = QFileDialog::getExistingDirectory(this, "Choose Folder");

    if(foldername.isEmpty()) {
        QMessageBox::critical(this, "Error", "Path is empty!");

        return;
    }

    ui->mLineEdit->setText(foldername);
}

void Widget::on_createDirButton_clicked()
{
    QString dirPath = ui->mLineEdit->text();

    if(dirPath.isEmpty()) {
        QMessageBox::critical(this, "Error", "Path is empty!");

        return;
    }

    QDir dir(dirPath);

    if(dir.exists()) {
        QMessageBox::warning(this, "Warning", "Directory already exists!");

        return;
    }

    bool ret = dir.mkpath(dirPath);

    if(!ret) {
        QMessageBox::critical(this, "Error", "Something went wrong");

        return;
    }

    QMessageBox::information(this, "Success", "Directory created!");
}

void Widget::on_dirExistsButton_clicked()
{
    QString dirPath = ui->mLineEdit->text();

    if(dirPath.isEmpty()) {
        QMessageBox::critical(this, "Error", "Path is empty!");

        return;
    }

    QDir dir(dirPath);

    if(!dir.exists()) {
        QMessageBox::warning(this, "Information", "Directory doesn't exist");

        return;
    }

    QMessageBox::information(this, "Information", "Directory exists");
}

void Widget::on_dirOrFileButton_clicked()
{
    if(ui->mListWidget->count() == 0) {
        QMessageBox::critical(this, "Error", "Load something into list!!!");

        return;
    }

    QFileInfo fileInfo(ui->mListWidget->currentItem()->text());

    if(fileInfo.isDir()) {
        QMessageBox::information(this, "Information", "This is a directory");

        return;
    }

    if(fileInfo.isFile()) {
        QMessageBox::information(this, "Information", "This is a file");

        return;
    }

    QMessageBox::information(this, "Information", "This is something else");
}

void Widget::on_folderContentsButton_clicked()
{
    ui->mListWidget->clear();

    QString dirPath = ui->mLineEdit->text();

    if(dirPath.isEmpty()) {
        QMessageBox::critical(this, "Error", "Path is empty!");

        return;
    }

    QDir dir(dirPath);

    QList<QFileInfo> file_list = dir.entryInfoList();

    for (int i = 0; i < file_list.count(); ++i) {
        ui->mListWidget->addItem(file_list[i].absoluteFilePath()); // ofc [0] is '.' and [1] is '..'
    }
}
