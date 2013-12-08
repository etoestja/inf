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

void nofprintf(FILE* a, ...)
{
}

#define fprintf nofprintf

map< unsigned int,vector<unsigned int> > g;
vector<unsigned int> used;

vector<unsigned int> isset;
vector<unsigned int> found;

void dfs1(unsigned int v) {
	used[v]=1;
    found[v] = 1;
    isset[v] = 0;
	if(g.find(v)!=g.end()) {
		vector<unsigned int>::iterator it;
		for(it=g[v].begin();it!=g[v].end();it++) {
			if(!used[*it])
                dfs1(*it);
		}
	}
}

int main() {
	unsigned int i,si,t1,t2;
	cin >> N >> M;
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
	
    isset.assign(N + 1, 0);
    found.assign(N + 1, 0);
    int res = 0;

	for(i=0;i<N;i++) {
        used.assign(N + 1, 0);
        if(!found[i])
        {
            dfs1(i);
            isset[i] = 1;
            fprintf(stderr, "setting to %d\n", i);
        }
	}

    for(int i = 0; i < N; i++)
        if(isset[i]) res++;

    cout << res << endl;

    return(0);
}
