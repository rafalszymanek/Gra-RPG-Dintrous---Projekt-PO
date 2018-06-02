#include "fightarea.h"
#include "ui_fightarea.h"

fightArea::fightArea(playerCharacter *kPlayer, opponentCharacter* kOpponent,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fightArea)
{
    ui->setupUi(this);
    player = kPlayer;
    opponent = kOpponent;

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

    ui->currentHealthLabel->setText( QString::number(player->infoAboutClass(7)));
    ui->currentEnergyLabel->setText( QString::number(player->infoAboutClass(8)));
    ui->currentManaLabel->setText( QString::number(player->infoAboutClass(9)));

    ui->currentOpponentHealth->setText(QString::number(opponent->info(1)));
}

fightArea::~fightArea()
{
    delete ui;
}
