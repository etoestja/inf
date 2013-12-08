TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    grammar.cpp \
    rule.cpp \
    analyzer.cpp \
    situation.cpp \
    situation_set.cpp \
    common.cpp

HEADERS += \
    grammar.h \
    rule.h \
    analyzer.h \
    situation.h \
    situation_set.h \
    common.h

