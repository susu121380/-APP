#ifndef MY_BLUETOOTH_H
#define MY_BLUETOOTH_H

#include <QBluetoothDeviceDiscoveryAgent>       //设备搜寻
#include <QBluetoothLocalDevice>                //本地设备信息
#include <QMessageBox>                          //对话框
#include <QLowEnergyController>                 //设备连接
#include <QLowEnergyService>                    //数据接收、发送
#include <QScrollBar>



#define BLUETOOTH_CONNECT "CONNECTION"
#define BLUETOOTH_DISCONNECT "DISCONNECT"

class My_Bluetooth : public QObject
{
    Q_OBJECT
public:
    My_Bluetooth(QObject *parent = nullptr);

    QBluetoothLocalDevice *localDevice;        //获取本地设备的蓝牙状态信息
    QBluetoothDeviceDiscoveryAgent *deviceDiscoveryAgent;   //搜索周围蓝牙设备
    QBluetoothDeviceInfo deviceInfo;            //保存需要连接的设备的信息
    QLowEnergyController *m_controller;         //用于蓝牙设备连接
    QLowEnergyService *m_service;               //用于数据接收与发送
    QLowEnergyCharacteristic m_readCharacteristic;      //“读”服务特性
    QLowEnergyCharacteristic m_writeCharacteristic[5];  //“写”服务特性
    QLowEnergyService::WriteMode m_writeMode;           //“写”特性模式
    QLowEnergyDescriptor m_notificationDesc;            //用于存储BLE描述符信息
    int sendMode;
    int sendSelect;
    QString Bluetooth_state;

    void openBlue();
    void connectBlue(const QString &text);
    void breakBlue();
    void sendBlue(QString &text);
    void searchBlue();
    void readCharacteristicValue();
private slots:
    void addBlueToothList(const QBluetoothDeviceInfo &info);
    void BlueServiceDiscovered(const QBluetoothUuid &gatt);
    void BlueServiceScanDone();
    void searchCharacteristic();
    void BlueDeviceConnected();
    void BlueDeviceDisconnected();
    void BleServiceServiceStateChanged(QLowEnergyService::ServiceState s);
    void BleServiceCharacteristicChanged(const QLowEnergyCharacteristic &c, const QByteArray &value);
    void finshdBlue();
signals:
    void search_Blue(QString label);
    void connect_Blue();
    void recv_Blue(QString text);
    void finsh_Blue();
    void discon_Blue();

protected slots:
    void BleServiceCharacteristicRead(const QLowEnergyCharacteristic &c, const QByteArray &value);
};

#endif // MY_BLUETOOTH_H
