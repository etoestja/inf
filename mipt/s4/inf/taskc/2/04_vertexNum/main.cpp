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
using std::cerr;

Tree* T;

void printHelpExit(char* name)
{
    cout << "Usage: " << name << " random vertN | test threadsN | both vertN threadsN | x vertN" << endl;
    exit(1);
}

int main(int argc, char** argv)
{
    if(argc <= 2)
        printHelpExit(argv[0]);

    unsigned N = atoi(argv[2]);

    if(argv[1][0] == 'r')
    {
        srand(time(NULL));
        randomTree b(N);
        cout << b.printTree() << endl;
    }
    if(argv[1][0] == 'x')
    {
        srand(time(NULL));
        randomTree b(N);
    }
    else if(argv[1][0] == 't')
    {
        T = new Tree;
        T->readCin();

        cerr << "Using " << N << " threads" << endl;

        treeThreadCounter tHC;
        cout << tHC.count(T, N) << endl;
    }
    else if(argv[1][0] == 'b' && argc == 4)
    {
        int N1 = atoi(argv[3]);
        srand(time(NULL));
        randomTree b(N);
        treeThreadCounter tHC;
        clock_t c = clock();
        cout << tHC.count(&b, N1) << endl;
    }
    else
        printHelpExit(argv[0]);

    return(0);
}
