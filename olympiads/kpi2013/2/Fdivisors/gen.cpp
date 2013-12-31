#include <iostream>
#include <vector>

using namespace std;

#define K 100000

vector<int> div;

int main()
{
    for(int i = 1; i <= K; i++)
    {
        if(K % i == 0)
            div.push_back(i);
    }

    cout << div.size() << endl;
    for(int i = 0; i < div.size(); i++)
        cout << div[i] << " ";
    cout << endl;

    return(0);
}
