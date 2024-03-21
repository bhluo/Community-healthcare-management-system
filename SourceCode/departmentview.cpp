#include "departmentview.h"
#include "ui_departmentview.h"
#include "idatabase.h"
DepartmentView::DepartmentView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepartmentView)
{
    ui->setupUi(this);

    ui->tableView_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView_2->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_2->setAlternatingRowColors(true);
    IDatabase &iDatabase=IDatabase::getInstance();
    if(iDatabase.initMedicineModel()){
        ui->tableView_2->setModel(iDatabase.medicineTabModel);
        ui->tableView_2->setSelectionModel(iDatabase.theMedicineSelection);
    }


//    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
//    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
//    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    ui->tableView->setAlternatingRowColors(true);
//    IDatabase &iDatabase=IDatabase::getInstance();
//    if(iDatabase.initPatientModel()){
//        ui->tableView->setModel(iDatabase.patientTabModel);
//        ui->tableView->setSelectionModel(iDatabase.thePatientSelection);
//    }
}

DepartmentView::~DepartmentView()
{
    delete ui;
}


void DepartmentView::on_btSearch_2_clicked()
{
    QString filter = QString("billname like '%%1%'").arg(ui->txtSearch_2->text());
    IDatabase::getInstance().searchMedicine(filter);
}


void DepartmentView::on_btAdd_2_clicked()
{
    qDebug()<<"1111";
    int currow = IDatabase::getInstance().addNewMedicine();
    qDebug()<<"2222";
    emit goMedicineEditView(currow);
}


void DepartmentView::on_btDelete_2_clicked()
{
    IDatabase::getInstance().deleteCurrentMedicine();
}


void DepartmentView::on_btEdit_2_clicked()
{
    QModelIndex curIndex=IDatabase::getInstance().theMedicineSelection->currentIndex();
   emit goMedicineEditView(curIndex.row());
}

