#include <iostream>
using namespace std;

int cur_n = 1;

void print_branch(int len)
{
	int from = 1;
	for (int i = 0; i < len; i++)
	{
		cout << from << ' ' << ++cur_n << endl;
		from = cur_n;
	}
}

int main()
{
	int h, d, n;
	cin >> n >> d >> h;
	if ((d > 2 * h) || ((d == h) && (d < n - 1)))
	{
		cout << -1 << endl;
		return 0;
	}
	print_branch(h);
	print_branch(d - h);
	while (cur_n < n)
		print_branch(1);
	return 0;
}