QT       += core gui
QT += core gui bluetooth
QT += core gui network
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    drawecurve.cpp \
    main.cpp \
    mainwindow.cpp \
    my_bluetooth.cpp \
    my_dialog.cpp \
    my_weather.cpp \
    singleton.cpp \
    widget.cpp

HEADERS += \
    drawecurve.h \
    mainwindow.h \
    my_bluetooth.h \
    my_dialog.h \
    my_weather.h \
    singleton.h \
    widget.h

FORMS += \
    drawecurve.ui \
    mainwindow.ui \
    my_weather.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    plc/AndroidManifest.xml
ANDROID_PACKAGE_SOURCE_DIR = $$PWD/plc

RESOURCES += \
    Appback.qrc
