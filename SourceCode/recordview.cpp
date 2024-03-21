#include "recordview.h"
#include "ui_recordview.h"
#include "idatabase.h"
RecordView::RecordView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecordView)
{
    ui->setupUi(this);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);
    IDatabase &iDatabase=IDatabase::getInstance();
    if(iDatabase.initRecoreModel()){
        ui->tableView->setModel(iDatabase.recordTabModel);
        ui->tableView->setSelectionModel(iDatabase.theRecordSelection);
    }
}

RecordView::~RecordView()
{
    delete ui;
}

void RecordView::on_btSearch_clicked()
{
    QString filter = QString("pname like '%%1%'").arg(ui->txtSearch->text());
    IDatabase::getInstance().searchRecore(filter);
}


void RecordView::on_btAdd_clicked()
{
    int currow = IDatabase::getInstance().addNewRecore();
    emit goRecoreEditView(currow);
}


void RecordView::on_btDelete_clicked()
{
    IDatabase::getInstance().deleteCurrentRecore();
}


void RecordView::on_btEdit_clicked()
{
    QModelIndex curIndex=IDatabase::getInstance().theRecordSelection->currentIndex();
    emit goRecoreEditView(curIndex.row());
}

