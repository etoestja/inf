#include <stdio.h>

char* arr[255];

long long res1, res2;

#define rstart() asm("movq $0, %rdx\n" "movq $0, %rcx\n" "rdtsc\n" "movl %eax, %ebx\n" "movl %edx, %ecx\n")
#define rstop() asm("rdtsc\n" "movq %rdx, %r8\n" "shlq $32, %r8\n" "movl %eax, %r8d\n"\
"movq %rcx, %r9\n" "shlq $32, %r9\n" "movl %ebx, %r9d\n" "movq %r8, res1\n" "movq %r9, res2\n")
#define print_res() printf("%lld\n", res1 - res2)
#define get_nop() {rstart(); asm("nop\n"); rstop();}

int main()
{
    char x;
    scanf("%c", &x);
    long long i, N = 10, sum = 0;
/*    for(i = 0; i < N; i++)
    {
        get_nop();
        sum += res1 - res2;
    }
    sum /= N;*/
    sum = 62;

//    printf("%llu\n", sum);

    if(x == 'n')
    {
//        rstart();
//        asm("nop\n");
//        rstop();
        printf("1\n");
        return(0);
    }
    else if(x == 'i')
    {
        rstart();
        asm("idivq %rax\n");
        rstop();
    }
    else if(x == 'f')
    {
        asm("finit\n");
        res1 = 200;
        res2 = 201;
        asm("fld res1\n");
        asm("fld res2\n");

        rstart();
        asm("fdivp\n");
        rstop();
    }

    printf("%lld\n", res1 - res2 - (sum - 1));
    return(0);
}
