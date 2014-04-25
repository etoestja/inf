#include "tree.h"
#include "randomTree.h"
#include "treeStupidCounter.h"
#include "treeThreadCounter.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

int main()
{
    srand(time(NULL));
    randomTree b(10000);

    //cout << "generated:" << endl;
    //cout << b.printTree();

    cout << "num=" << treeStupidCounter::count(&b) << endl;

    treeThreadCounter tHC;
    cout << "num1=" << tHC.count(&b, 1) << endl;
}
