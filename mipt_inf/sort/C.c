//#define MDEBUG 1
#undef MDEBUG
    
#ifdef MDEBUG
    #include <stdio.h>

    struct Point
    {
        int x;
        int y;
    };
#endif

int cmp_Point(const void *p1, const void* p2)
{
    int r1 = ((struct Point*) p1)->x * ((struct Point*) p1)->x + ((struct Point*) p1)->y * ((struct Point*) p1)->y;
    int r2 = ((struct Point*) p2)->x * ((struct Point*) p2)->x + ((struct Point*) p2)->y * ((struct Point*) p2)->y;
    if(r1 == r2) return 0;
    return(r1 > r2 ? 1 : -1);
}

#ifdef MDEBUG
    int main()
    {
        int x1, y1, x2, y2;
        scanf("%d", &x1);
        scanf("%d", &y1);
        scanf("%d", &x2);
        scanf("%d", &y2);


        struct Point p1, p2;
        p1.x = x1;
        p1.y = y1;

        p2.x = x2;
        p2.y = y2;

        printf("%d\n", cmp_Point(&p1, &p2));

        return 0;
    }
#endif
