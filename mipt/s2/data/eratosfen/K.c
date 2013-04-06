#include <stdio.h>
#include <stdlib.h>
char Ar[25000001];
int main()
{
    long x,i,d,k,by,count;
    int bi;
    scanf("%ld", &x);
    for(i=1; i<=(x-1)/8+1; i++)
    {
        Ar[i]=0;
    }

    for(d=2; d<=(x+1)/2; d++)
    {
        if((Ar[d/8+1] & (1<<(7-(d%8))))==0)
        {
            for(k=d * 2;k<=x;k+=d)
            {
                by=k/8+1;
                bi=k%8;
                Ar[by]|=(1<<(7-bi));
            }
        }
    }

    count=0;
    for(d=1; d<=(x+1)/2;d++)
    {
        by=d/8+1;
        bi=d%8;
        if((Ar[by] & (1<<(7-bi)))==0)
        {
            count+=1;
        }
    }

    printf("%ld", count);
    return 0;
}

