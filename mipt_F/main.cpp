#include <stdio.h>

int main()
{
    char c;
    bool first = true;

    while((scanf("%c", &c)) && ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F')))
    {
        if(first)
        {
            if(c != '0') first = false;

            if(c == '1') printf("1");
            else if(c == '2') printf("10");
            else if(c == '3') printf("11");
            else if(c == '4') printf("100");
            else if(c == '5') printf("101");
            else if(c == '6') printf("110");
            else if(c == '7') printf("111");
            else if(c == '8') printf("1000");
            else if(c == '9') printf("1001");
            else if(c == 'A') printf("1010");
            else if(c == 'B') printf("1011");
            else if(c == 'C') printf("1100");
            else if(c == 'D') printf("1101");
            else if(c == 'E') printf("1110");
            else if(c == 'F') printf("1111");
        }
        else
        {
            if(c == '0') printf("0000");
            else if(c == '1') printf("0001");
            else if(c == '2') printf("0010");
            else if(c == '3') printf("0011");
            else if(c == '4') printf("0100");
            else if(c == '5') printf("0101");
            else if(c == '6') printf("0110");
            else if(c == '7') printf("0111");
            else if(c == '8') printf("1000");
            else if(c == '9') printf("1001");
            else if(c == 'A') printf("1010");
            else if(c == 'B') printf("1011");
            else if(c == 'C') printf("1100");
            else if(c == 'D') printf("1101");
            else if(c == 'E') printf("1110");
            else if(c == 'F') printf("1111");
        }
    }

    if(first) printf("0");

    printf("\n");

    return 0;
}
