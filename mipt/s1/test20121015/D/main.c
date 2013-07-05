#include <stdio.h>

int main(void)
{
    int a, b, c, N;

    scanf("%d", &N);

    for(a = 1; a < N; a++)
        for(b = a + 1; a + b < N; b++)
        {
            c = N - a - b;
            if(a * a + b * b == c * c)
            {
                fprintf(stderr, "a=%d, b=%d, c=%d, a^2=%d, b^2=%d, a^2+b^2=%d, c^2=%d\n", a, b, c, a * a, b * b, a * a + b * b, c * c);
                printf("%d\n", a * b * c);
                return 0;
            }
        }

    return 0;
}

