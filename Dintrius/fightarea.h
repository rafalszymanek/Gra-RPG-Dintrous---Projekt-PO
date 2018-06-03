#ifndef FIGHTAREA_H
#define FIGHTAREA_H

#include <QDialog>

#include "playercharacter.h"
#include "opponent.h"
#include "textpluscontiuedialog.h"

namespace Ui {
class fightArea;
}

class fightArea : public QDialog
{
    Q_OBJECT

public:
    explicit fightArea(playerCharacter *player, opponentCharacter* opponent, QWidget *parent = 0);
    ~fightArea();
    void updateDataOfArea(int characterDmg = 0, int opponentDmg = 0);
    void playerIsDead();
    void opponentIsDead();

    void controlerOfAttack(int characterDmg = 0);
    void checkTurnsOfPowerAttack();
    bool didWon();


private slots:
    void on_attack1Button_clicked();

    void on_attack2Button_clicked();

    void on_attack3Button_clicked();

    void on_treatmentButton_clicked();

    void on_energyDrinkButton_clicked();

    void on_manaDrinkButton_clicked();

    void on_informationButton_clicked();

private:
    Ui::fightArea *ui;
    playerCharacter *player;
    opponentCharacter* opponent;
    int turnsToPowerAttack;
    int statusOfWin = 0; // 0 przegrana / 1 wygrana
};

#endif // FIGHTAREA_H
