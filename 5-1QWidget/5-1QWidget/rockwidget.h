#ifndef ROCKWIDGET_H
#define ROCKWIDGET_H

#include <QWidget>

class RockWidget : public QWidget
{
    Q_OBJECT

private:
    QSize sizeHint()const override; // OS window/widget size 'suggest-er'

public:
    explicit RockWidget(QWidget *parent = nullptr);

private slots:
    void button_clicked();

};

#endif // ROCKWIDGET_H
