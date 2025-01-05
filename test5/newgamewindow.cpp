#include "newgamewindow.h"
#include "ui_newgamewindow.h"
#include "health.h"
#include "game.h"
newgamewindow::newgamewindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::newgamewindow)
{
    ui->setupUi(this);
}
extern Health* health;
extern int Enemyspeed;
extern int level;
extern int timeRemaining;
newgamewindow::~newgamewindow()
{
    delete ui;
}

void newgamewindow::on_Nextlevelbutton_clicked()
{
    timeRemaining = 20;
    close();
    Enemyspeed = Enemyspeed + 1;
    level = level + 1;
    ui ->label->setText("Welcome to level" + QString::number(level));
    Game* game = new Game(Enemyspeed);
    game->show();

}

