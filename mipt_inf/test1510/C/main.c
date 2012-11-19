#include <stdio.h>

#define MM 12
int daysInM[MM] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                 //J  F  M   A   M   J   J   A   S   O   N   D

int is29(int Y)
{
    return(((Y % 4) == 0 && (Y % 100) != 0) || (Y % 400) == 0);
}

int main(void)
{
    int Y, M, D, ans = 0;
    scanf("%d %d %d", &Y, &M, &D);
    if(M >= 1 && M <= MM)
    {
        daysInM[1] = is29(Y) ? 29 : 28;

        if(D >= 1 && D <= daysInM[M - 1]) ans = 1;
    }

    printf("%s\n", ans ? "YES" : "NO");

    return 0;
}

