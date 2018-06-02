#ifndef FIGHTAREA_H
#define FIGHTAREA_H

#include <QDialog>

#include "playercharacter.h"
#include "opponent.h"

namespace Ui {
class fightArea;
}

class fightArea : public QDialog
{
    Q_OBJECT

public:
    explicit fightArea(playerCharacter *player, opponentCharacter* opponent, QWidget *parent = 0);
    ~fightArea();

private:
    Ui::fightArea *ui;
    playerCharacter *player;
    opponentCharacter* opponent;
};

#endif // FIGHTAREA_H
