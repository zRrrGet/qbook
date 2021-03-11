#include "ClickableQPixmap.h"


ClickableQPixmap::ClickableQPixmap(QPixmap pixmap): QGraphicsPixmapItem(pixmap) {
    setAcceptHoverEvents(true); // разрешаем hoverevents
}

void ClickableQPixmap::mousePressEvent(QGraphicsSceneMouseEvent *event) {

    int ind = 0;

    foreach(QList<int> p, ((RecordScene *)scene())->getsceneSeats()->poss) {
        if (QPointF(p[0],p[1])==this->pos()) break; // определение на какое место нажал пользователь
        ++ind;
    }

    // окошко для добавления записи
    addRecordDialog *d = new addRecordDialog(nullptr, (RecordScene *)scene(), ind);

    d->exec();

}

void ClickableQPixmap::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setCursor(QCursor(Qt::PointingHandCursor));
}

bool ClickableQPixmap::getIsOccupied() const
{
    return isOccupied;
}

void ClickableQPixmap::setIsOccupied(bool value)
{
    isOccupied = value;
}
