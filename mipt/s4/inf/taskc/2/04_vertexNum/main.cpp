#include "tree.h"
#include "randomTree.h"
#include "treeStupidCounter.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

int main()
{
    srand(time(NULL));
    randomTree b(100);

    cout << "generated:" << endl;
    cout << b.printTree();

    cout << "num=" << treeStupidCounter::count(&b) << endl;
}
