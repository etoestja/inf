#ifndef COMMON_H
#define COMMON_H

#include <sys/timeb.h>

#define CLIENTS_N 5

#define CLIENTSMAX 100

#define DMIN 10

typedef struct
{
    unsigned long long dataLen;
    unsigned long long duration;
    long double lastSpeed;
    long double maxSpeed;
} client;

extern struct timeb oldTime;

void setTime();
unsigned long long getTimeDifference();

#endif
