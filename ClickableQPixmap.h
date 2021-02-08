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
  ClickableQPixmap(QPixmap pixmap): QGraphicsPixmapItem(pixmap) {
      setAcceptHoverEvents(true); // разрешаем hoverevents
  };

  ~ClickableQPixmap() {
  };

  void mousePressEvent(QGraphicsSceneMouseEvent *event) {

      int ind = 0;



      foreach(QList<int> p, ((RecordScene *)scene())->getsceneSeats()->poss) {
          if (QPointF(p[0],p[1])==this->pos()) break; // определение на какое место нажал пользователь
          ++ind;
      }

      // окошко для добавления записи
      addRecordDialog *d = new addRecordDialog(nullptr, (RecordScene *)scene(), ind);

      d->exec();

  };

  void hoverEnterEvent(QGraphicsSceneHoverEvent *event)
   {
      setCursor(QCursor(Qt::PointingHandCursor));
  }

  bool getIsOccupied() const
  {
      return isOccupied;
  }

  void setIsOccupied(bool value)
  {
      isOccupied = value;
  }
};
#endif // CLICKABLEQPIXMAP_H


