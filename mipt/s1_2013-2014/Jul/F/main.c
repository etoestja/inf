//#define DEBUG
#undef DEBUG

#ifdef DEBUG
#include <stdio.h>
#endif

unsigned int nod(unsigned int a, unsigned int b)
{
    static unsigned int t;

    while(b)
    {
        if(a > b)
        {
            t = a;
            a = b;
            b = t;
        }

        b %= a;
    }

    return(a);
}

#ifdef DEBUG
int main()
{
    unsigned int a, b;
    scanf("%u %u", &a, &b);

    printf("%u\n", nod(a, b));

    return(0);
}
#endif
