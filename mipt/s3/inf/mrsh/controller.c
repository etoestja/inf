#include "common.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <errno.h>
#include <unistd.h>
#include "common.h"
#include "multicast.h"
#include "myaes.h"
#include "myauth.h"
#include <string.h>

#define CMDERROR "fuck you!\n"

char name[MNAME], password[MPASSWORD];

int main(int argc, char* argv[])
{   
    AESInit();
    authInfoReadFile();
    MD5_CTX md5handler;
    if(argc < 2)
    {
        printf("Usage: %s REAL_IFACE_IP\n", argv[0]);
        return(1);
    }

    broadcastMessage bm;

    printf("User: ");
    scanf("%s", bm.name);
    strcpy(bm.password, getpass("Password: "));

    //printf("[%s]", password);
    if(!authenticate(bm.name, bm.password))
    {
        fprintf(stderr, "Wrong username/password!\n");
        return(1);
    }

    printf("Welcome!\n");

    multicastInitTx(argv[1]);
    //multicastInitRx(argv[1]);

    size_t size;

    int error = 0;

    void* cipher;
    int len;

//    char buf[100];

//    if(!fork())
//    {
//        for(;;)
//            if((size = multicastRx(buf, RXMAX)) > 0)
//            {
//                write(STDOUT_FILENO, buf, size);
//            }
//        return(0);
//    }

    for(;;)
    {
        if((size = read(STDIN_FILENO, bm.command, MCOMMAND - 1)) > 0)
        {
            if(bm.command[size - 1] != '\n')
            {
                write(STDOUT_FILENO, CMDERROR, sizeof(CMDERROR) - 1);
                error = 2;
            }
            else if(error > 0) error--;
            if(error == 0)
            {
                //bm.password[0] = 1;
                bm.command[size - 1] = 0;
                fprintf(stderr, "[%s]\n", bm.command);
                len = sizeof(bm);

                MD5(((void*) &bm) + MD5_DIGEST_LENGTH, sizeof(bm) - MD5_DIGEST_LENGTH, bm.md5digest);

                cipher = AESEncrypt((void*) &bm, &len);
                printf("sending len=%d\n", len);

                multicastTx(cipher, len);
                //multicastTx(bm.command, size);
            }
        }
    }
}
