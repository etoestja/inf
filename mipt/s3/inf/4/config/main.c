#include <stdio.h>
#include "config.h"

int testFileToConfig()
{
    char* s = NULL;
    size_t len1;
    int len = getline(&s, &len1, stdin);

    s[len - 1] = 0;
    printf("[%s]\n", s);

    config conf;
    
    printf("code = %d\n", fileToConfig(s, &conf));
    return(0);
}

int main()
{
    return(testFileToConfig());
}
