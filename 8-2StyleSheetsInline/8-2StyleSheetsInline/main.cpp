#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // setting stylesheet on application level
    // a.setStyleSheet("QPushButton{background-color : yellow; color : red;}"); // QPushButton notation is selector
    Widget w;
    w.show();
    return a.exec();
}
