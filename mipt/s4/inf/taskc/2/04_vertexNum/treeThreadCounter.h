#ifndef TREECOUNTER_H
#define TREECOUNTER_H

#include "tree.h"

class treeThreadCounter
{
public:
    treeThreadCounter();
    static unsigned count(Tree* t, int threads, unsigned currentChild = 0);
    static void countStupid(Tree *, unsigned* result);
};

#endif // TREECOUNTER_H
