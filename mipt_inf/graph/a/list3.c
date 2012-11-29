#include <stdio.h>
#include <stdlib.h>

struct node
{
    int v;
    struct node *prev;
    struct node *next;
};

struct node *getLast(struct node *c)
{
    if(c == NULL) return(NULL);
    else if(c->next == NULL) return(c);
    else return(getLast(c->next));
}

struct node *getFirst(struct node *c)
{
    if(c == NULL) return(NULL);
    else if(c->prev == NULL) return(c);
    else return(getFirst(c->prev));
}

struct node* create(struct node *prev, struct node *next, int v)
{
    struct node *res = malloc(sizeof(struct node));
    res->prev = prev;
    res->next = next;
    res->v = v;
    return(res);
}

void insertLast(struct node **c, int v)
{
    if(*c == NULL)
        *c = create(NULL, NULL, v);
    else
    {
        struct node *a = getLast(*c);
        a->next = create(a, NULL, v);
    }
}

int getFirstValue(struct node *c)
{
    if(c != NULL)
        return(getFirst(c)->v);
    return(-1);
}

int getLastValue(struct node *c)
{
    if(c != NULL)
        return(getLast(c)->v);
    return(-1);
}

void popFirst(struct node **c)
{
    struct node *ptr;
    if(*c != NULL)
    {
        if((*c)->prev == NULL)
        {
            ptr = (*c)->next;
            if(ptr != NULL) ptr->prev = NULL;
            free(*c);
            *c = ptr;
        }
        else
        {
            ptr = getFirst(*c);
            struct node *ptr1;
            ptr1 = ptr->next;
            if(ptr1 != NULL)
                ptr1->prev = NULL;

            free(ptr);
        }
    }
}

struct node *l1, *l2;

#define N 5
#define MAXN 1000000

int main()
{
    int i, t;
    
    for(i = 0; i < N; i++)
    {
        scanf("%d", &t);
        insertLast(&l1, t);
    }

    for(i = 0; i < N; i++)
    {
        scanf("%d", &t);
        insertLast(&l2, t);
    }

    int c1, c2;

    for(i = 0; i <= MAXN; i++)
    {
        if(l1 == NULL)
        {
            printf("second %d\n", i);
            while(l2 != NULL) popFirst(&l2);
            return 0;
        }
        if(l2 == NULL)
        {
            printf("first %d\n", i);
            while(l1 != NULL) popFirst(&l1);
            return 0;
        }

        c1 = getFirstValue(l1);
        c2 = getFirstValue(l2);
        popFirst(&l1);
        popFirst(&l2);

        if((c1 >= 1 && c1 <= 9 && c2 >= 1 && c2 <= 9 && c1 > c2) || (c1 == 0 && c2 != 0))
        {
            insertLast(&l1, c1);
            insertLast(&l1, c2);
        }
        else if((c1 >= 1 && c1 <= 9 && c2 >= 1 && c2 <= 9 && c1 < c2) || (c2 == 0 && c1 != 0))
        {
            insertLast(&l2, c1);
            insertLast(&l2, c2);
        }
    }

    printf("botva\n");

    return 0;
}
