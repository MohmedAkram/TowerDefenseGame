#include "walls.h"

Walls::Walls() {
    QPixmap wall("C:/Users/moham/OneDrive/Desktop/pics/wall.jpeg");
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
