#ifndef ADDRECORDDIALOG_H
#define ADDRECORDDIALOG_H

#include <QDialog>
#include <RecordScene.h>

namespace Ui {
class addRecordDialog; // класс окошка для добавления записи по нажатию на место
}

class addRecordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addRecordDialog(QWidget *parent = nullptr, RecordScene *scene = nullptr, int num = -1);
    ~addRecordDialog();

private slots:
    void on_OKButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::addRecordDialog *ui;

    RecordScene *sc; // указатель на сцену
    int num; // номер нажатого места
};

#endif // ADDRECORDDIALOG_H
