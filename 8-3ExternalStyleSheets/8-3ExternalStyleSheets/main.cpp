#include <QApplication>
#include <QFile>

#include "widget.h"


QString readTextFile(QString path)
{
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) return "";

    QTextStream in(&file);

    return in.readAll();
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString css = readTextFile(":/styles/style.css");

    if(css.count() != 0) a.setStyleSheet(css);

    Widget w;
    w.show();
    return a.exec();
}
