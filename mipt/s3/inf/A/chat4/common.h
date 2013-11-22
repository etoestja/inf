#ifndef COMMON_H
#define COMMON_H

#define SERVER_PORT 2000
#define CLIENTS_N 5

#define MSGLEN 100
#define MSGMAX 100

typedef struct
{
    int sender;
    char text[MSGLEN];
} broadcastMessage;

#endif
