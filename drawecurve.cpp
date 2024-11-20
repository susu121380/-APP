#include "drawecurve.h"
#include "ui_drawecurve.h"

DraweCurve::DraweCurve(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DraweCurve),
    m_chart(new QChart()),
    m_series1(new QLineSeries())
{
    ui->setupUi(this);
    All_show=new QLabel(this);
    All_show ->setPixmap(QPixmap(":/plc/jpg/DraweLine.jpg"));
    All_show ->setScaledContents(true);

    QVBoxLayout *All_Vlayout=new QVBoxLayout();
    QHBoxLayout *All_Hlayout=new QHBoxLayout();
    QSpacerItem *firstendSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
/***************************按钮****************************************/
    Show_Blueline=new QPushButton();
    Show_Blueline->setFixedSize(120,50);
    Show_Blueline->setText("显示蓝牙数据");

    Clear_Line=new QPushButton();
    Clear_Line->setFixedSize(120,50);
    Clear_Line->setText("清除数据");

    All_Vlayout->addWidget(Show_Blueline);
    All_Vlayout->addWidget(Clear_Line);
    All_Vlayout->addItem(firstendSpacer);
    All_Hlayout->addLayout(All_Vlayout);
/***************************画图****************************************/
    m_chart=new QChart();
    m_chart->setTitle("小车速度监控图");
    m_series1=new QLineSeries();
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
    QChartView *chartview = new QChartView();
    chartview->setChart(m_chart); // 将chart添加到chartview中
    All_Hlayout->addWidget(chartview);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setBackgroundBrush(Qt::NoBrush); // 设置chartview背景为透明
    chartview->setAttribute(Qt::WA_TranslucentBackground); // 使chartview背景透明
    chartview->setStyleSheet("background: transparent"); // 设置样式表使背景透明
    // 创建曲线图1并设置属性
    m_series1->setColor(Qt::red);
    m_series1->setPen(QPen(Qt::red, 2));
    m_chart->addSeries(m_series1);


    // 设置横轴属性
    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0, 50);
    axisX->setTitleText("时间(秒)");
    m_chart->addAxis(axisX, Qt::AlignBottom);
    m_series1->attachAxis(axisX);

    // 设置横轴网格线和刻度标签颜色为半透明
    QColor semiTransparentColor(255, 255, 255, 180); // 白色，半透明
    axisX->setGridLineColor(semiTransparentColor);
    axisX->setLabelsColor(semiTransparentColor);
    axisX->setLinePenColor(semiTransparentColor);
    m_chart->addAxis(axisX, Qt::AlignBottom);
    m_series1->attachAxis(axisX);

    // 设置纵轴属性
    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(0, 10);
    axisY->setTitleText("速度(m/s)");
    m_chart->addAxis(axisY, Qt::AlignLeft);
    m_series1->attachAxis(axisY);

    // 设置纵轴网格线和刻度标签颜色为半透明
    axisY->setGridLineColor(semiTransparentColor);
    axisY->setLabelsColor(semiTransparentColor);
    axisY->setLinePenColor(semiTransparentColor);
    m_series1->attachAxis(axisY);

/*********************************************************************/
    this->setLayout(All_Hlayout);
    this->setStyleSheet("QPushButton{"
                        "color:#ffffff; /*文字颜色*/"
                        "background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #20ddf0, stop: 1 #7b763b);/*背景色*/"
                        "border-style:outset; /*边框风格*/"
                        "border-width:2px;/*边框宽度*/"
                        "border-color:#29a0d2; /*边框颜色*/"
                        "border-radius:10px; /*边框倒角*/"
                        "font:bold 14px; /*字体*/"
                        "font-family: Segoe UI;min-width:100px;/*控件最小宽度*/"
                        "min-height:20px;/*控件最小高度*/"
                        "padding:4px;/*内边距*/}"
                        "QPushButton:hover{"
                        "color:#ffffff; /*文字颜色*/"
                        "background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #1bc0d0, stop: 1 #7b763b);/*背景色*/"
                        "border-style:outset; /*边框风格*/"
                        "border-width:2px;/*边框宽度*/"
                        "border-color:#29a0d2; /*边框颜色*/"
                        "border-radius:10px; /*边框倒角*/"
                        "font:bold 14px; /*字体*/"
                        "font-family: Segoe UI;min-width:100px;/*控件最小宽度*/"
                        "min-height:20px;/*控件最小高度*/"
                        "padding:4px;/*内边距*/}"
                        "QPushButton:pressed{"
                        "color:#ffffff; /*文字颜色*/"
                        "background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #67b9dc, stop: 1 #76a7bb);/*背景色*/"
                        "border-style:outset; /*边框风格*/"
                        "border-width:2px;/*边框宽度*/"
                        "border-color:#29a0d2; /*边框颜色*/"
                        "border-radius:10px; /*边框倒角*/"
                        "font:bold 14px; /*字体*/"
                        "font-family: Segoe UI;min-width:100px;/*控件最小宽度*/"
                        "min-height:20px;/*控件最小高度*/"
                        "padding:4px;/*内边距*/}"
                        );
    connect(Show_Blueline,&QPushButton::clicked,this,&DraweCurve::addspeed);
    connect(Clear_Line,&QPushButton::clicked,this,&DraweCurve::clearLine);
}

DraweCurve::~DraweCurve()
{
    delete ui;
}

void DraweCurve::setSpeed_Agv(const double &AGV_Time, const double &Speed_AGV)
{
    QPoint point(AGV_Time,Speed_AGV);
    m_series1->append(point);
}

void DraweCurve::addspeed()
{
    setSpeed_Agv(i,i*0.5);
    i++;
}

void DraweCurve::clearLine()
{
    m_series1->clear();
}

void DraweCurve::resizeEvent(QResizeEvent *ev)
{
    All_show->resize(this->size());
}
