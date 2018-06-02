#include "comfirmfight.h"
#include "ui_comfirmfight.h"

comfirmFight::comfirmFight(QString kAnswer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comfirmFight)
{
    ui->setupUi(this);



    ui->answerLabel->setText(kAnswer);
}

comfirmFight::~comfirmFight()
{
    delete ui;
}

void comfirmFight::on_pushButton_clicked()
{
    this->close();
}
