#include "sceneseats.h"
#include "record.h"
#include "RecordScene.h"
#include <QTime>
#include <QDate>
#include <QCalendarWidget>
#include "ClickableQPixmap.h"
#include <QSettings>
#include <QTextStream>
#include <QFile>

#define freepm ":/assets/freeSeat.jpg"
#define occupiedpm ":/assets/occupiedSeat.jpg"

SceneSeats::SceneSeats(QGraphicsView *view, QCalendarWidget *currentDate, QTimeEdit *currentTime) :
    v(view), currentDate(currentDate), currentTime(currentTime) {

    updateSeats();

}

void SceneSeats::updateSeats() // обновить места на сцене в соответствии с массивом records
{
    updateRecords(); // обновить массив records в соответствии с файлом bookings.ini


    // удаляем все места со сцены
    foreach(QGraphicsItem *g, v->scene()->items(Qt::AscendingOrder))
        if (g->pos()!=QPointF(0,0)) delete g; // условие нужно, чтобы не удалить фон

    for (int i = 1;i<=poss.length(); ++i) { // на каждую позицию из poss ставим кресло
        ClickableQPixmap* pixmapItem = new ClickableQPixmap(QPixmap(freepm)); // создаем свободное кресло
        pixmapItem->setIsOccupied(false);
        pixmapItem->setToolTip("Свободное место!");

        // нужно ли повернуть кресло
        if ((i>=1&&i<=5) || (i>=15&&i<=19) || (i>=25&&i<=29) || (i>=35&&i<=39)) pixmapItem->setRotation(180);
        // добавляем его на сцену и устанавливаем ему позицию из const массива poss
        v->scene()->addItem(pixmapItem);
        v->scene()->items()[0]->setPos(poss[i-1][0],poss[i-1][1]);
    }

    foreach(Record r, records){
        // если на установленные дату и время есть запись, то меняем свободное место на занятое
        if ((currentTime->time().msecsSinceStartOfDay()>=r.getStartTime().msecsSinceStartOfDay())&&
                (currentTime->time().msecsSinceStartOfDay()<=r.getEndTime().msecsSinceStartOfDay())
            && (currentDate->selectedDate().toString("dd.MM.yyyy") == r.getDate().toString("dd.MM.yyyy")))
        {
            // функция itemAt() находит элемент сцены по координатам
            // поэтому для мест которые поворачивали на 180 градусов нужно искать по другим координатам
            // найденное место удаляем
            if (poss[r.getNum()][0]==54||poss[r.getNum()][0]==319||poss[r.getNum()][0]==426
                    ||poss[r.getNum()][0]==541)
                v->scene()->removeItem(v->scene()->itemAt(poss[r.getNum()][0]-10,poss[r.getNum()][1]-10,QTransform()));
            else v->scene()->removeItem(v->scene()->itemAt(poss[r.getNum()][0],poss[r.getNum()][1],QTransform()));


            // добавляем новое занятое место на место старого
            QGraphicsItem *it = v->scene()->addPixmap(QPixmap(occupiedpm));
            it->setPos(poss[r.getNum()][0],poss[r.getNum()][1]);

            // всплывающая подсказка
            it->setToolTip(r.getUserName()+": "+r.getStartTime().toString("HH:mm")+"-"+r.getEndTime().toString("HH:mm"));


            if (poss[r.getNum()][0]==54||poss[r.getNum()][0]==319||poss[r.getNum()][0]==426
                    ||poss[r.getNum()][0]==541)((ClickableQPixmap *)v->scene()->itemAt(poss[r.getNum()][0],poss[r.getNum()][1],QTransform()))->setRotation(180);
            v->scene()->update();
            v->viewport()->update();
        }
    }
}

void SceneSeats::updateRecords()
{
    // открываем файл с записями
    QFile in("bookings.ini");
    if (in.open(QFile::ReadOnly)) qDebug() << "nice open!";

    QTextStream data(&in);

    // очищаем массив с записями
    records.clear();

    // ввод и запись в массив с записями
    QString uname;
    data >> uname;
    while (uname!="") {
        int num;
        data >> num;
        QString date;
        data >> date;
        QString startTimeStr;
        data >> startTimeStr;
        QString endTimeStr;
        data >> endTimeStr;
        records.push_back(Record(uname,num,QDate::fromString(date,"dd.MM.yyyy"),
                                 QTime::fromString(startTimeStr,"HH:mm"),
                                 QTime::fromString(endTimeStr,"HH:mm")));
        data >> uname;
    }
}

QList<Record> SceneSeats::getRecords() const
{
    return records;
}
