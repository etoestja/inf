TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.c \
    implementation_file_semaphores.c \
    implementation_pipe_semaphores.c \
    implementation_messagequeue_semaphores.c \
    implementation_sharedmemory_semaphores.c \
    semaphores_lib.c \

HEADERS += implementation.h
