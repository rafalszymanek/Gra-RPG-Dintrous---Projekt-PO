#include "theend.h"
#include "ui_theend.h"

theEnd::theEnd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::theEnd)
{
    ui->setupUi(this);
}

theEnd::~theEnd()
{
    delete ui;
}

void theEnd::on_pushButton_clicked()
{
    this->close();
}
