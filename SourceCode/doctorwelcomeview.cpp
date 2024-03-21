#include "doctorwelcomeview.h"
#include "ui_doctorwelcomeview.h"

DoctorwelcomeView::DoctorwelcomeView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorwelcomeView)
{
    ui->setupUi(this);
}

DoctorwelcomeView::~DoctorwelcomeView()
{
    delete ui;
}

void DoctorwelcomeView::on_btDepartment_clicked()
{
     emit goDepartmentView();
}


void DoctorwelcomeView::on_btPatient_clicked()
{
     emit goPatientView();
}


void DoctorwelcomeView::on_btrecord_clicked()
{
    emit goRecordView();
}

