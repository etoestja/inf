#include "semmsg.h"

getMIDres getMID(int n)
{
    key_t key;
    getMIDres res;
    res.msqid = -1;
    res.isNew = 1;

    /* Create or attach message queue  */
    
    if((key = ftok(PATHNAME, n)) < 0)
        return(res); 
    
    if((res.msqid = msgget(key, 0666 | IPC_CREAT | IPC_EXCL)) < 0)
    {
        if(errno != EEXIST)
            return(res);
        else
        {
            res.msqid = msgget(key, 0666 | IPC_CREAT);
            res.isNew = 0;
        }
    }

    return(res);
}

int smCreate(int n)
{
    getMIDres a = getMID(n);
    if(a.msqid < 0)
        return(-1);
    if(a.isNew)
    {
        int i;
        for(i = 0; i < INITIAL; i++)
            smV(n);
    }
    return(a.isNew);
}

int smP(int n)
{
    int len;
    getMIDres a = getMID(n);
    semmsgbuf buf;
    if ((len = msgrcv(a.msqid, (struct msgbuf *) &buf, 0, 0, 0)) < 0)
        return(-1);
    return(0);
}

int smV(int n)
{
    getMIDres a = getMID(n);
    semmsgbuf b;
    if(msgsnd(a.msqid, (struct msgbuf *) &b, 0, 0) < 0)
        return(-1);
    return(0);
}
