#include "widget.h"
#include "ui_widget.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    Controllab=new QLabel(this);
    Controllab ->setPixmap(QPixmap(":/plc/jpg/AIRobo.jpg"));
    Controllab ->setScaledContents(true);
    QHBoxLayout *hlayout=new QHBoxLayout();
    QVBoxLayout *vlayout=new QVBoxLayout();
    // 创建网格布局
    QGridLayout *gridLayout = new QGridLayout();
    Up_AGVBtn=new QPushButton();
    Up_AGVBtn->setFixedSize(70,70);
    Up_AGVBtn->setStyleSheet("QPushButton {"
                         "border-image: url(:/plc/png/up.png); }");
    Down_AGVBtn=new QPushButton();
    Down_AGVBtn->setFixedSize(70,70);
    Down_AGVBtn->setStyleSheet("QPushButton {"
                             "border-image: url(:/plc/png/down.png); }");
    Left_AGVBtn=new QPushButton();
    Left_AGVBtn->setFixedSize(70,70);
    Left_AGVBtn->setStyleSheet("QPushButton {"
                             "border-image: url(:/plc/png/lift.png); }");
    Right_AGVBtn=new QPushButton();
    Right_AGVBtn->setFixedSize(70,70);
    Right_AGVBtn->setStyleSheet("QPushButton {"
                             "border-image: url(:/plc/png/right.png); }");

    gridLayout->setSpacing(0);       // 设置按钮之间的间距为0
    gridLayout->setContentsMargins(0, 0, 0, 0); // 设置边距为0

    middleLab=new QLabel();
    middleLab->setStyleSheet("QLabel {"
                             "border-image: url(:/plc/png/dirc.png); }");
    middleLab->setFixedSize(70,70);

    brakeButton=new QPushButton();
    brakeButton->setFixedSize(100,150);
    brakeButton->setStyleSheet("QPushButton {"
                                "border-image: url(:/plc/png/brake.png); }");

    throttleButton=new QPushButton();
    throttleButton->setFixedSize(100,150);
    throttleButton->setStyleSheet("QPushButton {"
                               "border-image: url(:/plc/png/throttle.png); }");

    showstate=new QLabel();
    showstate->setFixedHeight(80);
    showstate->setStyleSheet("QLabel {"
        "      opacity: 0.5;"
        "      }"
        "      QLabel {"
        "      padding: 10px;"/* 内边距 */
        "      margin: 5px; /* 外边距 */"
        "      border-style: solid; /* 边框样式 */"
        "      border-width: 2px; /* 边框宽度 */"
        "      border-color: #1c7cd6; /* 边框颜色 */"
        "      border-radius: 5px; /* 边框圆角 */"
        "      color: #e83591; /* 文本颜色 */"
        "      font-size: 28px; /* 字体大小 */"
        "      font-weight: bold; /* 字体粗细 */"
        "      font-family: Arial; /* 字体家族 */"
        "      };"
        );

    gridLayout->addWidget(Up_AGVBtn,0,1);
    gridLayout->addWidget(Left_AGVBtn,1,0);
    gridLayout->addWidget(middleLab,1,1);
    gridLayout->addWidget(Right_AGVBtn,1,2);
    gridLayout->addWidget(Down_AGVBtn,2,1);
    QSpacerItem *oneendSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem *twoendSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    hlayout->addLayout(gridLayout);
    hlayout->addItem(oneendSpacer);
    hlayout->addWidget(throttleButton);
    hlayout->addWidget(brakeButton);
    vlayout->addWidget(showstate);
    vlayout->addItem(twoendSpacer);
    vlayout->addLayout(hlayout);
    this->setLayout(vlayout);
    //信号和槽连接
    connect(Up_AGVBtn,&QPushButton::pressed,this,&Widget::set_upBtn_slot);
    connect(Down_AGVBtn,&QPushButton::pressed,this,&Widget::set_downBtn_slot);
    connect(Left_AGVBtn,&QPushButton::pressed,this,&Widget::set_liftBtn_slot);
    connect(Right_AGVBtn,&QPushButton::pressed,this,&Widget::set_rightBtn_slot);

    connect(Right_AGVBtn,&QPushButton::released,this,&Widget::set_rightBtn_slot);
    connect(Up_AGVBtn,&QPushButton::released,this,&Widget::set_upBtn_slot);
    connect(Down_AGVBtn,&QPushButton::released,this,&Widget::set_downBtn_slot);
    connect(Left_AGVBtn,&QPushButton::released,this,&Widget::set_liftBtn_slot);

    connect(brakeButton,&QPushButton::pressed,this,&Widget::set_break_slot);
    connect(throttleButton,&QPushButton::pressed,this,&Widget::set_throttl_slot);

    connect(brakeButton,&QPushButton::released,this,&Widget::set_break_slot);
    connect(throttleButton,&QPushButton::released,this,&Widget::set_throttl_slot);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::resizeEvent(QResizeEvent *ev)
{
    Controllab->resize(this->size());
}

void Widget::set_break_slot()
{
    is_brake=!is_brake;
    if(is_brake)
    {
        brakeButton->setStyleSheet("QPushButton {"
                                   "border-image: url(:/plc/png/brakeclick.png); }");
    }else
    {
        brakeButton->setStyleSheet("QPushButton {"
                                   "border-image: url(:/plc/png/brake.png); }");
    }
}

void Widget::set_throttl_slot()
{
    is_throttle=!is_throttle;
    if(is_throttle)
    {
        throttleButton->setStyleSheet("QPushButton {"
                                   "border-image: url(:/plc/png/throttleclick.png); }");
    }else
    {
        throttleButton->setStyleSheet("QPushButton {"
                                   "border-image: url(:/plc/png/throttle.png); }");
    }
}

void Widget::set_Label(const QString str)
{
    this->showstate->setText(str);
}

void Widget::set_upBtn_slot()
{
    up_btn=!up_btn;
    if(up_btn)
    {
        Up_AGVBtn->setStyleSheet("QPushButton {"
                                 "border-image: url(:/plc/png/upclick.png); }");
        middleLab->setStyleSheet("QLabel {"
                                 "border-image: url(:/plc/png/dircclick.png); }");
        set_Label("The car is turning upwards");
    }else
    {
        Up_AGVBtn->setStyleSheet("QPushButton {"
                                   "border-image: url(:/plc/png/up.png); }");
        middleLab->setStyleSheet("QLabel {"
                                 "border-image: url(:/plc/png/dirc.png); }");
    }
}

void Widget::set_downBtn_slot()
{
    down_btn=!down_btn;
    if(down_btn)
    {
        Down_AGVBtn->setStyleSheet("QPushButton {"
                                   "border-image: url(:/plc/png/downclick.png); }");
        middleLab->setStyleSheet("QLabel {"
                                 "border-image: url(:/plc/png/dircclick.png); }");
        set_Label("The car is turning downward");
    }else
    {
        Down_AGVBtn->setStyleSheet("QPushButton {"
                                   "border-image: url(:/plc/png/down.png); }");
        middleLab->setStyleSheet("QLabel {"
                                 "border-image: url(:/plc/png/dirc.png); }");
    }
}

void Widget::set_liftBtn_slot()
{
    lift_btn=!lift_btn;
    if(lift_btn)
    {
        Left_AGVBtn->setStyleSheet("QPushButton {"
                                   "border-image: url(:/plc/png/liftclick.png); }");
        middleLab->setStyleSheet("QLabel {"
                                 "border-image: url(:/plc/png/dircclick.png); }");
        set_Label("The car is turning to the left");
    }else
    {
        Left_AGVBtn->setStyleSheet("QPushButton {"
                                    "border-image: url(:/plc/png/lift.png); }");
        middleLab->setStyleSheet("QLabel {"
                                 "border-image: url(:/plc/png/dirc.png); }");
    }
}

void Widget::set_rightBtn_slot()
{
    right_btn=!right_btn;
    if(right_btn)
    {
        Right_AGVBtn->setStyleSheet("QPushButton {"
                                    "border-image: url(:/plc/png/rightclick.png); }");
        middleLab->setStyleSheet("QLabel {"
                                 "border-image: url(:/plc/png/dircclick.png); }");
        set_Label("The car is turning to the right");
    }else
    {
        Right_AGVBtn->setStyleSheet("QPushButton {"
                                    "border-image: url(:/plc/png/right.png); }");
        middleLab->setStyleSheet("QLabel {"
                                 "border-image: url(:/plc/png/dirc.png); }");
    }
}
