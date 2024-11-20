#include "my_bluetooth.h"
#include <QMessageBox>

My_Bluetooth::My_Bluetooth(QObject *parent): QObject{parent} {
    //实例化蓝牙相关对象
    deviceDiscoveryAgent = new QBluetoothDeviceDiscoveryAgent();
    localDevice = new QBluetoothLocalDevice();
    //初始化
    m_controller=NULL;
    m_service=NULL;
    Bluetooth_state=nullptr;
    sendSelect=1;
    sendMode=0;
    //关联发现设备的槽函数，当扫描发现周围的蓝牙设备时，会发出deviceDiscovered信号
    connect(deviceDiscoveryAgent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this,
            SLOT(addBlueToothList(QBluetoothDeviceInfo)));
    connect(deviceDiscoveryAgent,&QBluetoothDeviceDiscoveryAgent::finished,this,
            &My_Bluetooth::finshdBlue);
    //自动打开蓝牙
    if(localDevice ->hostMode() == QBluetoothLocalDevice::HostPoweredOff)
    {
        localDevice->powerOn();
    }
}
//当搜索到周围的设备时会调用当前的槽函数
void My_Bluetooth::addBlueToothList(const QBluetoothDeviceInfo &info)
{
    QString label= QString("%1 %2").arg(info.address().toString()).arg(info.name());
    //发送搜索到的设备
    emit search_Blue(label);
}

//每次发现新的服务，就会调用该槽函数
void My_Bluetooth::BlueServiceDiscovered(const QBluetoothUuid &gatt)
{
    //ui->textEdit->insertPlainText(gatt.toString()+"\n");
}
/*默认指定的UUID服务*/
static const QLatin1String serviceUuid("{0000fff0-0000-1000-8000-00805F9B34FB}");
static const QBluetoothUuid targetUuid("0000fff1-0000-1000-8000-00805F9B34FB");
//正在运行的服务发现完成时发出信号
void My_Bluetooth::BlueServiceScanDone()
{
    //判断之前有没有连接过
    if(m_service != NULL)
    {
        delete m_service;
        m_service = NULL;
    }
    //ui->textEdit->insertPlainText("选中的服务：\n"+serviceUuid);
    //与设备之间建立服务
    m_service = m_controller ->createServiceObject(QBluetoothUuid(serviceUuid),this);

    if(m_service == NULL)
    {
        //ui->textEdit->insertPlainText("服务建立失败！");
        return;
    }
    //服务状态改变时发出此信号
    connect(m_service,SIGNAL(stateChanged(QLowEnergyService::ServiceState)),this,
            SLOT(BleServiceServiceStateChanged(QLowEnergyService::ServiceState)));
    //特性值由事件改变时发出此信号在外设上。newValue参数包含更新后的值特性
    connect(m_service,SIGNAL(characteristicChanged(QLowEnergyCharacteristic,QByteArray)),this,
            SLOT(BleServiceCharacteristicChanged(QLowEnergyCharacteristic,QByteArray)));

    /*当特征读取请求成功返回其值时，发出此信号。*/
    connect(m_service, SIGNAL(characteristicRead(QLowEnergyCharacteristic,QByteArray)),
            this, SLOT(BleServiceCharacteristicRead(QLowEnergyCharacteristic,QByteArray)));

    if(m_service ->state() == QLowEnergyService::DiscoveryRequired)
    {
        m_service ->discoverDetails();  //启动服务扫描
    }
    else
        searchCharacteristic();
}


//当控制器成功连接到远程Low Energy设备时，会发出此信号。
void My_Bluetooth::BlueDeviceConnected()
{
    //启动发现服务Service
    m_controller->discoverServices();
}

//当控制器从远程低功耗设备断开此信号。
void My_Bluetooth::BlueDeviceDisconnected()
{

}

//服务状态改变时发出此信号
void My_Bluetooth::BleServiceServiceStateChanged(QLowEnergyService::ServiceState s)
{
    //所有细节都已同步
    if(s == QLowEnergyService::ServiceDiscovered)
    {
        searchCharacteristic();
        emit connect_Blue();
        Bluetooth_state=BLUETOOTH_CONNECT;
    }
}

//读取数据
void My_Bluetooth::BleServiceCharacteristicChanged(const QLowEnergyCharacteristic &c, const QByteArray &value)
{
    QString str = QString::fromUtf8(value);
    emit recv_Blue(str);
}

//读取数据
void My_Bluetooth::BleServiceCharacteristicRead(const QLowEnergyCharacteristic &c, const QByteArray &value)
{
    QString str = QString::fromUtf8(value);
    emit recv_Blue(str);
}

void My_Bluetooth::finshdBlue()
{
    emit finsh_Blue();
}

//打开蓝牙
void My_Bluetooth::openBlue()
{
    localDevice->powerOn();
}
//搜索附近设备
void My_Bluetooth::searchBlue()
{
    deviceDiscoveryAgent->start();
}
//连接蓝牙
void My_Bluetooth::connectBlue(const QString &text)
{
    int index = text.indexOf(' ');
    if(index == -1) return;
    QBluetoothAddress address(text.left(index));
    QString connect_device="是否开始连接蓝牙设备:\n";
    connect_device+=text;
    QMessageBox::StandardButton result2 = QMessageBox::information(nullptr,tr("连接提示"),connect_device,QMessageBox::Yes|QMessageBox::No);
    /*低功耗蓝牙设备*/
    if(result2 == QMessageBox::Yes)
    {
        if(m_controller!=NULL)
        {
            m_controller->disconnectFromDevice(); //断开远程设备
            delete m_controller;
            m_controller= NULL;
        }
        QList<QBluetoothDeviceInfo> info_list=deviceDiscoveryAgent->discoveredDevices(); //得到扫描的所有设备信息
        for(int i=0;i<info_list.count();i++)
        {
            if(info_list.at(i).address().toString()==text.left(index))
            {
                deviceInfo=info_list.at(i);
                break;
            }
        }
        //创建中央角色设备
        m_controller = QLowEnergyController::createCentral(deviceInfo, this);
        if(m_controller==0)
        {
            QMessageBox::critical(nullptr,"警告","创建中央角色设备失败!");
        }
        else
        {
            //            ui->plainTextEdit->insertPlainText("创建中央角色设备成功!\n");
        }
        //每次发现新的服务就会发送此信号
        connect(m_controller, SIGNAL(serviceDiscovered(QBluetoothUuid)),this, SLOT(BlueServiceDiscovered(QBluetoothUuid)));
        //正在运行的服务发现完成时发出此信号。
        connect(m_controller, SIGNAL(discoveryFinished()),this, SLOT(BlueServiceScanDone()));
        //当控制器成功连接到远程Low Energy设备时，会发出此信号。
        connect(m_controller, SIGNAL(connected()),this, SLOT(BlueDeviceConnected()));
        //当控制器从远程低功耗设备断开时发出此信号。
        connect(m_controller, SIGNAL(disconnected()),this, SLOT(BlueDeviceDisconnected()));
        //连接到远程蓝牙低功耗设备。
        m_controller->connectToDevice();
    }
}

//断开连接
void My_Bluetooth::breakBlue()
{
    QMessageBox::StandardButton result = QMessageBox::information(nullptr,"连接提示","是否断开蓝牙？",QMessageBox::Yes|QMessageBox::No);
    if(result == QMessageBox::Yes)
    {
        if(m_controller)
        {
            delete m_controller;
            m_controller = NULL;
        }
        QMessageBox::information(nullptr,"提示","已成功断开蓝牙！");
        emit discon_Blue();
        Bluetooth_state=BLUETOOTH_DISCONNECT;
    }
}

//发送数据
void My_Bluetooth::sendBlue(QString &text)
{
    // 将 QString 转换为 QByteArray (ASCII 编码)
    QByteArray array = text.toUtf8(); // 或者 text.toLocal8Bit()

    // 将字节数组写入 Bluetooth 特性
    /* 写入 newValue 作为特性的值。
       如果操作成功，将发射 characteristicWritten() 信号;
       低功耗设备: 每次最多写 20 个字节 */
    m_service->writeCharacteristic(m_writeCharacteristic[sendSelect], array, m_writeMode);
    //readCharacteristicValue();
}

//搜索特性
void My_Bluetooth::searchCharacteristic()
{
    if(m_service)
    {
        QList<QLowEnergyCharacteristic> list = m_service ->characteristics();
        //characteristic  获取详细特性

        sendMode = list.count();     //设置模式选择上限
        for (int i = 0; i < list.count(); i++)
        {
            QLowEnergyCharacteristic c = list.at(i);

            //如果QLowEnergyCharacteristic对象有效，则返回true,否则返回false
            if( c.isValid())
            {
                //返回特征的属性
                //这些属性定义了特征的访问权限
                if(c.properties() & QLowEnergyCharacteristic::WriteNoResponse || c.properties() & QLowEnergyCharacteristic::Write)
                {
                    m_writeCharacteristic[i] = c;   //保存写权限特性
                    if(c.properties() & QLowEnergyCharacteristic::WriteNoResponse)
                        //如果使用此模式写入特性，则远程外设不应发送写入确认。
                        //无法确定操作的成功，并且有效负载不得超过20个字节。
                        //一个特性必须设置QLowEnergyCharacteristic::WriteNoResponse属性来支持这种写模式。
                        //他的优点是更快的写入操作，因为它可能发生在其他设备交互之间。
                        m_writeMode = QLowEnergyService::WriteWithoutResponse;
                    else
                        m_writeMode = QLowEnergyService::WriteWithResponse;
                    //如果使用此模式写入特性，则外设应发送确认。
                    //如果操作成功，则通过characteristicWritten()信号发出确认。
                    //否则，发出CharacteristicWriteError。
                    //一个特性必须设置QLowEnergyCharacteristic::Write属性来支持这种写模式。
                }
                if((c.properties() & QLowEnergyCharacteristic::Read)&&(c.uuid()==targetUuid))
                {
                    m_readCharacteristic = c;   //保存读权限特性
                }

                //描述符定义特征如何由特定客户端配置
                m_notificationDesc = c.descriptor(QBluetoothUuid(quint16(0x2902)));

                //值为真
                if(m_notificationDesc.isValid())
                {
                    //写描述符
                    m_service ->writeDescriptor(m_notificationDesc,QByteArray::fromHex("0100"));
                }
            }
        }
    }
}

// 主动读取特征值
void My_Bluetooth::readCharacteristicValue() {
    if (m_readCharacteristic.isValid()) {
        m_service->readCharacteristic(m_readCharacteristic);
    }
}
