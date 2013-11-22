#ifndef COMMON_H
#define COMMON_H

#define MNAME       100
#define MPASSWORD   100
#define MCOMMAND    200

typedef struct
{
    char name[MNAME];
    char password[MPASSWORD];
    char command[MCOMMAND];
} broadcastMessage;

#endif
