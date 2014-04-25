#ifndef TREECOUNTER_H
#define TREECOUNTER_H

#include "tree.h"
#include <string>
#include <thread>
#include <atomic>

using std::string;
using std::thread;
using std::atomic;

class treeThreadCounter
{
private:
    std::atomic<unsigned> availableCounters, sum;
    unsigned maxCounters;
    void initValues(unsigned tN);
    void countOne(Tree *root);
public:
    treeThreadCounter();
    unsigned count(Tree *root, unsigned nTh);
};

#endif // TREECOUNTER_H
