#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

map<int, bool> myMap;
int N;
int t;

map<int, bool>::iterator it;

void update()
{
    it = myMap.find(t);
    if(it == myMap.end())
        myMap[t] = 1;
    else if((*it).second == 1) myMap.erase(it);
}

int main()
{
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        update();
    }

    for(it = myMap.begin(); it != myMap.end(); it++)
    {
        cout << (*it).first << " ";
    }

    cout << endl;

	return 0;
}
