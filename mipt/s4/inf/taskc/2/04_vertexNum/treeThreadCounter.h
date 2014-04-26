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
    std::atomic<unsigned> availableCounters; // counters left
    std::atomic<unsigned> sum; // result

    unsigned maxCounters; // max threads number

    void initValues(unsigned tN); // init local variables
    void countOne(Tree *root); // count number of vertexes with/wo threads
public:
    treeThreadCounter();
    unsigned count(Tree *root, unsigned nTh); // count number of vertexts with <= nTh threads
};

#endif // TREECOUNTER_H
