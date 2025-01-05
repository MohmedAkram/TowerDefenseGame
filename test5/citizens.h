#ifndef CITIZENS_H
#define CITIZENS_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "walls.h"


class Citizens: public QObject , public QGraphicsPixmapItem
{
public:
    Citizens(int x, int y);
    ~Citizens();
public slots:
    void move(int targetX, int targetY);

};

#endif// CITIZENS_H
