#include "citizens.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include <cmath>
#include "enemy.h"
#include <iostream>

Citizens::Citizens(int x, int y) {

    QPixmap citizen(":/new/prefix1/builder.jpeg");
    citizen =citizen.scaledToHeight(50);
    citizen=citizen.scaledToWidth(50);
    setPixmap(citizen);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=]() { move(x,y); });
    timer->start(100);


}
Citizens::~Citizens()
{


}


void Citizens::move(int targetX, int targetY) {
    // Calculate the direction vector towards the target coordinates
    int dx = targetX - pos().x();
    int dy = targetY - pos().y();

    // Calculate the distance to the target coordinates
    double distance = sqrt(dx * dx + dy * dy);

    // Ensure that the distance is not zero to avoid division by zero
    if (distance != 0) {
        // Calculate the unit vector components
        double unitX = dx / distance;
        double unitY = dy / distance;

        // Move the enemy towards the target coordinates with a certain speed
        double speed = 8.0; // Adjust the speed as needed
        setPos(pos().x() + unitX * speed, pos().y() + unitY * speed);
    }

    const double epsilon = 3.0; // Adjust as needed for precision

    // Check if the citizen is close enough to the target position
    if (distance <= epsilon) {
        Walls *newwall = new Walls();
        newwall->setPos(targetX, targetY);
        scene()->addItem(newwall);
        delete this;
    }

    QList<QGraphicsItem*> colliding_items = collidingItems();
    foreach(QGraphicsItem* citizen, colliding_items)
    {
        if (typeid(*citizen) == typeid(Enemy))
        {
            // Remove the citizen
            scene()->removeItem(this);
            delete this;

    }


}
}

