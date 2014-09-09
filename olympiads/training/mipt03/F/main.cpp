#include <iostream>
#include <vector>

using namespace std;

long long n, k, p;

vector<long long> v;

int main()
{
    cin >> n >> k >> p;

    long long sum = 0;

    sum += n - k;

    for(unsigned i = 0; i < n - k; i++)
        v.push_back(1);

    long long currentW = 2;
    long long currentWCount = 0;

    for(unsigned i = n - k; i < n; i++)
    {
        long long leftCount = i;
        long long leftLessCount = leftCount - currentWCount;

        /*cerr << i << "\t";
        cerr << "LC=" << leftCount << "\t";
        cerr << "LLC=" << leftLessCount << endl;*/

        if(100 * leftLessCount < p * leftCount)
        {
            currentW++;
            currentWCount = 0;
        }
        //else
            currentWCount++;

        v.push_back(currentW);
        sum += currentW;
    }

    cout << sum << endl;

    for(unsigned i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << endl;

    return 0;
}

