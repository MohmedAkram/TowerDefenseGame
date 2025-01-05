#include "game.h"
#include <QTimer>
#include "enemy.h"
#include "walls.h"
#include "clancastle.h"
#include "citizens.h"
#include "score.h"
#include "health.h"
#include "newgamewindow.h"


int Enemyspeed= 3;
int level = 1;
int timeRemaining = 20;
QTimer* gameTimer = new QTimer();
Game::Game(int speed) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,600);
    // Create the scene with the screen size
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1000,900);
    setScene(scene);



    // Initialize clan and components
    Tower1 = new DefenseTower(); // Initialize Tower1
    Tower1->setPos(600, 200);
    scene->addItem(Tower1);

    score -> setDefaultTextColor(Qt::blue);
    score -> setPlainText("Score: " + QString::number(score->score));
    score ->setPos(600,18);
    score->setFont((QFont("times",16)));
    scene -> addItem(score);
    bringScoreToFront(score);
    health -> setDefaultTextColor(Qt::blue);
    health -> setPlainText("health: " + QString::number(health->gethealth()));
    health ->setPos(600,0);
    health->setFont((QFont("times",16)));
    scene -> addItem(health);
    bringHealthToFront(health);

    Clan clan;
    clan.loadMatrixFromFile(":/new/prefix1/map.txt");
    Walls *walls = new Walls();
    ClanCastle *clancastle = new ClanCastle();
    DefenseTower *defensetower = new DefenseTower();
    defensetower->AttackTarget();
    Citizens * citizen;
    clan.displayMatrix(*scene, walls, clancastle, defensetower,citizen);

    // Set properties
    int castlePosx = clancastle->getcoorx();
    int castlePosy = clancastle->getcoory();


    timerDisplay = new QGraphicsTextItem();
    timerDisplay->setFont(QFont("times", 16));
    timerDisplay->setDefaultTextColor(Qt::blue);
    timerDisplay->setPlainText("Time Remaining:" + timeRemaining);
    timerDisplay->setPos(100, 18); // Adjust position as needed
    scene->addItem(timerDisplay);
    bringTimerToFront();

    QTimer *gameTimer = new QTimer();
    connect(gameTimer, &QTimer::timeout, this, &Game::updateTimerDisplay);
    gameTimer->start(1000);
    QTimer *fiveSecondTimer = new QTimer();
    connect(fiveSecondTimer, &QTimer::timeout, this, [gameTimer, fiveSecondTimer]() {
        // Stop and disconnect the gameTimer
        gameTimer->stop();
        disconnect(gameTimer, nullptr, nullptr, nullptr);
        fiveSecondTimer->stop();
        fiveSecondTimer->deleteLater();
    });


    fiveSecondTimer->start(21700);





    // Create timer for enemy generation
    // Create a QTimer for generating enemies
    QTimer *time = new QTimer();
    connect(time, &QTimer::timeout, [=]() {
        createEnemy(castlePosx, castlePosy, speed);
    });

    // Timer to stop and disconnect the `time` timer after a specific duration

    // Start the timers
    time->start(2000);         // Enemy creation every 2 seconds


//  Connect the timeout signal of the timer to the newgame() function
    //connect(newGameTimer, &QTimer::timeout, this, &Game::newgame);

//Start the timer with a period of 10,000 milliseconds (10 seconds)

 }

void Game::createEnemy(int x,int y,int speed) {
    Enemy* enemy = new Enemy(x,y,speed);
    scene->addItem(enemy);
}

void Game::mousePressEvent(QMouseEvent *event) {

    QPointF targetPos = mapToScene(event->pos());
    QPointF towerPos = Tower1 ->pos();
    QPointF direction = targetPos - towerPos;

    qreal angle = qAtan2(direction.y(), direction.x());
    qreal angleDegrees = qRadiansToDegrees(angle);

    Arrow *arrow = new Arrow;
    arrow->setPos(towerPos);
    arrow->setRotation(angleDegrees);
    Tower1->scene()->addItem(arrow);
 }

void Game::bringScoreToFront(Score *score) {
    qreal maxZValue = 0;
    foreach (QGraphicsItem *item, score->scene()->items()) {
        if (item->zValue() > maxZValue) {
            maxZValue = item->zValue();
        }
    }

    // Set the Score item's zValue to be higher than the highest zValue
    score->setZValue(maxZValue + 1);
}


void Game::bringHealthToFront(Health *health) {
    qreal maxPValue = 0;
    foreach (QGraphicsItem *item, score->scene()->items()) {
        if (item->zValue() > maxPValue) {
            maxPValue = item->zValue();
        }
    }

    // Set the Score item's zValue to be higher than the highest zValue
    health->setZValue(maxPValue + 1);
}

     void Game::bringTimerToFront() {
         qreal maxZValue = 0;
         foreach (QGraphicsItem *item, scene->items()) {
             if (item->zValue() > maxZValue) {
                 maxZValue = item->zValue();
             }
         }

         // Set the timer display's zValue to be higher than the highest zValue
         timerDisplay->setZValue(maxZValue + 1);
     }
     void Game::updateTimerDisplay() {
         timerDisplay->setPlainText("Time Remaining: " + QString::number(timeRemaining--));
         if (isTimeDone()) {
             gameTimer->stop(); // Stop the timer
             close();
             disconnect();
             newgamewindow *newg = new newgamewindow();
             newg->show();
         }
     }
     bool Game::isTimeDone() {
         if (timeRemaining == 0)
         {
             return true;
         }
         return false;
     }


