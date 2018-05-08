#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "confirmnewgame.h"
#include "confirmloadgame.h"
#include "confirmquitgame.h"


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
    confirmNewGame alertNewGame;
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
