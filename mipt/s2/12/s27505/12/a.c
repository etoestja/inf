#include <stdio.h>

union myint
{
    int a;
    char c;
};

int main()
{
    union myint mi;
    mi.a = 0x12345678;
    if(mi.c == 0x12) printf("Big-endian\n");
    else printf("Little-endian\n");
    return(0);
}
