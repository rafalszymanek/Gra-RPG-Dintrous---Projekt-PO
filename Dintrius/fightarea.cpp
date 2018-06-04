#include "fightarea.h"
#include "ui_fightarea.h"

fightArea::fightArea(playerCharacter *kPlayer, opponentCharacter* kOpponent,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fightArea)
{
    ui->setupUi(this);
    player = kPlayer;
    opponent = kOpponent;
    turnsToPowerAttack=0;

    ui->pictureOfPlayer->setPixmap(QString::fromStdString(player->returnImgPath()));
    ui->pictureOfPlayer->show();

    ui->picutreOfEnemy->setPixmap(QString::fromStdString(opponent->returnImgPath()));
    ui->picutreOfEnemy->show();

    QPalette sample_palette;
    sample_palette.setColor(QPalette::WindowText, Qt::white);
    ui->currentHealthLabel->setPalette(sample_palette);
    ui->currentEnergyLabel->setPalette(sample_palette);
    ui->currentManaLabel->setPalette(sample_palette);
    ui->currentOpponentHealth->setPalette(sample_palette);
    ui->damageCharacterLabel->setPalette(sample_palette);
    ui->damageOpponentLabel->setPalette(sample_palette);

    this->updateDataOfArea();

}

fightArea::~fightArea()
{
    delete ui;
}

void fightArea::updateDataOfArea(int characterDmg, int opponentDmg){
    ui->currentHealthLabel->setText( QString::number(player->infoAboutClass(7)));
    ui->currentEnergyLabel->setText( QString::number(player->infoAboutClass(8)));
    ui->currentManaLabel->setText( QString::number(player->infoAboutClass(9)));

    ui->currentOpponentHealth->setText(QString::number(opponent->info(1)));

    QString characterText = QString::number(characterDmg) + " dmg";
    QString opponentText = QString::number(opponentDmg) + " dmg";
    ui->damageCharacterLabel->setText(characterText);
    ui->damageOpponentLabel->setText(opponentText);
}

void fightArea::playerIsDead(){
    if(player->isDead()){
        textPlusContiueDialog dialog("Przegrałeś! Koniec gry!");
        statusOfWin = 0;
        dialog.setModal(true);
        dialog.exec();
        this->close();
    }

}

void fightArea::opponentIsDead(){
    if(opponent->isDead()){
        textPlusContiueDialog dialog("Wygrałeś!");
        statusOfWin = 1;
        dialog.setModal(true);
        dialog.exec();
        this->close();
    }
}

void fightArea::controlerOfAttack(int characterDmg){
    int opponentDmg = 0;
    this->updateDataOfArea(characterDmg, opponentDmg);
    this->opponentIsDead();
    if(opponent->isDead() == false){
        opponentDmg = opponent->attack();
        player->gainDamage(opponentDmg);


        this->updateDataOfArea(characterDmg, opponentDmg);
        this->playerIsDead();
    }

    checkTurnsOfPowerAttack();


}

void fightArea::checkTurnsOfPowerAttack(){



    if(player->eneughAttack1() == false)
        ui->attack1Button->setEnabled(false);
    else
        ui->attack1Button->setEnabled(true);

    if(turnsToPowerAttack > 0 && player->eneughAttack2() == true)
        ui->attack2Button->setEnabled(true);
    else
        ui->attack2Button->setEnabled(false);


    if(turnsToPowerAttack > 1 && player->eneughAttack3() == true)
        ui->attack3Button->setEnabled(true);
    else
        ui->attack3Button->setEnabled(false);
}


void fightArea::on_attack1Button_clicked()
{
    int characterDmg = player->attack1(opponent);

    turnsToPowerAttack++;
    this->controlerOfAttack(characterDmg);

}

void fightArea::on_attack2Button_clicked()
{
    int characterDmg = player->attack2(opponent);
    turnsToPowerAttack--;
    this->controlerOfAttack(characterDmg);

}

void fightArea::on_attack3Button_clicked()
{
    int characterDmg = player->attack3(opponent);
    turnsToPowerAttack-=2;
    this->controlerOfAttack(characterDmg);

}

void fightArea::on_treatmentButton_clicked()
{
    player->treatCharacter();
    turnsToPowerAttack++;
    controlerOfAttack(0);

}

void fightArea::on_energyDrinkButton_clicked()
{
    player->energyDrink();
    turnsToPowerAttack++;
    controlerOfAttack(0);

}

void fightArea::on_manaDrinkButton_clicked()
{
    player->manaDrink();
    turnsToPowerAttack++;
    controlerOfAttack(0);

}

void fightArea::on_informationButton_clicked()
{
    QString text;
    if(player->whatAClass()=="worrior"){
        text = "Wojownik <br/> 1. Atak mieczem (siła*(1.5 - 3) 25 energii <br/>"
                       "2. Potężny cios (siła*(2 - 3.5) 35 energii <br/>"
                       "3. Spirala śmierci (siła*(4 - 4.2) 60 energii <br/>"
                       "4. Leczenie (życie + leczenie*30) <br/>"
                       "Siła:" + QString::number(player->infoAboutClass(2)) + "<br/>"+
                       "Życie:" + QString::number(player->infoAboutClass(1)) + "<br/>"+
                       "Energia:" + QString::number(player->infoAboutClass(3)) + "<br/>" +
                       "Wiara:" + QString::number(player->infoAboutClass(4)) + "<br/>" +
                       "Mana:" + QString::number(player->infoAboutClass(5)) + "<br/>" +
                       "Lecznictwo:" + QString::number(player->infoAboutClass(6)) + "<br/>";
    }
     else if(player->whatAClass()=="mag"){
            text = "Mag <br/> 1. Atak laską (siła*(1.5 - 3) 10 energii <br/>"
                           "2. Czara (siła*(2 - 3.5) 30 many <br/>"
                           "3. Kula ognia (siła*(4 - 4.2) 60 many <br/>"
                           "4. Leczenie (życie + leczenie*30) <br/>"
                           "Siła:" + QString::number(player->infoAboutClass(2)) + "<br/>"+
                           "Życie:" + QString::number(player->infoAboutClass(1)) + "<br/>"+
                           "Energia:" + QString::number(player->infoAboutClass(3)) + "<br/>" +
                           "Wiara:" + QString::number(player->infoAboutClass(4)) + "<br/>" +
                           "Mana:" + QString::number(player->infoAboutClass(5)) + "<br/>" +
                           "Lecznictwo:" + QString::number(player->infoAboutClass(6)) + "<br/>";
    }
    else if(player->whatAClass()=="paladyn"){
           text = "Paladyn <br/> 1. Atak mieczem (siła*(1.5 - 3) 15 energii <br/>"
                          "2. Potężny cios (siła*(2 - 3.5) 40 energii <br/>"
                          "3. Świetlisty cios (siła*(4.6 - 5) 50 many <br/>"
                          "4. Leczenie (życie + leczenie*30) <br/>"
                          "Siła:" + QString::number(player->infoAboutClass(2)) + "<br/>"+
                          "Życie:" + QString::number(player->infoAboutClass(1)) + "<br/>"+
                          "Energia:" + QString::number(player->infoAboutClass(3)) + "<br/>" +
                          "Wiara:" + QString::number(player->infoAboutClass(4)) + "<br/>" +
                          "Mana:" + QString::number(player->infoAboutClass(5)) + "<br/>" +
                          "Lecznictwo:" + QString::number(player->infoAboutClass(6)) + "<br/>";
   }


        textPlusContiueDialog dialog(text);
        dialog.setModal(true);
        dialog.exec();

}

bool fightArea::didWon(){
    if(statusOfWin == 0)
        return false;
    else
        return true;
}
