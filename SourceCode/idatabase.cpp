#include "idatabase.h"
#include <QDebug>
#include <QUuid>
void IDatabase::ininDatabase()
{
    database=QSqlDatabase::addDatabase("QSQLITE");
    QString aFile="../Lab4a.db";
    database.setDatabaseName(aFile);
    if(!database.open()){
        qDebug()<<"fail to open database";
    }else{
        qDebug()<<"open database is ok";
    }
}

bool IDatabase::initPatientModel()
{
    patientTabModel=new QSqlTableModel(this,database);
    patientTabModel->setTable("patient");
    patientTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    patientTabModel->setSort(patientTabModel->fieldIndex("name"),Qt::AscendingOrder);
    if(!(patientTabModel->select()))
        return false;

    thePatientSelection=new QItemSelectionModel(patientTabModel);
    return true;
}

int IDatabase::addNewPatient()
{
    patientTabModel->insertRow(patientTabModel->rowCount(),QModelIndex());
    QModelIndex curIndex = patientTabModel->index(patientTabModel->rowCount()-1,1);

    int curRecNo=curIndex.row();
    QSqlRecord curRec = patientTabModel->record(curRecNo);
    curRec.setValue("CREATEDTIMESTAMP",QDateTime::currentDateTime().toString("yyyy-MM-dd"));
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces));
    patientTabModel->setRecord(curRecNo,curRec);
    return curIndex.row();
}

bool IDatabase::searchPatient(QString filter)
{
    patientTabModel->setFilter(filter);
    return patientTabModel->select();
}

bool IDatabase::deleteCurrentPatient()
{
    QModelIndex curIndex=thePatientSelection->currentIndex();
    patientTabModel->removeRow(curIndex.row());
    patientTabModel->submitAll();
    patientTabModel->select();
}

bool IDatabase::submitPatientEdit()
{
    return patientTabModel->submitAll();
}

void IDatabase::revertPatient()
{
    return patientTabModel->revertAll();
}

bool IDatabase::initMedicineModel()
{
    medicineTabModel=new QSqlTableModel(this,database);
    medicineTabModel->setTable("medicine");
    medicineTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    medicineTabModel->setSort(medicineTabModel->fieldIndex("billname"),Qt::AscendingOrder);
    if(!(medicineTabModel->select()))
    {
        qDebug()<<"初始化错误";
        return false;
    }

    theMedicineSelection=new QItemSelectionModel(medicineTabModel);
    qDebug()<<"初始化成功";
    return true;
}

int IDatabase::addNewMedicine()
{
    medicineTabModel->insertRow(medicineTabModel->rowCount(),QModelIndex());
    QModelIndex curIndex = medicineTabModel->index(medicineTabModel->rowCount()-1,1);
    int curRecNo=curIndex.row();
    QSqlRecord curRec = medicineTabModel->record(curRecNo);
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces));
    medicineTabModel->setRecord(curRecNo,curRec);
    return curIndex.row();
}

bool IDatabase::searchMedicine(QString filter)
{
    medicineTabModel->setFilter(filter);
    return medicineTabModel->select();
}

bool IDatabase::deleteCurrentMedicine()
{
    QModelIndex curIndex=theMedicineSelection->currentIndex();
    medicineTabModel->removeRow(curIndex.row());
    medicineTabModel->submitAll();
    medicineTabModel->select();
}

bool IDatabase::submitMedicineEdit()
{
    return medicineTabModel->submitAll();
}

void IDatabase::revertMedicine()
{
    return medicineTabModel->revertAll();
}

bool IDatabase::initRecoreModel()
{
    recordTabModel=new QSqlTableModel(this,database);
    recordTabModel->setTable("record");
    recordTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    recordTabModel->setSort(recordTabModel->fieldIndex("pname"),Qt::AscendingOrder);
    if(!(recordTabModel->select()))
    {
        qDebug()<<"初始化错误";
        return false;
    }

    theRecordSelection=new QItemSelectionModel(recordTabModel);
    qDebug()<<"初始化成功";
    return true;
}

int IDatabase::addNewRecore()
{
    recordTabModel->insertRow(recordTabModel->rowCount(),QModelIndex());
    QModelIndex curIndex = recordTabModel->index(recordTabModel->rowCount()-1,1);
    int curRecNo=curIndex.row();
    QSqlRecord curRec = recordTabModel->record(curRecNo);
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces));
    recordTabModel->setRecord(curRecNo,curRec);
    return curIndex.row();
}

bool IDatabase::searchRecore(QString filter)
{
    recordTabModel->setFilter(filter);
    return recordTabModel->select();
}

bool IDatabase::deleteCurrentRecore()
{
    QModelIndex curIndex=theRecordSelection->currentIndex();
    recordTabModel->removeRow(curIndex.row());
    recordTabModel->submitAll();
    recordTabModel->select();
}

bool IDatabase::submitRecoreEdit()
{
    return recordTabModel->submitAll();
}

void IDatabase::revertRecore()
{
    return recordTabModel->revertAll();
}

bool IDatabase::initDoctorModel()
{
    doctorTabModel=new QSqlTableModel(this,database);
    doctorTabModel->setTable("Doctor");
    doctorTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    doctorTabModel->setSort(doctorTabModel->fieldIndex("dname"),Qt::AscendingOrder);
    if(!(doctorTabModel->select()))
    {
        qDebug()<<"初始化错误";
        return false;
    }

    theDoctorSelection=new QItemSelectionModel(doctorTabModel);
    qDebug()<<"初始化成功";
    return true;
}

int IDatabase::addNewDoctor()
{
    doctorTabModel->insertRow(doctorTabModel->rowCount(),QModelIndex());
    QModelIndex curIndex = doctorTabModel->index(doctorTabModel->rowCount()-1,1);
    int curRecNo=curIndex.row();
    QSqlRecord curRec = doctorTabModel->record(curRecNo);
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces));
    doctorTabModel->setRecord(curRecNo,curRec);
    return curIndex.row();
}

bool IDatabase::searchDoctor(QString filter)
{
    doctorTabModel->setFilter(filter);
    return doctorTabModel->select();
}

bool IDatabase::deleteCurrentDoctor()
{
    QModelIndex curIndex=theDoctorSelection->currentIndex();
    doctorTabModel->removeRow(curIndex.row());
    doctorTabModel->submitAll();
    doctorTabModel->select();
}

bool IDatabase::submitDoctorEdit()
{
    return doctorTabModel->submitAll();
}

void IDatabase::revertDoctor()
{
    return doctorTabModel->revertAll();
}

QString IDatabase::userLogin(QString userName, QString password)//管理员登录
{

    QSqlQuery query;
    //查询数据库表
    query.prepare("select username,password from user where username=:USER");
    query.bindValue(":USER",userName);
    query.exec();
    //检验账号密码
    if(query.first()&&query.value("username").isValid()){
        QString passwd=query.value("password").toString();
        if(passwd==password){
            return "loginOk";
        }
        else{
             qDebug()<<"wrongPassword";
            return "wrongPassword";
        }
    }
    else{
        qDebug()<<"no such user";
        return "wrongUsername";
    }

}

QString IDatabase::doctorLogin(QString userName, QString password)
{
    QSqlQuery query;
    query.prepare("select dname,dpassword from doctorlogin where dname=:USER");
    query.bindValue(":USER",userName);
    query.exec();
    //检验账号密码
    if(query.first()&&query.value("dname").isValid()){
        QString passwd=query.value("dpassword").toString();
        if(passwd==password){
            return "loginOk";
        }
        else{
             qDebug()<<"wrongPassword";
            return "wrongPassword";
        }
    }
    else{
        qDebug()<<"no such doctor";
        return "wrongDoctorname";
    }
}

IDatabase::IDatabase(QObject *parent) : QObject(parent)
{
    ininDatabase();
}
