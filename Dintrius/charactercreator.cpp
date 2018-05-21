#include "charactercreator.h"
#include "ui_charactercreator.h"
#include "dialogarea.h"

characterCreator::characterCreator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::characterCreator)
{
    ui->setupUi(this);
}

characterCreator::~characterCreator()
{
    delete ui;
}

void characterCreator::on_approveButton_clicked()
{
    dialogArea newArea; // Zmienna do otworznia nowego
    newArea.setModal(true);
    this->close();
    newArea.exec();
}
