#include "score.h"
#include<QFont>

Score::Score()
{
    score = 0;
}

void Score::increase()
{
    score++;
    setPlainText("Score: " + QString::number(score));

}
Score *score = new Score();
