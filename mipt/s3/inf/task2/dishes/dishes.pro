TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.c \
    implementation_file_semaphores.c \
    implementation_pipe_semaphores.c \
    implementation_messagequeue_semaphores.c \

HEADERS += implementation.h
