#ifndef MYAUTH_H
#define MYAUTH_H

#include "common.h"
#define AUTHINFOFILE "passwords"

typedef struct
{
    char name[MNAME];
    char password[MPASSWORD];
} authInfo;

authInfo* authInfoArr;
int authInfoN;

void authInfoReadFile();
int authenticate(const char* user, const char* passwd);

#endif // MYAUTH_H
