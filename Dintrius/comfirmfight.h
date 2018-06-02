#ifndef COMFIRMFIGHT_H
#define COMFIRMFIGHT_H

#include <QDialog>

namespace Ui {
class comfirmFight;
}

class comfirmFight : public QDialog
{
    Q_OBJECT

public:
    explicit comfirmFight(QString answer, QWidget *parent = 0);
    ~comfirmFight();

private slots:
    void on_pushButton_clicked();

private:
    Ui::comfirmFight *ui;

};

#endif // COMFIRMFIGHT_H
