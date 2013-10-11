#include "common.h"
#include <unistd.h>

char name[MSGLEN];
key_t key;
int msqid;

void init()
{
    /* Create or attach message queue  */
    if((key = ftok(PATHNAME, KEY2)) < 0)
    {
        printf("Can't get key, exiting\n");
        exit(-1);
    }
    if((msqid = msgget(key, 0666 | IPC_CREAT | IPC_EXCL)) < 0)
    {
        if(errno != EEXIST)
        {
            printf("Can't get msqid\n");
            exit(-1);
        }
        else
            msqid = msgget(key, 0666 | IPC_CREAT);
    }
}

int main()
{
    init();
    int len, i, size;
    msgbuf buf;
    char name[MSGLEN];
    int myPID = getpid();

    printf("Your name: ");
    fgets(buf.message, MSGLEN, stdin);
    if(buf.message[strlen(buf.message) - 1] == '\n')
        buf.message[strlen(buf.message) - 1] = 0;
    strcpy(name, buf.message);
    buf.sourcePID = myPID;
    buf.mtype = TOSERVER;
    buf.type = MHELLO;
    if(msgsnd(msqid, (struct msgbuf *) &buf, MINLEN + strlen(buf.message) + 1, 0) < 0)
    {
        printf("Can't send message");
    }

    int exiting = 0;

    if(fork()) // stdin -> msg
    {
        for(;;)
            if(fgets(buf.message, MSGLEN, stdin) != NULL)
            {
                size = strlen(buf.message);
                if(size > 0 && buf.message[size - 1] == '\n')
                    buf.message[size - 1] = 0;
                if(!strcmp(buf.message, EXIT_STR))
                {
                    strcpy(buf.message, name);
                    buf.type = MBYE;
                    exiting = 1;
                }
                else
                    buf.type = MTEXT;
//                printf("got string len=%d\n", strlen(buf.message));
                buf.sourcePID = myPID;
                buf.mtype = TOSERVER;
                if(msgsnd(msqid, (struct msgbuf *) &buf, MINLEN + strlen(buf.message) + 1, 0) < 0)
                    printf("Can't send message");
                if(exiting)
                    return(0);
            }
    }
    else
    {
        init();
        int i;
        char* name;
        for(;;) // msg -> stdin
        {
            if ((len = msgrcv(msqid, (struct msgbuf *) &buf, MAXLEN, myPID, 0)) >= MINLEN)
            {
//                printf("Got message!\n");
                if(buf.type == MCOMES)
                {
                    addClient(buf.sourcePID, buf.message);
                    printf("[SYSTEM]: %s (%d) comes\n", buf.message, buf.sourcePID);
                }
                else if(buf.type == MLEAVES)
                {
                    rmClient(buf.sourcePID);
                    printf("[SYSTEM]: %s (%d) leaves\n", buf.message, buf.sourcePID);
                }
                else if(buf.type == MTEXT)
                {
                    for(i = 0; i < clientsSize; i++)
                        if(clients[i] == buf.sourcePID)
                            name = clientsNames[i];
                    printf("[%s (%d)]: %s\n", name, buf.sourcePID, buf.message);
                }
            }
        }
    }

    return 0;
}
