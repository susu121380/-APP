/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[44];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 9), // "Read_Text"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 11), // "connectblue"
QT_MOC_LITERAL(34, 9), // "CloseBlue"
QT_MOC_LITERAL(44, 10), // "searchblue"
QT_MOC_LITERAL(55, 11), // "finsh_blued"
QT_MOC_LITERAL(67, 14), // "connected_Blue"
QT_MOC_LITERAL(82, 11), // "search_Blue"
QT_MOC_LITERAL(94, 3), // "ptr"
QT_MOC_LITERAL(98, 15), // "sendupmasg_slot"
QT_MOC_LITERAL(114, 17), // "senddownmasg_slot"
QT_MOC_LITERAL(132, 17), // "sendleftmasg_slot"
QT_MOC_LITERAL(150, 18), // "sendrightmasg_slot"
QT_MOC_LITERAL(169, 16), // "sendstopmsg_slot"
QT_MOC_LITERAL(186, 9), // "Recv_slot"
QT_MOC_LITERAL(196, 4), // "text"
QT_MOC_LITERAL(201, 9), // "Send_slot"
QT_MOC_LITERAL(211, 15), // "disconBlue_slot"
QT_MOC_LITERAL(227, 9), // "timerSend"
QT_MOC_LITERAL(237, 13), // "Clear_Logdate"
QT_MOC_LITERAL(251, 12) // "Clear_MsgLog"

    },
    "MainWindow\0Read_Text\0\0connectblue\0"
    "CloseBlue\0searchblue\0finsh_blued\0"
    "connected_Blue\0search_Blue\0ptr\0"
    "sendupmasg_slot\0senddownmasg_slot\0"
    "sendleftmasg_slot\0sendrightmasg_slot\0"
    "sendstopmsg_slot\0Recv_slot\0text\0"
    "Send_slot\0disconBlue_slot\0timerSend\0"
    "Clear_Logdate\0Clear_MsgLog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  122,    2, 0x0a,    1 /* Public */,
       3,    0,  123,    2, 0x09,    2 /* Protected */,
       4,    0,  124,    2, 0x09,    3 /* Protected */,
       5,    0,  125,    2, 0x09,    4 /* Protected */,
       6,    0,  126,    2, 0x09,    5 /* Protected */,
       7,    0,  127,    2, 0x09,    6 /* Protected */,
       8,    1,  128,    2, 0x09,    7 /* Protected */,
      10,    0,  131,    2, 0x09,    9 /* Protected */,
      11,    0,  132,    2, 0x09,   10 /* Protected */,
      12,    0,  133,    2, 0x09,   11 /* Protected */,
      13,    0,  134,    2, 0x09,   12 /* Protected */,
      14,    0,  135,    2, 0x09,   13 /* Protected */,
      15,    1,  136,    2, 0x09,   14 /* Protected */,
      17,    0,  139,    2, 0x09,   16 /* Protected */,
      18,    0,  140,    2, 0x09,   17 /* Protected */,
      19,    0,  141,    2, 0x09,   18 /* Protected */,
      20,    0,  142,    2, 0x09,   19 /* Protected */,
      21,    0,  143,    2, 0x09,   20 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Read_Text(); break;
        case 1: _t->connectblue(); break;
        case 2: _t->CloseBlue(); break;
        case 3: _t->searchblue(); break;
        case 4: _t->finsh_blued(); break;
        case 5: _t->connected_Blue(); break;
        case 6: _t->search_Blue((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->sendupmasg_slot(); break;
        case 8: _t->senddownmasg_slot(); break;
        case 9: _t->sendleftmasg_slot(); break;
        case 10: _t->sendrightmasg_slot(); break;
        case 11: _t->sendstopmsg_slot(); break;
        case 12: _t->Recv_slot((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 13: _t->Send_slot(); break;
        case 14: _t->disconBlue_slot(); break;
        case 15: _t->timerSend(); break;
        case 16: _t->Clear_Logdate(); break;
        case 17: _t->Clear_MsgLog(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
