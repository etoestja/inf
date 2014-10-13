#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

unsigned N;

vector<double> x;
vector<double> y;

typedef vector<unsigned> indexes;

map<indexes, double> divdiff;

indexes rmFirst(indexes a)
{
    indexes b = a;
    b.erase(b.begin());
    return(b);
}

indexes rmLast(indexes a)
{
    indexes b = a;
    b.erase(b.begin() + (a.size() - 1));
    return(b);
}

void printIndexes(indexes a)
{
    vector<unsigned>::iterator it;
    for(it = a.begin(); it != a.end(); it++)
    {
        cout << (*it);
        if(it + 1 != a.end())
            cout << " ";
    }
}

void addDivDiff(indexes a)
{
    indexes b1 = rmFirst(a);
    indexes b2 = rmLast(a);

    int first = *(a.begin());
    int last = *(a.begin() + (a.size() - 1));

    divdiff[a] = (divdiff[b1] - divdiff[b2]) / (x[last] - x[first]);
}

void divDiffExpand()
{
    map<indexes, double> m;
    m = divdiff;

    map<indexes, double>::iterator it;
    for(it = m.begin(); it != m.end(); it++)
    {
        for(unsigned i = 0; i <= N; i++)
        {
            indexes I = (*it).first;

            bool flag = true;
            for(unsigned j = 0; j < I.size(); j++)
                if(I[j] == i)
                    flag = false;

            if(flag)
            {
                I.push_back(i);

                if(divdiff.find(I) == divdiff.end())
                    addDivDiff(I);
            }
        }
    }
}

void DivDiffInit()
{
    for(unsigned i = 0; i <= N; i++)
    {
        indexes I;
        I.push_back(i);
        divdiff[I] = y[i];
    }
}

double calcMaxAbs(int L, double x0)
{
    double maxAbs = 0;
    for(unsigned j = 0; j + L - 1 <= N; j++)
    {
        indexes I;

        bool flag = false;

        for(unsigned i = j; i <= j + L - 1; i++)
        {
            if(i < j + L - 1 && x[i] <= x0 && x[i + 1] >= x0)
                flag = true;
            I.push_back(i);
        }

        if(flag)
        {
            cout << "trying [" << endl;
            printIndexes(I);
            cout << "]" << endl;
        }

        if(flag && maxAbs < fabs(divdiff[I]))
            maxAbs = fabs(divdiff[I]);
    }
    return(maxAbs);
}

int main()
{
    cin >> N;

    x.resize(N + 1);
    y.resize(N + 1);

    for(unsigned i = 0; i <= N; i++)
        cin >> x[i];

    for(unsigned i = 0; i <= N; i++)
        cin >> y[i];

    DivDiffInit();

    for(unsigned i = 0; i < N; i++)
        divDiffExpand();

    map<indexes, double>::iterator it;
    for(it = divdiff.begin(); it != divdiff.end(); it++)
    {
        cout << "f(";
        printIndexes((*it).first);
        cout << ")=" << (*it).second << endl;
    }

    int M, L;
    double x0;

    cin >> M >> x0;

    for(unsigned i = 0; i < M; i++)
    {
        cin >> L;
        cout << calcMaxAbs(L, x0) << endl;
    }

    cout << (x0 - x[2]) * (x0 - x[3]) << endl;

    return 0;
}

