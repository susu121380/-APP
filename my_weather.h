#ifndef MY_WEATHER_H
#define MY_WEATHER_H

#include <QWidget>
#include <QPushButton>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QUrl>
#include <QJsonArray>
#include <QJsonObject>
#include <QTextEdit>
#include <QMap>
#include <QComboBox>
#include <QLabel>
#include <QDate>
#include <QList>

#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QTimer>
#include <QRandomGenerator>
#include <QChartView>
#include <QDateTimeAxis>
#include <QValueAxis>
#include <QDateTime>
#include <QGraphicsLayout>

namespace Ui {
class My_Weather;
}

class My_Weather : public QWidget
{
    Q_OBJECT

public:
    My_Weather(QWidget *parent = nullptr);
    ~My_Weather();
    void fetchWeatherData(const QString &url);
    void setContainerBackground(QFrame *frame, const QString &imagePath);
protected slots:
    void onResult(QNetworkReply *reply);
    void search_city(const QString &text);
    void search_weather(const QString &text);

protected:
    void resizeEvent(QResizeEvent * ev) override;

private:
    Ui::My_Weather *ui;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QMap<QString,QString>province_map;
    QMap<QString,QString>city_map;
    QComboBox *provinceBox;
    QComboBox *cityBox;
    QLabel *Showlab;

    QLabel *nowstate;
    QLabel *nowtem;
    QLabel *nowcity;
    QLabel *nowweather;

    QLabel *Now_Hum;
    QLabel *Now_HumNum;
    QLabel *weatherInfo_Label;

    QLabel *PMweather;
    QLabel *PMweather_text;
    //容量
    QMap<QString,int>wind_map;
    QMap<int,QString>weak_data;
    //风级
    QLabel *wind_direct;
    QLabel *wind_power;
    //空气质量
    QLabel *Quality;
    QLabel *Attribute;
    //星期
    QLabel *currentDate1;
    QLabel *currentDate2;
    QLabel *currentDate3;
    QLabel *currentDate4;
    QLabel *currentDate5;
    QLabel *currentDate6;
    //日期
    QDate currentDate;
    QLabel *mouthDate1;
    QLabel *mouthDate2;
    QLabel *mouthDate3;
    QLabel *mouthDate4;
    QLabel *mouthDate5;
    QLabel *mouthDate6;
    //天气
    QLabel *WeatherDate1;
    QLabel *WeatherDate2;
    QLabel *WeatherDate3;
    QLabel *WeatherDate4;
    QLabel *WeatherDate5;
    QLabel *WeatherDate6;
    QList<QLabel*>weatherList;
    //天气文字
    QLabel *WeatherText1;
    QLabel *WeatherText2;
    QLabel *WeatherText3;
    QLabel *WeatherText4;
    QLabel *WeatherText5;
    QLabel *WeatherText6;
    QList<QLabel*>wtrTextList;
    //天气折线图
    QChart *m_chart; // 图表指针
    QLineSeries *m_series1; // 设备1温度曲线
    QLineSeries *m_series2; // 设备2温度曲线
    //未来几天的状态图
    QLabel *Weatherstate1;
    QLabel *Weatherstate2;
    QLabel *Weatherstate3;
    QLabel *Weatherstate4;
    QLabel *Weatherstate5;
    QLabel *Weatherstate6;
    QList<QLabel*>wtrstateList;
    //未来几天的风级
    QLabel *Weathertext1;
    QLabel *Weathertext2;
    QLabel *Weathertext3;
    QLabel *Weathertext4;
    QLabel *Weathertext5;
    QLabel *Weathertext6;
    QList<QLabel*>wtrtextList;
};

#endif // MY_WEATHER_H
