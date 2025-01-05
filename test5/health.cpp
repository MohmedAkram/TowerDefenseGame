#include "health.h"
#include<QFont>
Health::Health()
{

}
int Health::gethealth()
{
    return health;
}
void Health :: dechealth()
{
    health--;
    setPlainText("Health: " + QString::number(health));
}
Health *health = new Health();
