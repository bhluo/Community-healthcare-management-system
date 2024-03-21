#include "doctoreditview.h"
#include "ui_doctoreditview.h"
#include "idatabase.h"
#include <QSqlTableModel>

DoctorEditView::DoctorEditView(QWidget *parent,int index) :
    QWidget(parent),
    ui(new Ui::DoctorEditView)
{
    ui->setupUi(this);
    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().doctorTabModel;
    dataMapper->setModel(IDatabase::getInstance().doctorTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    dataMapper->addMapping(ui->dbEditID,tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->ComboSex,tabModel->fieldIndex("sex"));
    dataMapper->addMapping(ui->EditDname,tabModel->fieldIndex("dname"));
    dataMapper->addMapping(ui->EditAge,tabModel->fieldIndex("age"));
    dataMapper->addMapping(ui->EditBNum,tabModel->fieldIndex("certificateId"));
    dataMapper->setCurrentIndex(index);
}

DoctorEditView::~DoctorEditView()
{
    delete ui;
}

void DoctorEditView::on_pushButton_clicked()
{
    IDatabase::getInstance().submitDoctorEdit();
    qDebug()<<"submitdatabase";
    emit goPreviousView();
}


void DoctorEditView::on_pushButton_2_clicked()
{
    IDatabase::getInstance().revertDoctor();
    emit goPreviousView();
}

