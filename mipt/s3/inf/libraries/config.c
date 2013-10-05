#include "config.h"
#include <string.h>

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
    int len;
    char* string = NULL;
    while((len = getline(&string, &len1, fd)) > 0)
    {
        conf->nStrings++;
        conf->strings = realloc(conf->strings, sizeof(char*) * conf->nStrings);
        string[len - 1] = 0;
        conf->strings[conf->nStrings - 1] = string;
//        printf("+1\n");
        string = NULL;
    }
    fclose(fd);
    return(0);
}

int configToFile(char* filename, config *conf)
{
    if(conf == NULL)
        return(-1);

    FILE* fd = fopen(filename, "w");
    int i;
    for(i = 0; i < conf->nStrings; i++)
        fprintf(fd, "%s\n", conf->strings[i]);

    conf->nStrings = 0;
    conf->strings = NULL;

    fclose(fd);
    return(0);
}

void printConfig(config *conf)
{
    if(conf == NULL) return;

    int i;
    for(i = 0; i < conf->nStrings; i++)
        printf("config str %d: [%s]\n", i, conf->strings[i]);
}

findKeyRes parseString(char* string)
{
    findKeyRes res;
    res.keyL = -1;
    res.keyPos = -1;
    res.eqPos = -1;
    res.valPos = -1;
    res.valL = -1;
    res.stringN = -1;
    if(string == NULL)
        return(res);

    enum _state {SLK, SFK, SLE, SLV, SFV};
    char* names[] = {"SLK", "SFK", "SLE", "SLV", "SFV"};
    int state = SLK;
    int i, L = strlen(string);
    char c;

    for(i = 0; i < L; i++)
    {
        c = string[i];
//        printf("i=%d, c=%c, state=%s\n", i, c, names[state]);
        if(state == SLK)
        {
            if(c == '#')
                break;
            if(c != ' ' && c != '\t')
            {
                res.keyPos = i;
                res.keyL = 1;
                state = SFK;
            }
        }
        else if(state == SFK)
        {
            if(c == '=')
            {
                res.eqPos = i;
                state = SLV;
            }
            else if(c == '#')
                break;
            else if(c != ' ' && c != '\t' )
                res.keyL++;
            else
                state = SLE;
        }
        else if(state == SLE)
        {
            if(c == '#')
                break;
            else if(c == '=')
            {
                res.eqPos = i;
                state = SLV;
            }
        }
        else if(state == SLV)
        {
            if(c == '#')
                break;
            else if(c != ' ' & c != '\t')
            {
                res.valPos = i;
                res.valL = 1;
                state = SFV;
            }
        }
        else if(state == SFV)
        {
            if(c != ' ' && c != '\t' && c != '#')
                res.valL++;
            else break;
        }
    }
    return(res);
}

findKeyRes findKey(config* conf, char* keyname)
{
    findKeyRes res;
    res.stringN = -1;
    if(conf == NULL || keyname == NULL)
        return(res);

    int i;
    for(i = 0; i < conf->nStrings; i++)
    {
//        fi
    }
}

char* getSubstr(char* string, int p0, int L)
{
    if(string == NULL || p0 < 0 || p0 + L > strlen(string)) return("");
    char* res = malloc(sizeof(char) * L + 1);
    int i;
    for(i = 0; i < L; i++)
        res[i] = string[p0 + i];
    res[L] = 0;
    return(res);
}

char* getKey(char* filename, char* keyname)
{
    config conf;
    if(fileToConfig(filename, &conf) != 0)
        return(NULL);

    int i;
    findKeyRes fk;
    char* tStr;
    char* res = NULL;
    int m;
    for(i = 0; i < conf.nStrings; i++)
    {
        fk = parseString(conf.strings[i]);
        if(fk.keyPos != -1 && fk.eqPos != -1 && fk.valPos != -1)
        {
            if(!strCmpSubstr(conf.strings[i], fk.keyPos, fk.keyL, keyname) && res == NULL)
                res = getSubstr(conf.strings[i], fk.valPos, fk.valL);
        }
    }
    freeConfig(&conf);
    return(res);
}

char* setKey(char* filename, char* keyname, char* value)
{
    config conf;
    if(value == NULL || strlen(value) == 0)
        return(NULL);
    if(fileToConfig(filename, &conf) != 0)
        return(NULL);

    int i;
    findKeyRes fk;
    char* tStr;
    char* res = NULL;
    int m;
    char* repl;
    for(i = 0; i < conf.nStrings; i++)
    {
        fk = parseString(conf.strings[i]);
        if(fk.keyPos != -1 && fk.eqPos != -1 && fk.valPos != -1)
        {
            if(!strCmpSubstr(conf.strings[i], fk.keyPos, fk.keyL, keyname) && res == NULL)
            {
                res = getSubstr(conf.strings[i], fk.valPos, fk.valL);
                repl = malloc(sizeof(char) * (strlen(conf.strings[i]) - fk.valL + strlen(value)));
                strncpy(repl, conf.strings[i], fk.valPos);
                strncpy(repl + fk.valPos, value, strlen(value));
                strcpy(repl + fk.valPos + strlen(value), conf.strings[i] + fk.valPos + fk.valL);
                free(conf.strings[i]);
                conf.strings[i] = repl;
//                printf("repl=%s\n", repl);
            }
        }
    }
    if(res == NULL)
    {
        conf.nStrings++;
        conf.strings = realloc(conf.strings, sizeof(char*) * (conf.nStrings));
        tStr = malloc(sizeof(char) * (1 + strlen(value) + 1 + strlen(keyname)));
        strcpy(tStr, keyname);
        strcpy(tStr + strlen(keyname), "=");
        strcpy(tStr + strlen(keyname) + 1, value);
        tStr[strlen(keyname) + strlen(value) + 2] = 0;
        conf.strings[conf.nStrings - 1] = tStr;
        printf("adding %s\n", tStr);
    }
    configToFile(filename, &conf);
    freeConfig(&conf);
    return(res);
}

int strCmpSubstr(char* string, int p0, int L, char* string2)
{
    if(string2 == NULL || string == NULL)
        return(-1);
    int L2 = strlen(string2);
    if(L2 != L)
        return(1);
    int i;
    for(i = 0; i < L; i++)
        if(string[p0 + i] != string2[i])
            return(1);
    return(0);
}

void freeConfig(config *conf)
{
    if(conf == NULL) return;
    int i;
    for(i = 0; i < conf->nStrings; i++)
    {
//        printf("freeing i\n", i);
        free(conf->strings[i]);
    }
    free(conf->strings);
}
