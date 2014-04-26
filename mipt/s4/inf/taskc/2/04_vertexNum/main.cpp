#include "tree.h"
#include "randomTree.h"
#include "treeStupidCounter.h"
#include "treeThreadCounter.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

Tree* T;

int mainRand()
{
    srand(time(NULL));
    randomTree b(10000000);

    //cout << "generated:" << endl;
    //cout << b.printTree();

    cout << "num=" << treeStupidCounter::count(&b) << endl;

    treeThreadCounter tHC;
    cout << "num1=" << tHC.count(&b, 1) << endl;

    return(0);
}

void printHelpExit(char* name)
{
    cout << "Usage: " << name << " random vertN | test threadsN" << endl;
    exit(1);
}

int main(int argc, char** argv)
{
    if(argc <= 3)
        printHelpExit(argv[0]);

    unsigned N = atoi(argv[2]);

    if(argv[1][0] == 'r')
    {
        randomTree b(N);
        cout << b.printTree() << endl;
    }
    else if(argv[1][0] == 't')
    {
        T = new Tree;
        T->readCin();

        treeThreadCounter tHC;
        cout << tHC.count(T, N);
    }
    else
        printHelpExit(argv[0]);

    return(0);
}
