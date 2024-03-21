#ifndef DOCTORWELCOMEVIEW_H
#define DOCTORWELCOMEVIEW_H

#include <QWidget>

namespace Ui {
class DoctorwelcomeView;
}

class DoctorwelcomeView : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorwelcomeView(QWidget *parent = nullptr);
    ~DoctorwelcomeView();

private slots:
    void on_btDepartment_clicked();

    void on_btPatient_clicked();

    void on_btrecord_clicked();
signals:
    void goDepartmentView();
    void goPatientView();
    void goRecordView();
private:
    Ui::DoctorwelcomeView *ui;
};

#endif // DOCTORWELCOMEVIEW_H
