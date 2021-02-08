#ifndef RECORD_H
#define RECORD_H
#include <QDate>
#include <QTime>
#include <QGraphicsPixmapItem>

class Record // класс запись в котором определены время записи дата имя пользователя и место
{
private:
    QDate date;
    QTime startTime; // время начала действия записи
    QTime endTime; // время когда запись заканчивается
    QString userName;
    int num; // номер места
public:

    Record();
    Record(QString userName, int num, QDate date, QTime startTime, QTime endTime);

    QString getUserName() const;
    void setUserName(const QString &value);
    QDate getDate() const;
    void setDate(const QDate &value);
    int getNum() const;
    void setNum(int value);
    QTime getStartTime() const;
    void setStartTime(const QTime &value);
    QTime getEndTime() const;
    void setEndTime(const QTime &value);
};

#endif // RECORD_H
