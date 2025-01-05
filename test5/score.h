#ifndef SCORE_H
#define SCORE_H

#endif // SCORE_H
#include <QGraphicsTextItem>
class Score: public QGraphicsTextItem
{
public:
    Score();
    void increase();
    int score;
private:
};
extern Score *score;
