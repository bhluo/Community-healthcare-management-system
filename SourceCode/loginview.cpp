#include "loginview.h"
#include "ui_loginview.h"
#include "idatabase.h"
LoginView::LoginView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginView)
{
    ui->setupUi(this);
}

LoginView::~LoginView()
{
    delete ui;
}

void LoginView::on_btSignUp_clicked()//管理员登录模块
{
    QString status= IDatabase::getInstance().userLogin(ui->inputUserName->text(),ui->inputUserPassword->text());
    if(status=="loginOk")//验证账号密码正确性
        emit loginSuccess();//跳转
}


void LoginView::on_DSignUp_clicked()//医生登录模块
{
    QString status= IDatabase::getInstance().doctorLogin(ui->inputUserName->text(),ui->inputUserPassword->text());
    if(status=="loginOk")
        emit DoctorloginSuccess();
}

