#ifndef MMAPPED_H
#define MMAPPED_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include "common.h"

typedef struct
{
    char text[MSGLEN];
    int sender;
    int size;
    int leftread;
} message;

#define FILENAME "messages"
#define FILESIZE (MSGMAX * sizeof(message) + 2 * sizeof(int))

void initMPD();
void messageCopy(char* dest, char* src, ssize_t size);

#endif
