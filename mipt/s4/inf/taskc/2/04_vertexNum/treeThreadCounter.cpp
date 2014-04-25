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

/*#define _semOp(__sem, __op) mybuf.sem_num = __sem;\
mybuf.sem_op  = __op;\
mybuf.sem_flg = 0;\
if(semop(semid, &mybuf, 1) < 0){\
    cerr << "Can't wait for condition" << endl;\
    exit(-1);\
}*/
#define _semOp(__sem, __op)

void treeThreadCounter::initSems()
{
    key_t key = ftok(pathname.c_str(), 0);

    if((semid = semget(key, nsems, 0666 | IPC_CREAT | IPC_EXCL)) < 0)
    {
        if(errno != EEXIST)
        {
            cerr << "Error creating semaphore array" << endl;
            exit(-1);
        }
        else {
            if((semid = semget(key, nsems, 0666)) < 0)
            {
                cerr << "Error accessing semaphore array" << endl;
                exit(-1);
            }
        }
    }

    sembuf mybuf;
    _semOp(MUTEX_SUM, 1);
    _semOp(MUTEX_AVAILABLE, 1);
}

void treeThreadCounter::initValues(int threads)
{
    sembuf mybuf;
    _semOp(MUTEX_SUM, -1);
    sum = 0;
    _semOp(MUTEX_SUM, 1);

    _semOp(MUTEX_AVAILABLE, -1);
    availableCounters = threads;
    _semOp(MUTEX_AVAILABLE, 1);

    maxCounters = threads;
}

treeThreadCounter::treeThreadCounter()
{
    pathname = string("main.o");
    initSems();
}

unsigned treeThreadCounter::count(Tree *root, unsigned nTh)
{
    initSems();
    initValues(nTh);

    countOne(root);

    sembuf mybuf;

    //_semOp(MUTEX_AVAILABLE, -10);
    //usleep(100000);
    //_semOp(MUTEX_AVAILABLE, -10);
    //_semOp(MUTEX_SUM, -1);
    return(sum);
}

void treeThreadCounter::countOne(Tree *root)
{
    sembuf mybuf;

    _semOp(MUTEX_SUM, -1);
    sum++;
    _semOp(MUTEX_SUM, 1);

    vector<Tree*>::iterator it;
    bool useThread;

    vector<thread> vT;

    for(it = root->children.begin(); it != root->children.end(); it++)
    {
        useThread = 0;
        _semOp(MUTEX_AVAILABLE, -1);

        if(availableCounters > 0)
        {
            availableCounters--;
            useThread = 1;
        }

        _semOp(MUTEX_AVAILABLE, 1);

        if(useThread)
        {
            //thread *t1 = new thread(&treeThreadCounter::countOne, this, (*it));
            thread t1(&treeThreadCounter::countOne, this, (*it));
            //t1.join();
            //vT.push_back(t1);
            vT.push_back(t1);
        }
        else
            countOne(*it);
    }

    for(vector<thread>::iterator it1 = vT.begin(); it1 != vT.end(); it1++)
    {
        (*it1).join();
        //delete *it;
    }

    _semOp(MUTEX_AVAILABLE, -1);
    availableCounters++;
    _semOp(MUTEX_AVAILABLE, 1);
}
