#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int a[100];
int main()
{
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	sort(a, a + N);
	cout << a[N / 2] << endl;
	return 0;
}
