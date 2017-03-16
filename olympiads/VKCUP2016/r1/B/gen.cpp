#include <iostream>
#include <stdlib.h>
#include <sys/timeb.h>
using namespace std;

long long rand_()
{
	long long res = rand();
	res *= rand();
	return res;
}

int main()
{
	timeb tp;
       	int t = ftime(&tp);
	srand(tp.time + tp.millitm);
	int N = (rand_()) % (100000-1) + 2;
	int K = (rand_()) % (N - 1) + 1;
	int Z = (rand_()) % (K - 1) + 1;
	cout << N << ' ' << K << ' ' << Z << endl;
	return 0;
}

