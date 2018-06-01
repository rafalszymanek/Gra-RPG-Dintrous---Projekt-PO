#include "charactercreator.h"
#include "ui_charactercreator.h"
#include "dialogarea.h"

#include <iostream>

using namespace std;

void characterCreator::goodPointsLeft(){
    QPalette sample_palette;
    sample_palette.setColor(QPalette::WindowText, Qt::white);
    ui->pointsLeftLabel->setPalette(sample_palette);
}
void characterCreator::badPointsLeft(){
    QPalette sample_palette;
    sample_palette.setColor(QPalette::WindowText, Qt::red);
    ui->pointsLeftLabel->setPalette(sample_palette);
}
void characterCreator::whichColorOfPoints(int points){
    if(points < 0)
        badPointsLeft();
    else
        goodPointsLeft();
}

characterCreator::characterCreator(int liczba, QWidget *parent) :
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
//    dialogArea newArea; // Zmienna do otworznia nowego
//    newArea.setModal(true);
//    newArea.exec();
    if(ui->getNameLineEdit->text()!=""  && ui->classBox->currentText()!="" && points == 0)
    {
        this->close();
    }
}

string characterCreator::getCharacterName()
{
    QString QCharacterName = ui->getNameLineEdit->text();
    string name = QCharacterName.toUtf8().constData();
  return name;
}

string characterCreator::getClassName()
{
    QString QClassName = ui->classBox->currentText();
    string className = QClassName.toUtf8().constData();
    return className;
}

int characterCreator::getStrength(){
    return ui->strengthBox->value();
}
int characterCreator::getHealth(){
    return ui->vitalBox->value();
}
int characterCreator::getEnergy(){
    return ui->energyBox->value();
}
int characterCreator::getFaith(){
    return ui->faithBox->value();
}
int characterCreator::getMana(){
    ////////
    return ui->manaBox->value();
}
int characterCreator::getTreatment(){
    return ui->treatmentBox->value();
}


void characterCreator::on_classBox_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "Wojownik"){
        ui->descriptionLabel->setText("<p><span style=' text-decoration: underline; color:#dedede;'>Wojownik</span><span style=' color:#dedede;'><br/>Charakteryzuje się siłą oraz dużą ilością życia.<br/>Jego minusem jest:<br/>- niskie własności lecznicze<br/>- brak umiejętności magicznych</span></p><p><span style=' color:#dedede;'>Jego ataki to:<br/>- atak mieczem<br/>- potężny cios<br/>- spirala śmierci</span></p>");
        ui->strengthBox->setValue(16);
        ui->vitalBox->setValue(14);
        ui->energyBox->setValue(12);
        ui->faithBox->setValue(2);
        ui->manaBox->setValue(2);
        ui->treatmentBox->setValue(4);
        ui->pointsLeftLabel->setText("5");
    }
    else if(arg1 == "Mag"){
        ui->descriptionLabel->setText("<p><span style=' text-decoration: underline; color:#dedede;'>Mag</span><span style=' color:#dedede;'><br/>Magiczna postać, zadająca ogromne obrażenia za<br/>pomocą magii. Do tego dochodzą<br/>ponadprzeciętne umiejętności lecznicze.<br/> <br/>Jego minusem jest:<br/>- niska siła<br/>- mało życia</span></p><p><span style=' color:#dedede;'>Jego ataki to:<br/>- atak laską<br/>- czara<br/>- kula ognia</span></p>");
        ui->strengthBox->setValue(3);
        ui->vitalBox->setValue(7);
        ui->energyBox->setValue(5);
        ui->faithBox->setValue(13);
        ui->manaBox->setValue(12);
        ui->treatmentBox->setValue(10);
    }
    else if(arg1 == "Paladyn"){
        ui->descriptionLabel->setText("<p><span style=' text-decoration: underline; color:#dedede;'>Paladyn</span><span style=' color:#dedede;'><br/>Połączenie wojownika z magiem. Jest zarówno<br/>silny jaki posiada umiejętności lecznicze,<br/> a także włada magią<br/><br/>Jego minusem jest:<br/>- zrównoważenie wszystkich cech</span></p><p><span style=' color:#dedede;'>Jego ataki to:<br/>- atak mieczem<br/>- potężny cios<br/>- świetlisty cios</span></p>");
        ui->strengthBox->setValue(11);
        ui->vitalBox->setValue(11);
        ui->energyBox->setValue(9);
        ui->faithBox->setValue(5);
        ui->manaBox->setValue(7);
        ui->treatmentBox->setValue(7);
    }
    else if(arg1 == ""){
        ui->descriptionLabel->setText("");
        ui->strengthBox->setValue(0);
        ui->vitalBox->setValue(0);
        ui->energyBox->setValue(0);
        ui->faithBox->setValue(0);
        ui->manaBox->setValue(0);
        ui->treatmentBox->setValue(0);
    }

}

void characterCreator::on_strengthBox_valueChanged(int arg1)
{
    points = 55;
    points -= ui->strengthBox->value();
    points -= ui->vitalBox->value();
    points -= ui->energyBox->value();
    points -= ui->faithBox->value();
    points -= ui->manaBox->value();
    points -= ui->treatmentBox->value();
    QString stringPoints = QString::number(points);
    whichColorOfPoints(points);
    ui->pointsLeftLabel->setText(stringPoints);
}

void characterCreator::on_vitalBox_valueChanged(int arg1)
{
    points = 55;
    points -= ui->strengthBox->value();
    points -= ui->vitalBox->value();
    points -= ui->energyBox->value();
    points -= ui->faithBox->value();
    points -= ui->manaBox->value();
    points -= ui->treatmentBox->value();
    QString stringPoints = QString::number(points);
    whichColorOfPoints(points);
    ui->pointsLeftLabel->setText(stringPoints);
}

void characterCreator::on_energyBox_valueChanged(int arg1)
{
    points = 55;
    points -= ui->strengthBox->value();
    points -= ui->vitalBox->value();
    points -= ui->energyBox->value();
    points -= ui->faithBox->value();
    points -= ui->manaBox->value();
    points -= ui->treatmentBox->value();
    QString stringPoints = QString::number(points);
    whichColorOfPoints(points);
    ui->pointsLeftLabel->setText(stringPoints);
}

void characterCreator::on_faithBox_valueChanged(int arg1)
{
    points = 55;
    points -= ui->strengthBox->value();
    points -= ui->vitalBox->value();
    points -= ui->energyBox->value();
    points -= ui->faithBox->value();
    points -= ui->manaBox->value();
    points -= ui->treatmentBox->value();
    QString stringPoints = QString::number(points);
    whichColorOfPoints(points);
    ui->pointsLeftLabel->setText(stringPoints);
}

void characterCreator::on_manaBox_valueChanged(int arg1)
{
    points = 55;
    points -= ui->strengthBox->value();
    points -= ui->vitalBox->value();
    points -= ui->energyBox->value();
    points -= ui->faithBox->value();
    points -= ui->manaBox->value();
    points -= ui->treatmentBox->value();
    QString stringPoints = QString::number(points);
    whichColorOfPoints(points);
    ui->pointsLeftLabel->setText(stringPoints);
}

void characterCreator::on_treatmentBox_valueChanged(int arg1)
{
    points = 55;
    points -= ui->strengthBox->value();
    points -= ui->vitalBox->value();
    points -= ui->energyBox->value();
    points -= ui->faithBox->value();
    points -= ui->manaBox->value();
    points -= ui->treatmentBox->value();
    QString stringPoints = QString::number(points);
    whichColorOfPoints(points);
    ui->pointsLeftLabel->setText(stringPoints);
}
