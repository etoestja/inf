#include <signal.h>
#include <stdio.h>

void handler(int sigid)
{
    printf("CTRLC\n");
}

int main(void){

    signal(SIGINT, handler);
    while(1);
    return 0;

}

