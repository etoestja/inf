#include <stdio.h>
#include <QDebug>
#include <stdlib.h>
unsigned char Ar[25000001];


void binPrint(char a)
{
    int i;
    for(i = 7; i >= 0; i--)
        printf("%d", (a & (1 << i)) ? 1 : 0);
}

void binPrintAll()
{
    int i, K = 10;
    for(i = 0; i < K; i++)
    {
        printf("01234567");
    }

    printf("\n");

    for(i = 0; i < K; i++)
    {
        binPrint(Ar[i]);
    }
    printf("\n");
}

int main()
{
    long x, i, d, k, by, count;
    int bi;
    scanf("%ld", &x);
    for(i=1; i <= (x-1) / 8 + 1; i++)
    {
        Ar[i]=0;
    }

    binPrintAll();

    for(d=2; d<=(x+1)/2; d++)
    {
        if((Ar[d / 8 + 1] & (1 << (7 - (d % 8)))) == 0x00)
        {
            qDebug() << d << " isprime";
            for(k = d * d; k <= x; k += d)
            {
                binPrint((1 << (7 - (k % 8))));
                printf("byte=%d, bit=%d, number=%d\n", k / 8 + 1, k % 8, k);
                Ar[k / 8 + 1] |= ((long unsigned int) (1 << (7 - (k % 8))));//(1 << (7 - (k % 8)));
            }
        }
    }

    binPrintAll();

    count=0;
    for(d=1; d<=x;d++)
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
//#include <stdio.h>
//#include <stdlib.h>
//char Ar[25000001];
//int main()
//{
//    long x,i,d,k,by,count;
//    int bi;
//    scanf("%ld", &x);
//    for(i=1; i<=(x-1)/8+1; i++)
//    {
//        Ar[i]=0;
//    }

//    for(d=2; d<=(x+1)/2; d++)
//    {
//        if((Ar[d/8+1] & (1<<(7-(d%8))))==0)
//        {
//            for(k=d * 2;k<=x;k+=d)
//            {
//                by=k/8+1;
//                bi=k%8;
//                Ar[by]|=(1<<(7-bi));
//            }
//        }
//    }

//    count=0;
//    for(d=1; d<=(x+1)/2;d++)
//    {
//        by=d/8+1;
//        bi=d%8;
//        if((Ar[by] & (1<<(7-bi)))==0)
//        {
//            count+=1;
//        }
//    }

//    printf("%ld", count);
//    return 0;
//}
