#ifndef FIGHTAREA_H
#define FIGHTAREA_H

#include <QDialog>

namespace Ui {
class fightArea;
}

class fightArea : public QDialog
{
    Q_OBJECT

public:
    explicit fightArea(QWidget *parent = 0);
    ~fightArea();

private:
    Ui::fightArea *ui;
};

#endif // FIGHTAREA_H
