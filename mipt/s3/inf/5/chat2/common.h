#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define PATHNAME "server.c"
#define KEY2 0
#define MSGLEN 100
#define MAXLEN (100 + 2 * sizeof(int))
#define TOSERVER 1
#define MINLEN (2 * sizeof(int))

enum mType{MTEXT, MHELLO, MBYE, MCOMES, MLEAVES};

typedef struct
{
    long mtype;
    int type;
    int sourcePID;
    char message[MSGLEN];
} msgbuf;


int *clients;
int clientsSize = 0;
char** clientsNames;

void addClient(int PID, char* name)
{
    int i;
    for(i = 0; i < clientsSize; i++)
    {
        if(clients[i] == -1)
        {
            clients[i] = PID;
            clientsNames[i] = malloc(strlen(name) + 1);
            strcpy(clientsNames[i], name);
            return;
        }
    }
    clientsSize++;
    clients = realloc(clients, sizeof(int) * (clientsSize));
    clientsNames = realloc(clientsNames,  (sizeof(char*)) * (clientsSize));
    clients[clientsSize - 1] = PID;
    clientsNames[clientsSize - 1] = malloc(strlen(name) + 1);
    strcpy(clientsNames[clientsSize - 1], name);
}

void rmClient(int PID)
{
    int i;
    for(i = 0; i < clientsSize; i++)
    {
        if(clients[i] == PID)
        {
            clients[i] = -1;
            free(clientsNames[i]);
            return;
        }
    }
}

void printClients()
{
    int i;
    for(i = 0; i < clientsSize; i++)
    {
        if(clients[i] != -1)
            printf("client #%d PID=%d name=%s\n", i, clients[i], clientsNames[i]);
    }
    printf("===\n");
}

#ifdef ADDRMTEST
int main()
{
    addClient(1231,"abacaba");
    printClients();
    addClient(1232,"abacaba");
    printClients();
    addClient(1233,"abacaba");
    printClients();
    rmClient(1231);
    printClients();
    rmClient(1232);
    printClients();
    rmClient(1233);
    printClients();

    return(0);
}
#endif
