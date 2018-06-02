#include "dialogarea.h"
#include "ui_dialogarea.h"
#include "fightarea.h"
#include "comfirmfight.h"



dialogArea::dialogArea(QString *tab, std::string kClassName, std::string kPlayerName, std::string kOpponentName, int kNumberToStartFight, QString pathToImgOpponent, std::string pathToImgPlayer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogArea)
{
    ui->setupUi(this);
    questionsAndAnswers = tab;
    className = kClassName;
    playerName = kPlayerName;
    opponentName = kOpponentName;
    numberToStartFight = kNumberToStartFight;
    imageOfOpponent = pathToImgOpponent;
    imageOfPlayer = QString::fromStdString(pathToImgPlayer);

    ui->pictureOfCharacter->setPixmap(imageOfPlayer);
    ui->pictureOfCharacter->show();
    QPixmap* pixmap2;

    pixmap2 = new QPixmap(imageOfOpponent);

    ui->pictureOfEnemy->setPixmap(*pixmap2);


    ui->pictureOfEnemy->show();

    QPalette sample_palette;
    sample_palette.setColor(QPalette::WindowText, Qt::white);
    ui->nameOfCharacterLabel->setPalette(sample_palette);
    ui->nameOfCharacterLabel->setText(QString::fromStdString(playerName));
    ui->nameOfAI->setAlignment(Qt::AlignRight);
    ui->nameOfAI->setPalette(sample_palette);
    ui->nameOfAI->setText(QString::fromStdString(opponentName));

    ui->dialogAILabel->setPalette(sample_palette);
    ui->dialogAILabel->setText(questionsAndAnswers[0]);

    ui->questionLabel1->setPalette(sample_palette);
    ui->questionLabel2->setPalette(sample_palette);
    ui->questionLabel3->setPalette(sample_palette);

    ui->questionLabel1->setText(questionsAndAnswers[1]);
    ui->questionLabel2->setText(questionsAndAnswers[2]);
    ui->questionLabel3->setText(questionsAndAnswers[3]);
}

dialogArea::~dialogArea()
{
    delete ui;
}



void dialogArea::on_choose1Button_clicked()
{

    ui->dialogAILabel->setText(questionsAndAnswers[4]);
    int buttonNumber = 1;
    if(buttonNumber == numberToStartFight){
        comfirmFight alertFight(questionsAndAnswers[buttonNumber+3]); // Zmienna do otworznia nowego
        alertFight.setModal(true);
        alertFight.exec();
        this->close();
    }
//
}

void dialogArea::on_choose2Button_clicked()
{
    int buttonNumber = 2;
    ui->dialogAILabel->setText(questionsAndAnswers[5]);

    if(buttonNumber == numberToStartFight){
        comfirmFight alertFight(questionsAndAnswers[buttonNumber+3]); // Zmienna do otworznia nowego
        alertFight.setModal(true);
        alertFight.exec();
        this->close();
    }
}

void dialogArea::on_choose3Button_clicked()
{
    int buttonNumber = 3;
    ui->dialogAILabel->setText(questionsAndAnswers[6]);

    if(buttonNumber == numberToStartFight){
        comfirmFight alertFight(questionsAndAnswers[buttonNumber+3]); // Zmienna do otworznia nowego
        alertFight.setModal(true);
        alertFight.exec();
        this->close();
    }
}

