#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

#define MAXLEN 10000
char s[MAXLEN];

int main()
{
    scanf("%s", s);
    printf("%s\n", dlopen(s, RTLD_LAZY) ? "YES" : "NO");
    return(0);
}

