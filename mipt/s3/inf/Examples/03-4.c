#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    int i = 0;

    while(envp[i] != NULL){
      printf("Env var %d: %s\n", i, envp[i]);
      i++;
    }

    exit(0);
}