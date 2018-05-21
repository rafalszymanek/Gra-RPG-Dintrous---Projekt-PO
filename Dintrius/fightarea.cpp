#include "fightarea.h"
#include "ui_fightarea.h"

fightArea::fightArea(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fightArea)
{
    ui->setupUi(this);
}

fightArea::~fightArea()
{
    delete ui;
}
