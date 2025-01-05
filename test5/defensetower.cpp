#include "defensetower.h"
#include "arrow.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QTimer>



DefenseTower::DefenseTower(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent) {

    setPixmap(QPixmap(":/new/prefix1/archer tower.jpeg").scaled(50,50));

    // set of pointers for the attack area/radius to make a polygon out of them
    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) <<  QPoint(2,3)
           << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    int SCALE_FACTOR = 50;
    for (size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE_FACTOR;
    }


}

void DefenseTower::AttackTarget(){
    Arrow * arrow = new Arrow;
    arrow->setPos(x()+128, y()+128);

    //rotates arrow to be parallel to shooting line
    QLineF ln(QPointF(x()+128, y()+128), attack_dest);
    int angle = -1 * ln.angle(); //getting the angle,
    arrow->setRotation(angle);
}
