#include "confirmloadgame.h"
#include "ui_confirmloadgame.h"
#include "charactercreator.h"

confirmLoadGame::confirmLoadGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confirmLoadGame)
{
    ui->setupUi(this);
}

confirmLoadGame::~confirmLoadGame()
{
    delete ui;
}

void confirmLoadGame::on_ButtonYes_clicked()
{

    this->close();

}

void confirmLoadGame::on_ButtonNo_clicked()
{
    this->close();
}

void confirmLoadGame::on_ButtonCancel_clicked()
{
    this->close();
}


