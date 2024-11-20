#ifndef MY_DIALOG_H
#define MY_DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class My_Dialog : public QDialog
{
    Q_OBJECT
public:
    My_Dialog(QWidget *parent = nullptr);
    QString getUsername() const;
    QString getPassword() const;
protected:
    void resizeEvent(QResizeEvent *ev);
private:
    QLabel *avatar;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLabel *ShowBack;
};

#endif // MY_DIALOG_H
