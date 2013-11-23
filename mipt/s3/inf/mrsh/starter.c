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

#define RXMAX (2 * sizeof(broadcastMessage))

int main(int argc, char* argv[])
{
    AESInit();
    MD5_CTX md5handler;

    if(argc < 2)
    {
        printf("Usage: %s REAL_IFACE_IP\n", argv[0]);
        return(1);
    }

    multicastInitRx(argv[1]);

    broadcastMessage *bm;
    size_t size;

    void *buf = malloc(RXMAX);
    int len;

    unsigned char md5Digest1[MD5_DIGEST_LENGTH];

    for(;;)
    {
        if((size = multicastRx(buf, RXMAX)) > 0)
        {
            len = size;
            bm = (broadcastMessage*) AESDecrypt(buf, &len);
            if(len <= 0 || bm == NULL)
            {
                fprintf(stderr, "Error decoding!\n");
            }
            else
            {
                MD5(((void*) bm) + MD5_DIGEST_LENGTH, sizeof(*bm) - MD5_DIGEST_LENGTH, md5Digest1);

                int i;
                for(i = 0; i < MD5_DIGEST_LENGTH; i++)
                {
                    if(md5Digest1[i] != bm->md5digest[i])
                    {
                        fprintf(stderr, "Wrong hash!\n");
                        break;
                    }
                }

                if(i == MD5_DIGEST_LENGTH)
                {
                    fprintf(stderr, "sz=%d, cmd=%s\n", size, bm->command);
                }
            }
        }
    }
}
