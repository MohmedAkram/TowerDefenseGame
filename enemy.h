#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "walls.h"
#include "citizens.h"
#include "clancastle.h"

class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(int x, int y, int speed);

public slots:
    void move(int x, int y,int speed);
    //bool wallandcivillian(Walls*);

private:

};
#endif // ENEMY_H
