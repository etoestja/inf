#include "common.h"

int main()
{
    key_t key;
    int msqid;

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

    int len, i;
    msgbuf buf, sndbuf;

    for(;;)
    {
        if ((len = msgrcv(msqid, (struct msgbuf *) &buf, MAXLEN, TOSERVER, 0)) >= MINLEN)
        {
            printf("Got message mtype=%d type=%d sourcePID=%d msg=[%s]\n", buf.mtype, buf.type, buf.sourcePID, buf.message);
            sndbuf = buf;
            if(buf.type == MHELLO)
            {
                sndbuf.type = MCOMES;

                for(i = 0; i < clientsSize; i++)
                {
                    if(clients[i] != -1 && clients[i] != buf.sourcePID)
                    {
                        printf(" Telling about %d...\n", clients[i]);
                        sndbuf.sourcePID = clients[i];
                        sndbuf.mtype = buf.sourcePID;
                        strcpy(sndbuf.message, clientsNames[i]);
                        if(msgsnd(msqid, (struct msgbuf *) &sndbuf, MINLEN + strlen(sndbuf.message) + 1, 0) < 0)
                            printf("Can't send message\n");
                    }
                }

                sndbuf = buf;
                sndbuf.type = MCOMES;
                addClient(buf.sourcePID, buf.message);
            }
            else if(buf.type == MBYE)
            {
                sndbuf.type = MLEAVES;
                rmClient(buf.sourcePID);
            }
//              else if(buf.type == MTEXT)

            for(i = 0; i < clientsSize; i++)
            {
                if(clients[i] != -1 && clients[i] != buf.sourcePID)
                {
                    printf(" relaying to %d...\n", clients[i]);
                    sndbuf.mtype = clients[i];
                    if(msgsnd(msqid, (struct msgbuf *) &sndbuf, MINLEN + strlen(sndbuf.message) + 1, 0) < 0)
                        printf("Can't send message\n");

                }
            }
        }

    }

    return(0);
}
