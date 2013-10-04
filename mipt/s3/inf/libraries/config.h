#include <stdio.h>
#include <stdlib.h>

/*typedef struct
{
    char* key;
    char* value;
} confpair;*/

typedef struct
{
    char** strings;
    int nStrings;
} config;

int fileToConfig(char* filename, config *conf);
int configToFile(char* filename, config *conf);

int getKey(char* filename, char* keyname);
int setKey(char* filename, char* key, char* value);
