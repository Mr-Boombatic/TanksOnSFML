TEMPLATE = subdirs

CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0

SUBDIRS = app tests

CONFIG += ordered

LIBS += -L$$PWD/SFML-2.5.1/lib -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
#LIBS += -LC:\Users\Baki\Desktop\testingLab.3\lib_dll -lgcc_s_seh-1 -lstdc++-6 -lwinpthread-1
 #   -lsfml-audio-2 -lsfml-graphics-2 -lsfml-network-2 -lsfml-system-2 -lsfml-window-2

INCLUDEPATH += $$PWD/SFML-2.5.1/include
DEPENDPATH += $$PWD/SFML-2.5.1/include
