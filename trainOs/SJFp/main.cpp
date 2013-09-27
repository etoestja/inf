#include <stdio.h>

#define NMAX (100 + 5)
#define TMAX (1000 + 5)

enum _state{S_NCOME, S_WAITING, S_RUNNING, S_DONE};

int arr[TMAX][NMAX];
int N;
int T0[NMAX];
int T[NMAX];
int Tr[NMAX];
int Num[NMAX];
int isDone[NMAX];
int startTime[NMAX];
int MTime;
int tTime[NMAX];
int wTime[NMAX];
int temp;

#define swap(a, b) {temp = a; a = b; b = temp;}

void psort()
{
    int i, j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N - 1; j++)
        {
            if(T0[j] > T0[j + 1])
            {
                swap(T0[j], T0[j + 1]);
                swap(T[j], T[j + 1]);
                swap(Num[j], Num[j + 1]);
            }
        }
}

void dumpArr()
{
    int i;
    printf("Num\t");
    for(i = 0; i < N; i++)
    {
        printf("%d\t", Num[i]);
    }

    printf("\nT0\t");
    for(i = 0; i < N; i++)
    {
        printf("%d\t", T0[i]);
    }

    printf("\nT\t");
    for(i = 0; i < N; i++)
    {
        printf("%d\t", T[i]);
    }
    printf("\n");
}

void fill()
{
    int currentProcess = -1;
    int currentTime = 0;
    int done = 0;
    int i, t1;
    for(currentTime = 0; done < N; currentTime++)
    {
//        if(currentProcess == -1)
//        {
            t1 = -1;
            for(i = 0; i < N; i++)
            {
                if(!isDone[i] && currentTime >= T0[i] && (t1 == -1 || Tr[i] < Tr[t1]))
                    t1 = i;
            }
            if(t1 != -1)
            {
                currentProcess = t1;
                startTime[t1] = currentTime;
            }
//        }

        for(i = 0; i < N; i++)
        {
            if(currentProcess == i)
            {
                tTime[i]++;
                arr[currentTime][i] = S_RUNNING;
                Tr[i]--;
            }
            else
            {
                if(currentTime < T0[i])
                    arr[currentTime][i] = S_NCOME;
                else
                {
                    if(!isDone[i])
                    {
                        tTime[i]++;
                        wTime[i]++;
                        arr[currentTime][i] = S_WAITING;
                    }
                    else
                        arr[currentTime][i] = S_DONE;
                }
            }

/*            if(currentProcess == -1 && !isDone[i] && currentTime >= T0[i])
            {
                currentProcess = i;
                startTime[i] = currentTime;
                if(arr[currentTime][i] == S_WAITING)
                    wTime[i]--;
                arr[currentTime][i] = S_RUNNING;
//                tTime[i]++;
            }*/
        }

        if(currentProcess != -1 && currentTime - startTime[currentProcess] + 1>= T[currentProcess])
        {
            isDone[currentProcess] = 1;
            currentProcess = -1;
            done++;
        }
    }
    MTime = currentTime - 1;
}

void init()
{
    int i;
    for(i = 0; i < N; i++)
    {
        isDone[i] = 0;
        wTime[i] = 0;
        tTime[i] = 0;
    }
}

void printN3(int x)
{
    printf("%3d", x);
}

void printS3(int s)
{
    printf("  ");
    if(s == S_NCOME)
        printf(" ");
    else if(s == S_WAITING)
        printf("r");
    else if(s == S_RUNNING)
        printf("R");
    else if(s == S_DONE)
        printf(" ");
}

void print()
{
    printf("n\\t|");
    int i, j, k;
    for(i = 0; i <= MTime; i++)
    {
        printN3(i);
    }

    printf("\n---|");
    for(i = 0; i <= MTime; i++)
    {
        printf("---");
    }
    printf("\n");

    for(i = 1; i <= N; i++)
    {
        printN3(i);
        printf("|");
        for(j = 0; j < N; j++)
        {
            if(Num[j] == i)
            {
                for(k = 0; k <= MTime; k++)
                {
                    printS3(arr[k][j]);
                }
                printf("\n");
            }
        }
    }

    double t, w;

    printf("\nturnaround time = (");
    for(i = 1; i <= N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(Num[j] == i)
            {
                printf("%d", tTime[j]);
                t += tTime[j];
                if(i < N)
                    printf(" + ");
            }
        }
    }
    printf(") / %d = %lg\n", N, t / N);

    printf("waiting time = (");
    for(i = 1; i <= N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(Num[j] == i)
            {
                printf("%d", wTime[j]);
                w += wTime[j];
                if(i < N)
                    printf(" + ");
            }
        }
    }
    printf(") / %d = %lg\n", N, w / N);
}

int main()
{
    scanf("%d", &N);

    int i;
    for(i = 0; i < N; i++)
    {
        scanf("%d", &(T0[i]));
        scanf("%d", &(T[i]));
        Tr[i] = T[i];
        Num[i] = i + 1;
    }

    psort();
//    dumpArr();

    fill();

    print();

    return(0);
}
