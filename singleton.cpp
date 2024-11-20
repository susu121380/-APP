#include "singleton.h"

// 初始化静态成员
Singleton* Singleton::instance = nullptr;

Singleton::Singleton() {
    My_Blue=new My_Bluetooth();
    Controlbtn=new Widget();
    city_Weater=new My_Weather();
    drawecurve=new DraweCurve();
}

Singleton *Singleton::getInstance()
{
    if (instance == nullptr) {
        instance = new Singleton();
    }
    return instance;
}

Singleton::~Singleton() {
    if(My_Blue->Bluetooth_state==BLUETOOTH_CONNECT)
    {
        //断开连接
        My_Blue->breakBlue();
    }
    // 清理资源
    delete My_Blue;
    delete Controlbtn;
    delete city_Weater;
    delete drawecurve;
}
