#include "randomTree.h"
#include <cstdlib>
#include <algorithm>

using std::random_shuffle;

randomTree::randomTree(int nodes)
{
    int nodesleft = nodes - 1;
    node = rand();

    if(nodesleft == 0) return;

    int m = maxChildren;
    if(m > nodesleft) m = nodesleft;

    int childrenN = m;//(rand() % m) + 1;
    int y = nodesleft / childrenN;

    for(int i = 0; i < childrenN; i++)
    {
        //nodesleft - here >= childrenN - i - 1
        //int here = ((rand() % (nodesleft + i + 1 - childrenN)) + 1);
        int here = y;
        randomTree *x = new randomTree(here);
        children.push_back(x);
        nodesleft -= here;
    }

    if(children.size() > 0)
        random_shuffle(children.begin(), children.end());
}
