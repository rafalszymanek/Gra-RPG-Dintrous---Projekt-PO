#ifndef TEXTPLUSCONTIUEDIALOG_H
#define TEXTPLUSCONTIUEDIALOG_H

#include <QDialog>

namespace Ui {
class textPlusContiueDialog;
}

class textPlusContiueDialog : public QDialog
{
    Q_OBJECT

public:
    explicit textPlusContiueDialog(QString text,QWidget *parent = 0);
    ~textPlusContiueDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::textPlusContiueDialog *ui;
};

#endif // TEXTPLUSCONTIUEDIALOG_H
