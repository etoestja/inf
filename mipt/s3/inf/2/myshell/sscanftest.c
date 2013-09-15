#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "test   1 test2 test3";

    char s0[100], s1[100];

    int t;
    sscanf(s, "%s%n", s0, &t);
    printf("asdf=%d\n", t);
    printf("got %d symbols\n", sscanf(s + strlen(s0), "%s", s1));

    printf("%s\n[%s]\n[%s]\n", s, s0, s1);

    return(0);
}
