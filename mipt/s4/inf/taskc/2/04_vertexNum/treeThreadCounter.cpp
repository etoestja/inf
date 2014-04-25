#include "treeThreadCounter.h"
#include "treeStupidCounter.h"
#include <thread>
#include <iostream>

using std::cerr;
using std::endl;
using std::thread;

treeThreadCounter::treeThreadCounter()
{
}

unsigned treeThreadCounter::count(Tree *t, int threads, unsigned currentChild)
{
    if(t->children.size() == 0)
        return(1);
    else if(t->children.size() == 1)
        return(1 + treeThreadCounter::count(t->children[0], threads));
    else
    {
        unsigned r0 = 0;
        thread* t1;

        if(threads > 0)
        {
            cerr << "new thread" << endl;
            t1 = new thread(treeThreadCounter::countStupid, t->children[currentChild], &r0);
        }
        else
            r0 = treeStupidCounter::count(t->children[currentChild]);

        unsigned r1 = 0;

        if(currentChild + 1 < t->children.size())
            r1 = count(t, threads > 0 ? threads - 1 : 0, currentChild + 1);

        if(threads > 0)
            t1->join();

        return((currentChild == 0 ? 1 : 0) + r0 + r1);
    }

}

void treeThreadCounter::countStupid(Tree *r, unsigned *result)
{
    *result = treeStupidCounter::count(r);
}
