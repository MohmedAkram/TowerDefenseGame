#include "walls.h"

Walls::Walls() {
    QPixmap wall(":/new/prefix1/wall.jpeg");
    wall =wall.scaledToHeight(50);
    wall=wall.scaledToWidth(50);
    setPixmap(wall);
}
void Walls::dechealth()
{
    health--;
}
int Walls::gethealth()
{
    return health;
}
