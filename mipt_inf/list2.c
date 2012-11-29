//#define DEBUG 1
#undef DEBUG

#ifdef DEBUG
#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node
{
    struct Node * prev;
    struct Node * next;
    Data data;
};

void list_init(struct Node * list); //initialize fake head
void list_insert(struct Node * list, struct Node * t); //insert t after list
void list_insert_before(struct Node * list, struct Node * t); //insert t before list
struct Node * list_push_front(struct Node * list, Data d);
struct Node * list_push_back(struct Node * list, Data d);
Data list_pop_front(struct Node * list);
Data list_pop_back(struct Node * list);
Data list_delete(struct Node * list);
int list_is_empty(struct Node * list);
int list_clear(struct Node * list);
void list_foreach(struct Node * list, void (*func)(Data d, void * param), void * param);
Data list_sum(struct Node * list);
void list_sum_one(Data d, void * ptr);
void list_print_one(Data d, void * ptr);
void list_print(struct Node * list);

#endif

void list_init(struct Node * list)
{
    if(list != NULL)
    {
        list->prev = list;
        list->next = list;
    }
}

void list_insert(struct Node * list, struct Node * t)
{
    if(t != NULL && list != NULL)
    {
        //prev <-> list <-> next
        //prev <-> list <-> t <-> next

        t->next = list->next;
        t->prev = list;
        if(list->next != NULL) list->next->prev = t;
        list->next = t;
    }
}

void list_insert_before(struct Node * list, struct Node * t)
{
    if(t != NULL && list != NULL)
    {
        //prev <-> list <-> next
        //prev <-> t <-> list <-> next

        t->next = list;
        t->prev = list->prev;
        if(list->prev != NULL) list->prev->next = t;
        list->prev = t;
    }
}

void list_remove(struct Node * t)
{
    if(t != NULL)
    {
        //prev <-> t <-> next
        //prev <-> next

        if(t->prev != NULL)
            t->prev->next = t->next;
        if(t->next != NULL)
            t->next->prev = t->prev;

        //free(t);
    }
}

struct Node * list_push_front(struct Node * list, Data d)
{
    struct Node * t = malloc(sizeof(struct Node));
    t->data = d;
    list_insert(list, t);
    return(t);
}

struct Node * list_push_back(struct Node * list, Data d)
{
    struct Node * t = malloc(sizeof(struct Node));
    t->data = d;
    list_insert_before(list, t);
    return(t);
}

Data list_pop_back(struct Node * list)
{
    if(!list_is_empty(list))
        return(list_delete(list->prev));
    return(0);
}

Data list_pop_front(struct Node * list)
{
    if(!list_is_empty(list))
        return(list_delete(list->next));
    return(0);
}

Data list_delete(struct Node * t)
{
    if(t != NULL)
    {
        Data d = t->data;
        list_remove(t);
        free(t);
        return(d);
    }
    return(0);
}

int list_is_empty(struct Node * list)
{
    if(list == NULL) return(1);
    return(list == list->next);
}

int list_clear(struct Node * list)
{
    int c;
    for(c = 0; !list_is_empty(list); c++, list_pop_front(list));
    return(c);
}

void list_foreach(struct Node * list, void (*func)(Data d, void * param), void * param)
{
    if(!list_is_empty(list))
    {
        struct Node * ptr;
        for(ptr = list->next; ptr != list; ptr = ptr->next)
            func(ptr->data, param);
    }
}

void list_print_one(Data d, void * ptr)
{
    fprintf(ptr, "%d ", d);
}

void list_sum_one(Data d, void * ptr)
{
    *((Data *) ptr) += d;
}

void list_print(struct Node * list)
{
    list_foreach(list, list_print_one, stdout);
    fprintf(stdout, "\n");
}

Data list_sum(struct Node * list)
{
    Data res = 0;
    list_foreach(list, list_sum_one, &res);
    return(res);
}

#ifdef DEBUG
int main()
{
    int i;
    struct Node x[10];
	struct Node * a = malloc(sizeof(struct Node));
	struct Node * b = malloc(sizeof(struct Node));

	list_init(a);
	list_init(b);
	
	for(i=0; i<10; i++) {
		x[i].data = i;
		list_insert(a, &x[i]);
	}
	list_print(a);
	
	list_remove(&x[5]);
	list_print(a);
	list_remove(&x[0]);
	list_print(a);
	list_remove(&x[9]);
	list_print(a);
	
	list_insert_before(a, &x[0]);
	list_print(a);
	list_insert(a, &x[9]);
	list_print(a);
	list_insert(&x[6], &x[5]);
	list_print(a);
	
	while(!list_is_empty(a))
		list_remove(a->next);

	for(i=0; i<10; i++)
		list_push_back(a, i);
	list_print(a);
	
	for(i=0; i<10; i++)
		list_push_front(b, list_pop_back(a));
	list_print(b);
	
	for(i=0; i<10; i++) {
		list_push_front(a, i);
		list_pop_front(b);
	}
	list_print(a);

	for(i=0; i<10; i++)
		list_push_back(b, list_pop_front(a));
	list_print(b);
	
	while(list_delete(b->next));

    free(a);
    free(b);
    b = a = NULL;
    return 0;
}
#endif
