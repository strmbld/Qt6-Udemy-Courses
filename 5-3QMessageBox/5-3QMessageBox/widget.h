#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

private:
    void hard_way();
    void easy_critical();
    void easy_information();
    void with_decisions();

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

};
#endif // WIDGET_H
