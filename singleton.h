#ifndef SINGLETON_H
#define SINGLETON_H
#include <QMainWindow>
#include <QTabWidget>
#include <QPushButton>
#include <QTabBar>
#include <QScreen>
#include <QRect>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QKeyEvent>
#include <QJniObject>
#include <QToolButton>
#include <QTextEdit>
#include <QDateTime>
#include <QComboBox>
#include <QListView>
#include <QLineEdit>
#include <QPalette>
#include <QColor>

#include "my_bluetooth.h"
#include "widget.h"
#include "my_weather.h"
#include "drawecurve.h"
#include "my_dialog.h"

class Singleton: public QObject
{
    Q_OBJECT
private:
    Singleton();
    static Singleton*instance;

public:
    static Singleton* getInstance();
    // 为了防止拷贝构造和赋值操作
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    //蓝牙连接类
    My_Bluetooth *My_Blue;
    Widget *Controlbtn;
    My_Weather *city_Weater;
    DraweCurve *drawecurve;

    ~Singleton();
};

#endif // SINGLETON_H
