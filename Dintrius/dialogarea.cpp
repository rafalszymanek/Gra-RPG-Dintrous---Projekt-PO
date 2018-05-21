#include "dialogarea.h"
#include "ui_dialogarea.h"
#include "fightarea.h"

dialogArea::dialogArea(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogArea)
{
    ui->setupUi(this);
}

dialogArea::~dialogArea()
{
    delete ui;
}

void dialogArea::on_choose1Button_clicked()
{
    fightArea newFightArea; // Zmienna do otworznia nowego
    newFightArea.setModal(true);
    newFightArea.exec();
}
