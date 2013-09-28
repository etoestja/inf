#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int a = 0;

void *mythread(void *dummy)

/*
 *   Parameter void *dummy is used only for type compatibility, and will not be used
 *   at the function now. At the same reason the return value of function has type 
 *   void *, but it wiil be not used at this program.
 */

{

   pthread_t mythid;
   
   mythid = pthread_self();

   a = a+1;

   printf("Thread %d, Calculation result = %d\n", mythid, a);

   return NULL;
}

#define N 20

int main()
{
   pthread_t thid[N], mythid; 
   int       result;

   int i;
   for(i = 0; i < N; i++)
   {
   result = pthread_create( &thid[i], (pthread_attr_t *)NULL, mythread, NULL);
   
   if(result != 0){
      printf ("Error on thread create, return value = %d\n", result);
      exit(-1);
   }
   printf("Thread created, thid = %d\n", thid[i]);
    }
   

   mythid = pthread_self();
   
   a = a+1;
   
   printf("Thread %d, Calculation result = %d\n", mythid, a);

    for(i = 0; i < N; i++)
   pthread_join(thid[i], (void **)NULL);

   return 0;
}
