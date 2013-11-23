#ifndef COMMON_H
#define COMMON_H

#define SERVER_PORT 2000
#define CLIENTS_N 5

#define CLIENTSMAX 100

#define MAXIPLEN 100

enum _ACTION {ADD, REMOVE};

typedef struct
{
    char ip[MAXIPLEN];
    int port;
    int id;
    int action;
} client;

#endif
