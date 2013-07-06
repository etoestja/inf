#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;

int t, N;
set<int> mySet;
set<int>::iterator it;

void update()
{
    it = mySet.find(t);
    if(it == mySet.end())
        mySet.insert(t);
    else mySet.erase(it);
}

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        update();
    }

    for(it = mySet.begin(); it != mySet.end(); it++)
    {
        cout << (*it) << " ";
    }

    cout << endl;

	return 0;
}
