//#define DEBUG
#undef DEBUG

#ifdef DEBUG

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

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

#endif

void stack_print(struct Node * s)
{
    if(!s)
    {
        printf("Empty stack\n");
        return;
    }

    struct Node * now;
    for(now = s; now != NULL; now = now->next)
        printf("%d ", now->data);

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

#ifdef DEBUG

#define stack_info() printf("stack size is %d\n", stack_size(sp))
#define stack_pget() printf("top element is %d\n", stack_get(sp))

int main()
{
    struct Node * sp = NULL;

    stack_info();
    stack_pget();

    long long int i;

    sp = stack_push(sp, 5);
    stack_print(sp);
    stack_info();
    stack_pget();
    sp = stack_push(sp, 19);
    stack_print(sp);
    stack_info();
    stack_pget();
    sp = stack_push(sp, -2);

    Data * a = malloc(sizeof(Data));

    sp = stack_pop(sp, a);
    stack_print(sp);
    stack_info();
    stack_pget();

    stack_destroy(sp);

    return 0;
}
#endif
