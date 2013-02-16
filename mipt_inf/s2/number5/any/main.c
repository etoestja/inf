#include <stdio.h>
#include <string.h>

int base1, base2;

#define LEN 1000

int power(int a, int b)
{
    int res = 1;
    for(; b; b--) res *= a;
    return(res);
}

int main()
{
    char x[LEN];
    int n = 0, l1, i;

    scanf("%d", &base1);
    scanf("%s", x);
    scanf("%d", &base2);
    l1 = strlen(x);

    for(i = 0; i < l1; i++)
    {
        if(x[i] >= '0' && x[i] <= '9') x[i] -= '0';
        if(x[i] >= 'A' && x[i] <= 'Z') x[i] -= 'A' - 10;
    }

    for(i = 0; i < l1; i++)
        n += power(base1, l1 - i - 1) * x[i];

//    printf("%d\n", n);

    char y[LEN];
    int yC = 0;

    if(n == 0) printf("0");

    while(n)
    {
        y[yC++] = n % base2;
        n /= base2;
    }

    char m;
    for(yC--; yC >=0; yC--)
    {
        if(y[yC] <= 9) m = y[yC] + '0';
        else m = y[yC] - 10 + 'A'; 
        printf("%c", m);
    }

    printf("\n");

    return 0;
}
