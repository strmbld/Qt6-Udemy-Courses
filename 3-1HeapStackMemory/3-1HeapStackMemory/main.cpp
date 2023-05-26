#include <QCoreApplication>


#include "house.h"


void do_things() {
    // Stack allocation
    House h1(nullptr, "First");
    h1.show();
    // Heap allocation
    House* p_h2 = new House(nullptr, "Second");
    p_h2->show();
    delete p_h2;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    do_things();

    qDebug() << "Done!";

    return a.exec();
}
