#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void showCharacterCreator();
private slots:
    void on_newGame_clicked();

    void on_loadGame_clicked();

    void on_quitGame_clicked();

private:
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
