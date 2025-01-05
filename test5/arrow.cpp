#include "arrow.h"
#include "enemy.h"
#include "score.h"
#include "health.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QGraphicsScene>



Arrow::Arrow(QGraphicsItem *parent) {

    //connecting the timer to the move method
    setPixmap(QPixmap("C:/Users/moham/Downloads/ball.png").scaled(50,50));
    QTimer * move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(50);
}

void Arrow::move(){ //arrow movement aka how fast it moves
    int STEP_SIZE = 30;
    double theta = rotation();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx,y()+dy);

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            score->increase();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
}
