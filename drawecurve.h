#ifndef DRAWECURVE_H
#define DRAWECURVE_H

#include <QWidget>
#include <QLabel>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QTimer>
#include <QRandomGenerator>
#include <QChartView>
#include <QDateTimeAxis>
#include <QValueAxis>
#include <QDateTime>
#include <QGraphicsLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

namespace Ui {
class DraweCurve;
}

class DraweCurve : public QWidget
{
    Q_OBJECT

public:
    explicit DraweCurve(QWidget *parent = nullptr);
    ~DraweCurve();
    void setSpeed_Agv(const double &AGV_Time,const double &Speed_AGV);

protected slots:
    void addspeed();
    void clearLine();

protected:
    void resizeEvent(QResizeEvent *ev);
private:
    Ui::DraweCurve *ui;
    QLabel *All_show;

    QChart *m_chart; // 图表指针
    QLineSeries *m_series1; // 设备1曲线

    QPushButton *Show_Blueline;

    QPushButton *Clear_Line;

    double i=2;
};

#endif // DRAWECURVE_H
