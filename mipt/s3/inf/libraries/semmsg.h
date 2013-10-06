#include <sys/types.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PATHNAME "semmsg.h"
#define MTYPE 1122334455
#define INITIAL 1

typedef struct
{
    long mtype;
} semmsgbuf;

typedef struct
{
    int msqid;
    int isNew;
} getMIDres;

// decrements semaphore value
// =reads message from queue
//  waits if there is no messages
// returns 0 if OK
int smP(int n);

// increments semaphore value
// =reads message from queue
int smV(int n);

// returns msqid
// n is second argument for ftok
getMIDres getMID(int n);

// creates message queue
// n is second argument for ftok
// initial value is INITIAL
// returns 1 if new
//         0 if not new
//        <0 if on error
int smCreate(int n);
