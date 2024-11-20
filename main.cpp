#include "mainwindow.h"

#include <QApplication>
#include <QScreen>
#include <QRect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //获取主机屏幕尺寸
    QRect UIsize=QApplication::primaryScreen()->geometry();
    w.set_UISize(UIsize);
    //w.setWindowState(Qt::WindowFullScreen);
    return a.exec();
}
