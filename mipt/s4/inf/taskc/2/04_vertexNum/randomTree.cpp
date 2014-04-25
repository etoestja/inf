#include "randomTree.h"
#include <cstdlib>
#include <algorithm>

using std::random_shuffle;

randomTree::randomTree(int nodes)
{
    int nodesleft = nodes - 1;
    node = rand();

    if(nodesleft == 0) return;

    int childrenN = (rand() % nodesleft) + 1;

    for(int i = 0; i < childrenN; i++)
    {
        //nodesleft - here >= childrenN - i - 1
        int here = ((rand() % (nodesleft + i + 1 - childrenN)) + 1);
        randomTree *x = new randomTree(here);
        children.push_back(x);
        nodesleft -= here;
    }

    random_shuffle(children.begin(), children.end());
}
