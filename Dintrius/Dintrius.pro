#-------------------------------------------------
#
# Project created by QtCreator 2018-05-06T21:22:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dintrius
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    confirmnewgame.cpp \
    confirmloadgame.cpp \
    confirmquitgame.cpp \
    charactercreator.cpp \
    dialogarea.cpp \
    fightarea.cpp \
    playercharacter.cpp \
    worrior.cpp \
    opponent.cpp \
    murlok.cpp \
    controleroffight.cpp \
    game.cpp \
    gamecontroler.cpp \
    theend.cpp \
    textpluscontiuedialog.cpp

HEADERS += \
        mainwindow.h \
    confirmnewgame.h \
    confirmloadgame.h \
    confirmquitgame.h \
    charactercreator.h \
    charactercreator.h \
    charactercreator.h \
    dialogarea.h \
    fightarea.h \
    playercharacter.h \
    worrior.h \
    opponent.h \
    murlok.h \
    controleroffight.h \
    game.h \
    gamecontroler.h \
    theend.h \
    textpluscontiuedialog.h

FORMS += \
        mainwindow.ui \
    confirmnewgame.ui \
    confirmloadgame.ui \
    confirmquitgame.ui \
    charactercreator.ui \
    dialogarea.ui \
    fightarea.ui \
    theend.ui \
    textpluscontiuedialog.ui

RESOURCES += \
    img/images.qrc

DISTFILES += \
    img/dialog background.jpg \
    img/fightbackground.jpeg \
    img/handel background.jpg \
    img/dialog background.jpg
