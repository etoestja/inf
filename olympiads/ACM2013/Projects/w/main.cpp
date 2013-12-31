#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	int i;
	long long sum = 0;
	cin >> N;
	if(N >= 1)
	{
		for(i = 1; i <= N; i++)
			sum += i;
	}
	else
	{
		for(i = 1; i >= N; i--)
			sum += i;
	}
	cout << sum << endl;
}
