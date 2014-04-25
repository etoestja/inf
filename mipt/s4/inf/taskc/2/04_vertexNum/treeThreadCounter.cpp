#include "treeThreadCounter.h"
#include "treeStupidCounter.h"
#include <thread>

using std::thread;

treeThreadCounter::treeThreadCounter()
{
}

unsigned treeThreadCounter::count(Tree *t, int threads)
{
    if(t->children.size() == 0)
        return(1);
    else if(t->children.size() == 1)
        return(1 + treeThreadCounter::count(t->children[0], threads));
    vector<unsigned> result;
}

unsigned treeThreadCounter::countStupid(Tree *r, int *result)
{
    *result = treeStupidCounter::count(r);
}
