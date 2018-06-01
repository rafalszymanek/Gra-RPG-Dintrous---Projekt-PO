#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "confirmnewgame.h"
#include "confirmloadgame.h"
#include "confirmquitgame.h"
#include "charactercreator.h"
#include "gamecontroler.cpp"

#include <iostream>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(QSize(1000, 700)); // Ustawienie rozmiaru okna
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_newGame_clicked()
{

    confirmNewGame alertNewGame; // Zmienna do otworznia nowego
    alertNewGame.setModal(true);
    alertNewGame.exec();

}

void MainWindow::on_loadGame_clicked()
{
    confirmLoadGame alertLoadGame;
    alertLoadGame.setModal(true);
    alertLoadGame.exec();
}

void MainWindow::on_quitGame_clicked()
{
    confirmQuitGame alertQuitGame;
    alertQuitGame.setModal(true);
    alertQuitGame.exec();
}


void MainWindow::showCharacterCreator(){
      auto win = new characterCreator();
      win->setAttribute( Qt::WA_DeleteOnClose );
      win->show();
      deleteLater();
}
