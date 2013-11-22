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

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s REAL_IFACE_IP\n", argv[0]);
        return(1);
    }

    multicastInitRx(argv[1]);

    broadcastMessage bm;
    size_t size;

    for(;;)
    {
        if((size = multicastRx(&bm, sizeof(bm))) == sizeof(broadcastMessage))
        {
            printf("sz=%d, cmd=%s\n", size, bm.command);
        }
    }
}
