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

    printConfig(&conf);
    return(0);
}

int testParseString()
{
    char* s = NULL;
    size_t len1;
    int len = getline(&s, &len1, stdin);

    s[len - 1] = 0;
    printf("[%s]\n", s);

    findKeyRes res = parseString(s);

    printf("stringN = %d\tkeyPos=%d\tkeyL=%d\teqPos=%d\tvalPos=%d\tvalL=%d\n", res.stringN, res.keyPos, res.keyL, res.eqPos, res.valPos, res.valL);

    if(res.keyPos != -1 && res.eqPos != -1 && res.valPos != -1)
    {
        char* s1 = getSubstr(s, res.keyPos, res.keyL);
        char* s2 = getSubstr(s, res.valPos, res.valL);
        printf("correct string: [%s]=[%s]\n", s1, s2);
        free(s1);
        free(s2);
    }
    return(0);
}

int testGetKey()
{
    char fn[100];
    char key[100];
    scanf("%s", fn);
    scanf("%s", key);
    char* res = getKey(fn, key);
    if(res == NULL)
        printf("Not found\n");
    else
    {
        printf("[%s]=[%s]\n", key, res);
        free(res);
    }
    return(0);
}

int testSetKey()
{
    char fn[100];
    char key[100];
    char v[100];
    scanf("%s", fn);
    scanf("%s", key);
    scanf("%s", v);
    char* res = setKey(fn, key, v);
    if(res == NULL)
        printf("Not found %s\n", key);
    else
    {
        printf("[%s]=[%s]\n", key, res);
        free(res);
    }
    return(0);
}

int main()
{
//    return(testFileToConfig());
//    return(testParseString());
//    return(testGetKey());
    char s[100];
    scanf("%s", s);
    if(!strcmp(s, "edit"))
        return(testSetKey());
    else if(!strcmp(s, "view"))
        return(testGetKey());
}
