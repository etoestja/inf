#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node
{
    struct Node * next;
    Data data;
};

struct Node * top = NULL;

struct Node * stack_push(struct Node * s, Data x);
struct Node * stack_destroy(struct Node * s);
Data stack_get(struct Node * s);
int stack_size(struct Node * s);
struct Node * stack_pop(struct Node * s, Data * res);

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

int char_isop(char c)
{
    return(c == '+' || c == '*' || c == '-');
}

int char_getvalue(int a, int b, char op)
{
    if(op == '+')
        return(a + b);
    else if(op == '-')
        return(a - b);
    else if(op == '*')
        return(a * b);
    else return 0;
}

int main()
{
    top = 0;

    Data a, b, current;

    char c;
    while(scanf("%c", &c) > 0 && c != '=')
    {
        if(c >= '0' && c <= '9')
        {
            top = stack_push(top, c - '0');
        }
        else if(char_isop(c))
        {
            top = stack_pop(top, &b);
            top = stack_pop(top, &a);

            current = char_getvalue(a, b, c);
            top = stack_push(top, current);
        }
    }

    current = stack_get(top);

    printf("%d\n", current);

    return 0;
}
