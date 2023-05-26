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


void Widget::on_chooseButton_clicked()
{
//    QString dir = QFileDialog::getExistingDirectory(this, "Open Directory",
//                                                    "C:/",
//                                                    QFileDialog::ShowDirsOnly
//                                                    | QFileDialog::DontResolveSymlinks);

//    qDebug() << dir;

//    QString fileName = QFileDialog::getOpenFileName(this, "Open File",
//                                                    "C:/",
//                                                    "Images (*.png *.xpm *jpg)");
//    qDebug() << fileName;

//    QStringList files = QFileDialog::getOpenFileNames(this, "Select one or more files to open",
//                                                      "C:/",
//                                                      "Images (*.png *.jpg);;Text files (*.txt)");

//    qDebug() << files;

    QString fileNameToSave = QFileDialog::getSaveFileName(this, "Save File",
                                                          "C:/untitled.png",
                                                          "Images (*.png *.jpg");

    qDebug() << fileNameToSave;
}
