#define DEBUG
//#undef DEBUG

#ifdef DEBUG

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node
{
    struct Node * next;
    struct Node * prev;
    Data data;
};


#endif


void list_init(struct Node * list);	 //инициализация пустого списка.
void list_insert(struct Node * list, struct Node * t); //вставляет элемент t после элемента list
void list_insert_before(struct Node * list, struct Node * t); //вставляет элемент t перед элементом list
void list_remove(struct Node * t);	//удаляет элемент t из списка
struct Node * list_push_front(struct Node * list, Data d); //выделяет память под новый элемент, содержащий данные d, и вставляет его в голову (хвост) списка.
struct Node * list_push_back(struct Node * list, Data d);
Data list_pop_front(struct Node * list); //удаляет голову (хвост, указанный элемент t) списка, возвращая данные. Память освободить!
Data list_pop_back(struct Node * list);
Data list_delete(struct Node * t);
void list_print (struct Node * list); //распечатывает через пробел числа, лежащие в списке. С самого первого до последнего. В конце переводит строку. Полезна для отладки прочих функций. Реализовывать через list_foreach.
Data list_sum (struct Node * list); //Суммирует данные в элементах списка. Реализовывать через list_foreach.
int list_is_empty(struct Node * list); //проверяет пустой это список или нет
int list_clear(struct Node * list); //опустошает список, освобождая память. После этого можно опять добавлять элементы в список.
void list_foreach(struct Node * list, void (*func)(Data d, void * param), void * param); //Используется для вызова функции func для всех элементов списка, например:
struct Node * list_get_front(struct Node * list);
struct Node * list_get_back(struct Node * list);
void list_print_one(Data d, void* a);

void list_print_one(Data d, void* a)
{
    fprintf(a, "%d ", d);
}

struct Node * list_get_front(struct Node * list)
{
    if(list == NULL)
        return(NULL);
    else
    {
        struct Node * current;
        for(current = list; current->prev != NULL; current = current->prev);
        return(current);
    }
}

struct Node * list_get_back(struct Node * list)
{
    if(list == NULL)
        return(NULL);
    else
    {
        struct Node * current;
        for(current = list; current->next != NULL; current = current->next);
        return(current);
    }
}

void list_init(struct Node * list)
{
    list = malloc(sizeof(struct Node));
    list->next = NULL;
    list->prev = NULL;
    list->data = 0;
}

void list_insert(struct Node * list, struct Node * t)
{
    if(list != NULL)
        t->next = list->next;
    else t->next = NULL;

    t->prev = list;

    if(list != NULL)
    {
        if(list->next != NULL)
            list->next->prev = t;
        list->next = t;
    }
}

void list_insert_before(struct Node * list, struct Node * t)
{
    if(list != NULL)
    {
        t->next = list;
        t->prev = list->prev;

        if(list->prev != NULL)
            list->prev->next = t;
        list->prev = t;
    }
    else
    {
        t->next = NULL;
        t->prev = NULL;
    }
}

void list_remove(struct Node * t)
{
    if(t != NULL)
    {
        if(t->next != NULL)
            t->next->prev = t->prev;
        if(t->prev != NULL)
            t->prev->next = t->next;
        free(t);
    }
}

struct Node * list_push_front(struct Node * list, Data d)
{
    struct Node * front = list_get_front(list), * t = malloc(sizeof(struct Node));
    t->next = NULL;
    t->prev = NULL;
    t->data = d;
    list_insert_before(front, t);
    return(t);
}

struct Node * list_push_back(struct Node * list, Data d)
{
    struct Node * back = list_get_back(list), * t = malloc(sizeof(struct Node));
    t->next = NULL;
    t->prev = NULL;
    t->data = d;
    list_insert(back, t);
    return(t);
}

Data list_pop_front(struct Node * list)
{
    return(list_delete(list_get_front(list)));
}

Data list_pop_back(struct Node * list)
{
    return(list_delete(list_get_back(list)));
}

Data list_delete(struct Node * t)
{
    Data r;
    if(t)
    {
        r = t->data;
        if(t->next)
            t->next->prev = t->prev;
        if(t->prev)
            t->prev->next = t->next;
        free(t);
    }
    else r = 0;
    return(r);
}

int list_is_empty(struct Node * list)
{
    return(list == NULL);
}

void list_foreach(struct Node * list, void (*func)(Data d, void * param), void * param)
{
    if(list)
    {
        struct Node * front;
        for(front = list_get_front(list); front != NULL; front = front->next)
            func(front->data, param);
    }
}

void list_print(struct Node * list)
{
    list_foreach(list, list_print_one, stdout);
    printf("\n");
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
    return 0;
}
#endif
