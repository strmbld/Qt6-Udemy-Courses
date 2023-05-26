#ifndef HOUSE_H
#define HOUSE_H

#include <QObject>

class House : public QObject
{
    Q_OBJECT

private:
    QString m_desc;

public:
    explicit House(QObject *parent = nullptr, const QString& desc = "");

    ~House();

    void show()const;

signals:

};

#endif // HOUSE_H
