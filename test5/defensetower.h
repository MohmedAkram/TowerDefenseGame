#ifndef DEFENSETOWER_H
#define DEFENSETOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>

class DefenseTower : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
public:
    DefenseTower(QGraphicsItem * parent=0);
    QGraphicsPolygonItem * AttackArea;
    QPointF attack_dest;
public slots:
    void AttackTarget();
};

#endif // DEFENSETOWER_H
