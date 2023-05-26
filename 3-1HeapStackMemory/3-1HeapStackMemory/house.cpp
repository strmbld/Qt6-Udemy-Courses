#include <QDebug>

#include "house.h"


House::House(QObject *parent, const QString &desc)
    : QObject(parent), m_desc(desc)
{
    qDebug() << "House object constructed!";
}

House::~House()
{
    qDebug() << "House object: " << m_desc << " is about to die";
}


void House::show() const
{
    qDebug() << "House: " << m_desc;
}
