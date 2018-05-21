#include "confirmnewgame.h"
#include "ui_confirmnewgame.h"
#include "charactercreator.h"

#include <QApplication>

confirmNewGame::confirmNewGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::confirmNewGame)
{
    this->setFixedSize(QSize(500, 223)); // Ustawienie rozmiaru okna
    ui->setupUi(this);
}

confirmNewGame::~confirmNewGame()
{
    delete ui;
}

void confirmNewGame::on_ButtonYes_clicked()
{
    this->close();
    characterCreator alertNewGame; // Zmienna do otworznia nowego
    alertNewGame.setModal(true);
    alertNewGame.exec();


}

void confirmNewGame::on_ButtonNo_clicked()
{
    this->close();
}

void confirmNewGame::on_ButtonCancel_clicked()
{
    this->close();
}
