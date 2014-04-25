#ifndef TREECOUNTER_H
#define TREECOUNTER_H

#include "tree.h"

class treeThreadCounter
{
public:
    treeThreadCounter();
    static unsigned count(Tree* t, int threads, int currentChild = 0);
    static void countStupid(Tree *, int* result);
};

#endif // TREECOUNTER_H
