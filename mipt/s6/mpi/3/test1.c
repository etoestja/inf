#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

int a = 0;

void op()
{
//    sem_wait(&sem);
    int i;
    for(i = 0; i < 1000; i++)
        a++;
//    sem_post(&sem);
}

void* func(void* a)
{
    int local = *((int*) a);
    op();
    return(NULL);
}

int main()
{
    const unsigned N = 10;
    sem_init(&sem, 0, 1);
    pthread_t thr[N];

    int param = 4;
    int i;
    for(i = 0; i < N; i++)
        pthread_create(&thr[i], NULL, func, (void*) &param);


    for(i = 0; i < N; i++)
        pthread_join(thr[i], NULL);
    printf("%d\n", a);

//    printf("Thread returned\n");
    sem_destroy(&sem);
    return(0);
}
