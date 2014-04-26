#include "treeThreadCounter.h"
#include "treeStupidCounter.h"
#include <thread>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/sem.h>
#include <unistd.h>
#include <fcntl.h>

using std::cerr;
using std::endl;
using std::thread;

void treeThreadCounter::initValues(unsigned threads)
{
    sum = 0;
    availableCounters = threads;
    maxCounters = threads;
}

treeThreadCounter::treeThreadCounter()
{
}

unsigned treeThreadCounter::count(Tree *root, unsigned nTh)
{
    initValues(nTh);
    availableCounters--;

    countOne(root, 0);

    return(sum);
}

void treeThreadCounter::countOne(Tree *root, bool threaded)
{
    // current vertex
    mutexSum.lock();
    sum++;
    mutexSum.unlock();

    vector<Tree*>::iterator it;
    bool useThread;

    vector<thread> vT;

    // children of current vertex
    for(it = root->children.begin(); it != root->children.end(); it++)
    {
        useThread = 0;

        mutexAC.lock();
        if(availableCounters > 0)
        {
            availableCounters--;
            useThread = 1;
        }
        mutexAC.unlock();

        if(useThread)
        {
            cerr << "using thread" << endl;
            vT.push_back(thread(&treeThreadCounter::countOne, this, (*it), 1));
        }
        else
            countOne(*it, 0);
    }

    for(vector<thread>::iterator it1 = vT.begin(); it1 != vT.end(); it1++)
    {
        (*it1).join();
    }

    // slow if used
    if(threaded)
    {
        mutexAC.lock();
        availableCounters++;
        mutexAC.unlock();
        cerr << "thread finished" << endl;
    }
}
