#include "clan.h"
#include "citizens.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <QGraphicsPixmapItem>


Clan::Clan(QObject *parent) : QObject(parent) {}

void Clan::loadMatrixFromFile(const QString &filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "Failed to open file" << std::endl;
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        std::vector<char> rowElements;
        for (int col = 0; col < line.size(); ++col) {
            rowElements.push_back(line[col].toLatin1());
        }
        matrix.push_back(rowElements);
    }



    file.close();
}

void Clan::displayMatrix(QGraphicsScene &scene, Walls *walls, ClanCastle *clancastle,DefenseTower *defensetower, Citizens * citizen) {
    for (int row = 0; row < matrix.size(); ++row) {
        for (int col = 0; col < matrix[row].size(); ++col) {
            QGraphicsPixmapItem *item = nullptr;
            switch (matrix[row][col]) {
            case '0':
                item = new QGraphicsPixmapItem(QPixmap("C:/Users/moham/OneDrive/Desktop/pics/images.jpeg"));
                item->setPos(col * 50, row * 50);
                scene.addItem(item);

                break;
            case '1':
                if (clancastle != nullptr) {
                    clancastle->setPos(col * 50, row * 50);
                    scene.addItem(clancastle);
                }
                break;
            case '2':
                if (defensetower != nullptr) {
                    DefenseTower *newdefensetower = new DefenseTower();
                    newdefensetower->setPos(col * 50, row * 50);
                    scene.addItem(newdefensetower);
                }
                break;
            case '3':
                if (walls != nullptr) {
                    Walls *newWall = new Walls();  // Create a new instance of Walls
                    newWall->setPos(col * 50, row * 50); // Set position for the new wall
                    scene.addItem(newWall); // Add the new wall to the scene
                }
                break;

            default:
                break;

            }

}
}
}
