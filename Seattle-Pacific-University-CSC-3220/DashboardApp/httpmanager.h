#ifndef HTTPMANAGER_H
#define HTTPMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class HTTPManager : public QObject
{
    Q_OBJECT
public:
    explicit HTTPManager(QObject *parent = nullptr);
    ~HTTPManager();

    void sendImageRequest(QString zip);
    void sendWeatherRequest(QString zip);
    void sendWeatherIconRequest(QString code);

signals:
    void ImageReady(QPixmap *image);
    void WeatherJsonReady(QJsonObject *json);
    void WeatherIconReady(QPixmap *image);

private slots:
    void ImageDownloadedHandler(QNetworkReply *reply);
    void WeatherDownloadedHandler(QNetworkReply *reply);
    void WeatherIconDownloadedHandler(QNetworkReply *reply);

private:
    QNetworkAccessManager  *imageDownloadManager;
    QNetworkAccessManager *weatherAPIManager;
    QNetworkAccessManager *iconAPIManager;
    QByteArray downloadedData;
};

#endif // HTTPMANAGER_H
