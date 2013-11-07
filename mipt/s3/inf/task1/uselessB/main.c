#include <stdio.h>

#include <string.h>

#include <sys/types.h>

#include <unistd.h>

#include <sys/wait.h>

#include <stdlib.h>



#define N 100

int main(void){

 char str[N];

 pid_t pid;

 int s,t, i;

FILE *f;

 char *fname = "15.txt";

 f = fopen(fname,"r");



fscanf(f, "%d%s", &s, str);





   if ( (pid = fork()) < 0)

      printf("fork is not correct\n");

   else if (pid == 0) {

      sleep(s);

      execlp(str, str, (char *) 0);

      printf("нельзя запустить %s\n", str);

      return(2);

   }

   if ( (pid = waitpid(pid, &t, 0)) < 0)

      printf("waitpid is not correct\n");

      printf("%% ");

 

fclose(f);

   return(0);

}
