#ifndef DIALOGAREA_H
#define DIALOGAREA_H

#include <QDialog>

namespace Ui {
class dialogArea;
}

class dialogArea : public QDialog
{
    Q_OBJECT

public:
    explicit dialogArea(QString *tab, std::string className, std::string playerName,
                        std::string opponentName, int numberToStartFight, QString pathToImgOpponent, std::string pathToImgPlayer
                        , QWidget *parent = 0);
    ~dialogArea();

private slots:
    void on_choose1Button_clicked();

    void on_choose2Button_clicked();

    void on_choose3Button_clicked();

private:
    Ui::dialogArea *ui;
    QString *questionsAndAnswers;
    std::string className;
    std::string playerName;
    std::string opponentName;
    int numberToStartFight;
    QString imageOfOpponent;
    QString imageOfPlayer;
};

#endif // DIALOGAREA_H
