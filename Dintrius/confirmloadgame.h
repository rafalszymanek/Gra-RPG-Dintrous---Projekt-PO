#ifndef CONFIRMLOADGAME_H
#define CONFIRMLOADGAME_H

#include <QDialog>

namespace Ui {
class confirmLoadGame;
}

class confirmLoadGame : public QDialog
{
    Q_OBJECT

public:
    explicit confirmLoadGame(QWidget *parent = 0);
    ~confirmLoadGame();

private slots:
    void on_ButtonYes_clicked();

    void on_ButtonNo_clicked();

    void on_ButtonCancel_clicked();

private:
    Ui::confirmLoadGame *ui;
};

#endif // CONFIRMLOADGAME_H
