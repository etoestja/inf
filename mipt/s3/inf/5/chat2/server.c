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
        if ((len = msgrcv(msqid, (struct msgbuf *) &buf, MAXLEN, TOSERVER, 0)) < 0)
        {
            if(len >= MINLEN)
            {
                sndbuf = buf;
                if(buf.mtype == MHELLO)
                {
                    sndbuf.type = MCOMES;
                    addClient(buf.sourcePID, buf.message);
                }
                else if(buf.mtype == MBYE)
                {
                    sndbuf.type = MLEAVES;
                    rmClient(buf.sourcePID);
                }
//                else if(buf.mtype == MTEXT)

                for(i = 0; i < clientsSize; i++)
                {
                    if(clients[i] != -1)
                    {
                        if(sndbuf.type == MTEXT && sndbuf.destPID != 0 && sndbuf.destPID != clients[i])
                            continue;
                        sndbuf.mtype = clients[i];
                        if(msgsnd(msqid, (struct msgbuf *) &sndbuf, MINLEN + strlen(sndbuf.message) + 1, 0) < 0)
                            printf("Can't send message\n");

                    }
                }
            }
            else
                printf("Got some strange message\n");
        }

    }

    return(0);
}
