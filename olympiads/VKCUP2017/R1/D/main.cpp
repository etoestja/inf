#include <stdio.h>

#define NMAX 100

char s[NMAX];

int L;

#define swap(i, j) {char c; c = s[i]; s[i] = s[j]; s[j] = c; res += 1;}

int res;

int is_OK()
{
    for(int i = 0; i < L - 1; i++)
    {
        if(s[i] == 'V' && s[i + 1] == 'K')
        {
            printf("Fail pos %d: %s\n", i, s + i);
            return(0);
        }
    }
    return(1);
}

int main()
{
    scanf("%d", &L);
    scanf("%s", s);

    printf("%s\n", s);

    while(!is_OK())
    {
    for(int i = L - 2; i >= 0; i++)
    {
        if(s[i] == 'V' && s[i + 1] == 'K')
        {
            printf("%s Found idx = %d\n", s, i);
            if(i > 0 && s[i - 1] != 'V' && s[i - 1] != 'K')
            {
               swap(i, i - 1);
            }
            else
            {
                swap(i, i + 1);
            }
        }
    }
    }

    printf("%s\n", s);
    is_OK();

    printf("%d\n", res);
}
