include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS +=     \
    ../app/Header.h \
    testingupdatebullets.h

SOURCES +=     main.cpp \
    ../app/bullet.cpp \
    ../app/enemy.cpp \
    ../app/player.cpp \
    ../app/update_bullets.cpp \

INCLUDEPATH += ../app

LIBS += -L$$PWD/SFML-2.5.1/lib -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-system -lsfml-window
#LIBS += -LC:\Users\Baki\Desktop\testingLab.3\lib_dll -lgcc_s_seh-1 -lstdc++-6 -lwinpthread-1
 #   -lsfml-audio-2 -lsfml-graphics-2 -lsfml-network-2 -lsfml-system-2 -lsfml-window-2

INCLUDEPATH += $$PWD/SFML-2.5.1/include
DEPENDPATH += $$PWD/SFML-2.5.1/include
