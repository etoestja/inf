#include <stdio.h>

#define BN 4
#define NMAX 200000
const char B1[BN] = {'(', '[', '{', '<'};
const char B2[BN] = {')', ']', '}', '>'};

char stack[NMAX];
int stack_position = -1;

void stack_push(char c)
{
    stack[++stack_position] = c;
    //printf("push %c\n", c);
}

int stack_empty()
{
    return(stack_position <= -1);
}

char stack_front()
{
    if(!stack_empty())
    {
        //printf("front c=%c\n", stack[stack_position]);
        return(stack[stack_position]);
    }
    else
    {
        //printf("front empty\n");
        return 0;
    }
}

void stack_pop()
{
    //printf("pop pos=%d\n", stack_position);
    if(!stack_empty()) stack_position--;
}

int main()
{
    char c, c1;
    unsigned i;
    short int used;

    while(scanf("%c", &c) == 1)
    {
        used = 0;
        for(i = 0; i < BN; i++)
        {
            if(c == B1[i])
            {
                used = 1;
                stack_push(c);
            }
            else if(c == B2[i])
            {
                used = 1;
                c1 = stack_front();
                if(c1 == B1[i]) stack_pop();
                else
                {
                    stack_push('!');
                    used = 0;
                    break;
                }
            }
        }

        if(!used) break;
    }

    printf("%s", stack_empty() ? "YES" : "NO");

    return 0;
}
