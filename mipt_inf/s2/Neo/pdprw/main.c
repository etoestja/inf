//#define DEBUG
#undef DEBUG

#ifdef DEBUG
#include <stdio.h>
#endif

typedef char byte;
typedef short int word;
typedef short int adr;

typedef union
{
    word x;
    char y[2];
} wordchar;

#define S (1 << 16)

byte mem[S];

byte b_read(adr a)
{
    return(mem[a]);
}

void b_write(adr a, byte val)
{
    mem[a] = val;
}

word w_read(adr a)
{
    wordchar wc;
    wc.y[0] = mem[a];
    wc.y[1] = mem[a + 1];
    return(wc.x);
}

void w_write(adr a, word val)
{
    wordchar wc;
    wc.x = val;
    mem[a] = wc.y[0];
    mem[a + 1] = wc.y[1];
}

#ifdef DEBUG
int main()
{
    word x = 11;
    word y;
    w_write((1 << 6) - 1, x);
    printf("%d", w_read((1 << 6) - 1));

    b_write(1231, 'h');
    printf("%c\n", b_read(1231));

    return(0);
}
#endif
