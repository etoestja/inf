#ifndef COMMON_H
#define COMMON_H

#include "openssl/md5.h"

#define MNAME       100
#define MPASSWORD   100
#define MCOMMAND    200
#define MRESPONSE   1024
#define MHOSTNAME   50

#define MD5_DIGEST_PLAIN_LENGTH 32

#include "myauth.h"

enum msgType {COMMAND, RESPONSE};

typedef struct
{
    unsigned char md5digest[MD5_DIGEST_LENGTH];
    char type;
    char name[MNAME];
    char password[MPASSWORD];
    char command[MCOMMAND];
} broadcastMessage;

typedef struct
{
    unsigned char md5digest[MD5_DIGEST_LENGTH];
    char type;
    char hostname[MHOSTNAME];
    char response[MRESPONSE];
} responseMessage;

#define RXMAX 4096

void* decryptMessageCheckHash(char* ciphertext, int *len);

#endif
