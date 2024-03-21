#ifndef IDATABASE_H
#define IDATABASE_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QDataWidgetMapper>
class IDatabase : public QObject
{
    Q_OBJECT
public:

    static IDatabase &getInstance()
    {
        static IDatabase instance;
        return instance;
     }
     QString userLogin(QString userName,QString password);
     QString doctorLogin(QString userName,QString password);

private:
    explicit IDatabase(QObject *parent = nullptr);
    IDatabase(IDatabase const&)= delete;
    void operator=(IDatabase const&)  = delete;

    QSqlDatabase database;

    void ininDatabase();


signals:


public:
    bool initPatientModel();
    int addNewPatient();
    bool searchPatient(QString filter);
    bool deleteCurrentPatient();
    bool submitPatientEdit();
    void revertPatient();
    bool initMedicineModel();
    int addNewMedicine();
    bool searchMedicine(QString filter);
    bool deleteCurrentMedicine();
    bool submitMedicineEdit();
    void revertMedicine();
    bool initRecoreModel();
    int addNewRecore();
    bool searchRecore(QString filter);
    bool deleteCurrentRecore();
    bool submitRecoreEdit();
    void revertRecore();
    bool initDoctorModel();
    int addNewDoctor();
    bool searchDoctor(QString filter);
    bool deleteCurrentDoctor();
    bool submitDoctorEdit();
    void revertDoctor();

    QSqlTableModel *patientTabModel;
    QItemSelectionModel *thePatientSelection;
    QSqlTableModel *medicineTabModel;
    QItemSelectionModel *theMedicineSelection;
    QSqlTableModel *recordTabModel;
    QItemSelectionModel *theRecordSelection;
    QSqlTableModel *doctorTabModel;
    QItemSelectionModel *theDoctorSelection;


};

#endif // IDATABASE_H
