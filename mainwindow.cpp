#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSpacerItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化登录密码界面
    //showLoginDialog();
    singnal_All=Singleton::getInstance();
    TabWidget=new QTabWidget(this);
    Connectbtn=new QWidget();
    Showbtn=new QWidget();
    Toolbtn=new QWidget();
    Helpbtn=new QWidget();

    KeySend=new QTimer(this);
    // 设置背景图片
    TabWidget->setStyleSheet(
        "QTabBar::tab {"
        "   min-width: 145%;"
        "   max-width: 145%;"
        "   min-height: 35px;"
        "   background: lightblue;"
        "   color: black;"
        "   margin: 2px;"
        "   background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #29a0d2, stop: 1 #b5c28b);"
        "}"
        "QTabBar::tab:pressed {"
        "   background: pink;"
        "   color: black;"
        "}"
        "QTabBar::tab:selected {"
        "   background: yellow;" // 选中标签自定义背景色
        "   background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #b5c28b, stop: 1 #29a0d2);"
        "}"
        );
    // 获取 QTabBar 对象并设置其扩展属性
    QTabBar* tabBar = TabWidget->tabBar();
    tabBar->setExpanding(true);

    // 设置 TabWidget 的大小策略为扩展
    TabWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    TabWidget->addTab(Connectbtn,"连接");
    TabWidget->addTab(singnal_All->city_Weater,"显示");
    TabWidget->addTab(singnal_All->drawecurve,"工具");
    TabWidget->addTab(singnal_All->Controlbtn,"操作");
    TabWidget->addTab(Helpbtn,"帮助");
    this->setCentralWidget(TabWidget);//将TabWidget设置为窗口主部件


/*****************************************************************************************/
/*****************************************************************************************/
    //连接界面设置
    //设置背景图片
    Connectlab=new QLabel(Connectbtn);
    Connectlab ->setPixmap(QPixmap(":/plc/jpg/Drawe.jpg"));
    Connectlab ->setScaledContents(true);

    //设置垂直布局、水平布局
    QVBoxLayout *AllConnect_Layout=new QVBoxLayout();
    QHBoxLayout *AllHConnect_Layout=new QHBoxLayout();
    QHBoxLayout *firstcnt_Layout=new QHBoxLayout();
    QHBoxLayout *twocnt_Layout=new QHBoxLayout();
    QHBoxLayout *threecnt_Layout=new QHBoxLayout();
    QHBoxLayout *four_Layout=new QHBoxLayout();
    QHBoxLayout *five_Layout=new QHBoxLayout();
    QHBoxLayout *six_Layout=new QHBoxLayout();


    Wread_date=new QPushButton();
    Wread_date->setFixedHeight(50);
    Wread_date->setText("写入到文本");

    Clear_date=new QPushButton();
    Clear_date->setFixedHeight(50);
    Clear_date->setText("清空日志文本");

    Clear_Log=new QPushButton();
    Clear_Log->setFixedHeight(50);
    Clear_Log->setText("清空日志信息");

    Recv_date=new QPushButton();
    Recv_date->setFixedHeight(50);
    Recv_date->setText("读取日志信息");

    five_Layout->addWidget(Wread_date);
    five_Layout->addWidget(Recv_date);

    six_Layout->addWidget(Clear_date);
    six_Layout->addWidget(Clear_Log);

    Blue_LOG=new QTextEdit();
    Blue_LOG->setStyleSheet(R"(
    QTextEdit {
        background-color: white;
        color: black;
    }
    QScrollBar:vertical {
        border: none;
        background: #f0f0f0;
        width: 20px;
        margin: 0px 0px 0px 0px;
    }
    QScrollBar::handle:vertical {
        background: #888;
        min-height: 20px;
    }
)");
    Blue_LOG->setReadOnly(true);
    // 设置垂直滚动条始终显示
    Blue_LOG->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    connect_Lab=new QLabel();
    connect_Lab->setText("连接:");
    connect_Lab->setStyleSheet("color: black;font-size:14px");
    connect_Lab->setFixedSize(40,18);
    show_Lab=new QLabel();
    show_Lab->setText("LOG日志信息:");
    show_Lab->setStyleSheet("color: black;font-size:14px");
    show_Lab->setFixedSize(100,18);
    QVBoxLayout *show_Layout=new QVBoxLayout();
    show_Layout->addWidget(show_Lab);
    show_Layout->addWidget(Blue_LOG);
    show_Layout->addLayout(five_Layout);
    show_Layout->addLayout(six_Layout);

    AllConnect_Layout->addWidget(connect_Lab);

    //搜索按钮
    searchBtn=new QPushButton();
    searchBtn->setText("搜索蓝牙");
    searchBtn->setFixedSize(100,40);
    search_Lab=new QLabel();
    search_Lab->setFixedSize(40,40);
    search_Lab->setStyleSheet("border-image: url(:/plc/png/search.png);");
    firstcnt_Layout->addWidget(search_Lab);
    firstcnt_Layout->addWidget(searchBtn);
    QSpacerItem *firstendSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);
    firstcnt_Layout->addItem(firstendSpacer);

    //打开蓝牙按钮
    open_blue=new QPushButton();
    open_blue->setText("打开蓝牙");
    open_blue->setFixedSize(100,40);
    openBlue=new QLabel();
    openBlue->setFixedSize(40,40);
    openBlue->setStyleSheet("border-image: url(:/plc/png/openBlue.png);");
    firstcnt_Layout->addWidget(openBlue);
    firstcnt_Layout->addWidget(open_blue);

    //选择框按钮
    Blue_Box=new QComboBox();
    Blue_Box->setMaxVisibleItems(10);
    Blue_Box->setStyleSheet("QComboBox{"
                            "color:#666666;"
                            "font-size:14px;"
                            "background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #29a0d2, stop: 1 #b5c28b);/*背景色*/"
                            "padding: 1px 15px 1px 3px;"
                            "border:1px solid rgba(228,228,228,1);"
                            "border-radius:5px;"
                            "} "
                            "QComboBox::drop-down {"
                            "subcontrol-origin: padding;"
                            "subcontrol-position: top right;"
                            "image: url(:/plc/png/downcheck.png);" // 设置下拉箭头图片
                            "width: 15px;"
                            "height: 40px"
                            "border:none;"
                            "}"
                            "QComboBox QAbstractItemView::scrollbar:vertical {"
                            "border: none;"
                            "background: #f0f0f0;"
                            "width: 15px;margin: 0px 0px 0px 0px;"
                            "}"
                            "QComboBox QAbstractItemView::scrollbar::handle:vertical {"
                            "background: #888;"
                            "min-height: 20px;"
                            "}");
    Blue_Box->setFixedSize(108,40);
    choose_Box=new QLabel();
    choose_Box->setFixedSize(40,40);
    choose_Box->setStyleSheet("border-image: url(:/plc/png/choose.png);");
    twocnt_Layout->addWidget(choose_Box);
    twocnt_Layout->addWidget(Blue_Box);
    QSpacerItem *twoendSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);
    twocnt_Layout->addItem(twoendSpacer);

    //连接按钮
    BlueconnectBtn=new QPushButton();
    BlueconnectBtn->setText("连接蓝牙");
    BlueconnectBtn->setFixedSize(100,40);
    BlueconnectBtn->setEnabled(false);
    blueconnectLab=new QLabel();
    blueconnectLab->setFixedSize(40,40);
    blueconnectLab->setStyleSheet("border-image: url(:/plc/png/connect.png);");
    twocnt_Layout->addWidget(blueconnectLab);
    twocnt_Layout->addWidget(BlueconnectBtn);

    //断开按钮
    disconnectBtn=new QPushButton();
    disconnectBtn->setText("断开蓝牙");
    disconnectBtn->setFixedSize(100,40);
    disconnectBtn->setEnabled(false);
    disconnectLab=new QLabel();
    disconnectLab->setFixedSize(40,40);
    disconnectLab->setStyleSheet("border-image: url(:/plc/png/disconnect.png);");
    threecnt_Layout->addWidget(disconnectLab);
    threecnt_Layout->addWidget(disconnectBtn);
    QSpacerItem *threeSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);
    threecnt_Layout->addItem(threeSpacer);

    //输入信息控件
    Send_Text=new QLineEdit();
    Send_Text->setFixedSize(108,40);
    Send_Text->setPlaceholderText("输入信息");
    Send_Text->setStyleSheet("QLineEdit{"
                             "  background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #29a0d2, stop: 1 #b5c28b);/*背景色*/"
                             "  border-radius:5px;"
                             "  border:2px solid rgba(228,228,228,1);"
                             "  color:#ffffff"
                             "}"
                             );
    Send_Label=new QLabel();
    Send_Label->setFixedSize(40,40);
    Send_Label->setStyleSheet("border-image: url(:/plc/png/readtext.png);");
    threecnt_Layout->addWidget(Send_Label);
    threecnt_Layout->addWidget(Send_Text);

    //读取按钮
    RecvBtn=new QPushButton();
    RecvBtn->setText("读取信息");
    RecvBtn->setFixedSize(100,40);
    RecvLab=new QLabel();
    RecvLab->setFixedSize(40,40);
    RecvLab->setStyleSheet("border-image: url(:/plc/png/recv.png);");
    four_Layout->addWidget(RecvLab);
    four_Layout->addWidget(RecvBtn);
    QSpacerItem *fourendSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);
    four_Layout->addItem(fourendSpacer);

    //发送按钮
    SendBtn=new QPushButton();
    SendBtn->setText("发送信息");
    SendBtn->setFixedSize(100,40);
    SendLab=new QLabel();
    SendLab->setFixedSize(40,40);
    SendLab->setStyleSheet("border-image: url(:/plc/png/send.png);");
    four_Layout->addWidget(SendLab);
    four_Layout->addWidget(SendBtn);

    AllConnect_Layout->addLayout(firstcnt_Layout);
    AllConnect_Layout->addLayout(twocnt_Layout);
    AllConnect_Layout->addLayout(threecnt_Layout);
    AllConnect_Layout->addLayout(four_Layout);
    AllHConnect_Layout->addLayout(AllConnect_Layout);
    AllHConnect_Layout->addLayout(show_Layout);
    Connectbtn->setLayout(AllHConnect_Layout);


    Connectbtn->setStyleSheet("QPushButton{"
                    "color:#ffffff; /*文字颜色*/"
                    "background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #29a0d2, stop: 1 #b5c28b);/*背景色*/"
                    "border-style:inset; /*边框风格*/"
                    "border-width:1px;/*边框宽度*/"
                    "border-color:#ffffff; /*边框颜色*/"
                    "border-radius:10px; /*边框倒角*/"
                    "font:bold 14px; /*字体*/"
                    "font-family: Segoe UI;"
                    "min-width:100px;/*控件最小宽度*/"
                    "min-height:20px;/*控件最小高度*/"
                    "padding:4px;/*内边距*/}"
                "QPushButton:pressed{"
                    "color:#ffffff; /*文字颜色*/"
                    "background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #a2e8f6, stop: 1 #7398a0);/*背景色*/"
                    "border-style:inset; /*边框风格*/"
                    "border-width:1px;/*边框宽度*/"
                    "border-color:#fffff0; /*边框颜色*/"
                    "border-radius:10px; /*边框倒角*/"
                    "font:bold 14px; /*字体*/"
                    "font-family: Segoe UI;"
                    "min-width:100px;/*控件最小宽度*/"
                    "min-height:20px;/*控件最小高度*/"
                    "padding:4px;/*内边距*/}"
                    );
/*****************************************************************************************/
/*****************************************************************************************/

    //显示界面设置
    //设置背景图片
    Showlab=new QLabel(Showbtn);
    Showlab ->setPixmap(QPixmap(":/plc/jpg/AIRobo.jpg"));
    Showlab ->setScaledContents(true);

/*****************************************************************************************/
/*****************************************************************************************/

    //工具界面设置
    //设置背景图片
    Toollab=new QLabel(Toolbtn);
    Toollab ->setPixmap(QPixmap(":/plc/jpg/AIRobo.jpg"));
    Toollab ->setScaledContents(true);

/*****************************************************************************************/
/*****************************************************************************************/

    //操作界面设置
    //设置背景图片
    // Controllab=new QLabel(Controlbtn);
    // Controllab ->setPixmap(QPixmap(":/plc/jpg/AIRobo.jpg"));
    // Controllab ->setScaledContents(true);
    //设置垂直和水平布局
    //QVBoxLayout *AllControl_Layout=new QVBoxLayout();

/*****************************************************************************************/
/*****************************************************************************************/
    //帮助界面设置
    //设置背景图片
    Helplab=new QLabel(Helpbtn);
    Helplab ->setPixmap(QPixmap(":/plc/jpg/AIRobo.jpg"));
    Helplab ->setScaledContents(true);
    //设置最下方的版权号
    CopyrightLb=new QLabel();
    QVBoxLayout *All_Layout=new QVBoxLayout();
    QVBoxLayout *Allv_Layout=new QVBoxLayout();
    QHBoxLayout *Allh_Layout=new QHBoxLayout();
    CopyrightLb->setText("西安仁义智 版权所有");
    // 设置文本居中
    CopyrightLb->setAlignment(Qt::AlignCenter);
    CopyrightLb->setStyleSheet("font-size: 20px; color: red; font-weight: bold;");
    //设置按钮
    QHBoxLayout *PasswordLay=new QHBoxLayout();
    PasswordBtn=new QPushButton();
    PasswordBtn->setText("修改密码");
    //设置按钮大小
    PasswordBtn->setFixedSize(150,25);
    PasswordLab=new QLabel();
    PasswordLab ->setPixmap(QPixmap(":/plc/png/Password.png"));
    PasswordLab ->setScaledContents(true);
    PasswordLab->setFixedSize(35, 25);
    PasswordLay->addWidget(PasswordLab);
    PasswordLay->addWidget(PasswordBtn);

    QHBoxLayout *HelpLay=new QHBoxLayout();
    HelpBtn=new QPushButton();
    HelpBtn->setText("帮助与支持");
    //设置按钮大小
    HelpBtn->setFixedSize(150,25);
    HelpLab=new QLabel();
    HelpLab ->setPixmap(QPixmap(":/plc/png/HelpSup.png"));
    HelpLab ->setScaledContents(true);
    HelpLab->setFixedSize(35, 25);
    HelpLay->addWidget(HelpLab);
    HelpLay->addWidget(HelpBtn);

    QHBoxLayout *UpdateLay=new QHBoxLayout();
    UpdateBtn=new QPushButton();
    UpdateBtn->setText("检查版本更新");
    //设置按钮大小
    UpdateBtn->setFixedSize(150,25);
    UpdateLab=new QLabel();
    UpdateLab ->setPixmap(QPixmap(":/plc/png/update.png"));
    UpdateLab ->setScaledContents(true);
    UpdateLab->setFixedSize(35, 25);
    UpdateLay->addWidget(UpdateLab);
    UpdateLay->addWidget(UpdateBtn);

    QHBoxLayout *PhoneLay=new QHBoxLayout();
    PhoneBtn=new QPushButton();
    PhoneBtn->setText("客服电话");
    //设置按钮大小
    PhoneBtn->setFixedSize(150,25);
    PhoneLab=new QLabel();
    PhoneLab ->setPixmap(QPixmap(":/plc/png/Phone.png"));
    PhoneLab ->setScaledContents(true);
    PhoneLab->setFixedSize(35, 25);
    PhoneLay->addWidget(PhoneLab);
    PhoneLay->addWidget(PhoneBtn);

    QSpacerItem *hfirstSpacer = new QSpacerItem(150, 25, QSizePolicy::Minimum, QSizePolicy::Minimum);
    QSpacerItem *hendSpacer = new QSpacerItem(150, 25, QSizePolicy::Minimum, QSizePolicy::Minimum);
    Allh_Layout->addItem(hfirstSpacer);
    Allv_Layout->addLayout(PasswordLay);
    Allv_Layout->addLayout(HelpLay);
    Allv_Layout->addLayout(UpdateLay);
    Allv_Layout->addLayout(PhoneLay);
    Allh_Layout->addLayout(Allv_Layout);
    Allh_Layout->addItem(hendSpacer);

    //头部图片
    QHBoxLayout *Top_Layout=new QHBoxLayout();
    QSpacerItem *topfristSpacer = new QSpacerItem(150, 80, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem *topendSpacer = new QSpacerItem(150, 80, QSizePolicy::Expanding, QSizePolicy::Minimum);
    TopLab=new QLabel();
    TopLab->setPixmap(QPixmap(":/plc/png/ProMax.png"));
    TopLab->setScaledContents(true);
    TopLab->setFixedSize(80,80);
    Top_Layout->addItem(topfristSpacer);
    Top_Layout->addWidget(TopLab);
    Top_Layout->addItem(topendSpacer);

    //公司名称
    QHBoxLayout *Name_Layout=new QHBoxLayout();
    QSpacerItem *namefristSpacer = new QSpacerItem(150, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem *nameendSpacer = new QSpacerItem(150, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);
    NameLab=new QLabel();
    NameLab->setText("这是一家公司!!");
    NameLab->setAlignment(Qt::AlignCenter);
    NameLab->setFixedSize(150,25);
    Name_Layout->addItem(namefristSpacer);
    Name_Layout->addWidget(NameLab);
    Name_Layout->addItem(nameendSpacer);

    //版本号
    QHBoxLayout *Version_Layout=new QHBoxLayout();
    QSpacerItem *versionfristSpacer = new QSpacerItem(150, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem *versionendSpacer = new QSpacerItem(150, 25, QSizePolicy::Expanding, QSizePolicy::Minimum);
    version=new QLabel();
    version->setText("v1.0.0");
    version->setAlignment(Qt::AlignCenter);
    version->setFixedSize(150,25);
    Version_Layout->addItem(versionfristSpacer);
    Version_Layout->addWidget(version);
    Version_Layout->addItem(versionendSpacer);

    All_Layout->addLayout(Top_Layout);
    All_Layout->addLayout(Name_Layout);
    All_Layout->addLayout(Version_Layout);
    All_Layout->addLayout(Allh_Layout);
    All_Layout->addWidget(CopyrightLb);
    Helpbtn->setLayout(All_Layout);

    Helpbtn->setStyleSheet("QPushButton{"
                              "color:#ffffff; /*文字颜色*/"
                              "background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #29a0d2, stop: 1 #b5c28b);/*背景色*/"
                              "border-style:inset; /*边框风格*/"
                              "border-width:1px;/*边框宽度*/"
                              "border-color:#ffffff; /*边框颜色*/"
                              "border-radius:10px; /*边框倒角*/"
                              "font:bold 14px; /*字体*/"
                              "font-family: Segoe UI;min-width:100px;/*控件最小宽度*/"
                              "min-height:20px;/*控件最小高度*/"
                              "padding:4px;/*内边距*/}"
                              "QPushButton:pressed{"
                              "color:#ffffff; /*文字颜色*/"
                              "background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #a2e8f6, stop: 1 #7398a0);/*背景色*/"
                              "border-style:inset; /*边框风格*/"
                              "border-width:1px;/*边框宽度*/"
                              "border-color:#fffff0; /*边框颜色*/"
                              "border-radius:10px; /*边框倒角*/"
                              "font:bold 14px; /*字体*/"
                              "font-family: Segoe UI;min-width:100px;/*控件最小宽度*/"
                              "min-height:20px;/*控件最小高度*/"
                              "padding:4px;/*内边距*/}"
                              );
/*****************************************************************************************/
/*****************************************************************************************/

/*****************************************信号和槽连接**************************************/
    connect(Wread_date,&QPushButton::clicked,this,&MainWindow::Read_Text);
    connect(Clear_date,&QPushButton::clicked,this,&MainWindow::Clear_Logdate);
    connect(Recv_date,&QPushButton::clicked,this,&MainWindow::readDataFromFile);
    connect(Clear_Log,&QPushButton::clicked,this,&MainWindow::Clear_MsgLog);

    connect(KeySend,&QTimer::timeout,this,&MainWindow::timerSend);
    connect(RecvBtn,&QPushButton::clicked,this,&MainWindow::RecvBtn_slot);
    connect(BlueconnectBtn,&QPushButton::clicked,this,&MainWindow::connectblue);
    connect(searchBtn,&QPushButton::clicked,this,&MainWindow::searchblue);
    connect(disconnectBtn,&QPushButton::clicked,this,&MainWindow::CloseBlue);
    connect(SendBtn,&QPushButton::clicked,this,&MainWindow::Send_slot);
    connect(singnal_All->Controlbtn->Up_AGVBtn,&QPushButton::pressed,
            this,&MainWindow::sendupmasg_slot
            );
    connect(singnal_All->Controlbtn->Down_AGVBtn,&QPushButton::pressed,
            this,&MainWindow::senddownmasg_slot
            );
    connect(singnal_All->Controlbtn->Left_AGVBtn,&QPushButton::pressed,
            this,&MainWindow::sendleftmasg_slot
            );
    connect(singnal_All->Controlbtn->Right_AGVBtn,&QPushButton::pressed,
            this,&MainWindow::sendrightmasg_slot
            );
    connect(singnal_All->Controlbtn->Up_AGVBtn,&QPushButton::released,
            this,&MainWindow::sendstopmsg_slot
            );
    connect(singnal_All->Controlbtn->Down_AGVBtn,&QPushButton::released,
            this,&MainWindow::sendstopmsg_slot
            );
    connect(singnal_All->Controlbtn->Left_AGVBtn,&QPushButton::released,
            this,&MainWindow::sendstopmsg_slot
            );
    connect(singnal_All->Controlbtn->Right_AGVBtn,&QPushButton::released,
            this,&MainWindow::sendstopmsg_slot
            );

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Read_Text() {
    //requestPermissions();
    // 获取外部存储的标准路径
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) {
        QMessageBox::critical(this, "Error", "Failed to get writable location.");
        return;
    }
    // 确保路径存在
    QDir dir(path);
    if (!dir.exists()) {
        if (!dir.mkpath(path)) {
            QMessageBox::critical(this, "Error", "Failed to create directory: " + path);
            return;
        }
    }
    // 定义文件路径
    QString filePath = path + "/My_Log.txt";
    // 打开文件进行写入
    QFile file(filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open file: " + file.errorString());
        return;
    }
    // 判断文件是否为空
    bool fileIsEmpty = file.size() == 0;
    // 使用 QTextStream 写入数据
    QTextStream out(&file);
    QString text = Blue_LOG->toPlainText();
    if (fileIsEmpty) {
        text = text + "\n";
    } else {
        text = text + "\n";
    }
    out << text;
    // 关闭文件
    file.close();
    QMessageBox::information(this, "Success", "Data saved to: " + filePath);
}

void MainWindow::requestPermissions() {
    QJniObject activity = QJniObject::callStaticObjectMethod(
        "org/qtproject/qt6/android/QtNative",
        "activity",
        "()Landroid/app/Activity;"
        );
    if (activity.isValid()) {
        QJniEnvironment env;
        jobjectArray permissions = env->NewObjectArray(2, env->FindClass("java/lang/String"), nullptr);
        env->SetObjectArrayElement(permissions, 0, QJniObject::fromString("android.permission.WRITE_EXTERNAL_STORAGE").object<jstring>());
        env->SetObjectArrayElement(permissions, 1, QJniObject::fromString("android.permission.READ_EXTERNAL_STORAGE").object<jstring>());

        QJniObject::callStaticMethod<void>(
            "androidx/core/app/ActivityCompat",
            "requestPermissions",
            "(Landroid/app/Activity;[Ljava/lang/String;I)V",
            activity.object<jobject>(),
            permissions,
            0
            );
    } else {
        QMessageBox::critical(this, "Error", "Failed to get activity object.");
    }
}

void MainWindow::readDataFromFile()
{
    // 获取外部存储的标准路径
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) {
        QMessageBox::critical(this, "Error", "Failed to get writable location.");
        return;
    }
    // 定义文件路径
    QString filePath = path + "/My_Log.txt";
    // 打开文件进行读取
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open file: " + file.errorString());
        return;
    }
    // 使用 QTextStream 读取数据
    QTextStream in(&file);
    QString text = in.readAll();
    // 关闭文件
    file.close();
    // 显示数据
    Blue_LOG->setPlainText(text);
}



void MainWindow::RecvBtn_slot()
{
    if(is_blueconnect)
    {
        singnal_All->My_Blue->readCharacteristicValue();
    }else
    {
        addToLogs("请先连接蓝牙，再读取信息！！！");
    }
}

void MainWindow::set_UISize(const QRect &rect)
{
    UI_rect=rect;
    UI_W=rect.width();
    UI_H=rect.height();
    setGeometry(0,0,UI_W*0.95,UI_H);
}

//日志输出函数
void MainWindow::addToLogs(QString message)
{
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    Blue_LOG->append(message+"\t"+currentDateTime);
}

//连接蓝牙
void MainWindow::connectblue()
{
    QString check_Text=Blue_Box->currentText();
    QStringList str=check_Text.split(' ');
    QString deviceAddres=str.last();
    singnal_All->My_Blue->connectBlue(check_Text);
    addToLogs(deviceAddres);
}

//断开蓝牙的连接
void MainWindow::CloseBlue()
{
    singnal_All->My_Blue->breakBlue();
}

void MainWindow::searchblue()
{
    singnal_All->My_Blue->searchBlue();
    connect(singnal_All->My_Blue,&My_Bluetooth::search_Blue,this,&MainWindow::search_Blue);
    connect(singnal_All->My_Blue,&My_Bluetooth::connect_Blue,this,&MainWindow::connected_Blue);
    connect(singnal_All->My_Blue,&My_Bluetooth::recv_Blue,this,&MainWindow::Recv_slot);
    connect(singnal_All->My_Blue,&My_Bluetooth::finsh_Blue,this,&MainWindow::finsh_blued);
    connect(singnal_All->My_Blue,&My_Bluetooth::discon_Blue,this,&MainWindow::disconBlue_slot);
}

void MainWindow::finsh_blued()
{
    this->addToLogs("初始化成功");
    this->BlueconnectBtn->setEnabled(true);
}

void MainWindow::connected_Blue()
{
    QMessageBox::information(nullptr,"提示","已成功连接蓝牙！");
    this->BlueconnectBtn->setEnabled(false);
    is_blueconnect=true;
    this->disconnectBtn->setEnabled(true);
}

void MainWindow::search_Blue(QString ptr)
{
    Blue_Box->addItem(ptr);
    this->addToLogs(ptr);
}

void MainWindow::sendupmasg_slot()
{
    if(is_blueconnect)
    {
        keypressd.insert("up",true);
        keySendMsg.insert("up","0xc0");
        KeySend->start(10);
        singnal_All->Controlbtn->set_Label("send masg 0xc0");
    }else
    {
       singnal_All->Controlbtn->set_Label("请链接蓝牙");
    }
}

void MainWindow::senddownmasg_slot()
{
    if(is_blueconnect)
    {
        keypressd.insert("down",true);
        keySendMsg.insert("down","0xa0");
        KeySend->start(10);
        singnal_All->Controlbtn->set_Label("send masg 0xa0");
    }else
    {
        singnal_All->Controlbtn->set_Label("请链接蓝牙");
    }
}

void MainWindow::sendleftmasg_slot()
{
    if(is_blueconnect)
    {
        keypressd.insert("left",true);
        keySendMsg.insert("left","0x90");
        KeySend->start(10);
        singnal_All->Controlbtn->set_Label("send masg 0x90");
    }else
    {
        singnal_All->Controlbtn->set_Label("请链接蓝牙");
    }
}

void MainWindow::sendrightmasg_slot()
{
    if(is_blueconnect)
    {
        keypressd.insert("right",true);
        keySendMsg.insert("right","0x88");
        KeySend->start(10);
        singnal_All->Controlbtn->set_Label("send masg 0x88");
    }else
    {
        singnal_All->Controlbtn->set_Label("请链接蓝牙");
    }
}

void MainWindow::sendstopmsg_slot()
{
    if(is_blueconnect)
    {
        QString text="0x80";
        singnal_All->My_Blue->sendBlue(text);
        singnal_All->Controlbtn->set_Label("send masg 0x80");
        KeySend->stop();
    }else
    {
        singnal_All->Controlbtn->set_Label("请链接蓝牙");
    }
}

void MainWindow::Recv_slot(QString text)
{
    //发送到画图函数中，添加数据
    //singnal_All->drawecurve->setSpeed_Agv();
    this->addToLogs(text);
}

void MainWindow::Send_slot()
{
    if(is_blueconnect)
    {
        QString text=this->Send_Text->text();
        singnal_All->My_Blue->sendBlue(text);
    }else
    {
        addToLogs("请先连接蓝牙!!!");
    }
}

void MainWindow::disconBlue_slot()
{
    is_blueconnect=false;
    addToLogs("蓝牙已断开");
    this->BlueconnectBtn->setEnabled(true);
    this->disconnectBtn->setEnabled(false);
}

void MainWindow::timerSend()
{
    for (auto it = keypressd.begin(); it != keypressd.end(); ++it) {
        if(it.value())
        {
            QString text=keySendMsg.value(it.key());
            singnal_All->My_Blue->sendBlue(text);
            addToLogs(keySendMsg.value(it.key()));
        }
    }
}

void MainWindow::Clear_Logdate()
{
    // 获取外部存储的标准路径
    QString path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (path.isEmpty()) {
        QMessageBox::critical(this, "Error", "Failed to get writable location.");
        return;
    }

    // 确保路径存在
    QDir dir(path);
    if (!dir.exists()) {
        if (!dir.mkpath(path)) {
            QMessageBox::critical(this, "Error", "Failed to create directory: " + path);
            return;
        }
    }

    // 定义文件路径
    QString filePath = path + "/My_Log.txt";

    // 打开文件进行写入
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open file: " + file.errorString());
        return;
    }

    // 使用 QTextStream 写入数据
    QTextStream out(&file);
    QString text = nullptr;
    out << text;

    // 关闭文件
    file.close();

    QMessageBox::information(this, "Success", "Data saved to: " + filePath);
}

void MainWindow::Clear_MsgLog()
{
    this->Blue_LOG->clear();
}

void MainWindow::resizeEvent(QResizeEvent *ev)
{
    Connectlab->resize(this->size());
    Showlab->resize(this->size());
    Toollab->resize(this->size());
    Helplab->resize(this->size());
}

void MainWindow::setbarcss(int index)
{
    QString cStyleSheet=QString(
        "QTabBar::tab:nth-child(%1) {"
        "   min-width: 70px; "
        "   min-height: 35px;"
        "   background: pink;"
        "   color: black;"
        "   padding: 5px;"
        "   margin: 5px;"
        "}"
        "QTabBar::tab:pressed {"
        "   background: pink;"
        "   color: black;"
        "}").arg(index);
    this->setStyleSheet(cStyleSheet);
}

void MainWindow::restorecss(int index)
{
    QString cStyleSheet=QString(
      "QTabBar::tab:nth-child(%1) {"
      "   min-width: 70px; "
      "   min-height: 35px;"
      "   background: lightblue;"
      "   color: black;"
      "   padding: 5px;"
      "   margin: 5px;"
      "}"
      "QTabBar::tab:pressed {"
      "   background: pink;"
      "   color: black;"
    "}").arg(index);
    this->setStyleSheet(cStyleSheet);
}

void MainWindow::showLoginDialog()
{
    My_Dialog loginDialog(this);

    // 使用 exec() 方法显示对话框并等待用户操作
    if (loginDialog.exec() == QDialog::Accepted) {
        QString username = loginDialog.getUsername();
        QString password = loginDialog.getPassword();

        // 在这里进行验证
        if (username == "susu" && password == "12138") {
            // 验证通过
            QMessageBox::information(this, "登录", "登录成功!");
            // 进入系统或进行其他操作

            // 这里添加主界面的切换或初始化代码
            return;  // 登录成功后返回
        } else {
            // 验证失败，提示用户
            QMessageBox::warning(this, "登录", "账号或密码输入错误");
            showLoginDialog();  // 重新显示对话框
        }
    } else {
        // 用户点击了取消或关闭对话框
        QMessageBox::information(this, "登录", "请重新输入账号密码");
        // 这里可以考虑不再递归调用，而是结束已经关闭的对话框
        // 可以选择直接返回，或在必要时重新显示对话框
    }
}

