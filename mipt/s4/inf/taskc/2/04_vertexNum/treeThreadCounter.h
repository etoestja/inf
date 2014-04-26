#ifndef TREECOUNTER_H
#define TREECOUNTER_H

#include "tree.h"
#include <string>
#include <thread>
#include <mutex>

using std::string;
using std::thread;
using std::mutex;

class treeThreadCounter
{
private:
    unsigned availableCounters; // counters left
    unsigned sum; // result

    mutex mutexSum, mutexAC;

    unsigned maxCounters; // max threads number

    void initValues(unsigned tN); // init local variables
    void countOne(Tree *root, bool threaded); // count number of vertexes with/wo threads
public:
    treeThreadCounter();
    unsigned count(Tree *root, unsigned nTh); // count number of vertexts with <= nTh threads
};

#endif // TREECOUNTER_H
