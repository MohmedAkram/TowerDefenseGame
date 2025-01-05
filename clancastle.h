#ifndef CLANCASTLE_H
#define CLANCASTLE_H
#include <QObject>
#include <QGraphicsPixmapItem>

class ClanCastle: public QObject , public QGraphicsPixmapItem
{   Q_OBJECT
public:
    ClanCastle();
    int getcoorx();
    int getcoory();
};

#endif // CLANCASTLE_H
