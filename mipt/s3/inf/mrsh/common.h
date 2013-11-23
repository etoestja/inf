#ifndef COMMON_H
#define COMMON_H

#include "openssl/md5.h"

#define MNAME       100
#define MPASSWORD   100
#define MCOMMAND    200

#define MD5_DIGEST_PLAIN_LENGTH 32

#include "myauth.h"

typedef struct
{
    unsigned char md5digest[MD5_DIGEST_LENGTH];
    char name[MNAME];
    char password[MPASSWORD];
    char command[MCOMMAND];
} broadcastMessage;

#endif
