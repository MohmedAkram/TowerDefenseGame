#ifndef CLAN_H
#define CLAN_H

#include <QObject>
#include <QGraphicsScene>
#include "citizens.h"
#include "walls.h"
#include "clancastle.h"
#include "defensetower.h"

class Clan : public QObject
{
    Q_OBJECT
public:
    explicit Clan(QObject *parent = nullptr);
    void loadMatrixFromFile(const QString &filename);
    void displayMatrix(QGraphicsScene &scene,Walls *walls = nullptr,ClanCastle *clancastle = nullptr,DefenseTower *defensetower = nullptr, Citizens * citizen = nullptr );


private:
    std::vector<std::vector<char>> matrix;

};

#endif // CLAN_H
