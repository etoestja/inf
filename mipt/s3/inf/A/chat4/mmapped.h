#ifndef MMAPPED_H
#define MMAPPED_H

#include "common.h"

typedef struct
{
    char text[MSGLEN];
    int sender;
    int size;
    int read;
} message;

#define USERS 2
#define FILENAME "messages"
#define MESSAGES 10
#define FILESIZE (MESSAGES * sizeof(message) + sizeof(int))

#endif
