#ifndef TREECOUNTER_H
#define TREECOUNTER_H

#include "tree.h"
#include <string>
#include <thread>

using std::string;
using std::thread;

class treeThreadCounter
{
private:
    int semid;
    string pathname;
    static const int nsems = 2;
    enum sems{MUTEX_SUM = 0, MUTEX_AVAILABLE};
    vector<thread> threads;

    unsigned availableCounters, maxCounters;
    unsigned sum;
    void initSems();
    void initValues(int threads);
    void countOne(Tree* root);
public:
    treeThreadCounter();
    unsigned count(Tree *root, unsigned nTh);
};

#endif // TREECOUNTER_H
