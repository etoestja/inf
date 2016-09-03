#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define NMAX 500

int main()
{
    char s[NMAX];
    scanf("%s", s);
    struct hostent* h = NULL;
    h = gethostbyname(s);
    struct in_addr* addr = ((struct in_addr**) h->h_addr_list)[0];
    char* ip = inet_ntoa(*addr);
    printf("%s\n", ip);
    return(0);
}
