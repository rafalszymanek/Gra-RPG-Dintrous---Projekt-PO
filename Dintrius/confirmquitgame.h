#ifndef CONFIRMQUITGAME_H
#define CONFIRMQUITGAME_H

#include <QDialog>

namespace Ui {
class confirmQuitGame;
}

class confirmQuitGame : public QDialog
{
    Q_OBJECT

public:
    explicit confirmQuitGame(QWidget *parent = 0);
    ~confirmQuitGame();

private slots:
    void on_ButtonYes_clicked();

private:
    Ui::confirmQuitGame *ui;
};

#endif // CONFIRMQUITGAME_H
