#include <iostream>
#include <map>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::map;
using std::vector;

const unsigned int NMAX = 7500;
int N;

map<int, bool> arr[NMAX + 1];
vector<bool> B;
vector<int> code;

int main()
{
    int t, i, j;
    while(cin >> t)
        code.push_back(t);

    N = code.size() + 2;
    for(i = 1; i < N; i++)
        B[i] = 1;

    int b;
    bool flag;

    for(i = 1; i <= N + 1; i++)
    {
        if(B[i])
        {
            flag = true;
            for(j = i - 1; j < code.size(); j++)
            {
                if(i == code[j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                
            }
        }
    }

    return 0;
}
