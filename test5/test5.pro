QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arrow.cpp \
    citizens.cpp \
    clan.cpp \
    clancastle.cpp \
    defensetower.cpp \
    dijkstrashortestpath.cpp \
    enemy.cpp \
    game.cpp \
    health.cpp \
    main.cpp \
    mainwindow.cpp \
    newgamewindow.cpp \
    score.cpp \
    walls.cpp

HEADERS += \
    arrow.h \
    citizens.h \
    clan.h \
    clancastle.h \
    defensetower.h \
    dijkstrashortestpath.h \
    enemy.h \
    game.h \
    health.h \
    mainwindow.h \
    newgamewindow.h \
    score.h \
    walls.h

FORMS += \
    mainwindow.ui \
    newgamewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc \
    resources.qrc

