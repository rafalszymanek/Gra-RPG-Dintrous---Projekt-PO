#include "confirmquitgame.h"
#include "ui_confirmquitgame.h"

confirmQuitGame::confirmQuitGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confirmQuitGame)
{
    ui->setupUi(this);
}

confirmQuitGame::~confirmQuitGame()
{
    delete ui;
}

void confirmQuitGame::on_ButtonYes_clicked()
{
    this->close();
    QCoreApplication::quit();
}

void confirmQuitGame::on_ButtonNo_clicked()
{
    this->close();
}

void confirmQuitGame::on_ButtonCancel_clicked()
{
    this->close();
}
