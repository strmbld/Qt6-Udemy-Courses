#include <QCoreApplication>
#include <Qdate>
#include <QRect>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Goodbye World!";

    qDebug() << "Date: " << QDate::currentDate();
    qDebug() << "Types: " << QString("String") << QChar('x') << QRect(0, 10, 50, 40);

    return a.exec();
}
