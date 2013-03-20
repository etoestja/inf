#include <stdio.h>

int read_six_numbers(int* a)
{
    scanf(stdin, "%d %d %d %d %d %d", a, a + 1, a + 2, a + 3, a + 4, a + 5);
}

int main()
{
    int arr[6];
    read_six_numbers(arr);
    return(0);
}
