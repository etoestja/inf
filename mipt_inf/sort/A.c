//#define MDEBUG 1
#undef MDEBUG
    
#ifdef MDEBUG
    #include <stdio.h>
#endif

int cmp_int(const void * p1, const void * p2)
{
    if(*((int*) p1) == *((int*) p2)) return 0;
    return(*((int*) p1) > *((int*) p2) ? 1 : -1);
}

#ifdef MDEBUG
    int main()
    {
        int x1, x2;
        scanf("%d", &x1);
        scanf("%d", &x2);

        printf("%d\n", cmp_int(&x1, &x2));

        return 0;
    }
#endif
