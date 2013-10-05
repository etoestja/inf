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

typedef struct
{
    int stringN;

    int keyPos;
    int keyL;

    int eqPos;

    int valPos;
    int valL;
} findKeyRes;

int fileToConfig(char* filename, config *conf);
int configToFile(char* filename, config *conf);

void printConfig(config *conf);

char* getKey(char* filename, char* keyname);
char* setKey(char* filename, char* key, char* value);

findKeyRes findKey(config* conf, char* keyname);

findKeyRes parseString(char* string);

char* getSubstr(char* string, int p0, int L);

int strCmpSubstr(char* string, int p0, int L, char* string2);

void freeConfig(config* conf);
