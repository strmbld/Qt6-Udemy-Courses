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
    // Smart pointers
    // Unique ptr
    std::unique_ptr<House> up_h3 { new House(nullptr, "Third") };
    up_h3->show();
    // Shared ptr
    std::shared_ptr<House> sp_h4 { new House(nullptr, "Fourth") };
    sp_h4->show();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    do_things();

    qDebug() << "Done!";

    qDebug() << sizeof(std::unique_ptr<House>);
    qDebug() << sizeof(std::shared_ptr<House>);

    return a.exec();
}
