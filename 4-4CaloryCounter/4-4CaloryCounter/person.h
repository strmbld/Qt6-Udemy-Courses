#ifndef PERSON_H
#define PERSON_H

#include <QObject>


class Person : public QObject
{
    Q_OBJECT

private:
    double m_weight = 0.0;

public:
    double weight()const { return m_weight; }
    void setWeight(double weight);

//signals:
//    void weightChanged();

};

#endif // PERSON_H
