#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::set;

unsigned int M,N;

#define NMAX 2013

int arr[NMAX][NMAX];

void nofprintf(FILE* a, ...)
{
}

#define fprintf nofprintf

int start;

map< unsigned int,vector<unsigned int> > g;
vector<unsigned int> used;
vector<unsigned int> okArr;

void dfs1(unsigned int v) {
    arr[start][v] = 1;
	used[v]=1;
	if(g.find(v)!=g.end()) {
		vector<unsigned int>::iterator it;
		for(it=g[v].begin();it!=g[v].end();it++) {
			if(!used[*it]) dfs1(*it);
		}
	}
}

int main() {
	unsigned int i,si,t1,t2;
	cin >> N >> M;

    for(t1 = 0; t1 < NMAX; t1++)
        for(t2 = 0; t2 < NMAX; t2++)
            arr[t1][t2] = 0;
	
	vector<unsigned int> tvect;
	
	for(i=0;i<M;i++) {
		cin >> t1 >> t2;
		t1--;t2--;
		if(g.find(t1)!=g.end()) g[t1].push_back(t2);
		else {
			tvect.clear();
			tvect.push_back(t2);
			g[t1]=tvect;
		}
	}
	

	for(i=0;i<N;i++) {
        start = i;
	    used.assign(N,0);
        dfs1(i);
	}

    for(t1 = 0; t1 < N; t1++)
    {
        for(t2 = 0; t2 < N; t2++)
            fprintf(stderr, "%d ", arr[t1][t2]);
        fprintf(stderr, "\n");
    }

	okArr.assign(N,0);
    int OKCount = 0;

    int probeOK;
    int maxProbeOK;
    int maxI;

    int res = 0;

    while(OKCount < N)
    {
        maxProbeOK = 0;
        for(i = 0; i < N; i++)
        {
            probeOK = 0;
            for(t1 = 0; t1 < N; t1++)
            {
                if(arr[t1][i] && !okArr[t1])
                    probeOK++;
            }
            fprintf(stderr, "v=%d, probeOK=%d\n", i, probeOK);

            if(probeOK > maxProbeOK)
            {
                maxProbeOK = probeOK;
                maxI = i;
            }
        }

        fprintf(stderr, "maxI = %d, maxProbeOK = %d\n", maxI, maxProbeOK);

        for(t1 = 0; t1 < N; t1++)
            if(arr[t1][maxI] && !okArr[t1])
                okArr[t1] = 1;

        fprintf(stderr, "to %d\n", maxI);
        OKCount += maxProbeOK;
        res++;
    }

    cout << res << endl;

    return(0);
}
