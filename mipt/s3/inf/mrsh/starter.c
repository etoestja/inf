#include "common.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "common.h"
#include "multicast.h"
#include "myaes.h"
#include "myauth.h"
#include "parseargs.h"

char **args;
int argsc;

int sd;

#define TRANSMIT() {MD5(((void*) &response) + MD5_DIGEST_LENGTH, sizeof(responseMessage) - MD5_DIGEST_LENGTH, response.md5digest); slen = sizeof(response); cipher = AESEncrypt((void*) &response, &slen); multicastTx(cipher, slen);}
int main(int argc, char* argv[], char** envp)
{
    AESInit();
    authInfoReadFile();
    MD5_CTX md5handler;

    if(argc < 2)
    {
        printf("Usage: %s REAL_IFACE_IP\n", argv[0]);
        return(1);
    }

    multicastInit(argv[1]);

    broadcastMessage *bm;
    size_t size;

    responseMessage response;
    response.type = RESPONSE;
    gethostname(response.hostname, MHOSTNAME - 1);

    void *buf = malloc(RXMAX);
    int len, slen;

    int strLen;

    void* plain, *cipher;

    for(;;)
    {
        if((size = multicastRx(buf, RXMAX)) > 0)
        {
            len = size;
            printf("got size=%d\n", size);

            plain = decryptMessageCheckHash(buf, &len);
            if((plain != NULL) && (len == sizeof(broadcastMessage)))
            {
                bm = ((broadcastMessage*) plain);
                if(bm->type == COMMAND)
                {
                    strcpy(response.response, "Received\n");
                    TRANSMIT();

                    if(!authenticate(bm->name, bm->password))
                    {
                        strcpy(response.response, "Wrong user/password!\n");
                        TRANSMIT();
                        continue;
                    }

                    strcpy(response.response, "Starting!\n");
                    TRANSMIT();

                    strLen = strlen(bm->command);
//                    if(strLen == 0)
//                        continue;
                    //printf("strLen=%d, cmd=%s\n", strLen, bm->command);

                    argsc = 0;
                    args = NULL;
                    mallocArgs(&args, strLen);
                    parseArgs(bm->command, strLen, args, &argsc);

                    if(argsc == 1 && !strcmp(args[0], "exit"))
                    {
                        freeArgs(&args, &argsc, strLen);
                        strcpy(response.response, "Bye!\n");
                        TRANSMIT();
                        return(0);
                    }
                    if(argsc == 1 && !strcmp(args[0], "list"))
                    {
                        strcpy(response.response, "Online!\n");
                        TRANSMIT();
                    }
                    else if(argsc >= 1 && args != NULL)
                    {
                        if(!fork())
                        {
                            int fd[2];
                            if(pipe(fd) < 0)
                            {
                                fprintf(stderr, "Can't pipe!");
                            }
                            //child
                            if(!fork())
                            {
                                {
                                    //child child. sending responses.
                                    for(;;)
                                    {
                                        if((size = read(fd[0], response.response, MRESPONSE - 1)) > 0)
                                        {
                                            response.response[size] = 0;
                                            TRANSMIT();
                                        }
                                    }
                                }
                            }
                            else
                            {
                                int res;
                                pid_t tPID = fork();
                                if(!tPID)
                                {
                                    dup2(fd[1], 1);
                                    execvpe(args[0], args, envp);
                                    strcpy(response.response, "Wrong command\n");
                                    TRANSMIT();
                                    return(-1);
                                }
                                else
                                {
                                    waitpid(tPID, &res, 0);
                                    sprintf(response.response, "Command [%s] finished with code %d\n", bm->command, WEXITSTATUS(res));
                                    TRANSMIT();
                                }
                            }
                        }
                    }

                    if(args != NULL)
                        freeArgs(&args, &argsc, strLen);
                }
            }
            else if(len != sizeof(responseMessage))
            {
                fprintf(stderr, "Wrong length!\n");
            }
        }
    }
}
