#ifndef MYVECTOR_H
#define MYVECTOR_H

#define MYVECTOR_TYPE int

typedef struct
{
    MYVECTOR_TYPE* ptr;
    unsigned int N;
} myvector;

typedef struct
{
    myvector mv;
    unsigned int p;
} myvectorIterator;

enum myvectorIteratorCmpResult {MICR_ERROR, MICR_LESS, MICR_GREATER, MICR_EQUAL};

int myvectorCreate(myvector* a, unsigned int N);
int myvectorCopyData(myvector* src, myvector* dest);
int myvectorCheckNULL(myvector *a);

int myvectorIteratorSet(myvectorIterator* it, myvector *mv, unsigned int N);
int myvectorIteratorCmp(myvectorIterator* it1, myvectorIterator *it2);
int myvectorIteratorGet(myvectorIterator* it, MYVECTOR_TYPE* v);
int myvectorIteratorAdd(myvectorIterator* it, int offset);
int myvectorIteratorPP(myvectorIterator* it);
int myvectorIteratorMM(myvectorIterator* it);

int myvectorIteratorSetBegin(myvectorIterator* it, myvector *mv);
int myvectorIteratorSetEnd(myvectorIterator* it, myvector *mv);

int myvectorResize(myvector* a, unsigned int Nnew);

int myvectorDestroy(myvector* a);

int myvectorAssign(myvector* a, unsigned int key, MYVECTOR_TYPE value);
int myvectorAt(myvector* a, unsigned int key, int **value);

#endif
