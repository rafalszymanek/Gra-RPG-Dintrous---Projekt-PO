#ifndef THEEND_H
#define THEEND_H

#include <QDialog>

namespace Ui {
class theEnd;
}

class theEnd : public QDialog
{
    Q_OBJECT

public:
    explicit theEnd(QWidget *parent = 0);
    ~theEnd();

private slots:
    void on_pushButton_clicked();

private:
    Ui::theEnd *ui;
};

#endif // THEEND_H
