#include <QFileDialog>
#include <QMessageBox>

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


void Widget::on_writeButton_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save As");

    if(filename.isEmpty()) return;

    QFile file(filename);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) return;

    QTextStream out(&file);
    out << ui->textEdit->toPlainText() << '\n';

    file.close();
}


void Widget::on_readButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open File");

    if(filename.isEmpty()) return;

    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QTextStream in(&file);
    QString fileTextContent;
    QString line = in.readLine();
    // more regular loop with !in.atEnd() works too
    while (!line.isNull()) {
        fileTextContent.append(line);
        line = in.readLine();
    }

    file.close();

    ui->textEdit->clear();
    ui->textEdit->setPlainText(fileTextContent);
}


void Widget::on_copyButton_clicked()
{
    QString src_filename = ui->sourceLineEdit->text();
    QString dest_filename = ui->destLineEdit->text();

    if(src_filename.isEmpty() || dest_filename.isEmpty()) return;

    QFile file(src_filename);

    if(!file.copy(dest_filename)) {
        QMessageBox::critical(this, "Error", "Copy failed!");

        return;
    }

    QMessageBox::information(this, "Success", "Copy successful!");

    file.close();
}


void Widget::on_selectFileButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose File");

    if(filename.isEmpty()) return;

    ui->sourceLineEdit->setText(filename);
}
