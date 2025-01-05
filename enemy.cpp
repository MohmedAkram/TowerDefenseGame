#include "enemy.h"
#include "walls.h"
#include <QGraphicsScene>
#include <stdlib.h> // rand() -> to generate really large integer
#include <QMessageBox>
#include <QTimer>
#include "citizens.h"
#include "health.h"
#include <QDebug>
#include <cmath>
#include "walls.h"
Enemy::Enemy(int x, int y,int speed) {
    QPixmap chicken(":/new/prefix1/Chicken.png");
    chicken = chicken.scaledToHeight(50);
    chicken = chicken.scaledToWidth(50);
    setPixmap(chicken);

    int forbiddenMinX = 250;
    int forbiddenMaxX = 900;
    int forbiddenMinY = 25;
    int forbiddenMaxY = 425;

    int random_numberx, random_numbery;
    do {
        // Generate random coordinates within the valid range
        random_numberx = rand() % 900;
        random_numbery = rand() % 900;
    } while (random_numberx >= forbiddenMinX && random_numberx <= forbiddenMaxX &&
             random_numbery >= forbiddenMinY && random_numbery <= forbiddenMaxY);

    // Set the position using the valid coordinates
    setPos(random_numberx, random_numbery);


    // Create a timer and connect its timeout signal to the move function
    QTimer *timer = new QTimer(this);

    connect(timer, &QTimer::timeout, [=]() { move(x, y,speed); });
    timer->start(50);
    QTimer *disconnectTimer = new QTimer(this);
    connect(disconnectTimer, &QTimer::timeout, [=]() {
        timer->stop();                      // Stop the move timer
        disconnect(timer, nullptr, nullptr, nullptr); // Disconnect all signals
        disconnectTimer->stop();            // Stop this disconnect timer
        disconnectTimer->deleteLater();     // Clean up the disconnect timer
    });
    disconnectTimer->start(21700); // Set the duration (e.g., 5000 ms or 5 seconds)

}



void Enemy::move(int targetX, int targetY, int speed) {
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
        double Speed = speed; // Adjust the speed as needed
        setPos(pos().x() + unitX * Speed, pos().y() + unitY * Speed);
    }
    if (distance == 0){
        //health->dechealth();
        delete this;
        }
        QList<QGraphicsItem *> collidingItemsList = collidingItems();
    for (int i = 0; i < collidingItemsList.size(); ++i) {
        if (typeid(*(collidingItemsList[i])) == typeid(Walls)) {
            // Move the enemy back 10 pixels in the x and y direction
            setPos(x() - 3, y() + 3);

            // Decrease wall's health
            Walls *wall = dynamic_cast<Walls*>(collidingItemsList[i]);
            if (wall) {
                wall->dechealth();
                if (wall->gethealth() <= 0) {
                    // Remove the wall from the scene

                    scene()->removeItem(wall);
                    delete wall;
                    Citizens* citizen = new Citizens(wall->x(),wall->y());
                    scene()->addItem(citizen);
                    }

                }
            }
        }
    }



