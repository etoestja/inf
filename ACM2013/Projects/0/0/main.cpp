#include <iostream>
#include <stdio.h>
using namespace std;
#define MaxN 10000
int a[2000], met[2000], t[2000];

int main()
{
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int h, m;
		char c;
		scanf("%d:%d %c", &h, &m, &c);
		t[i] = 60*h+m;
		if (c == 'S')
			a[i] = 26;
		else
		{
			a[i] = 28;
			met[i] = 1;
		}
	}
	int cost = a[0];
	for (int i = 1; i < N; i++)
	{
		if (t[i] - t[i-1] <= 90)
		{
			cost += 44 - a[i-1];
			int st = t[i-1];
			int k;
			if (met[i])
				k = 1;
			else
				k = 0;
			while ((i < N) && (k < 2) && (t[i] - st <= 90))
			{
				i++;
				if (met[i])
					k++;
			}
		}
		if (i < N)
			cost += a[i];
	}
	cout << cost;
	return 0;
}
