#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randInit()
{
    srand(time(NULL));
}

inline int rand2()
{
    return(rand() > RAND_MAX /2);
}

enum tState{sL, sIn, sR};
#define N 100
int sPosition;

// position: 0...N-1

int position;
enum tState state;
int moves;
int lastmove;

void stateUpdate()
{
    if(position < 0) state = sL;
    else if(position >= N) state = sR;
}

void move()
{
    int r = rand2();
    if(r == 0)
    {
        position--;
        lastmove = -1;
    }
    else
    {
        position++;
        lastmove = 1;
    }

    stateUpdate();

    moves++;
}

void printState()
{
    printf("%d\t%d\t", moves, position);
    if(state == sL) printf("left");
    else if(state == sIn) printf("in");
    else printf("right");
    printf("\t");
    printf("%s\n", lastmove == 1 ? "-->" : "<--");
}

void init()
{
    moves = 0;
    state = sIn;
    position = sPosition;
}

void man()
{
    init();

//    printState();

    while(state == sIn)
    {
        move();
//        printState();
    }
}

int Games;

void games()
{
    int i;

    int leftCount = 0;
    int rightCount;

    unsigned long long leftTime = 0;
    unsigned long long rightTime = 0;

    for(i = 0; i < Games; i++)
    {
        man();
//        printState();
        if(state == sL)
        {
            leftTime += moves;
            leftCount++;
        }
        else rightTime += moves;
    }

    rightCount = Games - leftCount;

    leftTime /= leftCount;
    rightTime /= rightCount;

    long double pL = 1.0 * leftCount / Games;
    long double pR = 1.0 * rightCount / Games;

    printf("%d\t%llf\t%llf\t%llu\t%llu\n", sPosition, pL, pR, leftTime, rightTime);

//    printf("pL=%lf\n", 1.0 * leftCount / Games);
//    printf("pR=%lf\n", 1.0 * rightCount / Games);

//    printf("tL=%llu\n", leftTime);
//    printf("tR=%llu\n", rightTime);

//    printf("pLpR=%lf\n", 1.0 * leftCount / rightCount);
//    printf("tRtL=%lf\n", 1.0 * rightTime / leftTime);
}

int main()
{
    randInit();
    Games = 100000;
    for(sPosition = 0; sPosition < N; sPosition++)
    {
        fprintf(stderr, "p=%d\n", sPosition);
        games();
    }
    return(0);
}
