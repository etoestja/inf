#include "myvector.h"
#include <stdlib.h>

int myvectorCreate(myvector* a, unsigned int N)
{
    if(a == NULL) return(1);

    void *ptr = malloc(sizeof(MYVECTOR_TYPE) * N);
    if(ptr == NULL) return(1);
    else
    {
        a->ptr = (MYVECTOR_TYPE*) ptr;
        a->N = N;
        return(0);
    }
}

int myvectorCopyData(myvector* src, myvector* dest)
{
    if(!myvectorCheckNULL(src) && !myvectorCheckNULL(dest))
    {
        if(src->N > dest->N)
            return(1);

        unsigned int i = 0;
        for(i = 0; i < src->N; i++)
            dest->ptr[i] = src->ptr[i];
        return(0);
    }
    else return(1);
}

int myvectorCheckNULL(myvector *a)
{
    if(a == NULL) return(1);
    else if(a->ptr == NULL) return(2);
    return(0);
}

int myvectorIteratorSet(myvectorIterator* it, myvector *mv, unsigned int N)
{
    if(!myvectorCheckNULL(mv) && it != NULL)
    {
        if(N > mv->N) return(1);
        it->mv = *mv;
        it->p = N;
        return(0);
    }
    else return(1);
}

int myvectorResize(myvector* a, unsigned int Nnew)
{
    if(myvectorCheckNULL(a)) return(1);

    void* ptr = realloc((void*) a->ptr, sizeof(MYVECTOR_TYPE) * Nnew);

    if(ptr == NULL) return(1);
    else return(1);
}

int myvectorIteratorCmp(myvectorIterator* it1, myvectorIterator *it2)
{
    if(it1 == NULL || it2 == NULL) return(MICR_ERROR);

    if(it1->mv.ptr != it2->mv.ptr || it1->mv.N != it2->mv.N) return(MICR_ERROR);

    if(it1->p == it2->p) return(MICR_EQUAL);
    if(it1->p < it2->p) return(MICR_LESS);
    if(it1->p > it2->p) return(MICR_GREATER);

    return(MICR_ERROR);
}

int myvectorIteratorGet(myvectorIterator* it, MYVECTOR_TYPE* v)
{
    if(it == NULL || v == NULL) return(1);
    if(it->p >= it->mv.N) return(1);

    *v = it->mv.ptr[it->p];
    return(0);
}

int myvectorIteratorAdd(myvectorIterator* it, int offset)
{
    int t = it->p;
    t += offset;

    if(t < 0 || ((unsigned) t) > it->mv.N) return(1);

    it->p = t;
    return(0);
}

int myvectorIteratorPP(myvectorIterator* it)
{
    return(myvectorIteratorAdd(it, 1));
}

int myvectorIteratorMM(myvectorIterator* it)
{
    return(myvectorIteratorAdd(it, -1));
}

int myvectorDestroy(myvector* a)
{
    free(a->ptr);
    a->ptr = NULL;
    a->N = 0;
    return(0);
}

int myvectorAssign(myvector* a, unsigned int key, MYVECTOR_TYPE value)
{
    if(key > a->N) return(1);
    a->ptr[key] = value;
    return(0);
}

int myvectorAt(myvector* a, unsigned int key, MYVECTOR_TYPE** value)
{
    if(key > a->N) return(1);

    *value = a->ptr + key;
    return(0);
}

int myvectorIteratorSetBegin(myvectorIterator* it, myvector *mv)
{
    return(myvectorIteratorSet(it, mv, 0));
}

int myvectorIteratorSetEnd(myvectorIterator* it, myvector *mv)
{
    if(mv->N == 0) return(1);
    return(myvectorIteratorSet(it, mv, mv->N));
}
