#ifndef CLICKABLEQPIXMAP_H
#define CLICKABLEQPIXMAP_H
#include <QPixmap>
#include <QTime>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QCursor>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "mainwindow.h"
#include "record.h"
#include "addrecorddialog.h"
#include <QMessageBox>
// класс-наследник QGraphicsPixmapItem, нужен чтобы определить методы mousePressEvent и hoverEnterEvent,
// которые срабатывать при нажатии и наведении соответственно

class ClickableQPixmap : public QGraphicsPixmapItem {

private:
    bool isOccupied; // стоит картинка с занятым местом или свободным

public:

    ClickableQPixmap(QPixmap pixmap);;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    bool getIsOccupied() const;
    void setIsOccupied(bool value);
};


#endif // CLICKABLEQPIXMAP_H


