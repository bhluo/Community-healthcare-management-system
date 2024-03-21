#ifndef DEPARTMENTVIEW_H
#define DEPARTMENTVIEW_H

#include <QWidget>

namespace Ui {
class DepartmentView;
}

class DepartmentView : public QWidget
{
    Q_OBJECT

public:
    explicit DepartmentView(QWidget *parent = nullptr);
    ~DepartmentView();

private slots:

    void on_btSearch_2_clicked();

    void on_btAdd_2_clicked();

    void on_btDelete_2_clicked();

    void on_btEdit_2_clicked();

signals:
    void goMedicineEditView(int idx);

private:
    Ui::DepartmentView *ui;
};

#endif // DEPARTMENTVIEW_H
