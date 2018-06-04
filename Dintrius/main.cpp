#include "mainwindow.h"
#include "worrior.h"

#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    // Urucham główne okno
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


}
