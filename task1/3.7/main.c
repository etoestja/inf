#include <stdio.h>
#include <stdlib.h>

struct node;

typedef struct node* link;

struct node
{
    int n;
    link next;
};

link first;
int N, M, left;

#define NPrint 3

int main()
{
    int i;

    scanf("%d%d", &N, &M);

    link prev_last, last;

    for(i = 1; i <= N; i++)
    {
        last = malloc(sizeof(struct node));
        last->n = i;
        if(i == 1) first = last;

        last->next = first;
        prev_last->next = last;
        prev_last = last;
    }

    link current = first;
    int counter;

    for(counter = 1, left = N; left;) 
    {
        if(((counter + 1) % left) == (M % left))
        {
            if(left <= NPrint) printf("%d ", current->next->n); 
            left--;

            current->next = current->next->next;
            counter = 1;
        }
        else counter++;

        current = current->next;
    }
}
