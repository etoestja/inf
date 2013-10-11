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
    int myPID = getpid();

    printf("Your name: ");
    scanf("%s", buf.message);
    buf.sourcePID = myPID;
    buf.mtype = TOSERVER;
    buf.type = MHELLO;
    if(msgsnd(msqid, (struct msgbuf *) &buf, MINLEN + strlen(buf.message) + 1, 0) < 0)
    {
        printf("Can't send message");
    }

    if(fork()) // stdin -> msg
    {
        for(;;)
            if((size = read(STDIN_FILENO, buf.message, MSGLEN - 1)) > 0)
            {
                buf.message[size] = 0;
                buf.type = MTEXT;
//                printf("got string %s\n", buf.message);
                buf.sourcePID = myPID;
                buf.mtype = TOSERVER;
                if(msgsnd(msqid, (struct msgbuf *) &buf, MINLEN + strlen(buf.message) + 1, 0) < 0)
                {
                    printf("Can't send message");
                }
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
                    printf("[%s (%d)]: %s", name, buf.sourcePID, buf.message);
                }
            }
        }
    }

    return 0;
}
