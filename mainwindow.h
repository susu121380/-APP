#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "singleton.h"
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QStringList>
#include <QStandardPaths>
#include <QDir>
#include <QCoreApplication>
#include <QJniObject>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>
#include <QJniObject>
#include <QJniEnvironment>
#include <QTextStream>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void set_UISize(const QRect &rect);
    void RecvBtn_slot();
    void onPermissionGranted();
    void onPermissionDenied();
    void requestPermissions();
    void readDataFromFile();
public slots:
    void Read_Text();
protected:
    void resizeEvent(QResizeEvent * ev) override;

    void showLoginDialog();
private:
    Ui::MainWindow *ui;
    QTabWidget *TabWidget;
    int currenindex;
    QWidget *Connectbtn;
    QWidget *Showbtn;
    QWidget *Toolbtn;
    QWidget *Helpbtn;
    void setbarcss(int index);
    void restorecss(int index);

    int UI_W,UI_H;
    QRect UI_rect;
    QLabel *Connectlab;
    QLabel *Showlab;
    QLabel *Toollab;
    QLabel *Controllab;
    QLabel *Helplab;

    //帮助界面资源
    //版权label
    QLabel *CopyrightLb;
    //头部label
    QLabel *TopLab;
    //公司名称
    QLabel *NameLab;
    //版本号
    QLabel *version;
    QPushButton *PasswordBtn;
    QLabel *PasswordLab;
    QPushButton *HelpBtn;
    QLabel *HelpLab;
    QPushButton *UpdateBtn;
    QLabel *UpdateLab;
    QPushButton *PhoneBtn;
    QLabel *PhoneLab;

/*****连接界面数据*****/
    QLabel *connect_Lab;
    QLabel *show_Lab;
    //读取发送信息log
    QTextEdit *Blue_LOG;
    QPushButton *searchBtn;
    QLabel *search_Lab;
    QPushButton *BlueconnectBtn;
    QLabel *blueconnectLab;
    QPushButton *disconnectBtn;
    QLabel *disconnectLab;
    QPushButton *RecvBtn;
    QLabel *RecvLab;
    QPushButton *SendBtn;
    QLabel *SendLab;
    QLineEdit *Send_Text;
    QLabel *Send_Label;
    QPushButton *open_blue;
    QLabel *openBlue;
    QComboBox *Blue_Box;
    QLabel *choose_Box;
    void addToLogs(QString message);

    QPushButton *Wread_date;
    QPushButton *Clear_date;
    QPushButton *Recv_date;
    QPushButton *Clear_Log;

/**********操作界面资源*************/
    QMap<QString,bool> keypressd;
    QMap<QString,QString> keySendMsg;

    QTimer *KeySend;

/**********蓝牙资源*************/

    //蓝牙连接类
    Singleton *singnal_All;
    bool is_blueconnect=false;
protected slots:
    void connectblue();
    void CloseBlue();
    void searchblue();
    void finsh_blued();
    void connected_Blue();
    void search_Blue(QString ptr);
    void sendupmasg_slot();
    void senddownmasg_slot();
    void sendleftmasg_slot();
    void sendrightmasg_slot();
    void sendstopmsg_slot();
    void Recv_slot(QString text);
    void Send_slot();
    void disconBlue_slot();
    void timerSend();
    void Clear_Logdate();
    void Clear_MsgLog();
};
#endif // MAINWINDOW_H
