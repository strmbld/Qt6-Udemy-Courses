#include <QCoreApplication>
#include <QList>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QString> list;

    list << "First string;" << "Second string;" << "Third string;"; // container supports double-shift operator like streams

    list.append("Fourth string;"); // append() way
    list.append("Fifth string;");

    qDebug() << "First elem: " << list[0]; // index access
    qDebug() << "Second elem: " << list[1];
    qDebug() << "Third elem: " << list[2];

    qDebug() << "list.count(): " << list.count(); // container size/length
    qDebug() << "list.size(): " << list.size(); // container size/length

    for (int i = 0; i < list.count(); ++i) {
        qDebug() << list[i];
    }

    for (int i = 0; i < list.size(); ++i) {
        qDebug() << "Elem at index " << i << " is " << list.at(i);
    }

    return a.exec();
}
