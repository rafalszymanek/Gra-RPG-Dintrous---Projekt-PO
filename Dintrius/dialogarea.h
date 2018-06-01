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
    explicit dialogArea(QString *tab, std::string className, std::string playerName, QWidget *parent = 0);
    ~dialogArea();

private slots:
    void on_choose1Button_clicked();

private:
    Ui::dialogArea *ui;
    QString *questionsAndAnswers;
    std::string className;
    std::string playerName;
};

#endif // DIALOGAREA_H
