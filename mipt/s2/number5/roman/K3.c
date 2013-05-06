#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int A[7];
    int i,M,count;
    A[0]=A[1]=A[2]=A[3]=A[4]=A[5]=A[6]=0;
    char c[100000];
    char res[20];
    scanf("%s", &c);
    M=strlen(c);

    for(i=0;i<M;i++)
    {
        if((c[i]=='I') || (c[i]=='i'))
            A[0]++;
        else
        if((c[i]=='V') || (c[i]=='v'))
            A[1]++;
        else
        if((c[i]=='X') || (c[i]=='x'))
            A[2]++;
        else
        if((c[i]=='L') || (c[i]=='l'))
            A[3]++;
        else
        if((c[i]=='C') || (c[i]=='c'))
            A[4]++;
        else
        if((c[i]=='D') || (c[i]=='d'))
            A[5]++;
        else
        if((c[i]=='M') || (c[i]=='m'))
            A[6]++;
    }

//    for(i = 0; i < 7; i++)
  //      printf("%d %d\n", i, A[i]);

    count=0;
    i=0;

    while((A[6]>0) && (count<3))
    {
        A[6]--;
        count++;
        res[i]='M';
        i++;
    }

    if((A[4]>=3) && (A[5]>=1))
    {
        A[4]-=3;
        A[5]--;
        res[i]='D';
        i++;
        res[i]='C';
        i++;
        res[i]='C';
        i++;
        res[i]='C';
        i++;
    }
    else
    if((A[4]>=2) && (A[5]>=1))
    {
        A[4]-=2;
        A[5]--;
        res[i]='D';
        i++;
        res[i]='C';
        i++;
        res[i]='C';
        i++;
    }
    else
    if(A[4]>=3)
    {
        A[4]-=3;
        res[i]='C';
        i++;
        res[i]='C';
        i++;
        res[i]='C';
        i++;
    }
    else
    if((A[6]>=1) && (A[4]>=1))
    {
        A[6]--;
        A[4]--;
        res[i]='C';
        i++;
        res[i]='M';
        i++;
    }
    else
    if((A[4]>=1) && (A[5]>=1))
    {
        A[4]--;
        A[5]--;
        res[i]='D';
        i++;
        res[i]='C';
        i++;
    }
    else
    if(A[4]>=2)
    {
        A[4]-=2;
        res[i]='C';
        i++;
        res[i]='C';
        i++;
    }
    else
    if(A[5]>=1)
    {
        A[5]--;
        res[i]='D';
        i++;
    }
    else
    if(A[4]>=1)
    {
        A[4]--;
        res[i]='C';
        i++;
    }



    if((A[2]>=3) && (A[3]>=1))
    {
        A[2]-=3;
        A[3]--;
        res[i]='L';
        i++;
        res[i]='X';
        i++;
        res[i]='X';
        i++;
        res[i]='X';
        i++;
    }
    else
    if((A[2]>=2) && (A[3]>=1))
    {
        A[2]-=2;
        A[3]--;
        res[i]='L';
        i++;
        res[i]='X';
        i++;
        res[i]='X';
        i++;
    }
    else
    if((A[4]>=1) && (A[2]>=1))
    {
        A[4]--;
        A[2]--;
        res[i]='X';
        i++;
        res[i]='C';
        i++;
    }
    else
    if(A[2]>=3)
    {
        A[2]-=3;
        res[i]='X';
        i++;
        res[i]='X';
        i++;
        res[i]='X';
        i++;
    }
    else
    if((A[2]>=1) && (A[3]>=1))
    {
        A[3]--;
        A[2]--;
        res[i]='L';
        i++;
        res[i]='X';
        i++;
    }
    else
    if(A[2]>=2)
    {
        A[2]-=2;
        res[i]='X';
        i++;
        res[i]='X';
        i++;
    }
    else
    if(A[3]>=1)
    {
        A[3]--;
        res[i]='L';
        i++;
    }
    else
    if(A[2]>=1)
    {
        A[2]--;
        res[i]='X';
        i++;
    }


    if((A[0]>=3) && (A[1]>=1))
    {
        A[0]-=3;
        A[1]--;
        res[i]='V';
        i++;
        res[i]='I';
        i++;
        res[i]='I';
        i++;
        res[i]='I';
        i++;
    }
    else
    if((A[0]>=2) && (A[1]>=1))
    {
        A[0]-=2;
        A[1]--;
        res[i]='V';
        i++;
        res[i]='I';
        i++;
        res[i]='I';
        i++;
    }
    else
    if(A[0]>=3)
    {
        A[0]-=3;
        res[i]='I';
        i++;
        res[i]='I';
        i++;
        res[i]='I';
        i++;
    }
    else
    if((A[2]>=1) && (A[0]>=1))
    {
        A[2]--;
        A[0]--;
        res[i]='I';
        i++;
        res[i]='X';
        i++;
    }
    else
    if((A[0]>=1) && (A[1]>=1))
    {
        A[0]--;
        A[1]--;
        res[i]='V';
        i++;
        res[i]='I';
        i++;
    }
    else
    if(A[0]>=2)
    {
        A[0]-=2;
        res[i]='I';
        i++;
        res[i]='I';
        i++;
    }
    else
    if(A[1]>=1)
    {
        A[1]--;
        res[i]='V';
        i++;
    }
    else
    if(A[0]>=1)
    {
        A[0]--;
        res[i]='I';
        i++;
    }

    res[i]=0;
    printf("%s", res);
    return 0;
}
