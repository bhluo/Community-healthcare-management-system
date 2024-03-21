#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include <QWidget>
#include "loginview.h"
#include "doctorview.h"
#include "departmentview.h"
#include "patienteditview.h"
#include "patientview.h"
#include "welcomeview.h"
#include "recordview.h"
#include "medicineditview.h"
#include "recordeditview.h"
#include "doctoreditview.h"
#include "doctorwelcomeview.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MasterView; }
QT_END_NAMESPACE

class MasterView : public QWidget
{
    Q_OBJECT

public:
    MasterView(QWidget *parent = nullptr);
    ~MasterView();

public slots:
    void goLoginView();
    void goWelcomeView();
    void goDoctorView();
    void goDepartmentView();
    void goPatientEditView(int rowNo);
    void goPatientView();
    void goPreviousView();
    void goRecordView();
    void goRecoreEditView(int rowNo);
    void goMedicineEditView(int rowNo);
    void goDoctorEditView(int rowNo);
    void goDoctorWelcomeView();

private slots:
    void on_btBack_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_btLogOut_clicked();

private:
    void pushWidgetToStackView(QWidget *widget);

    Ui::MasterView *ui;

    WelcomeView *welcomeView;
    DoctorView *doctorView;
    PatientEditView *patientEditView;
    PatientView *patientView;
    LoginView *loginView;
    DepartmentView *departmentView;
    RecordView *recordView;
    MedicineditView *medicineEditView;
    RecordEditView *recordEditView;
    DoctorEditView *doctorEditView;
    DoctorwelcomeView *doctorwelcomeView;
};
#endif // MASTERVIEW_H
