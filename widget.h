#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void set_Label(const QString str);
    QPushButton *Up_AGVBtn;
    QPushButton *Down_AGVBtn;
    QPushButton *Left_AGVBtn;
    QPushButton *Right_AGVBtn;
    QLabel *Controllab;
    QLabel *middleLab;

    QPushButton *brakeButton;
    QPushButton *throttleButton;
    QLabel *showstate;

    bool up_btn=false;
    bool down_btn=false;
    bool lift_btn=false;
    bool right_btn=false;
    bool is_brake=false;
    bool is_throttle=false;
protected:
    void resizeEvent(QResizeEvent * ev) override;
private slots:
    void set_upBtn_slot();
    void set_downBtn_slot();
    void set_liftBtn_slot();
    void set_rightBtn_slot();
    void set_break_slot();
    void set_throttl_slot();

private:
    Ui::Widget *ui;
    int i=1;

};
#endif // WIDGET_H
