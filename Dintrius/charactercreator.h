#ifndef CHARACTERCREATOR_H
#define CHARACTERCREATOR_H

#include <QDialog>

namespace Ui {
class characterCreator;
}

class characterCreator : public QDialog
{
    Q_OBJECT

public:
    explicit characterCreator(int liczba = 0 ,QWidget *parent = 0);
    ~characterCreator();
    std::string getCharacterName();
    std::string getClassName();
    int getStrength();
    int getHealth();
    int getEnergy();
    int getFaith();
    int getMana();
    int getTreatment();
    int points = 55;

    void goodPointsLeft();
    void badPointsLeft();
    void whichColorOfPoints(int points);


private slots:
    void on_approveButton_clicked();


    void on_classBox_currentIndexChanged(const QString &arg1);

    void on_strengthBox_valueChanged(int arg1);

    void on_vitalBox_valueChanged(int arg1);

    void on_energyBox_valueChanged(int arg1);

    void on_faithBox_valueChanged(int arg1);

    void on_manaBox_valueChanged(int arg1);

    void on_treatmentBox_valueChanged(int arg1);

private:
    Ui::characterCreator *ui;
};

#endif // CHARACTERCREATOR_H
