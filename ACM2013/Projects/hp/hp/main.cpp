#include <iostream>
#include <stdio.h>
using namespace std;

int d[200010];
int size = 0;

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void SiftUp(int i)
{
	if ((i > 1) && (d[i] < d[i/2]))
	{
		swap(d[i], d[i >> 1]);
		SiftUp(i >> 1);
	}
}

void SiftDown(int i)
{
	int min;
	if (i*2 > size)
		return;
	if ((i*2 == size) || (d[i*2] < d[i*2+1]))
		min = i*2;
	else
		min = i*2+1;
	if (d[i] > d[min])
	{
		swap(d[i], d[min]);
		SiftDown(min);
	}
}

void Add(int x)
{
	size++;
	d[size] = x;
	SiftUp(size);
}

int top()
{
	return d[1];
}

int pop()
{
	swap(d[1], d[size]);
	int ans = d[size];
	size--;
	SiftDown(1);
	return ans;
}




int main()
{
	char c;
	size = 0;
	cin >> c;
	while (c != 'q')
	{
		if (c == 'a')
		{
			int x;
			cin >> x;
			Add(x);
		}
		if (c == 'p')
			cout << pop() << endl;
		cout << "Size: " << size << endl;
		cin >> c;
	}
	return 0;

}