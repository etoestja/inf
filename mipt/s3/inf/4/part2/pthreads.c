#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sched.h>
#include <time.h>

//#define MATRIX_SIZE (10240 + 512 * 8)
#define MATRIX_SIZE 2

struct pthread_info {
	int msize;
	int srow;
	int rstep;
	int *a;
	int *b;
	int *c;
	int cpu;
};

void initMatricies(int *a, int *b, int *c, int size);
void *thread_multiplication(void *pargs);
void multiplyMatricies(int *a, int *b, int *c, int size);
int stick_this_thread_to_core(int core_id);

void printm(int *a)
{
    for(int i = 0; i < MATRIX_SIZE; i++)
    {
        for(int j = 0; j < MATRIX_SIZE; j++)
            printf("%d ", a[i * MATRIX_SIZE + j]);
        printf("\n");
    }
}

int main(int argc, char *argv[], char **envp){
	int *a = NULL, *b = NULL, *c = NULL;
	int num_cores = 0;
	int i = 0, j = 0;
	time_t stime, ftime;
	int size = MATRIX_SIZE;
	struct pthread_info *targs = NULL;
	pthread_t *threads = NULL;

	num_cores = sysconf(_SC_NPROCESSORS_ONLN);
	printf("System Info:\n--------------------\nCPUs: %d\n", num_cores);
	a = (int *)malloc(sizeof(int) * size * size);
	b = (int *)malloc(sizeof(int) * size * size);
	c = (int *)malloc(sizeof(int) * size * size);
	targs = (struct pthread_info *)malloc(sizeof(struct pthread_info) * num_cores);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * num_cores);
	for(i = 0; i < num_cores; i++){
		targs[i].msize = size;
		targs[i].srow = i;
		targs[i].rstep = num_cores;
		targs[i].a = a;
		targs[i].b = b;
		targs[i].c = c;
		targs[i].cpu = 0;
		threads[i] = 0;
	}

	printf("Init Matricies...\n");
	time(&stime);
	initMatricies(a, b, c, size);
	time(&ftime);
	printf("Finish of Initialization.\nTime: %d sec.\n", (ftime - stime));
	printf("Start multiplying...\n");
	time(&stime);
	multiplyMatricies(a, b, c, size);
	time(&ftime);
	printf("Finish Multiplying.\n");
	printf("Finish of Multiplying.\nTime: %d sec.\n", (ftime - stime));
        printf("\n");
        printm(a);
        printf("\n");
        printm(b);
        printf("\n");
        printm(c);
	printf("Now using threads.\n");
	for(j = 1; j <= num_cores; j++){
		printf("Start multiplying %d cores...\n", j);
		time(&stime);
		for(i = 0; i < num_cores; i++){
			targs[i].cpu = i % j;
			pthread_create(&threads[i], NULL, thread_multiplication, &targs[i]);
		}
		for(i = 0; i < num_cores; i++){
			pthread_join(threads[i], NULL);
		}
		time(&ftime);
		printf("Finish Multiplying.\n");
		printf("Finish of Multiplying.\nTime: %d sec.\n", (ftime - stime));
        printf("\n");
        printm(a);
        printf("\n");
        printm(b);
        printf("\n");
        printm(c);
        }
	return 0;
}

void *thread_multiplication(void *pargs){
	struct pthread_info *targs = (struct pthread_info *)pargs;
	int size = targs->msize;
	int srow = targs->srow;
	int rstep = targs->rstep;
	int *a = targs->a;
	int *b = targs->b;
	int *c = targs->c;
	int i = srow;
	int j = 0;
	int cpu = targs->cpu;
	stick_this_thread_to_core(cpu);
	while(i < size){
		j = 0;
		while(j < size){
			c[i * size + j] += a[i * size + j] * b[j * size + i];
			j++;
		}
		i += rstep;
	}
}

void initMatricies(int *a, int *b, int *c, int size){
    int i = 0, j = 0;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
/*			a[i * size + j] = i + j;
			b[i * size + j] = i * j;*/
			c[i * size + j] = 0;
		}
	}

    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;

    b[0] = 5;
    b[1] = 6;
    b[2] = 7;
    b[3] = 8;
}

void multiplyMatricies(int *a, int *b, int *c, int size){
	int i = 0, j = 0;
	for(i = 0; i < size; i ++){
		for(j = 0; j < size; j++){
			c[i * size + j] += a[i * size + j] * b[j * size + i];
		}
	}
}

int stick_this_thread_to_core(int core_id){
	int num_cores = sysconf(_SC_NPROCESSORS_ONLN);
	int res = 0;
	if(core_id < num_cores){
		cpu_set_t cpuset;
		CPU_ZERO(&cpuset);
		CPU_SET(core_id, &cpuset);

		pthread_t current_pthread = pthread_self();
		res = pthread_setaffinity_np(current_pthread, sizeof(cpu_set_t), &cpuset);
	}
	return res;
}
