#ifndef WIDGET_H
#define WIDGET_H


#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>


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
    void dataReadyToRead();
    void dataReadFinished();

    void on_fetchButton_clicked();

private:
    Ui::Widget *ui;

    QNetworkAccessManager* net_manager;
    QNetworkReply* net_reply;
    QByteArray* m_data_buffer;
};
#endif // WIDGET_H
