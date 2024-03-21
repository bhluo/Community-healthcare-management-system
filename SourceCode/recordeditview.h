#ifndef RECORDEDITVIEW_H
#define RECORDEDITVIEW_H

#include <QWidget>
#include <QDataWidgetMapper>
namespace Ui {
class RecordEditView;
}

class RecordEditView : public QWidget
{
    Q_OBJECT

public:
    explicit RecordEditView(QWidget *parent = nullptr,int index=0);
    ~RecordEditView();

private:
    Ui::RecordEditView *ui;
    QDataWidgetMapper *dataMapper;
signals:
    void goPreviousView();
private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};

#endif // RECORDEDITVIEW_H
