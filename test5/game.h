#ifndef GAME_H
#define GAME_H
#include "clan.h"
#include<QGraphicsView>
#include <QMouseEvent>
#include "defensetower.h"
#include "arrow.h"



class Score;
class Health;
extern QTimer* gameTimer;
class Game: public QGraphicsView
{
public:
    QGraphicsTextItem *timerDisplay;
    void bringTimerToFront();
    void mousePressEvent(QMouseEvent *event);
    QGraphicsScene *scene;
    Game(int speed);
    void createCitizen();
    DefenseTower* Tower1;
    void bringScoreToFront(Score* score);
    void bringHealthToFront(Health* health);
    void newgame();
    void updateTimerDisplay();
    bool isTimeDone();
public slots:
    void createEnemy(int x, int y, int speed);
};

#endif // GAME_H
