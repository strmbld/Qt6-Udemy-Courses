#include <QNetworkReply>

#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    net_manager = new QNetworkAccessManager(this);
    net_reply = nullptr;
    m_data_buffer = new QByteArray();

    QNetworkRequest request;
    // request.setUrl(QUrl("https://www.qt.io"));
    request.setUrl(QUrl("https://www.github.com"));

    net_reply = net_manager->get(request);

    // connect(net_reply, &QIODevice::readyRead, this, &Widget::dataReadyToRead);
    connect(net_reply, &QIODevice::readyRead, [=](){ test(&Widget::dataReadyToRead); });
    connect(net_reply, &QNetworkReply::finished, this, &Widget::dataReadFinished);
}

Widget::~Widget()
{
    delete m_data_buffer;
    delete ui;
}


void Widget::dataReadyToRead()
{
    qDebug() << "New data available!";
    m_data_buffer->append(net_reply->readAll());
}

void Widget::dataReadFinished()
{
    if(net_reply->error()) {
        qDebug() << "Error: " << QString(*m_data_buffer);

        return;
    }

    ui->textEdit->setPlainText(QString(*m_data_buffer));
}

void Widget::test(void (Widget::*func)())
{
    qDebug() << "test()";
    // dataReadyToRead();
    (*this.*func)();
}

