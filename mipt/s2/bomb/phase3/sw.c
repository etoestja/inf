#include <stdio.h>

void explode_bomb()
{
    printf("booom");
}

void phase_3(char* str)
{
    int x, y;
    char c;
    sscanf(str, "%d %c %d", &x, &c, &y);

    switch(x)
    {
        case 0: if(c == 'd' && y == 272) return;
        case 1: if(c == 'g' && y == 675) return;
        case 2: if(c == 'o' && y == 869) return;
        case 3: if(c == 'g' && y == 833) return;
        case 4: if(c == 'i' && y == 564) return;
        case 5: if(c == 't' && y == 921) return;
        case 6: if(c == 'v' && y == 153) return;
        case 7: if(c == 'f' && y == 521) return;
    }

    explode_bomb();
}

int main()
{
}
