#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>


#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , net_manager(new QNetworkAccessManager(this))
    , net_reply(nullptr)
    , m_data_buffer(new QByteArray())
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete m_data_buffer;
    delete ui;
}


void Widget::on_fetchButton_clicked()
{
    const QUrl API_ENDPOINT("https://jsonplaceholder.typicode.com/posts");

    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    net_reply = net_manager->get(request);

    connect(net_reply, &QIODevice::readyRead, this, &Widget::dataReadyToRead);
    connect(net_reply, &QNetworkReply::finished, this, &Widget::dataReadFinished);
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

    // qDebug() << "Data fetch finished: " << QString(*m_data_buffer);

    QJsonDocument jsonDoc = QJsonDocument::fromJson(*m_data_buffer);

    // for js objects
    // QJsonDocument objectDoc = QJsonDocument::fromJson(*m_data_buffer);
    // QJsonObject jsObject = objectDoc.toVariant().toJsonObject();

    QJsonArray jsonArray = jsonDoc.array();
    // person = {name:"John", age:31, city:"New York"};
    for (int i = 0; i < jsonArray.count(); ++i) {
        QJsonObject jsObject = jsonArray[i].toObject();
        QVariantMap map = jsObject.toVariantMap();
        QString userId = map["userId"].toString();
        QString id = map["id"].toString();
        QString title = map["title"].toString();
        QString body = map["body"].toString();

        ui->mListWidget->addItem("#" + QString::number(i) + " " + userId + " " + id + " " + title + " " + body);
    }
}
