#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_guessButton_clicked();
    void on_startOverButton_clicked();

private:
    Ui::Widget *ui;

    int secret_number;
    int guess_number;

    const QString END = "Gz gameover";
    const QString GUESS_HIGHER = "Your guess is higher than that";
    const QString GUESS_LOWER = "Your guess is lower than that";
};

#endif // WIDGET_H
