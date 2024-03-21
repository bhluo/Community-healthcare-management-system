#ifndef MEDICINEDITVIEW_H
#define MEDICINEDITVIEW_H

#include <QWidget>
#include <QDataWidgetMapper>
namespace Ui {
class MedicineditView;
}

class MedicineditView : public QWidget
{
    Q_OBJECT

public:
    explicit MedicineditView(QWidget *parent = nullptr,int index=0);
    ~MedicineditView();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MedicineditView *ui;
    QDataWidgetMapper *dataMapper;
signals:
    void goPreviousView();
};

#endif // MEDICINEDITVIEW_H
