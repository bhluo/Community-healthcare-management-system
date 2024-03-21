#include "medicineditview.h"
#include "ui_medicineditview.h"
#include "idatabase.h"
#include <QSqlTableModel>
MedicineditView::MedicineditView(QWidget *parent,int index) :
    QWidget(parent),
    ui(new Ui::MedicineditView)
{
    ui->setupUi(this);
    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().medicineTabModel;
    dataMapper->setModel(IDatabase::getInstance().medicineTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    dataMapper->addMapping(ui->dbEditID,tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->dbEditName,tabModel->fieldIndex("billname"));
    dataMapper->addMapping(ui->dbEditNum,tabModel->fieldIndex("num"));
    dataMapper->addMapping(ui->dbEditLastnum,tabModel->fieldIndex("lastnum"));
    dataMapper->setCurrentIndex(index);
}

MedicineditView::~MedicineditView()
{
    delete ui;
}

void MedicineditView::on_pushButton_clicked()
{
    IDatabase::getInstance().submitMedicineEdit();
    qDebug()<<"submitdatabase";
    emit goPreviousView();
}


void MedicineditView::on_pushButton_2_clicked()
{
    IDatabase::getInstance().revertMedicine();
    emit goPreviousView();
}

