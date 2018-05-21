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
    explicit characterCreator(QWidget *parent = 0);
    ~characterCreator();

private slots:
    void on_approveButton_clicked();

private:
    Ui::characterCreator *ui;
};

#endif // CHARACTERCREATOR_H
