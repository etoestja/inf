#include <stdio.h>
#include <string.h>

#define NMAX (2000 + 1)

char str[NMAX];
int N;

int main()
{
    scanf("%s", str);
    N = strlen(str);

    if(N % 2)
    {
        printf("NO\n");
        return 0;
    }

    int counter = 0, i, fix = 0;

    for(i = 0; i < N; i++)
    {
        if(str[i] == '(') counter++;
        if(str[i] == ')')
        {
            counter--;
            if(counter < 0)
            {
                counter += 2;
                fix++;
            }
        }
    }

    if(counter % 2)
        printf("NO\n");
    else
        printf("%d\n", fix + counter / 2);

    return(0);
}
