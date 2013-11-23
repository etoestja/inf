#include "myauth.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <openssl/md5.h>

void authInfoReadFile()
{
    FILE* f = fopen(AUTHINFOFILE, "r");

    authInfoN = 0;
    authInfoArr = NULL;

    if(f == NULL)
    {
        fprintf(stderr, "Can't open file\n");
        return;
    }

    if(fscanf(f, "%d", &authInfoN) < 1)
    {
        fprintf(stderr, "Can't read usersN!\n");
        return;
    }

    authInfoArr = malloc(sizeof(authInfo) * authInfoN);

    int i;
    for(i = 0; i < authInfoN; i++)
    {
        if(fscanf(f, "%s %s", authInfoArr[i].name, authInfoArr[i].password) < 2)
            fprintf(stderr, "Can't read row!\n");
        //printf("got u=[%s] p=[%s]\n", authInfoArr[i].name, authInfoArr[i].password);
    }

    fclose(f);
}

int authenticate(const char* user, const char* passwd)
{
    unsigned char md5pass[MD5_DIGEST_LENGTH];
    unsigned char md5passC[MD5_DIGEST_PLAIN_LENGTH];

    int i, j;
    char tmp[3];
    for(i = 0; i < authInfoN; i++)
    {
        MD5(passwd, strlen(passwd), md5pass);
        for(j = 0; j < MD5_DIGEST_LENGTH; j++)
        {
            sprintf(tmp, "%02x", md5pass[j]);
            md5passC[2 * j] = tmp[0];
            md5passC[2 * j + 1] = tmp[1];
        }

        //write(STDOUT_FILENO, md5passC, MD5_DIGEST_PLAIN_LENGTH);
        if(!strcmp(user, authInfoArr[i].name))
        {
            if(strlen(authInfoArr[i].password) != MD5_DIGEST_PLAIN_LENGTH)
            {
                //printf("strlen != ")
                continue;
            }
            if(!strncmp(authInfoArr[i].password, md5passC, MD5_DIGEST_PLAIN_LENGTH))
                return(1);
        }
    }
    return(0);
}
