#include <stdio.h>

void explode_bomb()
{
    printf("expl");
}

void phase6()
{
    int arr[6], i;
    for(i = 0; i < 6; i++)
        if(arr[i] > 6)
            explode_bomb();
}

int main()
{
}
