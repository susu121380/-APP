#include "my_dialog.h"

My_Dialog::My_Dialog(QWidget *parent) : QDialog(parent) {
    ShowBack=new QLabel(this);
    ShowBack->setPixmap(QPixmap(":/plc/jpg/BackLogin.jpg"));
    ShowBack->setScaledContents(true);
    this->showFullScreen(); // 设置为全屏显示
    QHBoxLayout *H_layout=new QHBoxLayout();
    avatar=new QLabel();
    H_layout->addWidget(avatar);

    QLabel *usernameLabel = new QLabel("Username:");
    usernameEdit = new QLineEdit(this);

    QLabel *passwordLabel = new QLabel("Password:");
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password); // 隐藏密码

    QPushButton *loginButton = new QPushButton("Login", this);
    QPushButton *cancelButton = new QPushButton("Cancel", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addLayout(H_layout);
    layout->addWidget(usernameLabel);
    layout->addWidget(usernameEdit);
    layout->addWidget(passwordLabel);
    layout->addWidget(passwordEdit);
    layout->addWidget(loginButton);
    layout->addWidget(cancelButton);

    connect(loginButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

QString My_Dialog::getUsername() const {
    return usernameEdit->text();
}

QString My_Dialog::getPassword() const {
    return passwordEdit->text();
}

void My_Dialog::resizeEvent(QResizeEvent *ev)
{
    ShowBack->resize(this->size());
}
