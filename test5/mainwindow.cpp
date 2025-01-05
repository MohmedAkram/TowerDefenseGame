#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
extern int Enemyspeed;
extern int level;
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Startbutton_clicked()
{
    hide();
    Game* game = new Game(Enemyspeed);
    game->show();

}


void MainWindow::on_pushButton_2_clicked()
{
    hide();
    close();

}


void MainWindow::on_Exitbutton_clicked()
{
    hide();
    close();
}

