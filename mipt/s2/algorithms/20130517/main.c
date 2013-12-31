#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int randN(int N) //random in {0, ..., N - 1}
{
//    srand(time(NULL));
    return(((long long) rand()) * (N - 1) / RAND_MAX);
}

enum tC{cB, cM, cH};
enum tState{online, won, lost};

enum tState state = online;
int B; //rabbits {0...+inf}
int M; //monsters {0...+inf}
int H; //player {0, 1}

int B0, M0;

// indexes: B, M, H

inline enum tC getType(int x)
{
    if(x < B) return(cB);
    else if(x < B + M) return(cM);
    else return(cH);
}

void choice()
{
    int r = randN(2);
    if(r == 1) B--;
}

void stateUpdate()
{
    if(M == 0) state = won;
    if(H == 0) state = lost;
}

void move()
{
    //get random pair
    int c1 = randN(B + M + H);
    int c2 = randN(B + M + H - 1);
    if(c2 == c1) c2 = B + M + H - 1;
    
    enum tC t1 = getType(c1);
    enum tC t2 = getType(c2);

    if(t1 == cM && t2 == cM)
        M -= 2;
    else if(t1 == cM && t2 == cB)
        B--;
    else if(t1 == cB && t2 == cM)
        B--;
    else if(t1 == cM && t2 == cH)
        H--;
    else if(t1 == cH && t2 == cM)
        H--;
    else if(t1 == cB && t2 == cH)
        choice();
    else if(t1 == cH && t2 == cB)
        choice();
    
    stateUpdate();

//    fprintf(stderr, "got pair (%d\t%d)\n", c1, c2);
}

void printState()
{
    printf("%d\t%d\t%d\t", M, B, H);
    if(state == won) printf("won");
    else if(state == lost) printf("lost");
    else printf("online");
    printf("\n");
}

void init()
{
    H = 1;
    B = B0;
    M = M0;
    state = online;
}

void randInit()
{
    srand(time(NULL));
}

int gameWon()
{
    init();

//    printState();
    while(state == online)
    {
        move();
//        printState();
    }

    return(state == won);
}

int main()
{
    randInit();
    int i, Games;
    scanf("%d", &B0);
    scanf("%d", &M0);
    scanf("%d", &Games);

    int won = 0;

    for(i = 0; i < Games; i++)
        if(gameWon()) won++;

    printf("%lf\n", (1.0 * won) / Games);

    return(0);
}
