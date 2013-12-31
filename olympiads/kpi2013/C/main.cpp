#include <iostream>
#include <vector>

using std::cin;
using std::endl;
using std::cout;

using std::vector;

#define NMAX 105

int N, K;
int maxK[NMAX][NMAX];
int arr[NMAX][NMAX]; //1 if OK

int visited[NMAX * 2][NMAX * 2];

vector<int> relX;
vector<int> relY;
vector<int> relK; //min k: (x, y) from above

string path;

//input map & path to array
void input()
{
    cin >> N >> K;
    char c;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            cin >> c;
            arr[i][j] = (c == '0');
        }
    if(K > 0)
        cin >> path;
}

int x, y;
int k;

void go()
{
    //transp.
    if(path[k] == 'D')
    {
        
    }
}

//get rel vectors for path
void getRel()
{
    for(k = 0; k < K; k++)
    {
        
    }
}
//get maxK for each (x, y)
//make binsearch for k

int main()
{
}
