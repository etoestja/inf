#include "common.h"
#include <unistd.h>

char name[MSGLEN];

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

    int len, i, size;
    msgbuf buf;
    buf.mtype = getpid();

    if(fork()) // stdin -> msg
        for(;;)
            if((size = read(STDIN_FILENO, buf.message, MSGLEN - 1)) > 0)
            {
                buf.message[size] = 0;
                buf.
                if(msgsnd(msqid, (struct msgbuf *) &sndbuf, MINLEN + strlen(sndbuf.message) + 1, 0) < 0)
                {
                }
            }
    else
        for(;;) // msg -> stdin
            if((size = read(fdR, buf, BUFSIZE)) > 0)
                write(STDOUT_FILENO, buf, size);

    close(fdW);
    close(fdR);

    return 0;
}
