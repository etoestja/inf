#ifndef COMMON_H
#define COMMON_H

#define SERVER_PORT 9809
#define CLIENTS_N 5

#define CLIENTSMAX 100

#define MAXIPLEN 100

enum _ACTION {ADD, REMOVE};
enum _DIRECTION {NEW2OLD, OLD2NEW, NEW2NEW};

typedef struct
{
    char ip[MAXIPLEN];
    int port;
    int id;
    int action;
    int direction;
} client;

#endif
