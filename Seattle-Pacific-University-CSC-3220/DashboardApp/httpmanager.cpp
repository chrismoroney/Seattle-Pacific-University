#include "httpmanager.h"
#include <QPixmap>
#include <QJsonDocument>
#include <QJsonObject>

HTTPManager::HTTPManager(QObject *parent) :
    QObject(parent),
    imageDownloadManager(new QNetworkAccessManager),
    weatherAPIManager(new QNetworkAccessManager),
    iconAPIManager(new QNetworkAccessManager)
{
    connect(imageDownloadManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(ImageDownloadedHandler(QNetworkReply*)));

    connect(weatherAPIManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(WeatherDownloadedHandler(QNetworkReply*)));

    connect(iconAPIManager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(WeatherIconDownloadedHandler(QNetworkReply*)));

}

HTTPManager::~HTTPManager()
{
    delete imageDownloadManager;
    delete weatherAPIManager;
    delete iconAPIManager;
}

void HTTPManager::sendImageRequest(QString zip)
{
    QNetworkRequest request;
    QString address = "https://dev.virtualearth.net/REST/V1/Imagery/Map/Road/"
            + zip
            + "/4?mapSize=350,400&mapLayer=TrafficFlow&format=png&key=AvK2_Qsi479iNFfB99p9OrYlIOjbFbeBofb71VjrGMN4VJBwJXRLeFVj1VbqF013";

    request.setUrl(QUrl(address));
    imageDownloadManager->get(request);
    qDebug() << "Image Request Sent to Addresss " << request.url();
}

void HTTPManager::sendWeatherRequest(QString zip)
{
    QNetworkRequest request;

    QString address = "https://api.openweathermap.org/data/2.5/weather?zip="
            + zip
            + ",us&units=imperial&appid=cd719faabe55ec53e984733b064e2f2a";

    request.setUrl(QUrl(address));
    weatherAPIManager->get(request);
    qDebug() << "Weather Request Sent to Addresss " << request.url();
}

void HTTPManager::sendWeatherIconRequest(QString code)
{
    QNetworkRequest request;

    QString address = "http://openweathermap.org/img/wn/"
                      + code
                      + "@2x.png";

    request.setUrl(QUrl(address));
    iconAPIManager->get(request);
    qDebug() << "Weather Icon Request Sent to Addresss " << request.url();
}

void HTTPManager::ImageDownloadedHandler(QNetworkReply *reply)
{
    qDebug() << "Image Request has arrived";
    if (reply->error())
    {
        qDebug() << reply->errorString();
        return;
    }

    qDebug() << "Download was successful";

    QPixmap *image = new QPixmap();
    image->loadFromData(reply->readAll());
    reply->deleteLater();

    emit ImageReady(image);
}

void HTTPManager::WeatherDownloadedHandler(QNetworkReply *reply)
{
    qDebug() << "Weather Request has arrived";
    if (reply->error())
    {
        qDebug() << reply->errorString();
        return;
    }
    qDebug() << "Download was successful";

    QString answer = reply->readAll();
    reply->deleteLater();

    QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());
    QJsonObject *jsonObj = new QJsonObject(jsonResponse.object());

    emit WeatherJsonReady(jsonObj);
}

void HTTPManager::WeatherIconDownloadedHandler(QNetworkReply *reply)
{
    qDebug() << "Weather Icon has arrived";
    if (reply->error())
    {
        qDebug() << reply->errorString();
        return;
    }
    qDebug() << "Download was successful";

    QPixmap *image = new QPixmap();
    image->loadFromData(reply->readAll());
    reply->deleteLater();

    emit WeatherIconReady(image);
}



