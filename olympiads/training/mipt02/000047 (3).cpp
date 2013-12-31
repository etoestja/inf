#include<iostream>
#include<deque>
using namespace std;
typedef struct A 
{
	int executetime;
	int starttime;
	int num;
} Elt;

Elt MakeElt(int sttime, int extime, int _num)
{
	Elt n;
	n.executetime = extime;
	n.starttime = sttime;
	n.num = _num;
	return n;
}

deque <Elt> f;
int ans[1000][1000] = {0};
int extime[1000];
Elt proc[1000];
int q, t, n, time1[1000], time2[1000];
int finished = 0;
void Add(Elt e)
{
	f.push_front(e);
}

void Run(int num, int time)
{
	for (int tt = t; tt < t+time; tt++)
	{
		ans[f[0].num - 1][tt] = 2;
		for (int i = 1; i < f.size(); i++)
			ans[f[i].num - 1][tt] = 1;
	}

	t+=time;
	f[num].executetime -= time;
	if (f[num].executetime == 0)
	{
		time1[f[num].num] = t - f[num].starttime;
		time2[f[num].num] = t - f[num].starttime - extime[f[num].num-1];
		f.erase(f.begin() + num, f.begin() + num + 1);
		finished++;
	}
	else
	{
		f.push_back(f[num]);
		f.erase(f.begin() + num, f.begin() + num + 1);
	}
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> q >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> proc[i].starttime;
		cin >> proc[i].executetime;
		extime[i] = proc[i].executetime;
		proc[i].num = i + 1;
	}

/*	for (int i = 0; i < n; i++)
	{
		cout << proc[i].starttime << ' ' << proc[i].executetime << ' ' << proc[i].num << endl;
	} */

	for (int i = 0; i < n-1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (proc[j].starttime > proc[j+1].starttime)
			{
				Elt t = proc[j];
				proc[j] = proc[j+1];
				proc[j+1] = t;
			}

	/*cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << proc[i].starttime << ' ' << proc[i].executetime << ' ' << proc[i].num << endl;
	} */

	t = 0;
	int cur = 0;
	while (finished < n)
	{
		/*for (int i = 0; i < f.size(); i++)
			cout << f[i].num << ' ';
		cout << endl;*/
		//cout << t << ' ' << proc[i].starttime << endl;
		while ((cur < n) && (t >= proc[cur].starttime))
		{
			Add(proc[cur]);
			for (int tt = proc[cur].starttime; tt < t; tt++)
				ans[proc[cur].num - 1][tt] = 1;
		//	cout << "Ababcaba\n";
			cur++;
		}
		int etime;
/*		if (cur < n)
			etime = min(min(proc[cur].starttime, f[0].executetime), q);
		else*/
			etime = min(f[0].executetime, q);
		//cout << "Num: " << f[0].num << " time " << etime << endl;
		Run(0, etime);
	}
	printf("n\\t|");
	for (int i = 0; i < t; i++)
		printf("%3d", i);
	printf("\n---|");
	for (int i = 0; i < t; i++)
		printf("---");
	for (int i = 0; i < n; i++)
	{
		printf("\n%3d|", i+1);
		for (int j = 0; j < t; j++)
		{
			if (ans[i][j] == 0)
				printf("   ");
			else if (ans[i][j] == 1)
				printf("  r");
			else
				printf("  R");
		}
	}
	printf("\n");
	printf("\n");
	printf("turnaround time = (");
	int t = 0;
	for (int i = 0; i < n; i++)
		t+=time1[i+1];
	printf("%d", time1[1]);
	for (int i = 2; i <= n; i++)
		printf(" + %d", time1[i]);
	printf(") / %d = %lg", n, (double)t/n);

	printf("\n");
	printf("waiting time = (");
	t = 0;
	for (int i = 1; i <= n; i++)
		t+=time2[i];
	printf("%d", time2[1]);
	for (int i = 2; i <= n; i++)
		printf(" + %d", time2[i]);
	printf(") / %d = %lg", n, (double)t/n);
	return 0;
}