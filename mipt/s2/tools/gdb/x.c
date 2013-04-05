#include <stdio.h>

union charint
{
    int y;
    char x[4];
};

int main()
{
    union charint ci;
/*    ci.x[0] = 0x2e;
    ci.x[1] = 0xca;
    ci.x[2] = 0x07;
    ci.x[3] = 0x00;*/

    
    ci.x[0] = 0x4d;
    ci.x[1] = 0x00;
    ci.x[2] = 0x00;
    ci.x[3] = 0x41;

    printf("%d\n", ci.y);
    return(0);
}
