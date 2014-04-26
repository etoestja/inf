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

using std::pair;

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

    countOne(root, 0, &sum);

    return(sum);
}

typedef pair<thread, unsigned*> threadWithRes;

void treeThreadCounter::countOne(Tree *root, bool threaded, unsigned* result)
{
    // current vertex
    unsigned tr = 1;

    vector<Tree*>::iterator it;
    bool useThread;

    vector<threadWithRes> vT;

    // children of current vertex
    for(it = root->children.begin(); it != root->children.end(); it++)
    {
        useThread = 0;

        if(!threaded)
        {
            mutexAC.lock();
            if(availableCounters > 0)
            {
                availableCounters--;
                useThread = 1;
            }
            mutexAC.unlock();
        }

        if(useThread)
        {
            cerr << "using thread" << endl;
            unsigned* t_int = new unsigned;
            vT.push_back(threadWithRes(thread(&treeThreadCounter::countOne, this, (*it), 1, t_int), t_int));
        }
        else
        {
            unsigned* t_int = new unsigned;
            countOne(*it, 0, t_int);
            tr += *t_int;
            delete t_int;
        }
    }

    for(vector<threadWithRes>::iterator it1 = vT.begin(); it1 != vT.end(); it1++)
    {
        (*it1).first.join();
        tr += *((*it1).second);
        delete (*it1).second;
    }

    *result = tr;

    // slow if used
    if(threaded)
    {
        //mutexAC.lock();
        //availableCounters++;
        //mutexAC.unlock();
        cerr << "thread finished" << endl;
    }
}
