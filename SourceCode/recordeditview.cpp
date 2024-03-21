#include "recordeditview.h"
#include "ui_recordeditview.h"
#include "idatabase.h"
#include <QSqlTableModel>
RecordEditView::RecordEditView(QWidget *parent,int index) :
    QWidget(parent),
    ui(new Ui::RecordEditView)
{
    ui->setupUi(this);

    dataMapper = new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().recordTabModel;
    dataMapper->setModel(IDatabase::getInstance().recordTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    dataMapper->addMapping(ui->dbEditID_2,tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->dbEditPname_2,tabModel->fieldIndex("pname"));
    dataMapper->addMapping(ui->EditBill,tabModel->fieldIndex("medicine"));
    dataMapper->addMapping(ui->EditResult,tabModel->fieldIndex("result"));
    dataMapper->addMapping(ui->Editdate,tabModel->fieldIndex("date"));
    dataMapper->addMapping(ui->dbEditDname,tabModel->fieldIndex("dname"));
    dataMapper->setCurrentIndex(index);
}

RecordEditView::~RecordEditView()
{
    delete ui;
}

void RecordEditView::on_pushButton_3_clicked()
{
    IDatabase::getInstance().submitRecoreEdit();
    emit goPreviousView();
}


void RecordEditView::on_pushButton_4_clicked()
{
    IDatabase::getInstance().revertRecore();
    emit goPreviousView();
}

