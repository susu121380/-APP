#include "my_weather.h"
#include "ui_my_weather.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>

My_Weather::My_Weather(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::My_Weather),
    m_chart(new QChart()),
    m_series1(new QLineSeries()),
    m_series2(new QLineSeries())
{
    ui->setupUi(this);
    Showlab=new QLabel(this);
    Showlab ->setPixmap(QPixmap(":/plc/jpg/SHow_Back.jpg"));
    Showlab ->setScaledContents(true);

 /***********************************************************************/   //设置天气图标
    nowstate=new QLabel();
    nowstate ->setScaledContents(true);
    QHBoxLayout *temlayout=new QHBoxLayout();
    nowstate->setFixedSize(100,100);

 /***********************************************************************/   //设置温度数值
    nowtem=new QLabel();
    nowtem->setFixedSize(150,100);
    // 设置文本左对齐
    nowtem->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    nowtem->setStyleSheet("QLabel {"
        "      padding: 5px;"/* 内边距 */
        "      margin: 5px; /* 外边距 */"
        "      border-style: solid; /* 边框样式 */"
        "      border-width: 0px; /* 边框宽度 */"
        "      border-color: #1c7cd6; /* 边框颜色 */"
        "      color: #ffffff; /* 文本颜色 */"
        "      font-size: 50px; /* 字体大小 */"
        "      font-weight: bold; /* 字体粗细 */"
        "      font-family: Arial; /* 字体家族 */"
        "      };");

    nowcity=new QLabel(this);
    nowcity->setGeometry(135,100,80,50);
    nowcity->setStyleSheet("QLabel {"
       "      padding: 5px;"/* 内边距 */
       "      margin: 5px; /* 外边距 */"
       "      border-style: solid; /* 边框样式 */"
       "      border-width: 0px; /* 边框宽度 */"
       "      border-color: #1c7cd6; /* 边框颜色 */"
       "      color: #ffffff; /* 文本颜色 */"
       "      font-size: 16px; /* 字体大小 */"
       "      font-weight: bold; /* 字体粗细 */"
       "      font-family: Arial; /* 字体家族 */"
       "      };");

    nowweather=new QLabel(this);
    nowweather->setGeometry(180,100,80,50);
    nowweather->setStyleSheet("QLabel {"
      "      padding: 5px;"/* 内边距 */
      "      margin: 5px; /* 外边距 */"
      "      border-style: solid; /* 边框样式 */"
      "      border-width: 0px; /* 边框宽度 */"
      "      border-color: #1c7cd6; /* 边框颜色 */"
      "      color: #ffffff; /* 文本颜色 */"
      "      font-size: 16px; /* 字体大小 */"
      "      font-weight: bold; /* 字体粗细 */"
      "      font-family: Arial; /* 字体家族 */"
      "      };");

    temlayout->addWidget(nowstate);
    temlayout->addWidget(nowtem);
    QSpacerItem *temendSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    temlayout->addItem(temendSpacer);

    QHBoxLayout *hlayout=new QHBoxLayout();
    QVBoxLayout *vlayout=new QVBoxLayout();

    QHBoxLayout *AllHlayout=new QHBoxLayout();

 /***********************************************************************/   //设置选择省和城市下拉框
    provinceBox=new QComboBox();
    cityBox=new QComboBox();

    QSpacerItem *oneendSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    hlayout->addWidget(provinceBox);
    hlayout->addWidget(cityBox);
    hlayout->addItem(oneendSpacer);
    vlayout->addLayout(hlayout);
    vlayout->addLayout(temlayout);

    QSpacerItem *threeSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    vlayout->addItem(threeSpacer);

/***********************************************************************/    //今日天气显示
    Now_Hum=new QLabel(this);
    Now_Hum->setText("湿度");
    Now_Hum->setGeometry(70,190,50,50);
    Now_Hum->setStyleSheet("QLabel {"
                           "      background: transparent;"
                           "      color: #ffffff; /* 文本颜色 */"
                           "      font-size: 16px; /* 字体大小 */"
                           "      font-family: Arial; /* 字体家族 */"
                           "      };");
    Now_HumNum=new QLabel(this);
    Now_HumNum->setGeometry(70,210,50,50);
    Now_HumNum->setStyleSheet("QLabel {"
                           "      background: transparent;"
                           "      color: #ffffff; /* 文本颜色 */"
                           "      font-size: 16px; /* 字体大小 */"
                           "      font-family: Arial; /* 字体家族 */"
                           "      };");
/***********************************************************************/    //PM2.5
    PMweather=new QLabel(this);
    PMweather->setText("PM2.5");
    PMweather->setGeometry(180,190,50,50);
    PMweather->setStyleSheet("QLabel {"
                              "      background: transparent;"
                              "      color: #ffffff; /* 文本颜色 */"
                              "      font-size: 16px; /* 字体大小 */"
                              "      font-family: Arial; /* 字体家族 */"
                              "      };");
    PMweather_text=new QLabel(this);
    PMweather_text->setText("- - - - - -");
    PMweather_text->setGeometry(180,210,50,50);
    PMweather_text->setStyleSheet("QLabel {"
                              "      background: transparent;"
                              "      color: #ffffff; /* 文本颜色 */"
                              "      font-size: 16px; /* 字体大小 */"
                              "      font-family: Arial; /* 字体家族 */"
                              "      };");

/***********************************************************************/    //风向风级
    wind_direct=new QLabel(this);
    wind_direct->setGeometry(70,250,50,50);
    wind_direct->setStyleSheet("QLabel {"
                                  "      background: transparent;"
                                  "      color: #ffffff; /* 文本颜色 */"
                                  "      font-size: 16px; /* 字体大小 */"
                                  "      font-family: Arial; /* 字体家族 */"
                                  "      };");
    wind_power=new QLabel(this);
    wind_power->setGeometry(70,270,50,50);
    wind_power->setStyleSheet("QLabel {"
                                  "      background: transparent;"
                                  "      color: #ffffff; /* 文本颜色 */"
                                  "      font-size: 16px; /* 字体大小 */"
                                  "      font-family: Arial; /* 字体家族 */"
                                  "      };");

/***********************************************************************/    //空气质量
    Quality=new QLabel(this);
    Quality->setText("空气质量");
    Quality->setGeometry(170,250,65,50);
    Quality->setStyleSheet("QLabel {"
                              "      background: transparent;"
                              "      color: #ffffff; /* 文本颜色 */"
                              "      font-size: 16px; /* 字体大小 */"
                              "      font-family: Arial; /* 字体家族 */"
                              "      };");
    Attribute=new QLabel(this);
    Attribute->setText("- - - - - - - -");
    Attribute->setGeometry(170,270,65,50);
    Attribute->setStyleSheet("QLabel {"
                              "      background: transparent;"
                              "      color: #ffffff; /* 文本颜色 */"
                              "      font-size: 16px; /* 字体大小 */"
                              "      font-family: Arial; /* 字体家族 */"
                              "      };");

/***********************************************************************/    //获取周几
    weak_data.insert(1,"一");
    weak_data.insert(2,"二");
    weak_data.insert(3,"三");
    weak_data.insert(4,"四");
    weak_data.insert(5,"五");
    weak_data.insert(6,"六");
    weak_data.insert(7,"七");
    // 获取当前日期
    currentDate = QDate::currentDate();
    int dayOfWeek = currentDate.dayOfWeek();
    // 获取当前的月和日
    int month = currentDate.month();
    int day = currentDate.day();

    currentDate1=new QLabel(this);
    currentDate1->setText("今天");
    currentDate1->setGeometry(325,-10,65,50);

    currentDate2=new QLabel(this);
    currentDate2->setText("明天");
    currentDate2->setGeometry(395,-10,65,50);

    currentDate3=new QLabel(this);
    if(dayOfWeek+2>7)
    {
        dayOfWeek=dayOfWeek-7;
    }
    currentDate3->setText("星期"+weak_data.value(dayOfWeek+2));
    currentDate3->setGeometry(467,-10,65,50);
    if(dayOfWeek+3>7)
    {
        dayOfWeek=dayOfWeek-7;
    }

    currentDate4=new QLabel(this);
    currentDate4->setText("星期"+weak_data.value(dayOfWeek+3));
    currentDate4->setGeometry(540,-10,65,50);
    if(dayOfWeek+4>7)
    {
        dayOfWeek=dayOfWeek-7;
    }

    currentDate5=new QLabel(this);
    currentDate5->setText("星期"+weak_data.value(dayOfWeek+4));
    currentDate5->setGeometry(615,-10,65,50);
    if(dayOfWeek+5>7)
    {
        dayOfWeek=dayOfWeek-7;
    }

    currentDate6=new QLabel(this);
    currentDate6->setText("星期"+weak_data.value(dayOfWeek+5));
    currentDate6->setGeometry(685,-10,65,50);

/***********************************************************************/    //日期
    mouthDate1=new QLabel(this);
    QString text =QString("%1/%2").arg(month).arg(day);
    mouthDate1->setText(text);
    mouthDate1->setGeometry(320,10,65,50);

    mouthDate2=new QLabel(this);
    text =QString("%1/%2").arg(month).arg(day+=1);
    mouthDate2->setText(text);
    mouthDate2->setGeometry(390,10,65,50);

    mouthDate3=new QLabel(this);
    text =QString("%1/%2").arg(month).arg(day+=1);
    mouthDate3->setText(text);
    mouthDate3->setGeometry(467,10,65,50);

    mouthDate4=new QLabel(this);
    text =QString("%1/%2").arg(month).arg(day+=1);
    mouthDate4->setText(text);
    mouthDate4->setGeometry(542,10,65,50);

    mouthDate5=new QLabel(this);
    text =QString("%1/%2").arg(month).arg(day+=1);
    mouthDate5->setText(text);
    mouthDate5->setGeometry(615,10,65,50);


    mouthDate6=new QLabel(this);
    text =QString("%1/%2").arg(month).arg(day+1);
    mouthDate6->setText(text);
    mouthDate6->setGeometry(685,10,65,50);

/****************************天气*****************************************/
    WeatherDate1=new QLabel(this);
    WeatherDate1->setScaledContents(true);
    WeatherDate1->setGeometry(315,65,45,30);

    WeatherDate2=new QLabel(this);
    WeatherDate2->setScaledContents(true);
    WeatherDate2->setGeometry(390,65,45,30);

    WeatherDate3=new QLabel(this);
    WeatherDate3->setScaledContents(true);
    WeatherDate3->setGeometry(464,65,45,30);

    WeatherDate4=new QLabel(this);
    WeatherDate4->setScaledContents(true);
    WeatherDate4->setGeometry(540,65,45,30);

    WeatherDate5=new QLabel(this);
    WeatherDate5->setScaledContents(true);
    WeatherDate5->setGeometry(610,65,45,30);

    WeatherDate6=new QLabel(this);
    WeatherDate6->setScaledContents(true);
    WeatherDate6->setGeometry(685,65,45,30);

    weatherList.append(WeatherDate1);
    weatherList.append(WeatherDate2);
    weatherList.append(WeatherDate3);
    weatherList.append(WeatherDate4);
    weatherList.append(WeatherDate5);
    weatherList.append(WeatherDate6);
/********************************天气文字************************************/
    WeatherText1=new QLabel(this);
    WeatherText1->setGeometry(324,79,50,40);

    WeatherText2=new QLabel(this);
    WeatherText2->setGeometry(395,79,50,40);

    WeatherText3=new QLabel(this);
    WeatherText3->setGeometry(472,79,50,40);

    WeatherText4=new QLabel(this);
    WeatherText4->setGeometry(546,79,50,40);

    WeatherText5=new QLabel(this);
    WeatherText5->setGeometry(618,79,50,40);

    WeatherText6=new QLabel(this);
    WeatherText6->setGeometry(692,79,50,40);

    wtrTextList.append(WeatherText1);
    wtrTextList.append(WeatherText2);
    wtrTextList.append(WeatherText3);
    wtrTextList.append(WeatherText4);
    wtrTextList.append(WeatherText5);
    wtrTextList.append(WeatherText6);

/***********************************************************************/

/**********************温度折线图*****************************************/
    m_chart=new QChart();
    m_series1=new QLineSeries();
    m_series2=new QLineSeries();
    //设置图标透明色
    m_chart->setBackgroundBrush(Qt::transparent);
    m_chart->setPlotAreaBackgroundBrush(Qt::transparent);
    // 设置图标透明色
    m_chart->setBackgroundBrush(Qt::NoBrush); // 设置图表背景为透明
    m_chart->setPlotAreaBackgroundBrush(Qt::NoBrush); // 设置绘图区背景为透明
    m_chart->setPlotAreaBackgroundVisible(false); // 隐藏绘图区背景
    // 禁用图例
    m_chart->legend()->hide();
    // 创建图表
    QChartView *chartview = new QChartView(this);
    chartview->setChart(m_chart); // 将chart添加到chartview中
    chartview->setGeometry(280, 80, 480, 210); // 设置chartview的几何位置和大小
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setBackgroundBrush(Qt::NoBrush); // 设置chartview背景为透明
    chartview->setAttribute(Qt::WA_TranslucentBackground); // 使chartview背景透明
    chartview->setStyleSheet("background: transparent"); // 设置样式表使背景透明
    // 创建温度曲线图1并设置属性
    m_series1->setColor(Qt::red);
    m_series1->setPen(QPen(Qt::red, 2));
    m_chart->addSeries(m_series1);

    // 创建温度曲线图2并设置属性
    m_series2->setColor(Qt::green);
    m_series2->setPen(QPen(Qt::green, 2));
    m_chart->addSeries(m_series2);

    // 设置横轴属性
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("MM-dd");
    QDateTime currentDate = QDateTime::currentDateTime();
    QDateTime startDate = currentDate;
    QDateTime endDate = currentDate.addDays(5);
    axisX->setRange(startDate, endDate);
    int numberOfTicks = 6; // 希望的刻度数量
    axisX->setTickCount(numberOfTicks);
    m_chart->addAxis(axisX, Qt::AlignBottom);
    m_series1->attachAxis(axisX);
    m_series2->attachAxis(axisX);

    // 设置横轴网格线和刻度标签颜色为半透明
    QColor semiTransparentColor(255, 255, 255, 80); // 白色，半透明
    axisX->setGridLineColor(semiTransparentColor);
    axisX->setLabelsColor(semiTransparentColor);
    axisX->setLinePenColor(semiTransparentColor);
    m_chart->addAxis(axisX, Qt::AlignBottom);
    m_series1->attachAxis(axisX);
    m_series2->attachAxis(axisX);

    // 设置纵轴属性
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-5, 25);
    axisY->setTitleText("温度(°C)(红高温绿低温)");
    m_chart->addAxis(axisY, Qt::AlignLeft);
    m_series1->attachAxis(axisY);
    m_series2->attachAxis(axisY);

    // 设置纵轴网格线和刻度标签颜色为半透明
    axisY->setGridLineColor(semiTransparentColor);
    axisY->setLabelsColor(semiTransparentColor);
    axisY->setLinePenColor(semiTransparentColor);
    m_series1->attachAxis(axisY);
    m_series2->attachAxis(axisY);

/***********************************************************************/

/********************未来几天状态*****************************************/
    Weatherstate1=new QLabel(this);
    Weatherstate1->setGeometry(324,265,50,40);

    Weatherstate2=new QLabel(this);
    Weatherstate2->setGeometry(395,265,50,40);

    Weatherstate3=new QLabel(this);
    Weatherstate3->setGeometry(472,265,50,40);

    Weatherstate4=new QLabel(this);
    Weatherstate4->setGeometry(546,265,50,40);

    Weatherstate5=new QLabel(this);
    Weatherstate5->setGeometry(618,265,50,40);

    Weatherstate6=new QLabel(this);
    Weatherstate6->setGeometry(692,265,50,40);

    wtrstateList.append(Weatherstate1);
    wtrstateList.append(Weatherstate2);
    wtrstateList.append(Weatherstate3);
    wtrstateList.append(Weatherstate4);
    wtrstateList.append(Weatherstate5);
    wtrstateList.append(Weatherstate6);

/********************未来几天风级*****************************************/
    Weathertext1=new QLabel(this);
    Weathertext1->setGeometry(326,285,50,40);

    Weathertext2=new QLabel(this);
    Weathertext2->setGeometry(398,285,50,40);

    Weathertext3=new QLabel(this);
    Weathertext3->setGeometry(474,285,50,40);

    Weathertext4=new QLabel(this);
    Weathertext4->setGeometry(548,285,50,40);

    Weathertext5=new QLabel(this);
    Weathertext5->setGeometry(620,285,50,40);

    Weathertext6=new QLabel(this);
    Weathertext6->setGeometry(694,285,50,40);

    wtrtextList.append(Weathertext1);
    wtrtextList.append(Weathertext2);
    wtrtextList.append(Weathertext3);
    wtrtextList.append(Weathertext4);
    wtrtextList.append(Weathertext5);
    wtrtextList.append(Weathertext6);
/***********************************************************************/
    this->setStyleSheet("QLabel {"
                        "      background: transparent;"
                        "      color: #ffffff; /* 文本颜色 */"
                        "      font-size: 15px; /* 字体大小 */"
                        "      font-family: SimSun; /* 字体家族 */"
                        "      };");

    AllHlayout->addLayout(vlayout);

    this->setLayout(AllHlayout);
    manager=new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &My_Weather::onResult);
    connect(provinceBox,&QComboBox::currentTextChanged,this,&My_Weather::search_city);
    connect(cityBox,&QComboBox::currentTextChanged,this,&My_Weather::search_weather);
/***********************************************************************/
    //加载QMap
    wind_map.insert("无风",0);
    wind_map.insert("软风",1);
    wind_map.insert("轻风",2);
    wind_map.insert("微风",3);
    wind_map.insert("和风",4);
    wind_map.insert("清风",5);
    wind_map.insert("强风",6);
    wind_map.insert("疾风",7);
    wind_map.insert("大风",8);
    wind_map.insert("烈风",9);
    wind_map.insert("狂风",10);
    wind_map.insert("暴风",11);
    wind_map.insert("飓风",12);

    this->fetchWeatherData("http://www.nmc.cn/rest/province");
}

My_Weather::~My_Weather()
{
    delete ui;
}

void My_Weather::setContainerBackground(QFrame *frame, const QString &imagePath) {
    QPixmap pixmap(imagePath);
    if (pixmap.isNull()) {
        return;
    }
    QPalette palette = frame->palette();
    palette.setBrush(QPalette::Window, QBrush(pixmap.scaled(frame->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
    frame->setAutoFillBackground(true);
    frame->setPalette(palette);
}

void My_Weather::fetchWeatherData(const QString &url)
{
    request.setUrl(QUrl(url));  // 这里要确保使用正确的构造方式
    manager->get(request);
}

void My_Weather::onResult(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        //读取网络获取的信息
        QByteArray responseData = reply->readAll();

        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        if (jsonDoc.isNull()) {
            return;
        }

        if(jsonDoc.isArray())
        {
            QJsonArray jsonArray = jsonDoc.array();
            for (const QJsonValue &value : jsonArray) {
                if (value.isObject()) {
                    QJsonObject obj = value.toObject();
                    //解析城市json数据
                    if(obj.contains("name"))
                    {
                        QString code = obj.value("code").toString();
                        QString name = obj.value("name").toString();
                        this->provinceBox->addItem(name);
                        province_map.insert(name,code);
                    }else if(obj.contains("city"))
                    //解析省份json数据
                    {
                        QString citycode = obj.value("code").toString();
                        QString cityname = obj.value("city").toString();
                        this->cityBox->addItem(cityname);
                        if(this->cityBox->count()>0&&this->cityBox->count()<2)
                        {
                            search_weather(cityname);
                        }
                        city_map.insert(cityname,citycode);
                    }
                }
            }
        }else if(jsonDoc.isObject())
        {
            QJsonObject jsonObject = jsonDoc.object();
            int code = jsonObject.value("code").toInt();
            // 检查 code 是否为 0，表示请求成功
            if (code != 0) {
                return;
            }
            // 提取 data 对象
            QJsonObject dataObj = jsonObject.value("data").toObject();
            // 提取 real 对象
            QJsonObject realObj = dataObj.value("real").toObject();
            // 提取 weather 对象
            QJsonObject weatherObj = realObj.value("weather").toObject();
            double temperature = weatherObj.value("temperature").toDouble();
            this->nowtem->setText(QString::number(temperature)+"°");
            double humidity  = weatherObj.value("rcomfort").toDouble();
            Now_HumNum->setText(QString::number(humidity)+"%");

            // 提取 wind 对象
            QJsonObject windObj = realObj.value("wind").toObject();
            QString windDirect = windObj.value("direct").toString();
            QString windPower = windObj.value("power").toString();
            wind_direct->setText(windDirect);
            wind_power->setText(QString::number(wind_map.value(windPower))+"级");

            // 提取 predict 对象
            QJsonObject predictObj = dataObj.value("predict").toObject();

            // 提取 detail 数组
            QJsonArray detailArray = predictObj.value("detail").toArray();
            int index=0;
            for (const QJsonValue &value : detailArray) {
                if (index >= weatherList.size()) {
                    break; // 防止越界访问
                }
                if (value.isObject()) {
                    QJsonObject detailObj = value.toObject();
                    // 提取 day 对象
                    QJsonObject dayObj = detailObj.value("day").toObject();
                    QJsonObject dayWeatherObj = dayObj.value("weather").toObject();
                    QString dayWeatherInfo = dayWeatherObj.value("info").toString();
                    if(dayWeatherInfo=="小雨"||dayWeatherInfo=="大雨")
                    {
                        weatherList[index]->setPixmap(QPixmap(":/plc/png/rain.png"));
                        wtrTextList[index]->setText("小雨");
                        if(index==0)
                        {
                            this->nowstate->setPixmap(QPixmap(":/plc/png/rainday.png"));
                            nowweather->setText("小雨");
                        }

                    }else if(dayWeatherInfo=="多云")
                    {
                        weatherList[index]->setPixmap(QPixmap(":/plc/png/cloudyday.png"));
                        wtrTextList[index]->setText("多云");
                        if(index==0)
                        {
                            this->nowstate->setPixmap(QPixmap(":/plc/png/cloudy.png"));
                            nowweather->setText("多云");
                        }
                    }else
                    {
                        weatherList[index]->setPixmap(QPixmap(":/plc/png/fineday.png"));
                        wtrTextList[index]->setText("晴天");
                        if(index==0)
                        {
                            this->nowstate->setPixmap(QPixmap(":/plc/png/fine.png"));
                            nowweather->setText("晴天");
                        }
                    }
                    //提取wind
                    QJsonObject dayWindObj = dayObj.value("wind").toObject();
                    QString dayWindPower=dayWindObj.value("power").toString();
                    //设置当天状态标签
                    if(dayWindPower=="9999")
                    {
                        dayWindPower="无风";
                    }
                    wtrstateList[index]->setText(dayWindPower);
                    wtrtextList[index]->setText(QString::number(wind_map.value(dayWindPower))+"级");
                    index++;
                }
            }
           // 提取 tempchart 数组
            QJsonArray tempchartArray = dataObj.value("tempchart").toArray();
            QDateTime todaytime = QDateTime::currentDateTime();
            QDate today =todaytime.date();

            for (const QJsonValue &value : tempchartArray) {
                if (value.isObject()) {
                    QJsonObject tempchartObj = value.toObject();
                    QString time = tempchartObj.value("time").toString();
                    double maxTemp = tempchartObj.value("max_temp").toDouble();
                    double minTemp = tempchartObj.value("min_temp").toDouble();
                    QDateTime dateTime = QDateTime::fromString(time, "yyyy/MM/dd");
                    QDate date=dateTime.date();
                    if (date.month() == today.month() && date.day() >= today.day() || date.month() > today.month()) {
                        QDateTime dateTime = QDateTime(date, QTime(0, 0, 0));
                        double timestamp = dateTime.toMSecsSinceEpoch(); // 转换为毫秒时间戳
                        QPointF p1(timestamp, maxTemp);
                        QPointF p2(timestamp, minTemp);
                        m_series1->append(p1);
                        m_series2->append(p2);
                    }
                }
            }
        }
    }else {
    }
    reply->deleteLater();
}

void My_Weather::search_city(const QString &text)
{
    cityBox->clear();
    QString url="http://www.nmc.cn/rest/province/"+province_map.value(text);
    this->fetchWeatherData(url);
}

void My_Weather::search_weather(const QString &text)
{
    QString url="http://www.nmc.cn/rest/weather?stationid="+city_map.value(text);
    update();
    m_series1->clear();
    m_series2->clear();
    this->fetchWeatherData(url);
    this->nowcity->setText(this->cityBox->currentText());
}

void My_Weather::resizeEvent(QResizeEvent *ev)
{
   Showlab->resize(this->size());
}

