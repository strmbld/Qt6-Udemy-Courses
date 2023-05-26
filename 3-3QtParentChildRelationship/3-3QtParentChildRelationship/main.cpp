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
    // Qt Parent Child relationship
    // derivation from QObject (macro btw) class allows to leverage automatic "tree-view" destruction in Qt
    House* p_parent1 = new House(nullptr, "Parent1");
    p_parent1->show();
    House* p_child1 = new House(p_parent1, "Child1");
    p_child1->show();
    House* p_child2 = new House(p_child1, "Grandchild1");
    p_child2->show();
    delete p_parent1; // single delete on root elem
    // combination with unique_ptr to get rid of 'delete' at all
    std::unique_ptr<House> up_parent2 { new House(nullptr, "Parent2") };
    up_parent2->show();
    House* p_child3 = new House(up_parent2.get(), "Child3");
    p_child3->show();
    House* p_child4 = new House(p_child3, "Grandchild4");
    p_child4->show();
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
