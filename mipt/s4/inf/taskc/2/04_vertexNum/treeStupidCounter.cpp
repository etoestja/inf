#include "treeStupidCounter.h"
#include <vector>

using std::vector;

treeStupidCounter::treeStupidCounter()
{
}

unsigned treeStupidCounter::count(Tree *root)
{
    unsigned s = 1;
    vector<Tree*>::iterator it;
    for(it = root->children.begin(); it != root->children.end(); it++)
        s += treeStupidCounter::count(*it);
    return(s);
}
