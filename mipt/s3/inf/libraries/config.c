#include "config.h"

int fileToConfig(char* filename, config *conf)
{
    if(conf == NULL)
        return(-1);

    FILE* fd = fopen(filename, "r");

    conf->nStrings = 0;
    conf->strings = NULL;

    if(fd == NULL)
        return(-2);
    
    size_t len1;
    char* string = NULL;
    while(getline(&string, &len1, fd) > 0)
    {
        conf->nStrings++;
        conf->strings = realloc(conf->strings, sizeof(char*) * conf->nStrings);
        conf->strings[conf->nStrings - 1] = string;
        printf("+1\n");
        string = NULL;
    }
    return(0);
}
