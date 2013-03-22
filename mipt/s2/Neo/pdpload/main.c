//#define DEBUG
#undef DEBUG

#ifdef DEBUG
#include <stdio.h>
#endif

typedef char byte;
typedef short unsigned int word;
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

void load_file()
{
    adr cadr;
    unsigned int i, n;
    unsigned int x, m;
    short int y;

    while(scanf("%x", &cadr) > 0)
    {
//        printf("addr= %x\n", cadr);
        scanf("%x", &n);
//        printf("n= %d\n", n);
        for(i = 0; i < n; i++)
        {
            scanf("%x", &x);
//            scanf("%c", &m);
//            y = x;
//            y &= 0b11111111;
//            printf("READ: %x\n", y);
            mem[cadr + i] = x;
        }
    }
}

void mem_dump(adr start, word n)
{
    adr c;
    wordchar x;
    for(c = start; c < start + n; c += 2)
    {
        x.y[0] = mem[c];
        x.y[1] = mem[c + 1];
        printf("%06o : %06o\n", c, x.x, x.x);
    }
}

#ifdef DEBUG
int main()
{
/*    word x = 11;
    word y;
    w_write((1 << 6) - 1, x);
    printf("%d", w_read((1 << 6) - 1));

    b_write(1231, 'h');
    printf("%c\n", b_read(1231));

    return(0);*/
    int i;
    for(i = 0; i < S; i++) mem[i] = 0;

    load_file();
    mem_dump(0x40, 12);
    mem_dump(0x200, 38);

    return(0);
}
#endif
