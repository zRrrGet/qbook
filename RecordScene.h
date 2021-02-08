#ifndef RECORDSCENE_H
#define RECORDSCENE_H
#include <QPixmap>
#include <QTime>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QCursor>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "record.h"
#include "sceneseats.h"

class RecordScene : public QGraphicsScene {
private:
    QString userRecordName; // имя авторизованного пользователя
    SceneSeats *sceneSeats;

public:
  RecordScene(QGraphicsScene *sc, QString userRecordName) : QGraphicsScene(sc), userRecordName(userRecordName) {

  };
  SceneSeats *getsceneSeats() const
  {
  return sceneSeats;
  }
  QString getuserRecordName() const
  {
      return userRecordName;
  }

  void setSceneSeats(SceneSeats *value)
  {
      sceneSeats = value;
  }
};
#endif // RECORDSCENE_H


