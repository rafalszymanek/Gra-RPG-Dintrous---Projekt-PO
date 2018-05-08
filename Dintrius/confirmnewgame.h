#ifndef CONFIRMNEWGAME_H
#define CONFIRMNEWGAME_H

#include <QDialog>

namespace Ui {
class confirmNewGame;
}

class confirmNewGame : public QDialog
{
    Q_OBJECT

public:
    explicit confirmNewGame(QWidget *parent = 0);
    ~confirmNewGame();

private slots:
    void on_ButtonYes_clicked();

    void on_ButtonNo_clicked();

    void on_ButtonCancel_clicked();

private:
    Ui::confirmNewGame *ui;
};

#endif // CONFIRMNEWGAME_H
