#include <stdio.h>

int leap(int year);

void test(int year)
{
    if(leap(year))
        printf("%d\n", year);
}

int main()
{
//    int i = 0;

/*    test(0);
    for(i = 1; i != 0; i++)
        test(i);*/


    printf("%d\n", leap(2057));
    return(0);
}
