#ifndef RANDOMTREE_H
#define RANDOMTREE_H

#include "tree.h"

class randomTree : public Tree
{
private:
    static const int maxChildren = 10;
public:
    randomTree(int nodes);
};

#endif // RANDOMTREE_H
