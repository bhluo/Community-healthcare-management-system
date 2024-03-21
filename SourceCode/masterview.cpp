#include "masterview.h"
#include "ui_masterview.h"
#include <QDebug>
#include "idatabase.h"
MasterView::MasterView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MasterView)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::FramelessWindowHint);
    goLoginView();

    IDatabase::getInstance();
}

MasterView::~MasterView()
{
    delete ui;
}

void MasterView::goLoginView()
{
    qDebug()<<"goLoginView";
    loginView = new LoginView(this);
    pushWidgetToStackView(loginView);

    connect(loginView,SIGNAL(loginSuccess()),this,SLOT(goWelcomeView()));
    connect(loginView,SIGNAL(DoctorloginSuccess()),this,SLOT(goDoctorWelcomeView()));

}

void MasterView::goWelcomeView()
{
    qDebug()<<"goWelcomeView";
    welcomeView = new WelcomeView(this);
    pushWidgetToStackView(welcomeView);

    connect(welcomeView,SIGNAL(goDoctorView()),this,SLOT(goDoctorView()));
    connect(welcomeView,SIGNAL(goDepartmentView()),this,SLOT(goDepartmentView()));
    connect(welcomeView,SIGNAL(goPatientView()),this,SLOT(goPatientView()));
    connect(welcomeView,SIGNAL(goRecordView()),this,SLOT(goRecordView()));

}

void MasterView::goDoctorView()
{
    qDebug()<<"goDoctorView";
    doctorView = new DoctorView(this);
    pushWidgetToStackView(doctorView);
    connect(doctorView,SIGNAL(goDoctorEditView(int )),this,SLOT(goDoctorEditView(int)));
}

void MasterView::goDepartmentView()
{
    qDebug()<<"goMedicineView";
    departmentView = new DepartmentView(this);
    pushWidgetToStackView(departmentView);
    connect(departmentView,SIGNAL(goMedicineEditView(int )),this,SLOT(goMedicineEditView(int)));
}
void MasterView::goRecordView()
{
    qDebug()<<"goRecordView";
    recordView = new RecordView(this);
    pushWidgetToStackView(recordView);
    connect(recordView,SIGNAL(goRecoreEditView(int )),this,SLOT(goRecoreEditView(int)));
}

void MasterView::goRecoreEditView(int rowNo)
{
    qDebug()<<"goRecordEditView";
    recordEditView = new RecordEditView(this,rowNo);
    pushWidgetToStackView(recordEditView);
    connect(recordEditView,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void MasterView::goMedicineEditView(int rowNo)
{

//    qDebug()<<"goPatientEditView";
//    patientEditView = new PatientEditView(this,rowNo);
//    pushWidgetToStackView(patientEditView);
//    connect(patientEditView,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
    qDebug()<<"goMedicineditView";
    medicineEditView = new MedicineditView(this,rowNo);
    pushWidgetToStackView(medicineEditView);
    connect(medicineEditView,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void MasterView::goDoctorEditView(int rowNo)
{
    qDebug()<<"goDoctorEditView";
    doctorEditView = new DoctorEditView(this,rowNo);
    pushWidgetToStackView(doctorEditView);
    connect(doctorEditView,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void MasterView::goDoctorWelcomeView()
{
    qDebug()<<"goDoctorWelcomeView";
    doctorwelcomeView = new DoctorwelcomeView(this);
    pushWidgetToStackView(doctorwelcomeView);

    connect(doctorwelcomeView,SIGNAL(goDepartmentView()),this,SLOT(goDepartmentView()));
    connect(doctorwelcomeView,SIGNAL(goPatientView()),this,SLOT(goPatientView()));
    connect(doctorwelcomeView,SIGNAL(goRecordView()),this,SLOT(goRecordView()));
}

void MasterView::goPatientEditView(int rowNo)
{
    qDebug()<<"goPatientEditView";
    patientEditView = new PatientEditView(this,rowNo);
    pushWidgetToStackView(patientEditView);
    connect(patientEditView,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void MasterView::goPatientView()
{
    qDebug()<<"goPatientView";
    patientView = new PatientView(this);
    pushWidgetToStackView(patientView);

    connect(patientView,SIGNAL(goPatientEditView(int )),this,SLOT(goPatientEditView(int)));

}

void MasterView::goPreviousView()
{
    int count=ui->stackedWidget->count();
    if(count>1) {
        ui->stackedWidget->setCurrentIndex(count-2);
        ui->labelTitle->setText(ui->stackedWidget->currentWidget()->windowTitle());

        QWidget *widget = ui->stackedWidget->widget(count-1);
        ui->stackedWidget->removeWidget(widget);
        delete  widget;
    }
}


void MasterView::pushWidgetToStackView(QWidget *widget)
{
    ui->stackedWidget->addWidget(widget);
    int count = ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(count - 1);
    ui->labelTitle->setText(widget->windowTitle());
}


void MasterView::on_btBack_clicked()
{
    goPreviousView();
}


void MasterView::on_stackedWidget_currentChanged(int arg1)
{
    int count =ui->stackedWidget->count();

    if(count>1){
        ui->btBack->setEnabled(true);
    }
    else{
        ui->btBack->setEnabled(false);
    }
    QString title = ui->stackedWidget->currentWidget()->windowTitle();

    if(title=="欢迎"){
        ui->btLogOut->setEnabled(true);
        ui->btBack->setEnabled(false);
    }else{
        ui->btLogOut->setEnabled(false);
    }
}


void MasterView::on_btLogOut_clicked()
{
    goPreviousView();
}







