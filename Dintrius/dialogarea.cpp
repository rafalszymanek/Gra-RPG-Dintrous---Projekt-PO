#include "dialogarea.h"
#include "ui_dialogarea.h"
#include "fightarea.h"

dialogArea::dialogArea(QString *tab, std::string kClassName, std::string kPlayerName, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogArea)
{
    ui->setupUi(this);
    questionsAndAnswers = tab;
    className = kClassName;
    playerName = kPlayerName;


    QPixmap pixmap(":/worrior1.png");
    ui->pictureOfCharacter->setPixmap(pixmap);
    //ui->pictureOfCharacter->setMask(pixmap.mask());

    ui->pictureOfCharacter->show();

    QPixmap pixmap2(":/murloc.png");
    ui->pictureOfEnemy->setPixmap(pixmap2);


    ui->pictureOfEnemy->show();

    QPalette sample_palette;
    sample_palette.setColor(QPalette::WindowText, Qt::white);
    ui->nameOfCharacterLabel->setPalette(sample_palette);
    ui->nameOfCharacterLabel->setText(QString::fromStdString(playerName));
    ui->nameOfAI->setAlignment(Qt::AlignRight);
    ui->nameOfAI->setPalette(sample_palette);
    ui->nameOfAI->setText("Murlok");

    ui->dialogAILabel->setPalette(sample_palette);
    ui->dialogAILabel->setText("Witaj w grze dintrous! Jestem treningowym murlokiem.<br/> Jakie pytanie chcesz mi zadać?");

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
