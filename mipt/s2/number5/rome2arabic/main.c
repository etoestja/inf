#include <stdio.h>
#include <string.h>

const unsigned int M = 256, T = 13;

#define LEN 1000

const char* names[T] = {"M",   "CM",   "D",    "CD",   "C",    "XC",  
    "L",    "XL",   "X",    "IX",   "V",    "IV",   "I"};
unsigned int values[T] =     {1000,  900,    500,    400,    100,   
    90,     50,     40,     10,     9,      5,      4,      1};
unsigned int used[T];
char y[LEN], yC;

void get_roman(unsigned int N)
{
    unsigned int i = 0;
    for(i = 0; i < T;)
    {
        if(values[i] <= N)
        {
            N -= values[i];
            used[i]++;
        }
        else i++;
    }
}

void print_roman()
{
    int i, si;
    for(i = 0; i < T; i++)
        for(si = 0; si < used[i]; si++)
        {
            y[yC++] = names[i][0];
            if(names[i][1]) y[yC++] = names[i][1];
        }
    y[yC] = 0;
}

int main()
{
    char x[LEN];
    int i, si;
    scanf("%s", x);

    for(i = 1; i <= 3999; i++)
    {
        for(si = 0; si < T; si++) used[si] = 0;
        yC = 0;
        get_roman(i);
        print_roman();
//        printf("%d\t%s\n", i, y);
        if(!strcmp(x, y)) break;
    }

    printf("%d\n", i);

    return 0;
}
