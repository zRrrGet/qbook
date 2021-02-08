#ifndef SCENESEATS_H
#define SCENESEATS_H
#include <QGraphicsView>
#include <QList>
#include <QTimeEdit>
#include "record.h"

class SceneSeats // класс оперирует местами
{
private:
    QGraphicsView *v;
    QList<Record> records; // все записи(берутся из файлы bookings.ini)
    QCalendarWidget *currentDate;
    QTimeEdit *currentTime;

public:
    const QList<QList<int>> poss= {{54,50},{54,110},{54,160},{54,200},{54,245}, // позиции мест на сцене
                            {55,25},{55,75},{55,120},{55,165},
                            {216,30},{216,75},{216,120},{216,165},{216,210},
                            {319,50},{319,95},{319,140},{319,185},{319,235},
                            {322,30},{322,75},{322,120},{322,165},{322,210},
                            {426,50},{426,95},{426,140},{426,185},{426,235},
                            {437,30},{437,75},{437,120},{437,165},{437,210},
                            {541,50},{541,95},{541,140},{541,185},{541,235},
                            {553,30},{553,75},{553,120},{553,165},{553,210}};
    SceneSeats(QGraphicsView *view, QCalendarWidget *currentDate, QTimeEdit *currentTime);
    void updateSeats();
    void updateRecords();
    QList<Record> getRecords() const;
};

#endif // SCENESEATS_H
