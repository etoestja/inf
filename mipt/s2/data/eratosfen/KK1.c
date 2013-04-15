#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char Ar[25000001];
char B[8];
int main()
{
    long x,i,d,k,by,count;
    int bi;
    for(i=0;i<8; i++)
    {
        B[i]=(1<<(7-i));
    }

    scanf("%ld", &x);
    for(i=1; i<=(x-1)/8+1; i++)
    {
        Ar[i]=0;
    }

    count=0;
    for(d=2; d*d<=x; d++)
    {
        if((Ar[d/8+1] & B[bi])==0)
        {
            for(k=d * d;k<=x;k+=d)
            {
                by=k/8+1;
                bi=k%8;
                if((Ar[by] & B[bi])==0)
                    count++;
                    Ar[by]|=B[bi];
            }
        }
    }

    printf("%ld", x-count-1);
    return 0;
}
