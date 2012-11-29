#include <stdio.h>
#include <stdlib.h>

struct node
{
    int v;
    struct node *l;
    struct node *r;
};

struct node *root;

void addVertex(struct node **ptr, int value)
{
    if(*ptr == NULL)
    {
        *ptr = malloc(sizeof(struct node));
        (*ptr)->v = value;
        (*ptr)->l = NULL;
        (*ptr)->r = NULL;
    }
    else if(value > (*ptr)->v)
        addVertex(&((*ptr)->r), value);
    else if(value < (*ptr)->v)
        addVertex(&((*ptr)->l), value);
}

void destroyTree(struct node **ptr)
{
    if(*ptr != NULL)
    {
        destroyTree(&((*ptr)->l));
        destroyTree(&((*ptr)->r));
        free(*ptr);
        *ptr = NULL;
    }
}

#define NMAX 10005

struct node *q[NMAX];
int qPtr1, qPtr2;
int qN;

int getQPos(int ptr)
{
    return((ptr + NMAX) % NMAX);
}

void putQ(struct node *c)
{
    if(qPtr1 == -1 && qPtr2 == -1)
    {
        qPtr1 = 0;
        qPtr2 = 0;
        qN = 1;
        q[0] = c;
    }
    else
    {
        qN++;
        qPtr2 = getQPos(qPtr2 + 1);
        q[qPtr2] = c;
    }
}

int main()
{
    int c, i;
    while(scanf("%d", &c) > 0 && c != 0)
        addVertex(&root, c);

    qPtr1 = qPtr2 = 0;
    qN = 1;
    if(root != NULL)
        q[0] = root;

    struct node *current, *other;

    while(qN)
    {
        current = q[qPtr1];
        if(qN == 1)
        {
            qPtr1 = -1;
            qPtr2 = -1;
        }
        else
            qPtr1 = getQPos(qPtr1 + 1);

        qN--;

        printf("%d ", current->v);

        if(current->l != NULL)
            putQ(current->l);
        if(current->r != NULL)
            putQ(current->r);
    }

    destroyTree(&root);

    printf("\n");

    return 0;
}
