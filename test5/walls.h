#ifndef WALLS_H
#define WALLS_H
#include <QObject>
#include <QGraphicsPixmapItem>

class Walls: public QObject , public QGraphicsPixmapItem
{   Q_OBJECT
public:
    Walls();
    void dechealth();
    int gethealth();
private:
    int health = 10;
};

#endif // WALLS_H
