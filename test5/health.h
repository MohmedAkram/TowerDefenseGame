#ifndef HEALTH_H
#define HEALTH_H

#endif // HEALTH_H
#include <QGraphicsTextItem>
class Health: public QGraphicsTextItem
{
public:
    Health();
    int gethealth();
    void dechealth();
private:
    int health = 10;
};
extern Health *health;
