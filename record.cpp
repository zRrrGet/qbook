#include "record.h"

Record::Record(QString name, int num, QDate date, QTime startTime, QTime endTime) : userName(name), num(num),
    date(date), startTime(startTime), endTime(endTime)
{

}

QString Record::getUserName() const
{
    return userName;
}

void Record::setUserName(const QString &value)
{
    userName = value;
}

QDate Record::getDate() const
{
    return date;
}

void Record::setDate(const QDate &value)
{
    date = value;
}

int Record::getNum() const
{
    return num;
}

void Record::setNum(int value)
{
    num = value;
}

QTime Record::getStartTime() const
{
    return startTime;
}

void Record::setStartTime(const QTime &value)
{
    startTime = value;
}

QTime Record::getEndTime() const
{
    return endTime;
}

void Record::setEndTime(const QTime &value)
{
    endTime = value;
}

Record::Record() {

}
