#include "addrecorddialog.h"
#include "ui_addrecorddialog.h"
#include <RecordScene.h>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

addRecordDialog::addRecordDialog(QWidget *parent, RecordScene *scene, int num) :
    QDialog(parent),
    ui(new Ui::addRecordDialog)
{
    ui->setupUi(this);

    sc=scene;

    this->num = num;

    ui->dateEdit->setDate(QDate::currentDate());
}

addRecordDialog::~addRecordDialog()
{
    delete ui;
}

void addRecordDialog::on_OKButton_clicked() // действия при нажатии OK
{

    foreach(Record r, sc->getsceneSeats()->getRecords()) {

        int a = r.getStartTime().msecsSinceStartOfDay();
        int b = r.getEndTime().msecsSinceStartOfDay();

        int c = ui->startTimeEdit->time().msecsSinceStartOfDay();
        int d = ui->endTimeEdit->time().msecsSinceStartOfDay();
        // входит ли выбранный временной промежуток в запись другого пользователя, если да - выводим сообщение
        if (!((a<=c&&b<=c)||(a>=d&&b>=d)) && r.getDate()==ui->dateEdit->date() && r.getNum()==num){
            QMessageBox::warning(this,"Ошибка","Заданный промежуток занят другим пользователем: "+r.getUserName()+" "+r.getStartTime().toString("HH:mm")+"-"+r.getEndTime().toString("HH:mm"));
            return;
        }
    }

    // если время начала записи превышает время конца записи
    if (ui->startTimeEdit->time().msecsSinceStartOfDay()>ui->endTimeEdit->time().msecsSinceStartOfDay()) QMessageBox::warning(this,"Ошибка","Некорректное время!");
    else {
        // открытие файла записей
        QFile out("bookings.ini");
        if (out.open(QFile::Append)) qDebug() << "nice open!";
        QTextStream data(&out);

        // запись в формате "имя номер_места дата время_начала конечное_время"
        data << sc->getuserRecordName() << " " << num << " " << ui->dateEdit->date().toString("dd.MM.yyyy") << " "
            << ui->startTimeEdit->time().toString("HH:mm") << " " << ui->endTimeEdit->time().toString("HH:mm") << "\n";

        out.close();
        sc->getsceneSeats()->updateSeats(); // обновляем сцену в соответствии с новой записью
        this->close();

    }
}

void addRecordDialog::on_cancelButton_clicked()
{
    this->close();
}
