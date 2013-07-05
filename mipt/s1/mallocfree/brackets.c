#include <stdio.h>
#include <stdlib.h>

typedef char Data;

struct Node
{
    struct Node * next;
    Data data;
};

struct Node * top = NULL;

void stack_print(struct Node * s);
struct Node * stack_push(struct Node * s, Data x);
struct Node * stack_destroy(struct Node * s);
Data stack_get(struct Node * s);
int stack_size(struct Node * s);
struct Node * stack_pop(struct Node * s, Data * res);
int stack_empty(struct Node * s);

int stack_empty(struct Node * s)
{
    return(s == NULL);
}

void stack_print(struct Node * s)
{
    if(!s)
    {
        printf("Empty stack\n");
        return;
    }

    struct Node * now;
    for(now = s; now != NULL; now = now->next)
        printf("%c ", now->data);

    printf("\n");
}

struct Node * stack_push(struct Node * s, Data x)
{
    struct Node * nitem = malloc(sizeof(struct Node));
    nitem->next = s;
    nitem->data = x;
    return(nitem);
}

struct Node * stack_destroy(struct Node * s)
{
    if(s != NULL)
    {
        if(s->next != NULL)
            stack_destroy(s->next);
        free(s);
    }
    return(NULL);
}

Data stack_get(struct Node * s)
{
    Data x;

    if(s)
        x = s->data;
    else x = 0;

    return(x);
}

int stack_size(struct Node * s)
{
    int counter = 0;
    struct Node * now;
    for(now = s; now != NULL; now = now->next) counter++;

    return(counter);
}

struct Node * stack_pop(struct Node * s, Data * res)
{
    *res = stack_get(s);
    if(s == NULL)
        return NULL;
    else return s->next;
}

#define stack_info() printf("stack size is %d\n", stack_size(sp))
#define stack_pget() printf("top element is %c\n", stack_get(sp))

#define BN 4
const char B1[BN] = {'(', '[', '{', '<'};
const char B2[BN] = {')', ']', '}', '>'};

int main()
{
    top = NULL;

    char * tc = malloc(sizeof(char));

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
                top = stack_push(top, c);
            }
            else if(c == B2[i])
            {
                used = 1;
                c1 = stack_get(top);
                if(c1 == B1[i]) top = stack_pop(top, tc);
                else
                {
                    top = stack_push(top, '!');
                    used = 0;
                    break;
                }
            }
        }

        if(!used) break;
    }

    printf("%s", stack_empty(top) ? "YES" : "NO");

    top = stack_destroy(top);

    return 0;
}
