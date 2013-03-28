#include <stdio.h>

int main()
{
    char x;
    scanf("%c", &x);

    if(x == 'e') printf("Big-endian\n");
    else if(x == 'a') printf("RISC\n");
    else if(x == 'p') printf("pc\n");
    else if(x == 'i') printf("bne\n");
}
